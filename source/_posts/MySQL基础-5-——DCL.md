---
title: MySQL基础(5)——DCL
date: 2026-03-15 20:45:15
tags:
---


DCL（Data Control Language，数据控制语言），用来管理数据库用户、控制数据库的访问权限。

## DCL-管理用户
```
#查询用户
USE mysql;
SELECT * FROM user; #直接访问系统数据库中的user表

#创建用户
CREATE USER '用户名'@'主机名' IDENTIFIED '密码';

#修改用户密码
ALTER USER '用户名'@'主机名' IDENTIFIED WITH mysql_native_password BY '新密码';

#删除用户
DROP USER '用户名'@'主机名';
```


## DCL-权限控制
MySQL中的常用权限：
```
ALL,ALL PRIVILEGES  #所有权限
SELECT              #查询数据
INSERT              #插入数据
UPDATE              #修改数据
DELETE              #删除数据
ALTER               #修改表
DROP                #删除数据库/表/视图
CREATE              #创建数据库/表
```

权限控制语句：
```
#查看权限
SHOW GRANTS FOR '用户名'@'主机名';

#授予权限
GRANTS 权限列表 ON 数据库名 表名 TO '用户名'@'主机名';

#撤销权限
REVOKE 权限列表 ON 数据库名 表名 FROM '用户名'@'主机名';
```