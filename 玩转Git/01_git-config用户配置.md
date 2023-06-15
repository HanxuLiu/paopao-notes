# git config用户配置

## 查看全局配置

```
git config --global --list
```

## 设置全局用户信息

```
git config --global user.name "myname"
git config --global user.email "myemail@xx.com"
```

## 查看项目单独配置

```
git config --local --list
```

## 为项目单独设置用户信息

```
git config --local user.name "myname"
git config --local user.email "myemail@xx.com"
```

## 修改全局配置文件.gitconfig

直接修改git的全局配置文件`~/.gitconfig`

```
lhx@ubuntu:~$ cat ~/.gitconfig 
[user]
	email = liu_han_xu@163.com
	name = Liu Hanxu
```

## 修改项目单独的配置文件.git/config

直接修改项目单独的配置文件`.git/config`

```
lhx@ubuntu:~$ cat .git/config
[user]
	email = liu_han_xu@163.com
	name = Liu Hanxu
```

## 删除用户配置信息

删除全局信息：

```
git config --global --unset user.name
git config --global --unset user.email
```

删除项目单独信息：

```
git config --local --unset user.name
git config --local --unset user.email
```