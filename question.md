
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
  rabbitmq 消息错误处理，是否按顺序 自己程序处理
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

mq重复消费消息
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

客户端轮询，出现异常，一直轮询不到消息怎么处理？返回失败信息？
将秒杀成功信息写入redis中，引入新的一致性问题
库存是怎么加载的，服务启动时，怎么修改库存，添加秒杀商品？创建接口？
处理热点商品数据
redis撑不住了怎么处理，并发量是10万，前端限流到10万？
Redis集群

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
rabbitmq消费问题 消费消息 消息顺序，消息的重复处理
数据不一致

mysql事务隔离级别
在指定的文本中查找一个字符