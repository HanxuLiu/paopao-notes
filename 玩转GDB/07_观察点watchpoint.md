
## 命令汇总
|命令|含义|
|---|---|
|watch a|观察变量a|
|watch a*b+c|观察表达式a*b+c|
|watch *0x123456|观察地址0x123456|
|awatch expression|设置读写观察点|
|rwatch expression|设置只读观察点|
|watch/awatch/rwatch expression thread thread-id|为单个线程设置观察点|
|info watchpoints|查看观察点|
|delete num|删除编号num的观察点|
|disable/enable num|禁用/启用编号num的观察点|
|set can-use-hw-watchpoints num|设置硬件观察点数目，0表示禁用|
|show can-use-hw-watchpoints|查看当前架构支持的硬件观察点数目|

## watchpoint介绍

**watchpoint（观察点）：**
很多情况下，程序的bug是由于某个变量或地址被莫名修改而导致的，但是具体什么时候修改了该值，我们很难定位到。使用传统的方法只能一步一步去调试跟踪程序，伤神费力，调试效率特别低。

gdb提供了观察点watchpoint功能，可以监控程序中变量或表达式的值，只要在运行过程中发生改变，程序就会停止执行。

**观察点适用场景：**
- 由于变量值异常变化导致的bug。
- 确定了某个异常变量，但是该变量被多次使用、还会在各种循环内被操作。
- 多线程场景，线程切来切去，不知道变量具体被哪个线程修改了。

## 测试用例

`test_watchpoint.c`：

```c
  1 /*================================================================
  2 *  Author: LiuHanxu
  3 *  Date: 2022-06-11
  4 *  Description: 
  5 ================================================================*/
  6 #include <stdio.h>
  7 
  8 int main()
  9 {
 10   int a = 1, b = 2, c = 3;
 11   printf("before: a = %d, b = %d, c = %d\n", a, b, c);
 12   int* ptr = &c;
 13   for(int i=0; i<=100; i++)
 14   {
 15     if (i == 66)
 16       a = 0;
 17     if (i == 88)
 18       b = 0;
 19     if (i == 99)
 20       *ptr = 123;
 21   }
 22   printf("after: a = %d, b = %d, c = %d\n", a, b, c);
 23   return 0;
 24 }
```

## 观察变量`watch a`

给变量a设置观察点，然后继续运行，当a被修改后程序就停止运行，可以看出当循环变量i为66时，将a的值改为了0。因此，我们就很快定位到程序第16行改变了变量值，程序停到17行。

```c
(gdb) watch a
Hardware watchpoint 2: a
(gdb) c
Continuing.
before: a = 1, b = 2, c = 3

Hardware watchpoint 2: a

Old value = 1
New value = 0
main () at test_watchpoint.c:17
17	    if (i == 88) 
(gdb) 
```

## 观察表达式`watch b+2*c`

观察表达式`b+2*c`，每次当表达式的值发生变化，程序就会暂停。通过下面调试结果发现在第18行时b的值改变导致表达式变化，第20行时c的值发生改变（此处是通过指针ptr修改c的值，所以gdb会定位到第12行，能发现循环变量i的值是99）。

```c
11	  printf("before: a = %d, b = %d, c = %d\n", a, b, c);
(gdb) n
before: a = 1, b = 2, c = 3
12	  int* ptr = &c;
(gdb) n
13	  for(int i=0; i<=100; i++)
(gdb) watch b+2*c
Hardware watchpoint 2: b+2*c
(gdb) c
Continuing.

Hardware watchpoint 2: b+2*c

Old value = 8
New value = 6
main () at test_watchpoint.c:19
19	    if (i == 99)
(gdb) c
Continuing.

Hardware watchpoint 2: b+2*c

Old value = 6
New value = 246
main () at test_watchpoint.c:13
13	  for(int i=0; i<=100; i++)
(gdb)
```

## 观察地址`watch *0x7fffffffe280`
观察变量c的地址，找出哪里修改变量c的值。通过命令`watch *0x7fffffffe280`观察变量c的地址，定位到程序第12行修改了该地址，gdb显示的下一行为13行，可以看到循环变量i为99。

```c
13	  for(int i=0; i<=100; i++)
(gdb) i loc
i = 21845
a = 1
b = 2
c = 3
ptr = 0x7fffffffe280
(gdb) watch *0x7fffffffe280
Hardware watchpoint 2: *0x7fffffffe280
(gdb) c
Continuing.

Hardware watchpoint 2: *0x7fffffffe280

Old value = 3
New value = 123
main () at test_watchpoint.c:13
13	  for(int i=0; i<=100; i++)
(gdb) 
```

## 只读观察点`rwatch a`

对变量a设置只读观察点后，printf打印时会读取变量a的值，于是触发了只读观察点。

```c
11	  printf("before: a = %d, b = %d, c = %d\n", a, b, c);
(gdb) rwatch a
Hardware read watchpoint 2: a
(gdb) c
Continuing.

Hardware read watchpoint 2: a

Value = 1
0x00005555555551a2 in main () at test_watchpoint.c:11
11	  printf("before: a = %d, b = %d, c = %d\n", a, b, c);
(gdb)
```

## 调试截图演示

![image-20221223221138102](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212232211630.png)
