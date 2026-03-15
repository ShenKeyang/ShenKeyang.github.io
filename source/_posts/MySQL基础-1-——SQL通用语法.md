---
title: MySQL基础(1)——SQL通用语法
date: 2025-10-13 23:55:46
tags:
---


## MySQL的基本操作
在CMD终端输入以下指令（确保在win+R>services.msc中启动了MySQL），接着输入密码，即可启动数据库。
```
mysql -u root -p
```

输入`quit`指令即可退出数据库。

## SQL的通用语法
1. SQL语句可以单行或多行书写，以分号结尾；
2. SQL语句可以使用空格/缩进来增强语句的可读性；
3. MySQL数据库的SQL语句不区分大小写，关键字建议使用大写；
4. 注释：
    - 单行注释：--注释内容 或 #注释内容
    - 多行注释：/\*注释内容\*/


## SQL语句的分类
1. DDL：Data Definition Language，数据定义语言，用来定义数据库对象；
2. DML：Data Manipulation Language，数据操作语言，用来对数据库表的数据进行增删改；
3. DQL：Data Definition Language，数据查询语言，用来查询数据库中表的记录；
4. DCL：Data Definition Language，数据控制语言，用来创建数据库用户、控制数据库的访问权限；