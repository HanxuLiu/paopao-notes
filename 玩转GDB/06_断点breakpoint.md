## 命令汇总
|命令|作用|
|---|---|
|break locspec|设置断点|
|break locspec if cond|设置条件断点|
|tbreak locspec|设置一次性断点|
|rbreak regex|设置正则表达式断点|
|break locspec inferior inferior-id|设断点到指定进程|
|break locspec thread thread-id|设断点到指定线程|
|set breakpoint pending [auto\|on\|off]|设置断点挂起状态|
|info breakpoints|查看断点|
|delete bpnum|删除断点|
|disable/enable bpnum|禁用/启用断点|
|enable once bpnum|断点启用一次|
|enable count n bpnum|断点启用多次|
|enable delete bpnum|断点启用一次就删除|
|condition bpnum expression|给断点加条件|
|condition bpnum|删除断点条件|
|ignore bpnum count|忽略多次断点|
|commands bpnum<br/>...<br/>end|给断点添加命令|
|dprintf locspec,template,expression|动态打印|
|save breakpoints filename|保存断点|

## 测试用例

```c
#include<stdio.h>

int fun(int n) {
  int sum = 0;
  for (int i=0; i<=n; i++)
    sum += i;
  return sum;
}

int main() {
  int x = 5;
  printf("0 + ... + %d = %d\n", x, fun(x));
  return 0;
}
```

## 设置断点

### 普通断点

```
break locspec
```

> 指定位置`locspec`（ Location Specifications）可以为源代码行号、函数名、地址等。

C++里会出现函数重载现象，即函数名相同传参不同，还会出现类名不同函数名相同，对此可以通过作用域来指定具体的断点位置：

```
break class1::fun
break class2::fun
break fun(int)
break fun(float)
```

### 条件断点

```
break locspec if cond
```

> 每次到达断点时都对表达式`cond`求值，并且仅当该值非零（即`cond`求值结果为 true）时才停止。

- 当a的值为10时，在func函数上设断点：
```
(gdb) break func if a == 10
```

- 当str的值为error时，在当前文件20行上设断点：
```
(gdb) break 20 if str="error"
```

### 一次性断点

```
tbreak locspec
```
> 程序在第一次停止后，断点会自动删除

### 正则表达式断点

```
rbreak regex
```

> 在与正则表达式 regex 匹配的所有函数上设置断点

- 在程序中的所有函数上设置断点：

```
(gdb) rbreak .
```

- 在指定文件中的每个函数上设置断点：

```
(gdb) rbreak file.c:.
```

- 在所有以`test_`开头的函数上设置断点：

```
(gdb) rbreak test_*
```

### 指定进程或线程的断点

设断点/条件断点到指定进程：

```
break locspec inferior inferior-id
break locspec inferior inferior-id if ...
```

设断点/条件断点到指定线程：

```
break locspec thread thread-id
break locspec thread thread-id if ...
```

> 默认情况下，不指定进程或线程，断点会设到所有进程或线程上。
> 如果指定的进程或线程已不在了，断点会自动删除。

### 挂起的断点

```
set breakpoint pending [auto|on|off]
show breakpoint pending  //查看当前设置状态
```

> auto：默认值，当解析不到断点位置时，会询问是否挂起断点  
> on：直接挂起断点  
> off：禁止创建断点  

## 查看断点

```
info breakpoints
```
> Num：断点编号  
> Type：断点类型（断点、观察点或捕捉点）  
> Disp：对断点的处置，keep表示命中后继续生效，del命中后删除，dis命中后禁用  
> Enb：y启用或n禁用断点  
> Address：断点地址  
> What：断点在源代码中的位置

## 删除断点

```
delete bpnum
```

> bpnum：断点编号，不加编号的话，默认删除所有断点。

- 删除编号为2，4，5的断点：

```
d 2 4 5
```

- 删除编号范围为2-5的断点：

```
d 2-5
```

## 禁用断点

### 禁用/启用

```
disable/enable bpnum
```

> bpnum：断点编号，不加编号的话，默认禁用所有断点。

### 启用一次

```
enable once bpnum
```

> 只启用一次断点，在第一次停下来后，断点会被禁用。

### 启用多次

```
enable count n bpnum
```

> 启用n次断点后，继续保持禁用。例如`enable count 5 2`，启用5次2号断点。  
> 适用场景：断点之前状态是禁用，然后想临时启用几次。

### 启用一次后就删除

```
enable delete bpnum
```

> 启用一次断点后就删除该断点，与临时断点类似，该方法将被禁用的断点转换成临时断点。

## 给断点添加条件

```
condition bpnum expression
```
> 通过加条件，让普通断点变成条件断点。
> 当表达式expression的值为 true（非零）时，断点 bpnum 才会工作。

