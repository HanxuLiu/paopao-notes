# git describe标签描述

git describe命令用来描述离当前commit最近的tag信息。

```shell
$ git describe -h
用法：git describe [<选项>] [<提交号>...]
   或：git describe [<选项>] --dirty

    --contains            寻找该提交之后的标签
    --debug               在标准错误上调试搜索策略
    --all                 使用任意引用
    --tags                使用任意标签，即使未附带注释
    --long                始终使用长提交号格式
    --first-parent        只跟随第一个父提交
    --abbrev[=<n>]        用 <n> 位数字显示 SHA-1 哈希值
    --exact-match         只输出精确匹配
    --candidates <n>      考虑最近 <n> 个标签（默认：10）
    --match <模式>        只考虑匹配 <模式> 的标签
    --exclude <模式>      不考虑匹配 <模式> 的标签
    --always              显示简写的提交号作为后备
    --dirty[=<标记>]      对于脏工作区，追加 <标记>（默认："-dirty"）
    --broken[=<标记>]     对于损坏的工作区，追加 <标记>（默认："-broken"）
```

## 显示最近的tag

如果最近的tag刚好对应最新的commit，则直接显示该tag：

```
$ git log --oneline 
3f5fd0f (HEAD -> master, tag: v3.0) add c.c
11ec1f1 (tag: v2.0) add b.c
e527287 (tag: v1.0) add a.c
$ git describe 
v3.0
```

如果最近的tag对应历史的commit，则显示的tag会附加一些后缀来描述版本信息：该tag之后有多少次提交以及最新的提交commit id。

```
lhx@ubuntu:~/test-git/mysource$ git log --oneline 
c36c787 (HEAD -> master) add e.c
7f1426b add d.c
3f5fd0f (tag: v3.0) add c.c
11ec1f1 (tag: v2.0) add b.c
e527287 (tag: v1.0) add a.c
lhx@ubuntu:~/test-git/mysource$ git describe 
v3.0-2-gc36c787
```

这里显示的`v3.0-2-gc36c787`含义为：
- `v3.0`表示最近的tag
- `2`表示自该tag有2次commit
- `g`表示git的缩写
- `c36c787`表示最新提交的commit id。



