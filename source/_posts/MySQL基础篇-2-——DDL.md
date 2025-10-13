---
title: MySQL基础篇(2)——DDL
date: 2025-10-14 04:21:51
tags:
---


DDL（Data Definition Language，数据定义语言）主要用于定义和管理数据库、表、视图、索引等数据库对象的结构。常用的 DDL 语句包括 CREATE（创建）、ALTER（修改）、DROP（删除）、RENAME（重命名）等。

## DDL-数据库操作
```
#查询所有数据库
SHOW DATABASES;

#查询当前数据库
SELECT DATABASE();

#创建数据库
CREATE DATABASE 数据库名;
或
CREATE DATABASE [IF NOT EXITS] 数据库名 [DEFAULT CHARSET 字符集][COLLATE排序规则];

#删除数据库
DROP DATABASE 数据库名;
或
DROP DATABASE [IF EXITS] 数据库名;

#使用/进入数据库
USE 数据库名;
```


## DDL-表操作
```

```