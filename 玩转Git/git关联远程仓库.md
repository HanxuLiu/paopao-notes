## github官方推荐方法

### 创建新的仓库并添加远程关联

```bash
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:HanxuLiu/wechat-push.git
git push -u origin main
```

### 将已有仓库关联到远程仓库

```bash
git remote add origin git@github.com:HanxuLiu/wechat-push.git
git branch -M main
git push -u origin main
```

### 参数解释

`git branch -M main` 命令用于将当前分支重命名为 `main`，常用于将默认分支名从其他名字（比如 `master`）更改为  `main`。

> git branch 是用于创建、列出或删除分支的命令。  
> -M 参数用于重命名分支，如果指定分支名已存在，则会覆盖同名分支。



`git push -u origin main` 命令用于将本地的 main 分支的提交推送到远程仓库 `origin` 上，并且建立本地 `main` 分支和远程 `origin/main` 分支的关联，使得本地 main 分支成为远程 `origin` 仓库上 `main` 分支的跟踪分支（上游分支），此命令通常在第一次推送本地分支到远程仓库时使用，以建立本地分支与远程分支的连接，后续可以使用 `git` push 命令进行推送而不需要指定远程仓库和分支名称。

> git push 用于将本地的提交推送（上传）到远程仓库。  
> -u 参数是 --set-upstream 的简写，用于将本地分支和远程分支关联起来，建立起追踪关系。  
> origin 是远程仓库的名称，它通常指向项目的远程 Git 仓库。  
> main 是指定要推送到远程仓库的本地分支名称。

## gitee官方推荐方法

### 创建git仓库

```bash
mkdir test
cd test
git init 
touch README.md
git add README.md
git commit -m "first commit"
git remote add origin git@gitee.com:liuhanxu/test.git
git push -u origin "master"
```

### 已有git仓库

```bash
cd existing_git_repo
git remote add origin git@gitee.com:liuhanxu/test.git
git push -u origin "master"
```