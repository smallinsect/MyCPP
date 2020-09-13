# MyServer

vs环境配置

```
输出目录
$(SolutionDir)../bin/$(Platform)/$(Configuration)/
中间目录
$(SolutionDir)../bintemp/$(Platform)/$(ProjectName)/$(Configuration)/
```

# Select模型

```
int select(
	int maxfd,//需要监视的最大的文件描述赋值+1
	fd_set *rdset,//要检测的可读文件描述符的集合
	fd_set *wrset,//可写文件描述符的集合
	fd_set *exset,//异常文件描述符的集合
	struct timeval *timeout//超时时间
);

fd_set//集合，是一个数组
void FD_ZERO(fd_set *fdset);//清空fdset
void FD_CLR(int fd, fd_set *fdset);//将一个fd从fd_set中移除
void FD_SET(int fd, fd_set *fdset);//将一个fd加入fd_set中
int FD_ISSET(int fd, fd_set *fdset);//判断指定位是否设置，已经设置返回非零，否则返回0
```