```
condition bpnum
```
> 删除断点 bpnum 的条件，使它成为普通的无条件断点。

```
ignore bpnum count
```
> 忽略count次编号为bpnum的断点。例如`ignore 1 5`忽略1号断点5次，第6次才会命中。

```
(gdb) b 6
Breakpoint 1 at 0x1164: file test.c, line 6.
(gdb) condition 1 sum==10
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001164 in fun at test.c:6
	stop only if sum==10
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test 

Breakpoint 1, fun (n=5) at test.c:6
6	    sum += i;
(gdb) p sum
$1 = 10
(gdb) 
```

## 给断点添加命令

```
commands bpnum
...
end
```

> 给断点添加一系列命令，让其命中断点后自动执行这些命令。  
> 没有bpnum的话，默认会给最后一个断点添加命令。

- 断点命中后，先打印变量x的值，再继续执行：

```
break fun
commands
silent
printf "x is %d\n",x
cont
end
```

> `silent`命令用于关掉断点停下来后的提示信息

- 断点2命中后，先把变量x的值改为y+4，再继续执行（可用于修复代码中的错误）：

```
commands 2
silent
set x = y + 4
cont
end
```

```c
(gdb) b 6
Breakpoint 1 at 0x1164: file test.c, line 6.
(gdb) commands 
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>silent
>printf "i = %d, sum = %d\n", i, sum
>cont
>end
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test 
i = 0, sum = 0
i = 1, sum = 0
i = 2, sum = 1
i = 3, sum = 3
i = 4, sum = 6
i = 5, sum = 10
0 + ... + 5 = 15
[Inferior 1 (process 3587) exited normally]
(gdb) 
```

## 动态打印

```
dprintf locspec,template,expression
```

> 动态打印`dprintf`结合断点与格式化打印功能，实现将 `printf` 动态插入到程序源码中的效果（底层还是利用断点功能），而无需重新编译程序。

- 在指定源码行添加动态打印`dprintf 6, "Line 6: sum = %d\n", sum`：

```c
(gdb) l
1	#include<stdio.h>
2	
3	int fun(int n) {
4	  int sum = 0;
5	  for (int i=0; i<=n; i++)
6	    sum += i;
7	  return sum;
8	}
9	
10	int main() {
(gdb) dprintf 6, "Line 6: sum = %d\n", sum
Dprintf 1 at 0x1164: file test.c, line 6.
(gdb) i b
Num     Type           Disp Enb Address            What
1       dprintf        keep y   0x0000000000001164 in fun at test.c:6
        printf "Line 6: sum = %d\n", sum
(gdb) r
Starting program: /home/lhx/paopao-notes/code/test 
Line 6: sum = 0
Line 6: sum = 0
Line 6: sum = 1
Line 6: sum = 3
Line 6: sum = 6
Line 6: sum = 10
0 + ... + 5 = 15
[Inferior 1 (process 3201) exited normally]
(gdb) 
```

- 在指定地址处添加动态打印`dprintf *0x0000555555555154, "At address 0x0000555555555154, arg n = %d\n", n`：

```c
(gdb) disassemble /s fun
Dump of assembler code for function fun:
test.c:
3	int fun(int n) {
   0x0000555555555149 <+0>:	endbr64 
   0x000055555555514d <+4>:	push   %rbp
   0x000055555555514e <+5>:	mov    %rsp,%rbp
   0x0000555555555151 <+8>:	mov    %edi,-0x14(%rbp)

4	  int sum = 0;
   0x0000555555555154 <+11>:	movl   $0x0,-0x8(%rbp)

(gdb) dprintf *0x0000555555555154, "At address 0x0000555555555154, arg n = %d\n", n
Dprintf 2 at 0x555555555154: file test.c, line 4.
(gdb) c
Continuing.
At address 0x0000555555555154, arg n = 5
0 + ... + 5 = 15
[Inferior 1 (process 3293) exited normally]
(gdb) 
```

## 保存断点

```
save breakpoints filename
```

```c
(gdb) b main
Breakpoint 2 at 0x555555555187: file test.c, line 11.
(gdb) b 6
Breakpoint 3 at 0x555555555164: file test.c, line 6.
(gdb) b *0x0000555555555176
Breakpoint 4 at 0x555555555176: file test.c, line 7.
(gdb) i b
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x0000555555555187 in main at test.c:11
3       breakpoint     keep y   0x0000555555555164 in fun at test.c:6
4       breakpoint     keep y   0x0000555555555176 in fun at test.c:7
(gdb) save breakpoints bp.txt
Saved to file 'bp.txt'.
(gdb)
```

```shell
lhx@ubuntu:~/paopao-notes/code$ cat bp.txt
break main
break /home/lhx/paopao-notes/code/test.c:6
break *0x0000555555555176
```

