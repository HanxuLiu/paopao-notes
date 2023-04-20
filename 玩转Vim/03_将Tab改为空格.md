# 将Tab改为空格

## 修改Tab为4个空格长度

在vimrc配置中添加下面命令，实现当vim中输入Tab键，自动替换为4个空格的效果。

```
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent
```

> tabstop，缩写为ts，表示TAB宽度，改为4个空格，默认为8。
> softtabstop表示在编辑模式下按退格键退回缩进的长度，一般搭配 expandtab 使用。
> shiftwidth 表示每一级缩进的长度。
> expandtab表示缩进用空格来表示，noexpandtab表示缩进用Tab。
> autoindent表示自动缩进

## 空格和Tab互换

对以前的文件或当前编辑的文件，通过下面命令实现空格和Tab之间互换。

- Tab替换为空格

```
:set tabstop=4
:set expandtab
:%retab!
```

- 空格替换为Tab

```
:set tabstop=4
:set noexpandtab
:%retab!
```

## 将文本中已存在的Tab替换为空格

首先确认vimrc中是否已经配置好了`set tabstop=4`和`set expandtab`，若没有配置这两个选项，则需要冒号进入命令行重新配置。

然后，直接在命令行模式下输入：
```
:%retab!
```