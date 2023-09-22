## 命令汇总
|命令|作用|
|---|---|
|catch signal [name/num]|通过名称和编号来捕获信号|
|catch syscall [name/num]|通过名称、分组或编号来捕捉系统调用|
|catch load/unload|捕捉共享库的加载/卸载 |
|catch fork/vfork| 捕捉fork/vfork的调用 |
|catch throw|捕获thrown的异常|
|catch exception|捕捉异常|
|catch exec|捕捉exec的调用 |

## 捕获fork事件`catch fork`

```
(gdb) catch fork 
Catchpoint 1 (fork)
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test_multi_process 

Catchpoint 1 (forked process 187697), 0x00007ffff7e98f3f in fork () from /lib/x86_64-linux-gnu/libc.so.6
(gdb) bt
#0  0x00007ffff7e98f3f in fork () from /lib/x86_64-linux-gnu/libc.so.6
#1  0x00005555555551fb in main () at test_multi_process.c:12
(gdb)
```

## 捕获信号`catch signal`

> `catch signal`默认捕获所有信号，还可以指定信号名称或编号。

```
(gdb) catch signal 
Catchpoint 1 (standard signals)
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test_multi_process 
[Detaching after fork from child process 187845]

Catchpoint 1 (signal SIGCHLD), 0x00007ffff7e98c3a in wait4 () from /lib/x86_64-linux-gnu/libc.so.6
(gdb)
```

> `catch signal num`指定捕获编号为num的信号。

```
(gdb) catch signal 6
Catchpoint 1 (signal SIGABRT)
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test_coredump 

Catchpoint 1 (signal SIGABRT), 0x00007ffff7df900b in raise () from /lib/x86_64-linux-gnu/libc.so.6
(gdb)
```

## 捕获系统调用`catch syscall`

> `catch syscall`：默认捕获所有系统调用

```
(gdb) catch syscall 
Catchpoint 1 (any syscall)
(gdb) r
Starting program: /home/lhx/paopao-notes/code/hello 

Catchpoint 1 (call to syscall brk), 0x00007ffff7fecf4b in ?? () from /lib64/ld-linux-x86-64.so.2
(gdb) 
```

> `catch syscall name`：指定捕获名称为name的系统调用

```
(gdb) cat syscall mmap
Catchpoint 1 (syscall 'mmap' [9])
(gdb) r
Starting program: /home/lhx/paopao-notes/code/hello 

Catchpoint 1 (call to syscall mmap), 0x00007ffff7fee186 in ?? () from /lib64/ld-linux-x86-64.so.2
(gdb) 
```

> `catch syscall num`：指定捕获编号为num的系统调用

```
(gdb) catch syscall 9
Catchpoint 1 (syscall 'mmap' [9])
(gdb) r
Starting program: /home/lhx/paopao-notes/code/hello 

Catchpoint 1 (call to syscall mmap), 0x00007ffff7fee186 in ?? () from /lib64/ld-linux-x86-64.so.2
(gdb)
```

## 捕获共享库`catch load/unload`

> `catch load`：捕获共享库的加载

```
(gdb) catch load 
Catchpoint 1 (load)
(gdb) r
Starting program: /home/lhx/paopao-notes/code/hello 

Catchpoint 1
  Inferior loaded /lib/x86_64-linux-gnu/libc.so.6
0x00007ffff7fd37b5 in ?? () from /lib64/ld-linux-x86-64.so.2
(gdb)
```


## 调试截图演示

![image-20221223221221048](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212232212575.png)



