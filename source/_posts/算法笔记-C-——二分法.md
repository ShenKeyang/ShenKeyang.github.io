---
title: 算法笔记(C++) ——二分法
date: 2025-08-23 19:40:53
tags:
---


## 查询是否存在某个数
二分算法是一种高效的查找算法，适用于`已经排好序`的数组或集合。其基本思想是通过每次将待查找的区间分成两半来逐步缩小查找范围，从而快速定位目标元素。与线性查找不同，二分查找能够大大减少查找次数，时间复杂度为`O(log n)`，其中n为数组的长度，效率远高于线性查找（`O(n)`）。  
__查找过程：__   
1. 设定一个查找范围的左右边界（双指针），通常用两个变量表示，low 和 high。
2. 计算当前区间的中间元素：mid = (low + high) / 2  
3. 将中间元素与目标值进行比较（指针迭代）：
    - 如果中间元素等于目标值，查找成功，返回该元素的位置。
    - 如果中间元素大于目标值，说明目标值在左半部分，更新high = mid - 1。
    - 如果中间元素小于目标值，说明目标值在右半部分，更新low = mid + 1。
4. 重复上述过程，直到查找范围为空（low > high），即目标值不存在。  
__二分法例题：__
```c++
/*给定一个升序排列的整数数组 A 和一个整数 Q，表示接下来有 Q 次查询。
  对于每次查询，您需要判断给定的整数 x 是否存在于数组 A 中。*/
#include <iostream>
#include <vector>
using namespace std;

// 二分查找函数
bool binarySearch(const vector<int>& A, int x) 
{
    int left = 0, right = A.size() - 1;
    while (left <= right)  //限定条件
    {
        int mid = (left + right) / 2;
        if (A[mid] == x) {
            return true; // 找到元素
        } else if (A[mid] < x) {
            left = mid + 1;  // 查找右半部分
        } else {
            right = mid - 1; // 查找左半部分
        }
    }
    return false; // 没有找到元素
}

int main() 
{
    int n, Q;
    cin >> n >> Q;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> A[i];
    }

    // 对每个查询进行二分查找
    while (Q--)   //共有 Q 次询问
    {
        int x;
        cin >> x;
        
        // 使用手写的二分查找函数
        if (binarySearch(A, x)) 
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
```
  
<br><br>






## lower_bound函数与upper_bound函数
在C++中，`lower_bound`和`upper_bound`是两个常用的标准库函数，位于`<algorithm>`头文件中。这两个函数主要用于在已排序的范围内进行二分查找，帮助快速定位元素的位置。  
1. __lower_bound:__  
`lower_bound`函数返回一个指向第一个不小于（>=）给定值的元素的迭代器。如果所有元素都小于该值，则返回范围的结束迭代器（arr.end()）。  
示例：  
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    vector<int> arr = {1, 3, 3, 5, 7};
    auto p = lower_bound(arr.begin(), arr.end(), 3);  //用auto定义
    if (p != v.end()) 
    {
        cout << "lower_bound of 3 is at position: " << (p - arr.begin()) << endl;
    }
    return 0;
}
//输出：lower_bound of 3 is at position: 1
```
2. __upper_bound:__  
`upper_bound`函数返回一个指向第一个大于（>）给定值的元素的迭代器。如果所有元素都小于该值，则返回范围的结束迭代器（arr.end()）。  
示例：  
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    vector<int> arr = {1, 3, 3, 5, 7};
    auto p = upper_bound(arr.begin(), arr.end(), 3);  //用auto定义
    if (p != v.end()) 
    {
        cout << "upper_bound of 3 is at position: " << (p - arr.begin()) << endl;
    }
    return 0;
}
//输出：upper_bound of 3 is at position: 3
```
- 为什么要使用`(p - arr.begin())`?
在上述示例中，p 是一个迭代器，指向容器中某个元素的位置。为了输出该元素在容器中的索引位置，需要将迭代器转换为整数索引。这时，使用 `(p - arr.begin())`进行迭代器的减法运算，其意义如下：
    1. 迭代器的减法：在C++中，随机访问迭代器（如 std::vector 的迭代器）支持直接的减法运算。`p - arr.begin()`计算的是 p 距离 arr.begin() 的距离，即 p 所指向元素的索引。
    2. 得到索引：通过`(p - arr.begin())`，可以将迭代器位置转换为具体的索引值，方便在输出或后续操作中使用。例如：  
    `cout << "lower_bound of 3 is at position: " << (p - arr.begin()) << endl;`  
    这行代码输出的是 3 在向量 arr 中第一次出现的位置索引 1。
    3. 通用性：这种方法不仅适用于`std::vector`，对于任何支持随机访问的容器（如`std::deque`、`std::array`），都可以使用迭代器减法来获取元素的索引。  

__注解：__
在上述向量 arr 共有 5 个元素，索引分别为0，1，2，3，4，`arr.begin()`指代的是 0 号索引，`arr.end()`指代的是5号索引（不存在，其对应元素值记为 0 ），p所指代的是某个元素的位置，通过加减符可以转化为整数索引用于输出，而可以用`*p`指代p所指的元素，例如在upper_bound示例中，`*p`即为 5 。  
  
<br><br>






## 