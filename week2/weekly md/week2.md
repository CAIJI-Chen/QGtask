# 线性回归法

## 简单的线性规划

通过分析问题，确定问题的损失函数或者效用函数。

通过最优化损失函数或者效用函数获得机器学习模型。

近乎所有参数学习算法都是这样的套路。

线性回归			SVM			最优原理

多项式回归		神经网络	凸优化

逻辑回归 ....

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\CBB4527873D773FD54C0600BC7A7ADB0.jpg)



## 最小二乘法

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\DC579FBC72942DC898F916634873B7BC.jpg)

## 简单的线性回归实现

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.array([1., 2., 3., 4., 5.])
y = np.array([1., 3., 2., 3., 5.])

plt.scattar(x,y)
plt.axis([0, 6, 0, 6])

x_mean = np.mean(x)
y_mean = np.mean(y)

num = 0.0
d = 0.0
for x,y in zip(x,y)
	num += (x_i - x_mean) * (y_i - y_mean)
    d +=(x - x_mean) ** 2

a=num / d
b = y_mean - a * x_mean
 
y_hat = a * x + b

plt.scatter(x,y)
plt.plot(x,y_hat,color='r')
plt.axis([0,6,0,6])
plt.show()

x_predict = 6
y_predict = a * x_predict + b

def fit(self,x_train,y_train)
	x_mean = np.mean(x)
	y_mean = np.mean(y)

	num = 0.0
	d = 0.0
	for x,y in zip(x,y)
		num += (x_i - x_mean) * (y_i - y_mean)
    	d +=(x - x_mean) ** 2

	self.a=num / d
	self.b = y_mean - a * x_mean
    return self
```

## 向量化运算

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\DF318A4ACAF3D1A2BE0ED13E4622675D.jpg)

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\D6238D6836B7E36C10DEE33B0EB8A0CB.jpg)



```python
def fit(self,x_train,y_train):
	x_mean = np.mean(x)
	y_mean = np.mean(y)
	
	num = (x_train - x_mean).dot(y_train - y_mean)
	d = (x_train - x_mean).dot(x_train - x_mean)
	for x_i,y_i in zip(x,y)

	self.a=num / d
	self.b = y_mean - a * x_mean
    return self

```

## 实现多元线性回归![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\AE08DF95A091D1D9F5BCEABAD6494F65.jpg)

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\4DC428C6A3641057AA7E7648D176E771.jpg)



```python
def fit_normal(self,X_train,y_train):
    X_b = np.hstack([np.ones(len(X_train,1)),X_train])
    self._theta = np.linalg.inv(X_b.T>dot(X_b)).dot(X_b.T).dot(y_train)
    self.interception_ = self._theta[0]
    self.coef_ = self._theta[1:]
    return self

def predict(self,X_predict):
    X_b = np.hstack([np.ones(len(X_predict,1)),X_predict])
    return X_b.dot(self._theta)

```

## 使用sklearn解决回归问题

```python
import numpy as np
import matplotlib.pyplot as plt
bosten = detasets.load_bosten()

x = bosten.data
y = bosten.target

x = x[y < 50.0]
y = y[y < 50.0]
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,random_state= 666)
from sklearn.linear_model import LinearRegression
lin_reg = LinearRegression()
lin_reg.fit(X_train,y_train)
lin_reg.coef_
lin_reg.intercept_

```

# 梯度下降法

## 实现线性回归中的梯度下降

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\C9768120093A7E9D7DC55753155FC19D.jpg)

```python
def J(theta,X_b,y):
    try:
        return np.sum((y - X_b.dot(theta)) **2)/len(X_b)
    except:
        return float('inf')

def dJ(eta,X_b,y):
    res = np.empty(len(theta))
    res[0] = np.sum(X_dot(theta) - y)
    for i in range(1,len(theta)):
        res[i] = (X_b.dot(theta) - y).dot(X_b[:,i])
    return res = 2/len(X_b)

def gradient_descent(X_b,y,inital_theta,eta,n_iters = 1e4,epsilon = 1e-6):
    theta = initial_theta
    i_iter = 0
    
    while i_iter < n_iters:
        gradient = dJ(theta,X_b,y)
        last_theta = theta
        theta = theta - eta * gradient
        
        if(abs(J(theta,X_b,y) - J(last_theta,X_b,y)) < epsilon):
            break
           i_iter +=1
        return
X_b = np.hatack([np.ones((len(x),1)),x,reshpe(-1,1)])
initial_theta = np.zero(X_b.shape[1])
eta = 0.01

theta = gradient_descent(X_b,y,initial_theta,eta)

```

