
## 源码安装

这里只介绍了`cmake`生成`Makefile`，然后使用`make && make install`进行安装的方法，此外还可以通过`ninja`来安装，编译速度比make更快一些。

### 获取源码

```shell
git clone https://github.com/llvm/llvm-project.git
```

### 在llvm项目里联合编译

将lldb当作llvm的一个子项目进行编译，只需要在-DLLVM_ENABLE_PROJECTS选项里添加上lldb即可，在llvm-project同级目录建立构建脚本build.sh，内容配置如下：

```cmake
cmake -S llvm-project/llvm -B build -G "Unix Makefiles" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=/home/lhx/llvm/install \
	-DLLVM_ENABLE_PROJECTS="clang;lldb"
```

然后经过漫长的编译和安装，正常情况下没有报错，顺利完成安装。

```shell
make -j8 && make install
```

成功安装后，进入指定的安装目录，可以看到bin目录下包含了所有llvm项目里的工具，lldb就在其中：

```shell
lhx@ubuntu:~/llvm/install/bin$ ls *lldb*
lldb  lldb-argdumper  lldb-instr  lldb-server  lldb-vscode
lhx@ubuntu:~/llvm/install/bin$ ./lldb
(lldb) version
lldb version 17.0.0git (https://github.com/llvm/llvm-project.git revision 068e9889b1ba0856af10d8ba2e21d41d81554533)
  clang revision 068e9889b1ba0856af10d8ba2e21d41d81554533
  llvm revision 068e9889b1ba0856af10d8ba2e21d41d81554533
(lldb) q
lhx@ubuntu:~/llvm/install/bin$ 
```

另外，虽然我编译的是release版，但是占用的空间还是很大，编译目录5.9G，安装目录4.1G。

```
lhx@ubuntu:~/llvm$ du -sh *
5.9G	build
4.0K	build.sh
4.1G	install
3.6G	llvm-project
```

### 单独编译lldb

还可以将lldb源码从llvm项目里剥离出来，单独进行编译安装，分为两步：

1. 先单独编译llvm，只需要用到build-llvm目录，可以不用安装，完成编译就行。

```shell
cmake -B build-llvm -G "Unix Makefiles" \
        -DLLVM_ENABLE_PROJECTS=clang \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/home/lhx/llvm/install-llvm \
        llvm-project/llvm
cd build-llvm
make -j8 && make install
```

2. 再单独编译lldb，此时需要指定llvm的编译目录build-llvm。

```shell
cmake -B build-lldb -G "Unix Makefiles" \
        -DLLVM_DIR=/home/lhx/llvm/build-llvm/lib/cmake/llvm \
        -DClang_DIR=/home/lhx/llvm/build-llvm/lib/cmake/clang \
        -DCMAKE_INSTALL_PREFIX=/home/lhx/llvm/install-lldb \
        llvm-project/lldb
cd build-lldb
make -j8 && make install
```

安装成功后，可以看下lldb安装目录占用的空间大小：

```
lhx@ubuntu:~/llvm/install-lldb$ du -sh *
73M	bin
3.9M	include
151M	lib
lhx@ubuntu:~/llvm/install-lldb$ cd bin/
lhx@ubuntu:~/llvm/install-lldb/bin$ ls
lldb  lldb-argdumper  lldb-instr  lldb-mi  lldb-server  lldb-vscode
lhx@ubuntu:~/llvm/install-lldb/bin$ ./lldb
(lldb) version 
lldb version 9.0.0 (https://github.com/llvm/llvm-project.git revision 0399d5a9682b3cef71c653373e38890c63c4c365)
  clang revision 0399d5a9682b3cef71c653373e38890c63c4c365
  llvm revision 0399d5a9682b3cef71c653373e38890c63c4c365
(lldb) q
lhx@ubuntu:~/llvm/install-lldb/bin$
```

### 编译报错和解决方法

#### python识别有问题

编译git仓库拉下来的最新代码时没有报错，当切换到llvmorg-9.0.0的tag后，cmake配置时报错python识别有问题，报错如下：

```shell
-- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython3.8.so (found version "3.8.10") 
CMake Error at /home/lhx/llvm/llvm-project/lldb/cmake/modules/LLDBConfig.cmake:229 (message):
  Found incompatible Python interpreter (2.7) and Python libraries (3.8)
Call Stack (most recent call first):
  /home/lhx/llvm/llvm-project/lldb/CMakeLists.txt:20 (include)

-- Configuring incomplete, errors occurred!
```

解决方法是安装对应的依赖：

```shell
sudo apt-get install python3.8 python3.8-dev python3.8-distutils python3.8-venv
```

#### 没有指定`Clang_DIR`
注意，只指定`LLVM_DIR`不行，还需要指定`Clang_DIR`，另外`Clang_DIR`要用绝对路径，我一开始用的相对路径还是报错，为避免错误，最好都使用绝对路径。

```shell
CMake Error at cmake/modules/LLDBStandalone.cmake:6 (find_package):
  Could not find a package configuration file provided by "Clang" with any of
  the following names:

    ClangConfig.cmake
    clang-config.cmake

  Add the installation prefix of "Clang" to CMAKE_PREFIX_PATH or set
  "Clang_DIR" to a directory containing one of the above files.  If "Clang"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  CMakeLists.txt:17 (include)

-- Configuring incomplete, errors occurred!
```

解决方法：cmake配置时添加`-DLLVM_DIR=/home/lhx/llvm/build-llvm/lib/cmake/llvm`和`-DClang_DIR=/home/lhx/llvm/build-llvm/lib/cmake/clang`就可以了。

## 仓库安装

```shell
sudo apt install lldb
```



