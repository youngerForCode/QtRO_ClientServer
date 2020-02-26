# QtRO_ClientServer

使用QtRO模块下的LPC,实现类似于聊天对话窗口。默认双方都在是本地。


# log
- 静态replica 实现。
- 动态replica 实现。 在Server.pro和 Client.pro 分别定义宏：DYNAMIC_REPLICA。 如果定义DYNAMIC_REPLICA编译生成动态replica实现。
	
	
	
# 参考资料
- [QtRO简介](https://zhuanlan.zhihu.com/p/36501814)
- [Qt Remote Object（QtRO）实现进程间通信](https://blog.csdn.net/luoyayun361/article/details/91588654)
- [Qt Remote Object（QtRO）动态Replica实现进程间通信](https://blog.csdn.net/luoyayun361/article/details/92205562)
