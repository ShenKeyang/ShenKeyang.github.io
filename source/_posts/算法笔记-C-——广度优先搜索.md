---
title: 算法笔记(C++) ——广度优先搜索
date: 2025-09-20 16:36:45
tags:
---


## 核心思想
广度优先搜索（Breadth-First Search，简称 BFS）是一种图或树的遍历或搜索算法。它从起始节点开始，首先访问所有相邻节点，然后对这些相邻节点的未访问邻居进行同样的操作，逐层向外扩展，直到遍历完所有节点或找到目标节点。BFS的特点就是：层次遍历（按照节点与起始节点的距离逐层遍历）与最短路径（在无权图中，BFS可以找到起始节点到目标节点的最短路径）  

__算法步骤：__
1. 初始化队列：创建一个空队列，用于存储待访问的节点。
2. 起始节点入队：将起始节点入队。
3. 循环以下操作，直到队列为空：
    - 从队列中出队一个节点作为当前节点，并标记它为已访问。
    - 访问当前节点的所有未被访问的邻居节点：
        - 将这些邻居节点标记为已访问。
        - 将这些邻居节点入队。

__注意：__
- 队列的种类决定了BFS的使用范围，例如普通队列（先进先出）适用于层次遍历，优先队列（大根堆或小根堆）适用于最短路算法。以下先来看普通队列的BFS。  

如下所示的是一个BFS的简单例子，需要从节点1开始使用BFS标记整个图，我们通过图示来逐步拆解这个过程：  
1. 创建一个空的普通队列，把节点1作为起始节点，标记节点1，先让它进入队列。  
![ ](/images/cpp_10_1.png)  
2. 接着开始执行BFS，从队列头部取出节点1，访问节点1的所有未被访问的邻居节点（2，3），然后将节点2和节点3入队，并标记它们。  
![ ](/images/cpp_10_2.png)  
3. 从队列头部取出节点2，标记节点2，访问节点2的所有未被访问的邻居节点（4，5），然后将节点4和节点5入队，并标记它们。  
![ ](/images/cpp_10_3.png)  
4. 重复上述步骤，直到队列为空，退出循环，到这里BFS就执行结束了。  
![ ](/images/cpp_10_4.png)  


<br>





## 队列queue的使用
C++ 中的 queue 是一个基于 FIFO（先进先出）原则的容器适配器。它通常用于需要按顺序处理元素的场景。queue 适配器是基于底层容器（通常是 deque 或 list）实现的，它提供了简单的接口来进行数据的插入和删除操作。

__基本使用：__
首先，需要包含头文件queue，然后可以通过以下几种基本操作来使用 queue。
```c++
#include <iostream>
#include <queue> //必要头文件

int main()
{
    // 创建一个空的队列
    std::queue<int> q;

    // 入队操作：push
    q.push(10);  // 向队列中添加元素 10
    q.push(20);  // 向队列中添加元素 20
    q.push(30);  // 向队列中添加元素 30

    // 获取队列的大小
    std::cout << "队列大小: " << q.size() << std::endl;  // 输出 3

    // 查看队列的前端元素：front
    std::cout << "队列头部元素: " << q.front() << std::endl;  // 输出 10

    // 出队操作：pop
    q.pop();  // 移除队列中的第一个元素

    // 再次查看队列的前端元素
    std::cout << "新的队列头部元素: " << q.front() << std::endl;  // 输出 20

    // 判断队列是否为空：empty
    if (q.empty())
    {
        std::cout << "队列为空" << std::endl;
    } else {
        std::cout << "队列不为空" << std::endl;
    }

    return 0;
}
```

__常用方法：__
- push(value)：将元素添加到队列的末尾。
- pop()：移除队列的头部元素。
- front()：获取队列的头部元素（但不移除它）。
- back()：获取队列的尾部元素（但不移除它）。
- size()：返回队列中元素的数量。
- empty()：检查队列是否为空。  

__特点与注意事项：__
- queue 是一个容器适配器，只能进行插入和删除操作，不能随机访问元素。
- queue 默认使用 deque 作为底层容器，因此具有高效的插入和删除操作，尤其是在队列两端。
- 不能通过下标访问队列中的元素，因为 queue 是一个先进先出（FIFO）结构。

