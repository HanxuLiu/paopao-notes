# git config用户配置

## 查看全局配置

```
git config --global --list
```

## 修改用户信息

```
git config --global user.name "myname"
git config --global user.email "myemail@xx.com"
```

## 修改.gitconfig配置文件

也可以直接修改git的全局配置文件`~/.gitconfig`

```
lhx@ubuntu:~$ cat ~/.gitconfig 
[user]
	email = liu_han_xu@163.com
	name = Liu Hanxu
```