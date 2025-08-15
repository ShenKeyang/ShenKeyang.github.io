---
title: 算法笔记(C++) ——哈希表
date: 2025-08-15 22:13:28
tags:
---


## 哈希表的概念
哈希表是一种基于哈希函数（Hash Function）的数据结构，用于实现键值对的快速存储和查找。它的主要特点是：
1. 快速查找：平均情况下，__哈希表的查找、插入和删除操作的时间复杂度都是`O(1)`__。

2. 键值对存储：哈希表存储的是键值对，每个键（Key）唯一对应一个值（Value）。

3. 哈希函数：通过哈希函数将键映射到哈希表中的位置，从而实现快速存取。

__C++ 中的哈希表 ——`unordered_map`：__   

在 C++ 中，`unordered_map`是标准库提供的哈希表实现。它具有以下特点：

1. 键值对存储：unordered_map<Key, T> 存储的是键为 Key，值为 T 的键值对。

2. 快速访问：提供了常数时间复杂度的查找、插入和删除操作。

__主要操作：__   
1. 插入元素：
```c++
unordered_map<int, int> hash_map;  //定义哈希表
hash_map[key] = value;  // 插入或更新键为 key 的值为 value
```
2. 查找元素： 在C++的`unordered_map`（或`map`）中，`find(key)`方法用于查找关键字`key`是否存在。`find(key)`返回一个迭代器，如果`key`存在，迭代器指向元素，否则指向`end()`。使用`find(key)`可以高效检查`key`的存在。
```c++
if (hash_map.find(key) != hash_map.end()) {
    // 找到了 key
    int value = hash_map[key];
} else {
    // 没找到 key
}
```
3. 获取某键key的键值：
```c++
int count = hash_map[key];  // 如果key不存在，会自动插入key并初始化值为0
```
__示例代码（有一个包含n个整数的口袋，同时提出q个问题，每个问题询问特定的数字在口袋中出现了多少次。）：__
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,num;
    cin >> n >> q;

    unordered_map<int,int> map;  //定义哈希表

    for(int i =0; i<n; i++)
    {
        cin >> num;
        map[num]++;   
        //如果key不存在，会自动插入key并初始化值为0，遇到相应key键时对应的键值自增
    }

    for(int i =0; i<q; i++)
    {
        cin >> num;
        if(map.find(num)!=map.end())  //如果能找到对应键值的话
        {
            cout << map[num] << endl;
        }
        else
        {
            cout << 0 << endl;   //如果找不到对应键值，则输出0
        }
    }

    return 0;
}
```
  

<br><br>





## 时间复杂度
在编写程序时，分析其时间复杂度（Time Complexity）是一个重要指标。时间复杂度描述了程序运行时间与输入规模之间的关系。  
OJ一般C++1秒大概能跑1e8量级。
```c++
#include <iostream>
using namespace std;
int x;
int ans=0;
int main() {
	cin>>x;
	for (int i = 1; i <= x; i++) {
		ans++;
	}
	cout<<ans;
	return 0;
}
//对于这个简单的代码，x < 1e8 , 运行不会超时 ， x > 1e8 , 运行超时
```

__常见的时间复杂度包括：__

`O(1)`：常数时间，无论输入规模多大，执行时间保持不变。

`O(log n)`：对数时间，随着输入规模增加，执行时间按对数增长。例如二分操作。

`O(n)`：线性时间，执行时间与输入规模成正比。

`O(n log n)`：线性对数时间，常见于高效排序算法如快速排序、归并排序。

`O(n²)`：平方时间，常见于简单的嵌套循环，如冒泡排序。

__如何计算时间复杂度：__

1. 识别基本操作：确定算法中最频繁执行的操作，如循环中的语句、递归调用等。

2. 计算基本操作的执行次数：根据输入规模，计算这些操作随着输入增长的次数。

3. 忽略低阶项和常数系数：在大O表示法中，只保留增长最快的项，忽略常数和低阶项。

对于上述口袋问题题目而言，q=n=10^5 ，如果考虑对于每次查询去遍历一遍所有数，复杂度为O(n*Q)=10^10 ,根据上面的`1e8定理`，显然1秒钟是跑不完的，可能会被反馈超时（Time Exceeded），因此可以选用哈希表（Hash Table）的方式来统计每个数字出现的次数，使用C++提供的`unordered_map`来实现哈希表，因其具有平均`O(1)`的查找和插入时间复杂度，故能够高效地回答每个查询。  

