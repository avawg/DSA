
#### 阿里 3.18
  cbu:
  介绍一下servlet
  get 和 post 区别
  分页但后面查询很慢怎么解决

  数据库索引
  聚集索引和非聚集索引
  数据库表数据量很大怎么办，解决
  数据库锁
  mvcc
  多个线程修改数据不加锁怎么处理

  关系型数据库和非关系型数据库的使用场景

  redis为什么快
  redis同步机制
  redis分布式锁做数据同步

  session 和cookie

  jvm
  jvm内存模型
  垃圾回收
  真实环境 jvm out of memory 怎么排除，使用什么工具？

  两个线程交替执行怎么做，有什么方案
  juc锁
  syncronized 和lock 区别
  aqs
  不加锁怎么处理
  cas
  cas aba 问题怎么处理，解决还是不解决


  项目到真实场景怎么做？有思考吗？gap？
  cdn 负载均衡有了解？

  分布式怎么保证主键自增，设计方案
  分奇偶？

  钉钉：

  设计模式 观察者模式
  java 锁实现同步
  mysql高并发
  项目
  第k大元素
  bfs搜索


#### 美团 3.23
  一面：
    hashmap 实现和扩容机制
    hashmap是线程安全的吗
    hashmap有哪些线程安全问题

    线程池参数 处理策略
    threadlocal 原理和使用
    thread pool 大小怎么确定
    volatile
    java锁
    可重入锁和不可重入锁

    java四种引用 怎么淘汰
    java 内存模型
    jvm参数设置
    分代垃圾回收

    直接内存

    数据库：
      b+树 叶子节点有序
      脏读和幻读
      primary  key
      innodb 一定要有primary key吗
      怎么判断有没有走索引
      聚簇索引
      覆盖索引
      最左前缀匹配

   redis高并发
   缓存雪崩 原因
   预热
   更新策略和淘汰机制

   kafka 消息队列是做什么的，解耦合

   了解哪些常见的设计模式

   tcp udp协议栈
   tcp udp区别
   tcp 粘包 拆包 字节 报文
   https握手过程
   单向确认 双向确认

   netty 了解吗
   io多路复用
   写过socket编程

   进程和线程区别 协程
   epoll

二面：
  并发

  索引
  事务并发
  mvcc
  数据结构不走索引
  threadlocal

  redis过期键淘汰策略
  四种引用

  http cookie session
  https
  get

  注解
  spring

  串口
  最具挑战的项目
  怎么学习
  优点 缺点
  缺点怎么改
  证明学习能力
  大学最有用的一门课


### 远景
   https
   udp工作在第几层
   tcp最大连接数
   客户端网线断了，能感知到吗

   虚拟地址和逻辑地址

   最小堆
   链表倒排 递归
   第k个数的时间复杂度 快排
   红黑树

   https 2.0
   linux统计操作行数
   防止sql注入


#### 华为技术一面

  算法题：打印螺旋三角形

  数据结构：
    快速排序 堆排序 二叉查找树
  操作系统：
   进程和线程
   银行家算法
  计算机网络：
     osi七层协议名称
     tcp流量控制
  数据库三范式
  jvm 工具

#### 携程 订单模块组

  Redis指令
  **rabbitmq 消息错误处理，是否按顺序 自己程序处理**
  Mysql
  ThreadLocal ？ 线程池

  冒泡排序
  B树
  二分查找 递归实现
  二分插入排序

携程二面
  支付模块支付失败怎么处理
  客户端怎么设置秒杀按钮，提高并发量准时开启
  单台redis撑不住怎么处理

  servlet 生命周期
  怎么判断用户有没有登录，登录原理，第二次不需要登录，字段
  servlet是单例的吗

  java HashMap什么时候扩容，扩容原理
  HashMap是线程安全的吗
  ArrayList和LinkedList区别，分别适用于什么场景
  Java 线程池工作流程
  应急线程是怎么销毁的，自己销毁？

  一直发生full gc什么原因

  innodb 默认隔离级别，解决了什么问题
  没解决什么问题，间隙锁是怎么上锁的

  mysql主从复制原理，是怎么保证可靠性的
  mysql主从事务，是数据同步才成功吗

  redis常用数据类型，分布式锁

  spring boot和spring区别，spring boot是怎么注入jar包的
  maven -snapshot版本是做什么的

  4*4矩阵移动方格，最小移动次数
  快排和归并排序时间复杂度，稳定否
  稳定排序适用于什么场景

   查阅什么网站解决问题

   hr面
      中间一年空档期，脱产
      第一年考研
      为什么转行计算机
      自己的优势缺点
      offer
      实习时间
      对携程的看法

字节一面

项目
redis存哪些数据，怎么预减库存，decr / get and set
返回给用户的状态是什么
怎么保持redis和数据库数据一致性
问题，保持数据一致性，缓存键失效怎么处理

redis key eviction
LRU实现
持久化，copy on write

