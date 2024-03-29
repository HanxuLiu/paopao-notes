# 通过vimdiff进行文件对比合并

`vimdiff`命令是对`vim`中diff模式的封装，相当于`vim`和`diff`命令的结合体。系统下只要安装了`vim`和`diff`，就可以使用`vimdiff`命令。

不想用`vimdiff`命令的话，还可以直接用`vim -d`，两者等价。


## `vimdiff`启动方式

```
vimdiff file1 file2 //默认左右分屏
vimdiff -o file1 file2 //上下分屏
```

`vim`等价命令：

```
vim -d file1 file2 //默认左右分屏
vim -d -o file1 file2 //上下分屏
```

**左右分屏和上下分屏效果图：**

![image-20230321171731005](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202303211717119.png)

## `vimdiff`界面颜色

文件存在的差异会通过不同颜色高亮显示出来：
- 只在某一文件中存在的行的背景色是蓝色，而在另一文件中的对应位置被显示为淡绿色。
- 两个文件中都存在，但是包含差异的行显示为粉色背景，引起差异的文字用红色加以突出。

**界面颜色区分图：**

![image-20230321165844338](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202303211658464.png)

## 折叠和展开相同的内容

两个文件中连续的相同的行会被折叠起来，从而更好聚焦到文件差异上。

通过`z o`命令展开被折叠的相同文本行：

```
z o （folding open）
```

通过`z c`命令重新折叠：

```
z c （folding close）
```

之所以用`z`这个字母，是因为它看上去比较像折叠着的纸。

![vimdiff-zozc](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202303212058541.gif)

## 差异点上下跳转

通过下列两种快捷键，实现在文件的各个差异点上下跳转：

```
] c：跳转到下个差异点
[ c：跳转到上个差异点
```

## 窗口左右跳转
通过下面的快捷键，实现光标在两个窗口之前的切换：

```
Ctrl-w, l：光标切换到右侧的窗口
Ctrl-w, h：光标切换到左侧的窗口
Ctrl-w, w：光标在两个窗口间彼此切换
```

## 差异内容合并
文件比较完之后，接下来就是内容合并来消除差异。

- 针对某个差异点，把当前文件的内容复制、推送到另一个文件里：

```
d p (diff "put")：//从当前复制到另一个
```

- 针对某个差异点，把另一个文件的内容复制、获取到当前文件里：

```
d o (diff "obtain")：//从另一个复制到当前
```


- 针对指定范围的差异内容进行合并：

> 先指定范围1-100行，再用另外一个窗口的不同处替换当前：

```
:1,100 diffget
```

> 先指定范围1-100行，再用另外一个窗口的不同处替换当前：

```
:1,100 diffput
```

## 同时退出两个窗口

```
:qa：退出所有文件
:wa：保存所有文件
:wqa：保存并退出所有文件
qa!：强制退出所有文件（不保存）
```