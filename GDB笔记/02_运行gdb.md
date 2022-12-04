
## 启动gdb

### 启动方式
1. 直接启动`gdb`，然后再`file a.out`加载待调试程序。
2. 启动并指定程序`gdb a.out`
3. 启动并调试指定进程`gdb -p 1234`

### 启动选项
#### 启动gdb调试core文件
`gdb --core corefile --exec=execfile`

#### 启动gdb进入TUI图形调试界面
`gdb -tui`

#### 启动gdb并指定其他TTY窗口操作程序input/output
`gdb -tty`

#### 启动gdb进入执行时间统计模式
`gdb -statistics`

#### 启动gdb进入安静模式（不显示介绍、版权信息）
`gdb --silent（-q 或--quiet）` //

### 设置调试程序参数
