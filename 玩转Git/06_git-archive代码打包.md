# git archive代码打包

archive是归档的意思，用于将git仓库中的文件打包导出来，生成一份干净的代码（没有.git仓库信息）。

## 查看支持格式

```
git archive -l
git archive --list
```

如下可以看到，支持的归档格式有tar、tgz、tar.gz、zip。

```
lhx@ubuntu:~$ git archive -l
tar
tgz
tar.gz
zip
```

## 指定打包格式和名称

标准命令：

```
git archive <分支/标签/commit> --prefix=<前缀>/ --format=<格式> -o <名称>
```

> `--prefix`指定打包前缀，这样解压后就会全部到该前缀文件夹里，记得后面加上/。  
> `--format` 指定打包格式，若省略该参数则会从文件名中推断格式，建议省略。  
> `-o, --output` 指定打包文件名，也就是压缩包名称。

例如：
```
git archive master --prefix=mycode/ -o ../mycode.zip
```

## 打包成tar.gz和tar.bz2格式

导出并压缩为 tar.gz 格式：

```
git archive v1.0 --prefix=mycode-v1.0/ | gzip > mycode-v1.0.tar.gz
```

导出并压缩为 tar.bz2 格式：

```
git archive v1.0 --prefix=mycode-v1.0/ | bzip2 > mycode-v1.0.tar.bz2
```

