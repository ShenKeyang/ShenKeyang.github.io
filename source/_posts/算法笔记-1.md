---
title: 算法笔记(C++)——IO
date: 2025-08-14 22:18:35
comments: true
tags:
description: 一些关于C++算法中输入和输出的语法笔记，以便于查阅
---




## C++万能头文件
```c++
#include <bits/stdc++.h>
```
#### 它包含（但不限于）：  
1. 基础头文件：   
`<iostream`：输入输出流，包含cin、cout等 I/O 操作  
`<cstdio>`：C 风格输入输出，包含printf、scanf等函数  
`<cmath>`：数学函数库，包含sin、cos、sqrt等数学运算     

2. 容器与数据结构:  
`<vector>`：动态数组容器  
`<string>`：字符串类及相关操作  
`<map>/<unordered_map>`：映射容器（键值对）  
`<set>/<unordered_set>`：集合容器  
`<list>`：双向链表容器  
`<queue>`：队列容器  
`<stack>`：栈容器  
`<array>`：固定大小数组（C++11）   

3. 算法:  
`<algorithm>`：标准算法库，包含排序、查找等算法（如sort、find）     

<br><br>  





## C++的命名空间
在C++中，`using namespace std;`是一个用于简化代码的语句，它的作用是告诉编译器你希望使用标准库中的名称而不需要加上 `std::`前缀。  

<br><br>






## 输入输出格式化
C++ 提供了多种方式来控制输入输出的格式，常用的包括 `std::setw`、`std::setprecision`、`std::fixed`等。
```c++
#include <iostream>
#include <iomanip>  // 提供格式化工具

int main() {
    double pi = 3.14159265358979;
    
    std::cout << "原始值: " << pi << std::endl;

    // 设置输出精度为 2 位小数
    std::cout << "保留两位小数: " << std::fixed << std::setprecision(2) << pi << std::endl;
    return 0;
}
```
`std::setw(width)`用于设置输出的宽度。  
`std::setprecision(n)`设置浮点数的精度。  
`std::fixed`控制浮点数按照固定格式输出。   

<br><br>  






## long long
相比于`int`（通常为 4 字节，32位），`long long`拥有更大的存储范围（通常占用 8 字节,64 位整数类型，它的取值范围是：从 -2^63 到 2^63 - 1，即约 -9.2 × 10^18 到 9.2 × 10^18），适用于需要存储大整数的场合。如果你需要处理的整数值超过了`int`的最大值（大约 21 亿, 约为2 × 10^9），那么`long long`就是更合适的选择。  

<br><br>





## ACM模式下的评测反馈
`AC（Accepted，接受）`：
表示提交的程序正确，输出符合要求，并且在规定的时间和内存限制内运行完成。AC是最理想的反馈，说明选手的代码通过了所有的测试用例。  

`WA（Wrong Answer，错误答案）`：
这表示程序的输出与期望的结果不符。选手需要检查程序中的逻辑错误，特别是输入输出的处理部分，确保符合题目要求。 

`TLE（Time Limit Exceeded，超时）`：
如果程序运行时间超过了题目规定的时间限制，就会出现TLE错误。通常是算法效率的问题，选手需要优化算法，减少计算时间。 

`MLE（Memory Limit Exceeded，超出内存限制）`：
如果程序的内存使用量超过了题目要求的限制，系统会返回MLE反馈。通常是因为程序使用了过多的内存，可能是由于存储过多数据或不必要的数据结构。  

`RE（Runtime Error，运行时错误）`：
如果程序在运行过程中发生了错误（如除以零、访问非法内存等），则会返回RE错误。选手需要检查代码中的边界情况、异常处理等。  

`PE（Presentation Error，输出格式错误）`：
这个反馈表示程序的输出没有按照题目要求的格式输出。比如输出的数字顺序不对，或者多了不必要的空格或换行符。  
  
`CE（Compilation Error，编译错误）`：
如果提交的代码存在编译问题，平台会给出编译错误的反馈。选手需要检查代码是否存在语法错误或未定义的变量。  

<br><br>





## stringstream
1.创建和初始化
可以通过以下几种方式创建`std::stringstream`对象：

