---
title: 算法笔记(C++) ——并查集
date: 2025-09-23 16:58:49
tags:
---


## 并查集的概念
并查集（Union-Find）是一种树型数据结构，它的作用是管理元素所属集合的数据结构，主要支持两种操作：
- 合并（Union）：将两个不同的集合合并成一个集合。
- 查询（Find）：查询某个元素属于哪个集合。

从代码实现来说：  
- 并查集是一个森林，每一棵树是一个集合。
- 查询是找元素所在树的根节点。
- 合并是把一个树的根节点成为另一个树的根节点的子节点。

<br>



## 数据结构实现原理：
并查集通常使用数组实现：
- 使用一个数组parent来表示每个元素的父节点。每个集合由一个代表（根节点）表示。
- 如果某个元素的父节点是自身（即parent[i] = i），则该元素是集合的代表（根节点）。

例如，初始情况：
```
元素：1 2 3 4
父亲：1 2 3 4
```

<br>



## 代码结合说明：
1. 初始化：
```c++
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }   
}
```
初始parent数组为：[0, 1, 2, 3, 4,...] (下标0未用，元素1-4为独立集合)
2. 查找操作（路径压缩）：
```c++
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    } 
    return parent[x];
}
```
__路径压缩的作用：__  
当查找某个节点的根节点时，直接将该节点挂在根节点下面，这样能减少后续查询的复杂度。  
示例说明：
x → y 表示 parent[x] = y  
假设集合结构：1→2→3，此时查询1的根，路径压缩前是1→2→3，路径压缩后变为：  
1 → 3  
2 → 3  
查询效率明显提升。
3. 合并操作：
```c++
void unionSet(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);
    if (xRoot != yRoot)
    {
        parent[xRoot] = yRoot;
    }
}
```
示例说明：  
假设集合结构：1→1，2→2，3→1，执行union(2,3)后集合变为：  
1 → 1  
2 → 1  
3 → 1  

<br>



## 并查集的优势和适用场景：
- 优势：
    - 路径压缩优化：在查询(find)过程中，让树的结构更加扁平化，大大提升了查询和合并的效率。
    - 并查集的平均复杂度为O(log2 N)，性能优秀。

- 适用场景：
    - 判断两个元素是否属于同一集合或群组（如好友关系、网络连接性等）。
    - 动态计算图中联通块数量。
    - 快速实现“分组”操作，如“好友圈”问题。

__并查集例题1：__
```c++
/*题目描述：
如题，现在有一个并查集，你需要完成合并和查询操作。

输入格式：
第一行包含两个整数n,m表示共有 n 个元素和 m 个操作。接下来 m 行，每行包含三个整数 zi,xi,yi.
当 zi = 1 时，将 xi 与 yi 所在的集合合并。
当 zi = 2 时，输出 xi 与 yi 是否在同一集合内，是的输出Y，否则输出N。
（1<=N,M<=10^5）
 
输出格式：
对于每一个 zi =2 的操作，都有一行输出，每行包含一个大写字母，为 Y 或者 N 。*/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// 初始化
void init(int n)
{
    for(int i=0;i<n;++i)
    {
        parent[i] = i;
    }
}

// 查找（路径压缩）
int find(int x)
{
    if(parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并
void unionSet(int x, int y)
{
    if(find(x)!=find(y))
    {
        parent[find(x)] = find(y);
    }
}

int main()
{
    int n, m, z, x, y;
    cin >> n >> m;
    parent.resize(n);
    init(n);
    while(m--)
    {
        cin >> z >> x >> y;
        if (z == 1)
        {
            unionSet(x, y);
        }else{
            if (find(x) == find(y))
            {
                cout << "Y\n";
            }else{
                cout << "N\n";
            }
        }
    }
    return 0;
}
```
<br>

__并查集例题2：__
```c++
/*题目描述
小红想要处理一批图片，将相似的图片分类。他首先对图片的特征采样，得到图片之间的相似度，然后按照以下规则判断
图片是否可以归为一类:
1.相似度>0表示两张图片相似；
2.如果A和B相似，B和C相似，但A和C不相似。那么认为A和C间接相似，可以把ABC归为一类，但不计算AC的相似度；
3.如果A和所有其他图片都不相似，则A自己归为一类，相似度为0。给定一个大小为N×N的矩阵 M 存储任意两张图片的相
  似度，M[i][j]即为第i个图片和第j个图片的相似度，请按照"从大到小"的顺序返回每个相似类中所有图片的相似度之和。

输入描述：
第一行一个数N(1≤N≤900)，代表矩阵M中有N个图片。下面跟着N行，每行有N列数据，空格分隔，代表N个图片之间的相似度。
其中 0≤M[i][j]≤100，输入保证 M[i][j] = M[j][i]；
输入的矩阵分隔符为1个或多个连续空格。

输出描述：
每个相似类的相似度之和。格式为:一行数字，分隔符为1个空格。*/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
}

int find(int x)
{
    if(x != parent[x])
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x,int y)
{
    if(find(x)!=find(y))
    {
        parent[find(x)] = find(y);
    }
}

int main()
{
    int n;
    cin >> n;
    parent.resize(n);
    init(n);
    vector<vector<int>> map(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(map[i][j]>0)
            {
                unionSet(i,j);
            }
        }
    }

    int res[905]={0};
    // 计算每个相似类的相似度之和
    for(int i=0;i<n;i++)
    {
        for(int j= i ;j<n;j++) // 矩阵是对称的，只用得到半个矩阵
        {
            if(map[i][j] && find(i)==find(j))
            {
                res[find(i)]+=map[i][j];
            }
        }
    }

    sort(res+1,res+n+1);
    // 先排序，再倒序输出，遇到0则说明输出结束
    for(int i=n;i>=0;i--)
    {
        if(res[i]==0) break;
        cout << res[i] << " ";
    }

    return 0;
}
```