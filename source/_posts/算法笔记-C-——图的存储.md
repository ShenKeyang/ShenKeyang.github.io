---
title: 算法笔记(C++) ——图的存储
date: 2025-09-10 18:11:36
tags:
---


## 前置知识
- 稀疏图：边的数量远小于顶点数的平方。  
- 稠密图：边的数量接近顶点数的平方。  
- 有向图：边具有方向性。  
- 无向图：边没有方向，可以视作双向边。  
- 有权图与无权图：有权图的边具有权值，无权图的边没有权值。  
  
<br><br>






## 邻接矩阵（Adjacency Matrix）
邻接矩阵用一个二维数组表示图，matrix[i][j] 表示从顶点 i 到 j 的边的信息（例如 1 代表有边，0 代表无边），适用于稠密图。  
![ ](/images/cpp_8_1.png)  

__实现：__  
1. 建表操作  
```c++
// 建立一张具有n个节点的图，此时这张图没有任何一条边
vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1));
```
2. 加边操作  
有时，一张图的读入通常以给定若干条边u v w 的形式给出，其中u代表这条边的起点,v代表这条边的终点,w代表这条边的权值。如果不含w，则读入的是无权图。  
对于邻接矩阵而言，需要了解如何对一张图进行加边操作  
```c++
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // 无向图
}
```
3. 输出邻接矩阵  
```c++
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        cout << (adjMatrix[i][j] ? "有边" : "无边") << " ";
    }
    cout << endl;
}
```
  
<br><br>





## 邻接表（Adjacency List）
对于稀疏图，邻接表是一种更高效的存储方式，只存储实际存在的边，使用数组或 vector 存储每个顶点的邻居列表。  
![ ](/images/cpp_8_1.png) 

__实现：__  
1. 建表操作  
使用结构体表示边信息，如果是无权图，可以直接使用 vector<int> adjList[n + 1]：
```c++
vector<vector<int>> adjList(n + 1);

// 或定义边的结构体
struct Edge {
    int to, weight;
};
vector<vector<Edge>> adjList(n + 1);
```
2. 加边操作  
无向图的加边操作：
```c++
void addEdge(int u, int v, int w) {
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w}); // 无向图
}
```
3. 遍历操作  
遍历邻接表的示例：
```c++
for (int u = 1; u <= n; u++) {
    cout << "Vertex " << u << " connects to ";
    for (auto edge : adjList[u]) {
        cout << "(" << edge.to << ", " << edge.weight << ") ";
    }
    cout << endl;
}
```
  
<br><br>




