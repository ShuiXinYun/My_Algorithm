# 北大《程序设计与算法》（一）C语言程序设计相关代码

> [MOOC](https://www.icourse163.org/course/PKU-1001553023)

## week 1

有符号数、无符号数

## week 2

+ 输入输出、逻辑控制运算符 
+ %d, %c, %f, %lf, %lld, %x, %nd, %0nd, %.nf, %u
+ void 指针 

## week 3 & week 4

pass

## week 5

+ 筛法求n以内的素数
+ 二维数组元素内存地址连续性 

## week 6

+ 二维数组作为函数参数, 必须写明列数 
+ 位运算：按位与将某些位置零，按位或将某些位置1，按位异或将某些位取反, 按位非, 左移, 右移 

## week 7

字符串：读入数组, scanf, cin读入到空格;  读入行cin.getline(), gets();  <cstring>

## week 8

指针与数组, 指针运算

## week 9

+ 指针与字符串
+ void指针
+ 字符串操作库函数 
+ 内存操作库函数
+ 函数指针 

## week 10

+ 结构与指针
+ static
+ static应用: strtok()的实现
+ 简单排序: 选择排序, 插入排序，冒泡排序 

## week 11

二分查找, lowerbound(), upperbound() 

## week 12

+ c的qsort()
+ STL的sort()
+ STL的binary_search, lower_bound, upper_bound 
+ `bool binary_search(ArrayName, ArrayName + N, value); `
+ `bool binary_search(ArrayName, ArrayName + N, value, SortStructName());`
+ `T * lower_bound(ArrayName, ArrayName + N, value); `
+ `T * lower_bound(ArrayName, ArrayName + N, value, SortStructName)`
+ lower_bound(): 查找大于等于value, 下标最小的元素, 找不到则返回N处指针; upper_bound(): 查找大于value, 下标最小的元素, 找不到则返回N处指针

