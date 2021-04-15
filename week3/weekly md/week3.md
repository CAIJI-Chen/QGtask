# 数据挖掘

## 1 导入数据

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
#import missingno as msno
pass_ = pd.read_csv(r"C:\Users\Administrator\Desktop\中期考核\data\train\train.csv")
test_ = pd.read_csv(r"C:\Users\Administrator\Desktop\text\test2.csv")
```

## 2 数据处理

### 2-1 查看数据

```python
pass_.head(10)      #查看前十个数据
pass_.describe()    #数字类型数据平均值，最值等查看
test_.describe()
```

### 2-2 缺失值处理

```python
#填充缺失值

print(pass_["gender"].unique())  #查看此列数据有哪些（不重复）
pass_["gender"] = pass_["gender"].fillna('F')    #补充缺失值
pass_["city_tier"] = pass_["city_tier"].fillna(pass_["city_tier"].median()) #用中位数填充缺失值

#将字符串型的数据改为数字
pass_.loc[pass_["gender"] == "M","gender"] = 0   #男为0，女为1
pass_.loc[pass_["gender"] == "F","gender"] = 1

#查看此列各个数据具体信息
pass_.groupby("education").describe()   


#删去缺失值

df = pd.DataFrame(pass_)     

df.dropna(inplace = True,axis=0,how='any')  #删去任何一个字段为空值的行
df.dropna(inplace = True,axis=0,how='all')  #删去所有字段均为为空值的行
df.dropna(inplace = True,axis=1,how='any')  #删去任何一个字段为空值的列
df.dropna(inplace = True,axis=1,how='all')  #删去所有字段均为为空值的列


pass_.info()    #查看结果


```

![img](file:///C:\Users\Administrator\AppData\Roaming\Tencent\Users\1622674681\QQ\WinTemp\RichOle\UU~5XHR5W%LG7`PA3X745@H.png)



## 3 线性回归

```python
from sklearn.linear_model import LinearRegression    #线性回归
from sklearn.model_selection import KFold           #交叉验证

#特征
predictors = ["program_type","test_id","trainee_engagement_rating","program_duration","education", "test_type", "difficulty_level", "gender", "city_tier", "total_programs_enrolled","age","is_handicapped",]

alg = LinearRegression()
kf = KFold(n_splits=3, random_state=1) # KFold类实例化

predictions = []

# 有3次for循环，每次建立一个回归模型
for train, test in kf.split(pass_):
    train_predictors = (pass_[predictors].iloc[train,:])           # 取出训练数据
    train_target = pass_["is_pass"].iloc[train] 
    alg.fit(train_predictors, train_target)                        # 训练模型
    test_predictions = alg.predict(pass_[predictors].iloc[test,:]) # 套入模型
    predictions.append(test_predictions)

    
predictions = np.concatenate(predictions, axis=0)           # 转换成数组

# 使用线性回归得到的结果是在区间[0,1]上的某个值，需要将该值转换成0或1
predictions[predictions > 0.5] = 1
predictions[predictions <= 0.5] = 0

print("测试数据的总数量：", len(predictions))
print("正确的数量：", sum(predictions == pass_["is_pass"]))
accuracy = sum(predictions == pass_["is_pass"]) / len(predictions)
print("准确率为：", accuracy)
```

## 4 逻辑回归

```python
from sklearn import model_selection
from sklearn.linear_model import LogisticRegression

log = LogisticRegression(random_state=1, solver='liblinear') # 初始化逻辑回归类

score = model_selection.cross_val_score(log, pass_[predictors], pass_["is_pass"], cv=3)
print("准确率为：", score.mean())
```

## 5 随机森林

```python
from sklearn import model_selection
from sklearn.feature_selection import SelectKBest, f_classif 
from sklearn.ensemble import RandomForestClassifier

predictors = ["program_type","test_id","program_duration", "education","trainee_engagement_rating","gender","test_type", "city_tier", "difficulty_level","age","is_handicapped"]

#, "total_programs_enrolled"
rand = RandomForestClassifier(random_state=1, n_estimators=150, min_samples_split=4, min_samples_leaf=2)
kf = model_selection.KFold(n_splits=3, random_state=1)           #交叉验证
scores = model_selection.cross_val_score(rand, pass_[predictors], pass_["is_pass"], cv=kf)
print("随机森林模型的准确率："  +str(scores.mean()))
```

```python
#重要程度
selector = SelectKBest(f_classif, k=5) # f_classif：基于方差分析的检验统计f值，根据k个最高分数选择功能
selector.fit(pass_[predictors], pass_["is_pass"])

scores = -np.log10(selector.pvalues_)

plt.bar(range(len(predictors)), scores)
plt.xticks(range(len(predictors)), predictors, rotation='vertical')
plt.show()
```



## 6 集成多个分类

```python
from sklearn.ensemble import GradientBoostingClassifier
import numpy as np

algorithms = [
    [RandomForestClassifier(random_state=1, n_estimators=150, min_samples_split=4, min_samples_leaf=2),predictors],
    [GradientBoostingClassifier(random_state=5, n_estimators=50, max_depth=10), predictors ],     
    [LogisticRegression(random_state=1, solver='liblinear'), predictors],
    [LinearRegression(),predictors]                   #加入线性回归
]

kf = KFold(n_splits=10, random_state=5)               #分为10分，每份都拟合一次            

l_predictions = []
l_all_ = []
for train, test in kf.split(pass_):
    train_target = pass_["is_pass"].iloc[train]
    full_test_predictions = []
    i = 0
    for alg, predictors in algorithms:
        
        alg.fit(pass_[predictors].iloc[train,:], train_target)
        if i<3:
            test_predictions = alg.predict_proba(pass_[predictors].astype(float)) [:,1]
        else:
            test_predictions = alg.predict(pass_[predictors].astype(float)) 
        full_test_predictions.append(test_predictions)
        i = i+1
        
    
        
    test_predictions = (full_test_predictions[0]*3 + full_test_predictions[1]+full_test_predictions[2]+full_test_predictions[3]) /6
    l_all_.append(test_predictions)
    
l_predictions = (l_all_[0]+l_all_[1]+l_all_[2]+l_all_[3]+l_all_[4]+l_all_[5]+l_all_[6]+l_all_[7]+l_all_[8]+l_all_[9])/10           #数据平均值
l_predictions[test_predictions <= 0.5] = 0
l_predictions[test_predictions > 0.5] = 1
```

## 7 传入文件

```python
l_id_num = pd.read_csv("C:\\Users\\Administrator\\Desktop\\5\\test2.csv")["id_num"]       #传入文件
df = pd.DataFrame({
    "id_num":l_id_num,
    "is_pass":predictions
})


df.to_csv("C:\\Users\\Administrator\\Desktop\\5\\test2.csv",index=False,encoding='utf_8')
```