__队列实现BFS例题 1：__
```c++
/*题目描述：
给定一个二维矩阵，表示一个迷宫，其中 1 表示墙壁，0 表示可以通行的道路。你有两个点，起点和终点，问是否存在
一条从起点到终点的路径，使得你可以从起点走到终点。你可以上下左右四个方向移动，但不能穿过墙壁，也不能离开迷
宫范围。坐标以行和列表示，均从0开始，左上角坐标是 (0,0) ，右下角坐标是 (n-1,m-1) 。

输入：
第一行输入两个整数 n 和 m，表示迷宫的行数和列数(1≤n,m≤100)。
接下来 n 行，每行包含 m 个整数，表示迷宫的地图，其中 0 表示通路，1 表示墙壁。
最后输入两个整数 x_1, y_1 和 x_2, y_2，表示起点和终点的坐标。

输出：
输出一个字符串，若从起点到终点存在路径，输出 "YES"，否则输出 "NO"。*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // 检查起点和终点是否在迷宫范围内，并且不是墙壁
    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || 
       x2 < 0 || x2 >= n || y2 < 0 || y2 >= m ||
       maze[x1][y1] == 1 || maze[x2][y2] == 1)
    {
        cout << "NO";
        return 0;
    }
    
    // 初始化访问数组
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // 定义四个移动方向：左，右，上，下
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // 使用队列进行BFS
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;
    
    bool found = false;
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        // 如果当前点是终点，设置 found 为 true 并跳出循环
        if(current.first == x2 && current.second == y2)
        {
            found = true;
            break;
        }
        
        // 尝试四个方向移动
        for(int i = 0; i < 4; ++i)
        {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];
            
            // 检查新位置是否在迷宫范围内，且是通路，且未被访问过
            if(newX >=0 && newX < n && newY >=0 && newY < m &&
               maze[newX][newY] == 0 && !visited[newX][newY])
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    // 根据是否找到终点输出结果
    if(found)
    {
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    return 0;
}
```
<br>

__队列实现BFS例题 2：__
```c++
/*题目描述：
给定一个无向图，该图通过邻接表的方式存储。请你使用广度优先搜索（BFS）算法计算该图的连通块数量。
在无向图中，一个连通块是指图中所有节点之间有路径相连的最大子图。你需要输出图中连通块的数量。

输入：
第一行包含两个整数 n 和 m（2≤n≤10^4 ，1≤m≤10^5 ），表示图中有 n 个节点和 m 条边。
接下来的 m 行，每行包含两个整数 u 和 v（1≤u,v≤n），表示存在一条从节点 u 到节点 v 的无向边。

输出：
输出一个整数，表示图中连通块的数量。*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int res=0;
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(0);
    bool allvisited = false;

    while(!allvisited)
    {
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            visited[cur]=true;
            for(int i=0;i<adj[cur].size();i++)
            {
                if(visited[adj[cur][i]]!=true)
                {
                    q.push(adj[cur][i]);
                }
            }
        }
        res++;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                allvisited=false;
                q.push(i);
                break;
            }
            allvisited=true;
        }
    }
    
    cout << res;

    return 0;
}
```
<br>

__队列实现BFS例题 3：__
```c++
/*题目内容：
每天早晨，环卫工人需要处理各个小区的生活垃圾，每个小区的生活垃圾由一队坏卫工人负责运送到最近的垃圾回收站
进行处理，求将所有小区垃圾送到垃圾回收站的最小距离和.假设小区和垃圾回收站都在都在一个m行n列的区域矩阵上，
相邻点的距离为1，只能上下左右移动;其中0表示垃圾处理站，1表示小区，2表示空白区域，−1表示障碍区域不可通行。
区域内如果没有小区或者没有垃圾回收站，则最小距离和返回0。
无法到达垃圾回收站的小区不计入本次距离和中。
计算所有小区垃圾送到垃圾回收站的最小距离和。

输入描述：
第一行为两个数字m和n的和，表示区域矩阵的行数和列数，中间使用空格分隔，m和n的范围均为[1,300]。
接下来的m行表示一个m×n的区域矩阵数组，每行的元素间以空格分隔，其中元素取值仅为−1(障碍)、0(垃圾处理站)、
1(小区)、2(空白区域)。

输出描述：
一个整数，表示所计算的最小距离和。*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> map(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> map[i][j];
        }
    }
    bool hasXiaoqu = false,hasLajizhan=false;
    vector<pair<int,int>> xiaoqu;

    for(int i=0;i<m;i++) //判断是否有小区和垃圾站并记录小区
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==0) hasLajizhan=true;
            if(map[i][j]==1)
            {
                hasXiaoqu=true;
                xiaoqu.push_back({i,j});
            }
        }
    }

    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};

    if(!hasLajizhan||!hasXiaoqu)
    {
        cout << 0;
        return 0;
    }

    int res=0;
    queue<pair<pair<int,int>,int>> q; //定义队列，元素为坐标绑定步数
    
    for(auto xq : xiaoqu) //每个小区各进行一轮BFS
    {
        vector<vector<int>> visited(m,vector<int>(n,0));

        while(!q.empty()) //把上一个小区所遗留的队列清空
        {
            q.pop();
        }
        q.push({{xq.first,xq.second},0});

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int step=cur.second; //步数迭代
            visited[cur.first.first][cur.first.second]=1;
            if(map[cur.first.first][cur.first.second]==0)
            {
                res+=step;
                break;
            }
            for(int i=0;i<4;i++)
            {
                int newX = cur.first.first+dx[i];
                int newY = cur.first.second+dy[i];
                if(newX >= 0 && newX < m && newY >= 0 
                    && newY < n && map[newX][newY]!=-1 
                    && visited[newX][newY]!=1) //不越界，不调头，不是墙
                {
                    q.push({{newX,newY},step+1});
                }
            }
        }
    }

    cout << res;

    return 0;
}
```


<br>