mysql 索引
联合索引查询过程
a > 50 and b > 50怎么走索引

四种事务隔离级别
mysql默认隔离级别
Repeated Read怎么实现的
生成readView的时机，开启事务时还是第一次快照读
select where a > 100 for update
100 怎么加锁的，加锁范围，最接近100的数据是50
间隙锁会阻塞吗
select where a > 50 for update;
select where a > 50 for update;
第二次会阻塞吗

算法题： 爬楼梯 输出所有的方案路径


顺丰一面

请求限流
redis减库存
怎么保证数据一致性
Redis数据丢失怎么处理的 key

Java面向对象
程序中有使用多态

Java异常
运行时异常有哪些
有哪些地方使用异常

threadlocal
threadlocalmap是线程私有的吗
有使用多线程吗

数据库查询比较慢的情况
数据库事务有用吗
怎么回滚的？

hr 面

为什么考研，为什么转到计算机专业，天赋点在哪
有加入社团吗
从什么开始确立方向的
个人有点
业余爱好
有为工作做过哪些准备
实习个人优势
身边的人是怎么评价你的
意见冲突，怎么解决的
研究生成绩怎么样

select 和epoll各适用什么场景


拼多多一面

项目

**mq重复消费消息**
redis缓存更新策略
先更新数据库，后更新缓存有什么问题
redis分布式锁

了解的其他数据库 neo4j，mongodb
数据库线程池

线程池问题
threadlocal问题

spring代理的两种模式 java jdk 和 cglib
springboot ioc
aop 面向切面好处

微服务
rpc远程调用 dubbo

网络流量控制

linux cpu满负荷，怎么查看

遇到的最大挫折

leetcode 最大的三个数成绩

拼多多二面：
   算法题：判断一个数是否对称
                 链表反转 m 到 n之间的部分 一次遍历
                 数组元素下一个比自己大的元素
 tcp拥塞控制
 Java IO 模型
 io多路复用怎么实现
 epoll为什么高效
epoll二种类型，触发方式

**客户端轮询，出现异常，一直轮询不到消息怎么处理？返回失败信息？**
将秒杀成功信息写入redis中，引入新的一致性问题
库存是怎么加载的，服务启动时，怎么修改库存，添加秒杀商品？创建接口？
处理热点商品数据
redis撑不住了怎么处理，并发量是10万，前端限流到10万？
Redis集群
消息丢失，消息的重复消费怎么处理

Mysql支持的引擎, Inodb MyISAM ,还有别的吗
innodb的特性好在哪
事务隔离级别，分别解决了哪些问题

购物车是怎么实现的，session
数据库连接池的原理


redis支持的数据类型
可以作消息队列
为什么用rabbitmq（重量级） 不用redis作消息队列，重量级，好在哪


 磁盘拥塞，怎么查看
 merge 和 rebase 区别


业务主管面：
算法题：
   二叉排序树找第N大的节点， O(1)时间复杂度
   用一个固定大小的数组，设置队列，在多线程环境下使用

  浏览器输入url到显示数据，经历的过程
  说一下登录的原理，如何将登录功能实现地更好




 得物一面

怎么学习Java的，如何系统学习的
servlet和spring 的区别，servlet和controller路由跳转的区别

为什么数据库支持并发小
redis为什么快，支持这么大的qps
为什么用单线程
项目redis可能会挂掉，怎么处理，集群的实现方案

java怎么实现一个线程
jvm是怎么创建线程，cpu调度
怎么判断线程的状态，jps
java怎么创建线程池，corepoolSize，线程池的原理
4核8GB主机，进行网络爬虫，怎么确定线程数量，cpu运算时间是什么，怎么判断估计，百分比
java 有哪些线程安全的类，
可重入锁是怎么实现可重入，多个线程争抢可重入锁，计数器变化
ArryaList, HashMap为什么线程不安全，怎么让其线程安全
concurrentHashMap怎么实现线程安全的
HashMap的底层实现原理，什么时候树化，为什么树化阈值是8

mysql实现一个 分页查询，按价格区间查询，多个条件可以任意拼接，mybatis怎么实现，自己实现
mybatis 实现sql查询的两种方法，mapper和注解，用过的常见的标签
mysql查询慢怎么处理，加索引，哪些字段加索引
索引哪些情况下可能会失效，怎么判断有没有走索引
索引的底层原理，为什么快

得物二面
   Redis Hashes是怎么实现的
    一致性哈希
    跨域
   tcp udp
  最长回文子串


微众银行

app 后台
**rabbitmq消费问题 消费消息 消息顺序，消息的重复处理**
数据不一致

mysql事务隔离级别
在指定的文本中查找一个字符



实习
实习收获

已有系统开发，增加一些功能，web管理后台，app端员工使用，提供接口
强化学习，后台配置学习课程，不同的岗位配置 学习课程内容、时间，关联权限(转集体，锁巴枪)等
        记录员工学习情况，推送展示
        师带徒 看板展示，徒弟看板、员工看板
