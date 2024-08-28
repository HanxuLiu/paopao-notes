## 命令汇总
|命令|作用|
|---|---|
|sudo apt install gdb|apt安装gdb|
|sudo yum install gdb|yum安装gdb|
|./configure && make && make install|源码安装gdb|
|gdb -v或show version|打印gdb版本|
|gdb -config或show configuration|打印gdb配置|


## 仓库安装

```
sudo apt install gdb
或
sudo yum install gdb
```

## 源码安装

1. 下载、解压
```
wget http://ftp.gnu.org/gnu/gdb/gdb-11.2.tar.gz
tar -xvf gdb-11.2.tar.gz
```

2. 编译并安装
```
mkdir build && cd build
../configure --prefix={你想要安装的路径}/install
make -j16
make install
```

3. 添加 bin 路径到 PATH
```
export PATH={你想要安装的路径}/install/bin:$PATH
```

4. 编译报错解决方法

- 报错 makeinfo is missing on your system
安装texinfo: `sudo apt install texinfo`

- 报错expat is missing or unusable
安装expat库：`sudo apt install expat libexpat1-dev`

- 报错python is missing or unusable
安装python库文件：`sudo apt install python2.7-dev`

- 安装的gdb启动后没有TUI图形界面
在编译gdb前，需要先安装curses图形库：`sudo apt install libncurses5-dev libncursesw5-dev`

- 安装的gdb查看源代码没有语法高亮
在编译gdb前，需要先安装boost库，语法高亮依赖到boost正则匹配库，安装命令：`sudo apt install libboost-all-dev`

- 安装的gdb启动报错error while loading shared libraries:libbabeltrace.so.1
需要额外安装babeltrace库：`sudo apt install libbabeltrace-dev`

## 打印gdb版本`(show version)`
```
lhx@ubuntu:~/test_notes$ gdb -v
GNU gdb (GDB) 9.1
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

```
(gdb) show version
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
(gdb)
```

## 打印gdb配置`(show configuration)`
使用命令`show configuration`，或者在shell窗口使用命令`gdb --configuration`避免gdb启动。

```
(gdb) show configuration 
This GDB was configured as follows:
   configure --host=x86_64-linux-gnu --target=x86_64-linux-gnu
             --with-auto-load-dir=$debugdir:$datadir/auto-load
             --with-auto-load-safe-path=$debugdir:$datadir/auto-load
             --with-expat
             --with-gdb-datadir=/usr/share/gdb (relocatable)
             --with-jit-reader-dir=/usr/lib/gdb (relocatable)
             --without-libunwind-ia64
             --with-lzma
             --with-babeltrace
             --without-intel-pt
             --with-mpfr
             --without-xxhash
             --with-python=/usr (relocatable)
             --without-guile
             --disable-source-highlight
             --with-separate-debug-dir=/usr/lib/debug (relocatable)
             --with-system-gdbinit=/etc/gdb/gdbinit

("Relocatable" means the directory can be moved with the GDB installation
tree, and GDB will still find it.)
(gdb)
```



