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


## DDL-表操作-查询
```
#查询当前数据库所有表
SHOW TABLES;

#查询表结构
DESC 表明;

#查询指定表的建表语句
SHOW CREATE TABLE 表名;
```


## DDL-表操作-创建
```
CREATE TABLE 表名(
    字段1 字段1类型[COMMENT 字段1注释],
    字段2 字段2类型[COMMENT 字段1注释],
    字段3 字段3类型[COMMENT 字段1注释],
    ···
    字段n 字段n类型[COMMENT 字段1注释]
)[COMMENT 表注释];
```


## DDL-表操作-数据类型
数值类型：
![ ](/images/MySQL_2_1.png)

字符串类型：
![ ](/images/MySQL_2_2.png)

日期时间类型：
![ ](/images/MySQL_2_3.png)

__示例：__
设计一张员工信息表，要求如下：  
1. 编号（纯数字）
2. 员工工号（字符串类型，长度不超过10位）
3. 员工姓名（字符串类型，长度不超过10位）
4. 性别（男/女）
5. 年龄（非负数）
6. 身份证号（定长字符串18位）
7.  入职时间（取值年月日即可）
```
create table emp(
    id int comment '编号',
    workno varchar(10) comment '工号',
    name varchar(10) comment '姓名',
    gender char(1) comment '性别',
    age tinyint unsigned comment '年龄'，
    idcard char(18) comment '身份找号',
    entrydate date comment '入职时间'
) comment '员工表';
```


## DDL-表操作-修改
```
#添加字段
ALTER TABLE 表名 ADD 字段名 类型(长度) [COMMENT 注释] [约束];

#修改数据类型
ALTER TABLE 表名 MODIFY 字段名 新数据类型(长度);

#修改字段名和字段类型
ALTER TABLE 表名 CHANGE 旧字段名 新字段名 类型(长度) [COMMENT 注释] [约束];

#删除字段
ALTER TABLE 表名 DROP 字段名;

#修改表名
ALTER TABLE 表名 RENAME TO 新表名;

#删除表
DROP TABLE [IF EXISTS] 表名;

#删除指定表，并重新创建该表
TRUNCATE TABLE 表名;
```
