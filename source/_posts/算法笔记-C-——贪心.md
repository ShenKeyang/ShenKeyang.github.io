---
title: 算法笔记(C++) ——贪心
date: 2025-09-23 15:44:25
tags:
---


在解决一些优化问题时，我们通常需要找出最优解（例如：最大化、最小化）。而`贪心算法（Greedy Algorithm）`是一种常用的求解方法，它的基本思想是：在每一步选择中都采取`当前最优的选择`，以期得到全局的最优解。  

__具体来说，贪心算法有以下特点：__
1. 局部最优选择：在每个阶段或步骤中，选择当前最优的解决方案，通常是选择那个“最好”的选项。
2. 不考虑全局情况：在每一步的决策中，贪心算法并不考虑未来的步骤，也不关心当前选择对后续的影响。它只专注于当前问题的最优解，而不是全局最优解。
3. 贪心策略的正确性：有时候，贪心算法能给出最优解，但`并不是所有的优化问题都能通过贪心算法找到全局最优解`。在能通过贪心算法找到最优解的情况下，这种算法非常高效。


__贪心正确性的证明：__
1. 交换法（Exchange Argument）：假设在某个最优解中，某些选择的顺序与贪心算法的选择顺序不一致。通过交换这些选择，证明交换后的解并不比原解差，或者至少能得到相同的最优解，从而证明贪心算法能得到全局最优解。
2. 归纳法（Inductive Proof）：在贪心算法中，归纳法常用于证明每一步选择的局部最优性能够导致全局最优解。在归纳步骤中，我们假设贪心算法对于较小规模问题的正确性，然后证明它对较大规模问题也能成立。

__贪心算法的实现步骤：__
1. 选择标准：确定每一步选择的标准，即选择当前最优的选项。
2. 选择过程：通过选择当前的最优解，逐步逼近问题的全局最优解。
3. 可行性检查：在选择过程中，要随时检查当前选择是否符合问题的约束条件。
4. 问题的最终解：在所有步骤完成后，得出最终的解。

__贪心算法例题1：__
```c++
/*题目描述：有一堆商品，每个商品有一个重量和价值。你有一个背包，背包的最大承重为 C，你需要从商品中选择
一部分商品放入背包，使得总价值最大化。商品可以被分割，即你可以选择一部分商品放入背包。

输入格式：
第一行包含两个整数 
n 和 C，分别表示商品的数量和背包的最大承重。(2<=n<=10^5),(1<=C<=10^5)接下来的n行，每行包含 2 个整数，
格式为 (w1,v1),(w2,v2),...,(wn,vn),其中 wi表示商品的重量，vi表示商品的价值。

输出格式：
输出一个浮点值，表示背包中放入商品后能得到的最大价值。结果保留 2 位小数。*/

#include<bits/stdc++.h>
using namespace std;

struct Item{ // 定义结构体存储每件商品的重量、价值、价重比
    int weight;
    int value;
    double ratio;
};

bool compare(const Item &a, const Item &b)
{   // 为后续的依照价重比降序排序作准备
    return a.ratio > b.ratio;
}

double func(int n, int c, vector<pair<int,int>> &items)
{
    vector<Item> itemsWithRatio;

    for(int i=0;i<n;i++)
    {
        int weight = items[i].first;
        int value = items[i].second;
        double ratio = (double)value / weight;
        itemsWithRatio.push_back({weight, value, ratio});
    }
    
    // 按照价重比降序排序（用到第三个参数，自定义排序办法）
    sort(itemsWithRatio.begin(),itemsWithRatio.end(),compare);
    
    double totalValue = 0.0;
    int remainingCapacity = c;

    for(const auto &item : itemsWithRatio)
    {   // 贪心：每次选取当前未装入背包的商品中价重比最高的
        if(remainingCapacity == 0)
        {
            break;
        }
        if (item.weight <= remainingCapacity)
        {   // 商品能完全放入背包
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {  
            // 注意本题中提到“商品可分割”，可以部分放入，到最后背包肯定是满的
            totalValue += item.value * ((double)remainingCapacity / item.weight);
            remainingCapacity = 0;
        }
    }
    
    return totalValue;
}

int main()
{
    int n,c;
    cin >> n >> c;
    vector<pair<int,int>> items(n);
    for(int i=0;i<n;i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    double res = func(n,c,items);
    
    // 依照题目要求格式化输出
    cout << fixed << setprecision(2) << res << endl;


    return 0;
}
```
<br>

__贪心算法例题2：__
```c++
/*题目内容：
小塔正在给自己的物品贴标签。她一共有m种不同的标签，每种标签只有一个。 对于第i个物品，如果贴上ai号标签，
那么它的美观值为bi;如果没有贴上ai号标签，则其美观值为ci。小美想知道在合理的分配下，所有物品的美观值之
和最大为多少。

输入描述：
第一行输入两个整数n和m代表小美的物品个数和标签种类。第二行输入n个整数ai代表每个物品适合的标签种类. 第
三行输入n个整数bi代表每个物品贴上适合的标签后的美观值。第四行输入n个整数ci代表每个物品未贴上适合标签时
的美观值。

输出描述：
在一行上输出一个整数，代表所有物品美观值之和的最大值。*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*思路：
1.标签分配：我们首先将物品根据它们适合的标签进行分组，记录每个标签所对应的物品索引。
2.优先选择贴标签：对于每个标签所对应的物品，优先选择能够带来更高美观值的物品贴标签。如果物品不能贴标签，
  就选择不贴标签的美观值。
3.排序策略：每个标签所对应的物品排序时，应该根据 bi - ci（即贴上标签和不贴标签的美观值差）来排序。这样
  可以优先选择那些能够通过贴标签获得更大美观值的物品。*/

ll greedy(int n, int m, const vector<int>& a, const vector<int>& b, const vector<int>& c)
{
    vector<vector<int>> idx(m+1);
    
    for (int i = 0; i < n; ++i)
    {
        idx[a[i]].push_back(i);
    }

    ll total_value = 0;
    for (const auto& lst : idx)
    {
        if (lst.empty()) continue;

        vector<int> sorted_lst = lst;
        sort(sorted_lst.begin(), sorted_lst.end(), [&c, &b](int x, int y) {
                return b[x] - c[x] > b[y] - c[y];
            }
        );

        total_value += max(b[sorted_lst[0]], c[sorted_lst[0]]);
        for (size_t i = 1; i < sorted_lst.size(); ++i)
        {
            total_value += c[sorted_lst[i]];
        }
    }
    return total_value;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll res = greedy(n, m, a, b, c);
    cout << res << endl;

    return 0;
}
```