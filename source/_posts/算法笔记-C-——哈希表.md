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
在编写程序时，时间复杂度（Time Complexity）是一个重要指标。时间复杂度描述了程序运行时间与输入规模之间的关系。  
OJ 一般 C++ 1秒大概能跑1e8量级。
```c++
#include <iostream>
using namespace std;

int main() {
    int x;
    int ans=0;
	cin>>x;
	for (int i = 1; i <= x; i++) {
		ans++;
	}
	cout<<ans;
	return 0;
}
//对于这个简单的代码，x < 1e8，运行不会超时；x > 1e8，运行超时。
```

__常见的时间复杂度包括（从小到大）：__

`O(1)`：常数时间，无论输入规模多大，执行时间保持不变。

`O(log n)`：对数时间，随着输入规模增加，执行时间按对数增长。例如二分操作。

`O(n)`：线性时间，执行时间与输入规模成正比。

`O(n log n)`：线性对数时间，常见于高效排序算法如快速排序、归并排序。

`O(n^2)`：平方时间，常见于简单的嵌套循环，如冒泡排序。

`O(n^3)`：立方时间。

`O(2^n)`：指数时间。

`O(n!)`：阶乘时间。

`O(n^n)`：幂指时间。

__如何计算时间复杂度：__

1. 识别基本操作：确定算法中最频繁执行的操作，如循环中的语句、递归调用等。

2. 计算基本操作的执行次数：根据输入规模，计算这些操作随着输入增长的次数。

3. 忽略低阶项和常数系数：在大O表示法中，只保留增长最快的项，忽略常数和低阶项。
<br>  

对于上述口袋问题题目而言，`q=n=10^5`，如果考虑对于每次查询去遍历一遍所有数，复杂度为`O(n*Q)=10^10`，根据上面的`1e8定理`，显然1秒钟是跑不完的，可能会被反馈超时（Time Exceeded），因此可以选用哈希表（Hash Table）的方式来统计每个数字出现的次数，使用C++提供的`unordered_map`来实现哈希表，因其具有平均`O(1)`的查找和插入时间复杂度，故能够高效地回答每个查询。    
  
<br><br>







## STL容器的嵌套使用
STL（Standard Template Library）容器的嵌套是指在一个容器中存储另一个容器作为其元素。例如，可以用`vector<vector>`表示一个二维数组，或用`map<int, vector>`表示一种键值对的映射。通过容器的嵌套，可以灵活地表示复杂的数据结构，如树、图、矩阵等。  
示例：
```c++
//题目描述：给定一个长度为 n 的数组 a 和 q 个询问。每个询问包含一个数 x 和一个整数 k 。对于每个询问，求数 x 在数组中第 k 次出现的位置（位置从 1 开始）。如果 x 在数组中出现次数不足 k 次，则输出 −1。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> res(q);
    unordered_map<int,vector<int>> pos; 
    //嵌套定义：键为整数，键值为一维数组的哈希表

    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
        pos[arr[i]].push_back(i+1); //向键为arr[i]的对应键值（数组）压入元素 i+1
    }
    
    for(int i =0;i<q;i++)
    {
        int x,k;
        cin >> x >> k;
        if (pos[x].size() < k) {
            res[i]=-1;
        } else {
            res[i]=pos[x][k - 1];//pos[x]是键为x所对应的键值（数组），相当于arr[k-1]
        }
    }

    for(int i =0 ; i<q ; i++)
    {
        cout << res[i] <<endl;
    }

    return 0;
}
```

<br>






## 哈希表例题 ——严格递增三元组
__题目描述：__  
给定一个大小为n的数组，找出所有的严格递增三元组(0 ≤ i < j < k < n) , 使得 a[i] = a[k] = a[j]+1 , 输出其数量`（有算法运行时间限制TL）`。

__输入描述：__  
第一行输入一个正整数 n（3 ≤ n ≤ 10^5）。  
第二行输入数组元素（1 ≤ a[i] ≤ 10^9）。  

__输出描述：__  
一个正整数，代表符合条件的三元组数量。  

__题目分析：__  
我们需要找出所有符合条件的严格递增三元组 (i, j, k)，使得：  
`1 <= i < j < k <= n`  
`a[i] = a[k] = a[j] + 1`  
换句话说，给定一个数 a[j] ，我们希望找到两个 i 和 k，使得 a[i] = a[k] = a[j] + 1 且 i < j < k。这可以形象地看作寻找形如 (x+1 , x , x+1) 的三元组。将求和过程先聚焦于中间的这个 x ，那么最终的答案等价于：
1. 对于位置 i 的数 a[i] , 寻找它前缀中 a[i]+1 的个数和后缀中 a[i]+1 的个数 , 根据乘法原理，答案是个数相乘
2. 对每个位置的个数进行求和。  


__示例代码：__
```c++
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;

    // 使用哈希表存储频率
    unordered_map<int, int> countLeft;
    unordered_map<int, int> countRight;

    // 读取数组
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 初始化 countRight
    for (int i = 0; i < n; i++) {
        countRight[a[i]]++;
    }

    // 遍历每个元素，计算符合条件的三元组数量
    for (int i = 0; i < n; i++) {
        int t = a[i] + 1;  // 计算 t = a[j] + 1
        res += countLeft[t] * countRight[t];

        // 更新 countLeft 和 countRight
        countLeft[a[i]]++;
        countRight[a[i]]--;
    }

    // 输出结果
    cout << res << endl;

    return 0;
}
```
  
<br><br>




