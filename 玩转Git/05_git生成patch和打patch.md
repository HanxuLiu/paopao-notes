# git生成patch和打patch

日常开发过程中，经常会遇到对修改的代码进行对比和合并，也就是给代码打patch，其中patch里记录了代码的修改情况，可以通过打patch将修改内容同步应用到其他代码上。目前主要两种打patch的方法：

**两种打patch方法：**

- Linux里有`diff`和`patch`两个命令可以用来给代码打patch。适用于某个或某些文件的变动。
- git里有`git format-patch`和`git am`、`git apply`命令来给代码打patch，还能打上commit提交记录，对于git仓库管理的代码，建议优先使用该方法。

## 生成patch

生成最近commit的patch：

```
git format-patch HEAD^	#最近1次
git format-patch HEAD^^	#最近1次
```

生成单个commit1的patch：

```
git format-patch -1 <commit1>
```

生成两个commit之间的修改patch（包含最后的commit，包含第一个commit)：

```
git format-patch <commit1>..<commit2>
```

生成自commit1以来的修改patch（不包含commit1）

```
git format-patch <commit1>
```

生成从根源到commit1提交的所有patch：

```
git format-patch --root <commit1>
```

## 打patch


