# 1.串

对于不同的高级语言，对串的基本操作会有不同的定义方法。

## 1.1 串的抽象定义

```c
ADT 串(String)
Data
   串中元素仅由一个字补组成，相邻元素具有前驱和后继关系。
Operation 
  	StrAssign(T,*chars) :生成一个其值子于字符串常量chars的串T。
  	StrCopy(T,S):串S存在， 由串S复制得串T
  	ClearString (S):串s存在，将串清空。
  	StringEmpty(S):若S串为空，返回true， 否则返回false。
  	StrLength(S):退回串S的元素个数， 即串的长度。
  	StrCompare(S,T):若S>T,则返回值>0， 若S=T，返回0， 若S<T， 返回值<0
  	Concat(T,S1,S2) :用T返回出由S1和S2联接而成的新串。
  	SubString(Sub,S,pos,len):串S存在， 1<pos<StrLength(s),且0<len<StrLength(S)-pos+1,用Sub回串s的第pos个字符起长                              度为len的子串。
    Index（S,T,pos）：串s和t存在，t是非空串1<=pos<=StrLength(S),若主串s中存在和串T值相同的子串，则返回他在主串s中第pos个                      字符之后，第一次出现的位置，否则返回0。
   	Replace(S,T,V):串S和T存在，T是非空串。用V替换主串S中出现的所有与T相等的不重复子串。
    StrInsert(S,pos,T):串S和T存在，1<=pos<=StrLength(S)+1.在串S的第pos个字符之前插入串T。
    StrDelete(S,pos,len):串S存在，1<=pos<=StrLength(S)-len+1。从串S中删除第pos个字符起长度为len的子串。
endADT

```



## 1.2 Index的实现算法

 Index（S,T,pos）：串s和t存在，t是非空串1<=pos<=StrLength(S),若主串s中存在和串T值相同的子串，则返回他在主串s中第pos个字符之后，第一次出现的位置，否则返回0。

```c
int Index(String S,String T,int pos)
{
	int n,m,i;
    String sub;
    if(pos>0)
    {
        n=StrLength(s);//得到主事S的长度
    	m=Str Length(T);//得到子串下的长度
    	i=pos；
        while(i<=n-m+1)
        {
            SubString(sub,S,i,m); //取主串第i个位置 长度与T相等子串给sub
        	if(StrCompare(sub， T)!=0)//如果两串不和等
            	++i;
            else//如果两串相等
                return i;//则返回i值
    	}
    }
    return O;   //若无子串与T相等，返回0

}
```

## 1.3 模式匹配的算法Index

用基本数组来实现同样的算法

~~~c
/*返回子串Ｔ在主串S中第pos个字符之后的位置。若不存在， 则函数返回值为0。*/
/*T非空， 1≤pos≤StrLength(s) 。*/
int Index(StringS，String T，int pos)
{
    int i=pos;/*i用于主串S中当前位置下标， 若pos不为1*/
              /*则从pos位置开始匹配*/
	int j=1;  /*j用于子串T中当前位置下标值*/
	while(i<=S[0]&&j<=T[0])  /*若i小于Ｓ长度且j小于卫的长度时循环*/
  	{ if(S[i]==T[j])  /*两字母相等则继续*/
      	{++i;
       	++j;
      	}
   	  else  /*指针后退重新开始匹配*/
     {
          i=i-j+2;   /*i退回到上次匹配首位的下一位*/
          j=1;       /*j退回到子串T的首位*/
   	  }
 	}
  if(j>T[0])
    return i-T[0];
  else
	return 0;
}
~~~

## 1.4 KMP模式匹配算法实现

```c
/*通过计算返回子串Ｔ的next数组。*/
void get_nez t(String T，int*next)
{
    int i,j;
 	i=l;
    j=0;
	next[l]=0;
 	whlie(i<T[0])     /*此处T[0]表示事了的长度*/
	{
        if(j==0||T[i]==T[j])/*T[i]表示后缀的单个字符，*/
                            /*T[j]表示前缀的单个字符*/
   		{
            ++i;
         	++j;
    		next[i]=j;
        }
 		else
    		j=next [j];              /*若字符不相同，到j值回溯*/
 	}
 }

```

这段代码的目的就是为了计算出当前要匹配的串t和next数组。

```c
/*返回子串t在主串s中第pos个字符之后的位置，若不存在，则函数返回值为0*/
/*T非空，1<=pos<=StrLength(S)。*/
int Index_KMP(String S,String T,int pos)
{
    int i = pos;        //i用于主串S当前位置下标值，若pos不为1,则从pos位置开始匹配
    int j = 1;          //j用于子串T中当前位置下标值
    int next[255];      //定义一next数组
    get_next(T,next);   //对串T作分析，得到next数组
    while(i<=S[0]&&j<=T[0])     //若i小于S的长度且j小于T的长度时循环继续
	{
    	if(j==0||S[i]==T[j])  /*两字母相等则继续，与朴素算法增加了，/*j=0判断*/
   		{
        	++1;
    		++j;
    	}
 		else                   /*指针后退重新开始匹配*/
   			j=next[j];/*j退回合适的位置，i值不变*/
	}
	if(j>T[0])
		return i-T[0];
	else 
		return 0;
}

```