并发
app版本变更，做兼容
所做的事

素数对数
java 线程池，有没有使用过
java注解
三次握手过程，怎么编程，多个线程处理
排序
设计模式 adapter 桥接模式
实习算法考试第一题
pAAs IS


访问修饰符
java bean get set
面向对象 多态

进程 线程
数据库很大时查询，加索引，缓存
-xms -xmx
-UseParaellGC

实习遇到的困难怎么解决
协作 沟通问题
承担职责之外的事情，为什么这么做
未来3-5年的规划
华为文化，对做奋斗者的理解
工作的考量标准
有没有Offer


携程

开发流程为什么是这样

dubbo 服务发现
zk怎么发现宕机的服务器

rpc 和http的差别，rpc应用层用的是什么协议
spring ioc 用了怎么模式，作用，怎么管理对象的生命周期的，为什么有控制反转
spring容器加载完后， 执行某个方法
aop动态代理 jdk 和 cglib的差别
pointcut 作用，放在那里 类 或 方法

sybcnronized 和lock的区别，偏向锁，
公共锁和非公平锁是怎么实现的

actomic Integer
HashMap ConcurrentHashMap
jvm 哪些作为gc roots

redis 缓存穿透和缓存雪崩怎么处理

mysql 事务怎么实现的
主键索引和二级索引的区别
慢查询日志怎么优化

kafka 怎么保证消息不丢失，怎么保证消息有序消费

java nio 和bio的区别，当线程很多的nio影响什么参数，会有什么问题

最大最小的k个数，字符串匹配

图论算法
实习
maven
inner join, left join, right join, full join
redis 怎么解决缓存击穿
java 内存模型
io 解决什么问题





美团

遇到的问题
团队中沟通问题

websocket 长连接
spring定时任务
怎么保证并发时，对浏览量点赞量的更改正确，数据库行级锁，还有什么

死锁
浏览器输入网址过程

链表找环的入口
sql查询


50s到8s怎么优化
优化
servlet 和spring 的原理，是怎么传递的
怎么打日志
websocket 怎么给指定的用户发消息 怎么判断连接，。
1000万个用户，存不下怎么办
分片，一致性哈希算法
进程和线程
设计模式，源码
异步和 io多路复用差别

远景
tps + qps 100, 每个查询50ms，连接池设置多少？
kafka是怎么清理offset字段
redis　string key value 是怎么存储的，为什么不用hashmap
扩容 存储额外时间
lru 和 lfu的使用场景
技术增长方式，学习

生产问题，慢查询

网易
io模型 用户态到内核态
jvm 方法区和元空间区别
工作目标，什么样的工作


招银
jvm 内存结构，垃圾回收区域
偏向锁，轻量级锁，重量级锁
重载重写 继承
bean的生命周期
数据库索引
b树b+树区别
排序算法

dubbo 微服务框架的优势
dubbo 怎么保证分布式事务
复合索引怎么建立，查询频率差不多的情况下怎么区分，性别、年龄


阿里
hashmap结构
红黑树为什么查找效率高，hashmap扩容
hashtable concurrenthashmap
queue，入队 出队

快排
10个数里选10个最大的
两颗树，判断a是否是b的子树

synchronized
synchronized 和 lock 区别，什么时候用哪个
volatile, cpu缓存

死锁
threadlocal, threadlocalmap
数据库事务
b+树

参加过数据竞赛吗? 奖学金，校级

二面：
分层网络协议
数据链路层的功能，防火墙工作再哪一层
应用层有哪些协议
https, rsa 是对称还是非对称的，双方都有密钥

面向对象三大特征，多态怎么实现的
方法重载和重写

泛型，哪里有用到
泛型方法 泛型擦除

java 序列化怎么实现
序列化排除某个字段，怎么做 transient 还有其它字段吗
静态变量会序列化吗

快排为什么是不稳定的
多路归并，时间复杂度和空间复杂度
判断字段串s是否是字符串t的子串，除了暴力，kmp还有什么

jvm 内存结构
什么情况下为内存溢出
年轻代一直回收，怎么调整

cap理论
redis集群是cp还是ap，为什么
主管面
锁
设计读写锁
自己的编程能力、代码能力怎么样
怎么评价自己的性格
遇到挫折怎么缓解
实习谁对你帮助最大，导师的反馈
为什么继续找别的公司，对公司更看重什么





代理模式和观察者模式区别
实习中职责

索引
b+树具体的记录数
mysql 怎么保证事务的
mysql query 和update 语句执行的过程

网站上输入网址到内容显示的过程

字符串去重，字符串压缩
quick_sort

装饰器模式、单例 python书写

观察者模式
aop
java反射
c 申请释放内存
c 的内存结构
python gc 垃圾回收
python 是一门面向对象的语言吗
python 可变对象与不可变对象



