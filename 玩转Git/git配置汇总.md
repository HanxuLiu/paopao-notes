# git 配置汇总

## 在编辑器里写提交日志

简单的提交日志可以直接用命令`git commit -m`来填写，但对于复杂的日志，如多行、嵌套单引号/双引号，可能需要换行或添加转义符，此时通过交互式编辑器填写日志信息更加方便。打开`~/.bashrc`，添加下面的内容：

```
export GIT_EDITOR=vim
```

设置好`GIT_EDITOR`环境变量后，此时再输入`git commit`命令就会自动唤起编辑器，效果图如下：

![git_editor](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2024/202402021058347.gif)