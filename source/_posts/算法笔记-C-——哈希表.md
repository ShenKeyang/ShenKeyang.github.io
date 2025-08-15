---
title: 算法笔记(C++) ——哈希表
date: 2025-08-15 22:13:28
tags:
---


## 哈希表的概念
哈希表是一种基于哈希函数（Hash Function）的数据结构，用于实现键值对的快速存储和查找。它的主要特点是：
1. 快速查找：平均情况下，哈希表的查找、插入和删除操作的时间复杂度都是 O(1)。

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

