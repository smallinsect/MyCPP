# MyCPP

//C语言库函数查询学习网址  
https://www.runoob.com/cprogramming/c-tutorial.html  

输出目录  
$(SolutionDir)..\bin\$(Platform)\$(Configuration)\
中间目录  
$(SolutionDir)..\bintemp\$(Platform)\$(ProjectName)\$(Configuration)\

# MFC

在线文档

- https://docs.microsoft.com/en-us/cpp/mfc/reference/cbitmap-class?view=vs-2019
- https://docs.microsoft.com/zh-cn/cpp/mfc/mfc-desktop-applications?view=msvc-160

# 同步和异步

- 同步：同步是指一个进程在执行某个请求的时候，如果该请求需要一段时间才能返回信息，那么这个进程会一直等待下去，直到收到返回信息才继续执行下去。

- 异步：异步是指进程不需要一直等待下去，而是继续执行下面的操作，不管其他进程的状态，当有信息返回的时候会通知进程进行处理，这样就可以提高执行的效率了，即异步是我们发出的一个请求，该请求会在后台自动发出并获取数据，然后对数据进行处理，在此过程中，我们可以继续做其他操作，不管它怎么发出请求，不关心它怎么处理数据。

简单的说

- 同步：吃完饭，才能去拉屎。
- 异步：边吃饭，边拉屎。

# CAsyncSocket和CSocket是同步套接字

- CAsyncSocket：是异步套接字

- CSocket：是同步套接字

# GDI+

#include "gdiplus.h"
#pragma comment( lib, "gdiplus.lib" )
using namespace Gdiplus;