# archive打包用法

## 打包

```
git archive master --prefix=‘project/’ | gzip > master.tar.gz
```

## 查看打包支持格式

```
git archive --list
```

支持的归档格式有tar、tgz、tar.gz、zip