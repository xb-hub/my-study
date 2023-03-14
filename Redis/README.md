# Redis
## String
```
- 常用命令:
set/get: 设置/获取键值对
exist: 判断key是否存在
type: 查看key类型
del: 删除key
unlink: 非阻塞删除key，仅将key删除，value后续异步删除
expire: 设置key过期时间
ttl: 查看key过期时间，-1表示永久不过期，-2表示已过期
select: 切换数据库
dbsize: 查看当前数据库key数量
flushdb: 清空当前数据库
flushall: 清空所有数据库
strlen: 获得value长度
setnx: 只有key不存在才会设置value
incr/incrby: 数字增加，原子操作
decr/decrby: 数字减少，原子操作
mset/mget/msetnx: 同时设置/获取多个key，原子性，一个失败全部失败
setrange/getrange: 设置/获取范围内值
setex: 设置key同时设置过期时间 
getset: 取值后设置新值
```

## List(双向链表，单键多值)
```
lpush/rpush: 从左边/右边插入一个或多个值
lpop/rpop: 从左边/右边取出一个值
rpoplpush: 从key1右边取出值放到key2左边
lrrange: 按照索引下标获得键值对
```

## Set(自动去重，无序，哈希表)
```
sadd
smembers: 取出集合所有值
sismemebr: 判断集合key是否有该value
scard: 返回集合元素个数
srem: 删除集合某个元素
spop: 随机取出一个值
srandmmember: 随即取出n个值，不会删除
smove: 把集合中一个值从一个集合移动到另一个集合
sinter/sunion/sdiff: 返回集合交集/并集/差集
```

## Hash(键值对集合，value(field, value)
```
hset/hget:
```

## Zset(有序集合，不重复)
```
zadd:
```
### 跳表

