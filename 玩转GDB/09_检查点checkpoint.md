## 命令汇总
|命令|作用|
|---|---|
|checkpoint|保存快照检查点|
|info checkpoints|查看检查点|
|restart checkpoint-id|恢复checkpoint-id编号的检查点|
|delete checkpoint checkpoint-id|删除checkpoint-id编号的检查点|

## checkpoint介绍
checkpoint（称为检查点）用于保存程序状态的快照，并且可以返回到该检查点位置，撤销程序中内存、寄存器等系统状态的更改。因此，checkpoint适用于当调试到接近出错的地方，此时设置一个checkpoint，避免错过关键位置而从头重新调试程序，直接可以返回到检查点重新开始。

checkpoint 的本质相当于通过 fork 复制出来了一个同样的进程。

## 保存检查点`checkpoint`
> 保存被调试程序当前执行状态的快照

```
(gdb) checkpoint 
checkpoint 1: fork returned pid 2941.
(gdb)
```

## 查看检查点`info checkpoints`
> 列出当前调试会话中已保存的检查点，每个检查点包括下述信息：

- Checkpoint ID  
- Process ID  
- Code Address  
- Source line, or label

```
(gdb) i checkpoints 
* 0 process 2937 (main process) at 0x0
  1 process 2941 at 0x555555555164, file test.c, line 6
(gdb)
```

## 恢复检查点`restart checkpoint-id`

> 恢复检查点编号为 checkpoint-id 的程序状态，此时程序中所有变量、寄存器、堆栈等都将恢复到保存检查点时的值，实现了将一切“倒回”到保存检查点的时间点。

```
(gdb) c
Continuing.

Breakpoint 1, fun (n=5) at test.c:6
6	    sum += i;
(gdb) i locals 
i = 5
sum = 10
(gdb) restart 1
Switching to process 2941
#0  fun (n=5) at test.c:6
6	    sum += i;
(gdb) i loc
i = 4
sum = 6
(gdb)
```

## 删除检查点`delete checkpoint checkpoint-id`
> 删除检查点之前，记得先恢复到其他位置，才能删除当前 checkpoint。

```
(gdb) d checkpoint 1
Please switch to another checkpoint before deleting the current one
(gdb) restart 0 
Switching to process 2937
(gdb) i checkpoints 
* 0 process 2937 (main process) at 0x555555555164, file test.c, line 6
  1 process 2941 at 0x555555555164, file test.c, line 6
(gdb) d checkpoint 1
Killed process 2941
(gdb) i checkpoints 
No checkpoints.
(gdb)
```

## 调试截图演示

![image-20221223221349564](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212232213077.png)
