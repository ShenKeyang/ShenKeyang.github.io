---
title: MySQL基础(4)——DQL
date: 2026-03-15 20:08:38
tags:
---


DQL（Data Query Language，数据查询语言），用来查询数据库中表的记录。

## DQL-语法
```
SELECT 字段列表
    FROM 表名列表（配合聚合函数count/max/min/avg/sum）
        WHERE 条件列表
            GROUP BY 分组字段列表
                HAVING 分组后条件列表
                    ORDER BY 排序字段列表
                        LIMIT 分页参数;
```


## DQL-基本查询
```
#查询多个字段
SELECT 字段1,字段2,... FROM 表名;
SELECT * FROM 表名;

#设置别名
SELECT 字段1[AS 别名1],字段2[AS 别名2]... FROM 表名;

#去除重复记录
SELECT DISTINCT 字段列表 FROM 表名;
```


## DQL-条件查询
```
#语法
SELECT 字段列表 FROM 表名 WHERE 条件列表;

#条件
>
>=
<
<=
=
<>或!=
BETWEEN ... AND ...
IN(...)
LIKE 占位符
IS NULL
AND或&&
OR或||
NOT或!
```


## DQL-聚合函数
将一列数据作为一个整体，进行纵向计算，常见聚合函数：
```
count   #统计数量

max     #最大值

min     #最小值

avg     #平均值

sum     #求和

#语法
SELECT 聚合函数(字段列表) FROM 表名;
#注：所有的 NULL 值不参与聚合函数的运算。
```


## DQL-分组查询
```
#语法
SELECT 字段列表 FROM 表名 [WHERE 条件] GROUP BY 分组字段名 [HAVING 分组后过滤条件];
```


## DQL-排序查询
```
#语法（支持多字段排序）
SELECT 字段列表 FROM 表名 ORDER BY 字段1 排序方式1,字段 排序方式;

#排序方式
ASC     #升序
DESC    #降序
```


## DQL-分页查询
```
#语法
SELECT 字段列表 FROM 表名 LIMIT 起始索引,查询记录数;
/*注：
    1.起始索引从0开始，起始索引=(查询页码-1)*每页显示记录数；
    2.分页查询是数据库的方言，不同的数据库有不同的实现，MySQL中是LIMIT；
    3.如果查询的是第一页数据，则起始索引可以省略，直接简写为LIMIT 记录查询数；
```


## DQL-执行顺序
```
5 SELECT 字段列表
1     FROM 表名列表（配合聚合函数count/max/min/avg/sum）
2         WHERE 条件列表
3             GROUP BY 分组字段列表
4                  HAVING 分组后条件列表
6                     ORDER BY 排序字段列表
7                         LIMIT 分页参数;
```