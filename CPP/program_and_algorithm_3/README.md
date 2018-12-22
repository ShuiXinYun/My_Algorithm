# 北大《程序设计与算法》（三）C++面向对象程序设计

> 课程地址：[MOOC](https://www.icourse163.org/learn/PKU-1002029030#/learn/announce)

## week 1

+ 引用
+ const: const常量、指针、引用 
+ 动态内存分配
+ inline内联函数 

## week 2

构造函数：

+ 复制构造函数及其起作用的三种情况：用一个对象初始化另一个对象、函数参数、函数返回值为对象 
+ 类型转换构造函数

## week 3

静态成员 

+ 访问静态成员的4种方式
+ 静态成员的使用注意事项 
+ 友元：友元函数、友元类
+ 常量成员函数 

## week 4

### 4.1

运算符重载

+ 重载 + -实现复数加减 
+ 重载 + -为友元函数以支持左右加减 
+ 重载 = 实现实数赋值给复数对象，注意其与初始化复数对象使用到的构造函数的区别 

### 4.2 

运算符重载

+ 编写String类, bug版 
+ 重载 = 实现字符串对String对象的赋值
+ 未编写相应的 = 重载成员函数，导致浅拷贝，析构出错

### 4.3

改善4.2程序, 编写同类对象的赋值重载函数，进行的是深拷贝

### 4.4

编写可变长整型数组类
