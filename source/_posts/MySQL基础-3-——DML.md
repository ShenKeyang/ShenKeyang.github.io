---
title: MySQL基础(3)——DML
date: 2026-03-15 19:04:42
tags:
---


DML（Data Manipulation Language，数据库操作语言），用来对数据库中表的数据记录进行增删改操作。

## DML-添加数据
```
#给指定字段添加数据
INSERT INTO 表名(字段名1，字段名2,...)VALUES(值1,值2,...);

#给全部字段添加数据
INSERT INTO 表名 VALUES(值1,值2,...);

#批量添加数据
INSERT INTO 表名(字段名1,字段名2,...)VALUES(值1,值2,...),(值1,值2,...)(值1,值2,...),...;
INSERT INTO 表名 VALUES(值1,值2,...),(值1,值2,...)(值1,值2,...),...;
```


## DML-修改数据
```
UPDATE 表名 SET 字段名1=值1,字段名2=值2,...[WHERE 条件];
```

## DML-删除数据
```
DELETE FROM 表名 [WHERE 条件];
```