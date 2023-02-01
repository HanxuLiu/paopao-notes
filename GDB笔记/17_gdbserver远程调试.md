## 命令汇总
|命令|作用|
|---|---|
|gdbserver IP地址:端口 可执行文件|目标机对可执行文件进行远程调试|
|target remote IP地址:端口|调试机连接目标机后进行远程调试|
|gdbserver IP地址:端口 --attach 进程pid|远程调试正在运行的进程|


## 远程调试可执行文件

### 目标机（远程机）

目标机（远程机）运行gdbserver，启动调试的命令格式为：`gdbserver IP地址:端口 可执行文件`，随后开始监听端口。

```
gdbserver 192.168.174.128:1234 ./bubble_sort
Process ./bubble_sort created; pid = 4305
Listening on port 1234
```

### 调试机（本地机）

调试机（本地机）运行gdb，通过`target remote IP地址:端口`，连接目标机，开始远程调试：

```
lhx@ubuntu:~$ gdb
(gdb) target remote 192.168.174.128:1234
Remote debugging using 192.168.174.128:1234
```

### 调试截图

![微信截图_20230117160922](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301171624722.png)

然后在调试机输入continue、step、next、finish等命令进行调试，注意远程调试场景下，不支持run命令，因为调试程序本来就是运行状态。

![微信截图_20230117161238](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301171645162.png)


## 远程调试正在运行的进程

### 目标机（远程机）

目标机上先运行程序，这里用一个死循环测试用例：

```
/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-17
*  Description: 
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void loop(int flag)
{
  while(flag) {
    printf("loop .... (pid = %d)\n", getpid());
    sleep(3);
  }
}

int main()
{
  int flag = 1;
  loop(flag);
  return 0;
}
```

测试用例每隔3秒就会打印一遍，不会停止：

```
./loop 
loop .... (pid = 15055)
loop .... (pid = 15055)
loop .... (pid = 15055)

```

目标机运行gdbserver的命令格式为：`gdbserver IP地址:端口 --attach 进程pid`。

```
gdbserver 192.168.174.128:1234 --attach 15055
Attached; pid = 15055
Listening on port 1234
```

### 调试机（本地机）

调试机运行gdb的命令不变：

```
lhx@ubuntu:~$ gdb
(gdb) target remote 192.168.174.128:1234
Remote debugging using 192.168.174.128:1234
```

### 调试截图

![image-20230117164441987](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301171644090.png)
