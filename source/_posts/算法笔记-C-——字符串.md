---
title: 算法笔记(C++) ——字符串
date: 2025-08-15 16:51:38
tags:
---


## __常用的string成员函数__
```c++
//构造函数
string s1;                // 默认构造，创建一个空字符串
string s2("Hello, C++!"); // 用常量字符串构造
string s3(s2);            // 用另一个字符串构造（拷贝构造）
string s4(10, 'a');       // 创建一个长度为 10 的字符串，每个字符为 'a'

//赋值操作
string s1 = "Hello";
s1 = "World";  // 赋新值，原有的内容会被释放并替换

//字符串拼接（连接）
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2;  // 拼接两个字符串
s1.append(" C++");               // 使用 append() 进行拼接

//获取长度
string s = "Hello";
size_t length = s.length();   // 获取字符串的长度
size_t size = s.size();       // 等价于 length()

//字符访问
string s = "Hello";
char c = s[1];    // 访问字符串中索引为 1 的字符，结果是 'e'
char c2 = s.at(1); // 等价于 s[1]，但如果索引越界，会抛出异常

//查找字符或子字符串
string s = "Hello, C++!";
size_t pos = s.find("C++");  // 返回第一次出现 "C++" 的位置，如果没找到返回string::npos
if (pos != string::npos) {
    cout << "Found at position " << pos << endl;
}

//替换字符或子字符串
string s = "Hello, World!";
s.replace(7, 5, "C++");  // 从位置 7 开始替换 5 个字符，替换为 "C++"

//删除字符
string s = "Hello, World!";
s.erase(5, 7);  // 从位置 5 开始，删除 7 个字符

//子字符串
string s = "Hello, C++!";
string x = "my ";
string sub1 = s.substr(7, 3);  // 获取从位置 7 开始，长度为 3 的子字符串 "C++"
string sub2 = s.substr(7, 3);  // 获取从位置 7 开始往后的整个子字符串 "C++!"
string newString = s.substr(0, 7) + x + s.substr(7);  // 将字符串x插入到位置7，形成一个新的字符串"Hello, my C++!"

//比较字符串
string s1 = "Hello";
string s2 = "World";
if (s1 == s2) {
    cout << "Strings are equal." << endl;
} else {
    cout << "Strings are not equal." << endl;
}
```
  
<br><br>  





## __回文串__
回文字符串是指正着读和反着读都一样的字符串。换句话说，回文字符串从左到右和从右到左的字符顺序完全相同。
```c++
// 检查字符串是否是回文示例（非函数形式）
bool is_palindrome = true; //先假定其是回文串
        
for (int j = 0; j < c.length() / 2; j++) {
    // 对称位置字符不相等，不是回文
    if (c[j] != c[c.length() - 1 - j]) {
        is_palindrome = false; 
        break;  //不执行则is_palindrome 仍为 true
    }
}
```
```c++
// 检查字符串是否是回文示例（函数形式）
bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1; //双指针
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // 如果不相等，返回 false
        }
        left++;
        right--;
    }
    return true; // 全部字符都匹配，返回 true
}
```