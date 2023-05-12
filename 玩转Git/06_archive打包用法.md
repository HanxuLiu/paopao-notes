# archive打包用法

archive是归档的意思，用于将git仓库中的文件打包导出来，生成一份干净的代码（没有.git仓库信息）。

## 打包

```
git archive master --prefix=‘project/’ | gzip > master.tar.gz
```

## 查看支持格式

```
git archive -l
git archive --list
```
支持的归档格式有tar、tgz、tar.gz、zip：
```
lhx@ubuntu:~$ git archive -l
tar
tgz
tar.gz
zip
```

## 打包不同的分支或commit
果想打包不同分支，只要使用不同分支名即可。比如我有一个分支名为“testbr”，可以用如下命令将其打包。

git archive --format tar.gz --output "./output.tar.gz" testbr
如果要打包某个commit，只要先使用git log找到相应的commit id, 再使用该commit id打包即可。比如：

git archive --format tar.gz --output "./output.tar.gz" 5ca16ac0d603603

