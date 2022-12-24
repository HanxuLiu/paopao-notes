## 插件1：GEF
### GEF介绍
GEF (GDB Enhanced Features) - a modern experience for GDB with advanced debugging capabilities for exploit devs & reverse engineers on Linux.

GEF（发音为Jeff），该插件通过Python API 为 GDB 提供附加功能，以协助开发人员进行动态分析和逆向分析。2020.01之后GEF官方弃用了对Python2的支持，目前仅支持Python 3，且要求GDB版本8.0+和Python版本3.6+。

gef源码: [https://github.com/hugsy/gef](https://github.com/hugsy/gef)

gef手册：[https://hugsy.github.io/gef/](https://hugsy.github.io/gef/)

### 安装方式

1. 从GitHub拉源码。
```
git clone https://github.com/hugsy/gef.git
```
2. 把源码里gef.py导入到~/.gdbinit文件里。

```
lhx@ubuntu:~/gdb-plugins/gef$ echo source $PWD/gef.py >> ~/.gdbinit
lhx@ubuntu:~/gdb-plugins/gef$ cat ~/.gdbinit 
source /home/lhx/gdb-plugins/gef/gef.py
```

### 效果图

GEF启动后窗口：
![image-20221224143308348](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241433459.png)

寄存器、汇编、源码等窗口组合显示：
![image-20221224143339756](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241433859.png)

查看16进制反汇编视图：

![image-20221224144451910](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241444977.png)

 对地址或寄存器进行取消引用：

![image-20221224144554675](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241445754.png)

展示详细的ELF信息：

![image-20221224144742390](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241447468.png)

显示GOT表信息：

![image-20221224145057498](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241450560.png)

展示全面的地址空间：

![image-20221224145155514](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241451604.png)


## 插件2：Pwndbg
### Pwndbg介绍
pwndbg (/poʊndbæg/) is a GDB plug-in that makes debugging with GDB suck less, with a focus on features needed by low-level software developers, hardware hackers, reverse-engineers and exploit developers.

Pwndbg是一款强大的GDB功能扩展插件，对不同类型数据进行颜色匹配，包含一系列工具集，功能非常丰富，同时兼容支持Python 2和Python 3。Pwndbg由于工具种类多，所以依赖的python包也比较多。

pwndbg源码: [https://github.com/pwndbg/pwndbg](https://github.com/pwndbg/pwndbg)

### 安装方式

1. 参照GitHub源码官方安装介绍，如下：
```
git clone https://github.com/pwndbg/pwndbg.git
cd pwndbg
./setup.sh
```

2. 把源码里gdbinit.py导入到~/.gdbinit文件里。

```
lhx@ubuntu:~/gdb-plugins/pwndbg$ echo source $PWD/gdbinit.py >> ~/.gdbinit
lhx@ubuntu:~/gdb-plugins/pwndbg$ cat ~/.gdbinit 
#source /home/lhx/gdb-plugins/gef/gef.py
source /home/lhx/gdb-plugins/pwndbg/gdbinit.py
```

### 效果图

![image-20221224174425130](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241744229.png)

![image-20221224174440397](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241744493.png)

显示内存信息：

![image-20221224174627026](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241746114.png)

### GEF和Pwndbg联合配置
可以在`.gdbinit`文件里自定义两个命令`init-pwndbg`和`init-gef`来分别加载两个插件，这样启动gdb后可以再输入对应命令调用插件。

```
define init-pwndbg
source ~/gdb-plugins/pwndbg/gdbinit.py
end
document init-pwndbg
Initializes PwnDBG
end

define init-gef
source ~/gdb-plugins/gef/gef.py
end
document init-gef
Initializes GEF (GDB Enhanced Features)
end
```

## 插件3：gdb-dashboard

### gdb-dashboard介绍
gdb-dashboard是一个python脚本，增强gdb功能，界面炫酷，组件众多，自定义配置，多终端显示。

gdb-dashboard源码：[https://github.com/cyrus-and/gdb-dashboard](https://github.com/cyrus-and/gdb-dashboard)

### 安装方式

1. 从GitHub拉源码。
```
git clone https://github.com/cyrus-and/gdb-dashboard.git
```
2. 把源码里.gdbinit复制替换到主目录~/.gdbinit文件里。

### 效果图

gdb-dashboard提供了很多命令选项：

![image-20221224173745010](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241737106.png)

gdb-dashboard有很多试图，包括：
assembly	汇编信息
breakpoints	断点信息
expressions	表达式
history		历史信息
memory		内存信息
registers	寄存器信息
source		源代码
stack		栈帧信息
threads		多线程信息
variables	变量信息

![image-20221224150518156](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241505263.png)

gdb-dashboard还能分窗口进行显示：

![image-20221224150536805](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241505028.png)

![image-20221224150502326](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212241505496.png)


## 插件4：gdbgui

### gdbgui介绍
gdbgui is a browser-based frontend to gdb, the gnu debugger. You can add breakpoints, view stack traces, and more in C, C++, Go, and Rust!

gdbgui是一个gdb前端调试界面，可以在网页上进行调试，程序调试信息基本都可以显示在网页上。

gdbgui源码：[https://github.com/cs01/gdbgui](https://github.com/cs01/gdbgui)

gdbgui手册：[https://www.gdbgui.com/](https://www.gdbgui.com/)

### 安装方式

方式1. 直接通过`pip install gdbgui`安装。
方式2. 从[release界面](https://github.com/cs01/gdbgui/releases)下载二进制文件，`./gdbgui`运行。

### 效果图

`./gdbgui`启动运行：

![image-20221224204437534](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212242044651.png)

默认网址：[http://127.0.0.1:5000/](http://127.0.0.1:5000/)

![image-20221224204917308](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212242049415.png)

控制面板网址：[http://127.0.0.1:5000/dashboard](http://127.0.0.1:5000/dashboard)

![image-20221224204304052](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2022/202212242043165.png)


![img](https://github.com/cs01/gdbgui/raw/master/screenshots/gdbgui_animation.gif)
