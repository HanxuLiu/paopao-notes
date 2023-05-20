
## 源码安装

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
        -DLLVM_DIR=/path/to/build-llvm/lib/cmake/llvm \
        -DCMAKE_INSTALL_PREFIX=/home/lhx/llvm/install-lldb \
        llvm-project/lldb
cd build-lldb
make -j8 && make install
```

### 编译报错和解决方法

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

## 仓库安装

```shell
sudo apt install lldb
```



