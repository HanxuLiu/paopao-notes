
## 源码安装

### 1. 下载 gdb 版本
```
 wget http://ftp.gnu.org/gnu/gdb/gdb-11.2.tar.gz
```
### 2.  解压
```
tar -xvf gdb-11.2.tar.gz
```
### 3. 编译并安装
```
mkdir build && cd build
../configure --prefix={你想要安装的路径}/install
make -j16
make install
```
### 4. 添加 bin 路径到 PATH
```
export PATH={你想要安装的路径}/install/bin:$PATH
```

### 5. Q & A

Q: makeinfo is missing on your system

A: sudo apt install texinfo


## 仓库安装

### 1. apt 源安装
```
sudo apt install gdb
```
### 2. yum 源安装
```
sudo yum install gdb
```


## 显示gdb信息

### 1. 显示gdb版本信息`(show version)`
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

### 2. 显示gdb配置信息`(show configuration)`
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