- 默认构造：创建一个空的 stringstream 对象。  
- 使用字符串初始化：通过构造函数将一个字符串传给 stringstream。
```c++
#include <iostream>
#include <sstream>
int main() {
    // 默认构造
    std::stringstream ss1;
    
    // 使用字符串初始化
    std::stringstream ss2("123 456");
    
    return 0;
}
```  

2.输出操作
使用 << 运算符，可以将数据写入到 stringstream 中，数据将会被存储为一个字符串。
```c++
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;
    
    int x = 10;
    double y = 3.14;
    
    // 向stringstream中写入数据
    ss << "Integer: " << x << ", Double: " << y;
    
    std::cout << ss.str() << std::endl;  // 输出字符串
    return 0;
}
```
在上述代码中，ss.str() 返回的是字符串流中存储的字符串。  

3.输入操作
使用 >> 运算符，从 stringstream 中读取数据。
```c++
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("100 200 3.14");

    int a, b;
    double c;
    
    // 从stringstream中读取数据
    ss >> a >> b >> c;
    
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    return 0;
}
```
在这个例子中，stringstream 中的字符串被解析并提取成不同的变量。

4.清空 stringstream
如果想清空 stringstream 中的数据，可以使用 str("") 方法，将流的内容设置为空字符串，或者使用 clear() 来重置流的状态。
```c++
#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;
    ss << "Hello, world!";
    
    std::cout << ss.str() << std::endl;  // 输出 "Hello, world!"
    
    ss.str("");  // 清空内容
    std::cout << ss.str() << std::endl;  // 输出空字符串
    
    return 0;
}
```  

<br><br>






## 多组不定组输入
在 C++ 中，处理多行不定数量的输入数据是一个常见的需求，特别是在面对不确定数据量的情况下。可以使用一些方法来读取不定行数的数据。下面是几种常见的方式：

1.`getline`函数介绍  
`getline`函数是 C++ 中用于从输入流中读取一行文本的函数，通常用于读取用户输入或文件中的一行数据。它的基本用法是：
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;  // 用来存储输入的文本

    // 提示用户输入一行文本
    cout << "请输入一行文本: ";

    // 使用 getline 从标准输入中读取一整行
    getline(cin, line);  

    // 输出用户输入的内容
    cout << "你输入的内容是: " << line << endl;

    return 0;
}
```
`getline`会读取一整行数据，直到遇到换行符（\n）为止。它不会将换行符包含在返回的字符串中。  

上面的代码举一个例子:
```bash
请输入一行文本: 你好，世界！
你输入的内容是: 你好，世界！
```  
  
2.使用`cin`和循环
你可以使用`cin`来逐行读取输入数据，然后根据特定条件判断是否继续读取。例如，当输入数据结束时（通常是遇到文件结束符 EOF 或空行），停止读取。
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        // 处理每一行输入的内容
        cout << "输入的行是: " << line << endl;
    }
    return 0;
}
```
在这个例子中，`getline(cin, line)`会读取每一行输入数据，直到输入结束（通常通过文件结束符 EOF ： Ctrl + Z 或 Ctrl + D 来结束）。读取的每一行会存储在 line 变量中，之后你可以对该行数据进行处理。  

<br><br>





## 动态数组容器vector
相较于一般数组，`vector`可以定义动态数组向量，参数可以用变量来设置，更为灵活。用法如下：  
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;      //定义一个整型变量
    cin >> n;   //输入给变量赋值
    vector<int> arr(n); //定义一个元素种类为int的vector向量
    ...
    return 0;
}
```
用`vector`定义二维数组（矩阵）的用法如下：
```c++
#include <iostream>
#include <vector>
using namespace std;
      
int main()
{
    int n,m;
    cin >> n >> m ;
    vector<vector<int> > matrix(n,vector(m)); //vector嵌套vector形成一个二维矩阵
    ...
    return 0;
}
```
若上述实现全部使用传统的静态数组，则无法使用变量作为开辟数组的大小，需要定义静态的、超额大小的数组，如：`int arr[1000][1000] = {0}`，或先在函数外宏定义`#define SIZE 1000`再定义静态数组`int arr[SIZE][SIZE] = {0}`。