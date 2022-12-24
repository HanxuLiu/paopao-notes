## 命令汇总
|命令|作用|
|---|---|
|gdb a.out|调试a.out|
|gdb -p 1234|调试1234进程|
|gdb a.out core.93110|调试a.out对应的core文件|
|gdb -tui|启动gdb进入TUI界面|
|gdb -tty=/dev/pts/1|启动gdb并指定tty窗口|
|gdb -statistics|启动gdb进入执行时间统计模式|
|gdb -q |启动gdb进入安静模式|

## gdb启动方式

1. 直接启动`gdb`，然后再`file a.out`加载待调试程序。
2. 启动并指定程序`gdb a.out`
3. 启动并调试指定进程`gdb -p 1234`
4. 启动并调试core文件`gdb a.out core.93110`

## 启动gdb进入TUI图形调试界面
`gdb -tui`

![image-20221224132730438](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241327509.png)

## 启动gdb并指定其他tty窗口处理程序input/output
`gdb -tty=/dev/pts/1`
打开新窗口，输入`tty`命令查看窗口编号，通过`gdb -tty=新窗口编号`开启调试，随后程序的输入输出都将在新窗口里进行。

![image-20221224120756526](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241208647.png)

## 启动gdb进入执行时间统计模式
`gdb -statistics`
在统计模式下进行调试时，每条命令从开始到结束所消耗的时间和内存都能准确统计显示出来。
![image-20221224121347737](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241213806.png)

## 启动gdb进入安静模式（不显示介绍、版权信息）
`gdb --silent（-q 或--quiet）`

![image-20221224121649923](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241216996.png)
