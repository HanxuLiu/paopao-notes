# tag标签用法

tag标签的作用是对版本发布进行管理，可以把标签看成版本号，比如v1.0、v2.0。
通常发布一个版本就在git仓库打一个标签，这样就建立了版本和commit唯一对应关系。

**tag和branch的区别：**

- tag 对应某次 commit ，是一个固定节点。
- branch对应一系列commit，是由很多节点组成的一条线，可以根据HEAD 指针进行移动。

## 创建tag

创建普通tag：
```
git tag v1.0
```

创建带注释的tag：
```
git tag v1.0 -m "This is first release version"
```

给历史commit创建tag：
```
git tag v1.0 commit_id
```

## 查看tag

查看tag名称列表：
```
git tag
```

查看tag注释信息：
```
git tag -n
```

查看tag详细信息（包括tag信息及对应commit信息）：
```
git show v1.0
```

## 推送tag到远程

创建的标签都只存储在本地，不会自动推送到远程，需要手动进行推送。

推送单个本地tag到远程：
```
git push origin v1.0
```

推送全部未推送过的本地tag：
```
git push origin --tags
```

## 删除tag

删除本地tag：
```
git tag -d v1.0
```

删除远程tag（先删除本地，再删除远程）：

```
git tag -d v1.0
git push origin :refs/tags/v1.0
```

## 检出tag

tag 本身指向的就是某个 commit，所以和根据 commit_id 检出分支操作类似。

```
git checkout <tagName>
git checkout -b <branchName> <tagName>
```