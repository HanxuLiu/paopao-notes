# vim必备插件汇总

## 插件管理器[vim-plug](https://github.com/junegunn/vim-plug)

![vim-plug示意图](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202308011626461.gif)

### 安装

```shell
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

### 使用

第一步：在配置文件`~/.vimrc`里添加vim-plug：

```
call plug#begin()
" 根据插件名vim-easy-align，获取地址https://github.com/junegunn/vim-easy-align
" Plug 'junegunn/vim-easy-align'
" 根据github地址安装
" Plug 'https://github.com/junegunn/vim-github-dashboard.git'
" 手动安装和更新插件
" Plug '~/my-prototype-plugin'

Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdtree'
Plug 'airblade/vim-gitgutter'

call plug#end()
```

第二步：重新打开vim，通过`:PlugInstall` 安装插件。

### 命令

| 命令               | 介绍              |
| ------------------ | ------------------ |
| `PlugInstall`     | 安装插件                       |
| `PlugUpdate`      | 安装或更新插件                     |
| `PlugClean[!]`    | 删除未列出的插件（bang版本将在没有提示的情况下清理） |
| `PlugUpgrade`     | 升级 vim-plug本身        |
| `PlugStatus`      | 检查插件的状态          |
| `PlugDiff`        | 检查上次更新和挂起的更改 |
| `PlugSnapshot[!] [output path]`     | 生成用于恢复插件当前快照的脚本 |

## 状态栏插件[lightline.vim](https://github.com/itchyny/lightline.vim)

![lightline.vim效果图](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202308020907806.png)

### 安装

推荐通过[vim-plug](https://github.com/junegunn/vim-plug)插件管理器安装。

第一步：在`~/.vimrc`里添加 `lightline.vim`插件：

```
Plug 'itchyny/lightline.vim'
```

第二步：在vim窗口里通过命令`:PlugInstall`安装。

### 使用

在`~/.vimrc`里开启vim配置：

```
"----配置lightline状态栏----
set laststatus=2
" 开启256配色
if !has('gui_running')
  set t_Co=256
endif
" 关闭状态栏模式显示
"set noshowmode
" 设置为wombat配色
let g:lightline = {'colorscheme': 'wombat', }
"--------------------------
```

## 目录树插件[nerdtree](https://github.com/preservim/nerdtree)

![nerdtree效果图](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202308020943726.png)

### 安装

推荐通过[vim-plug](https://github.com/junegunn/vim-plug)插件管理器安装。

第一步：在`~/.vimrc`里添加 `nerdtree`插件：

```
Plug 'preservim/nerdtree'
```

第二步：在vim窗口里通过命令`:PlugInstall`安装。

### 命令

|命令|描述|
|---|---|
| :NERDTree | 打开目录树 |
| ？ | 查看快捷键映射 |
| :help NERDTree | 查看详细文档 |

### 快捷键

```
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>
```

## git状态显示插件[vim-gitgutter](https://github.com/airblade/vim-gitgutter)

vim-gitgutter作用是在符号列中显示git diff信息，包括添加、修改或删除的代码行。

![vim-gitgutter效果图](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202308021030436.png)

![自定义配置](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202308021039598.png)

### 安装


推荐通过[vim-plug](https://github.com/junegunn/vim-plug)插件管理器安装。

第一步：在`~/.vimrc`里添加 `vim-gitgutter`插件：

```
Plug 'airblade/vim-gitgutter'
```

第二步：在vim窗口里通过命令`:PlugInstall`安装。

### 使用

显式关闭和打开 vim-gitgutter（默认为 on）：

- 关闭 `:GitGutterDisable`
- 打开 `:GitGutterEnable`
- 切换 `:GitGutterToggle` 

要切换每个缓冲区的 vim-gitgutter：

- 关闭 `:GitGutterBufferDisable`
- 打开`:GitGutterBufferEnable`
- 切换`:GitGutterBufferToggle`

打开和关闭标志（默认为打开）：

- 打开`:GitGutterSignsEnable`
- 关闭 `:GitGutterSignsDisable`
- 切换 `:GitGutterSignsToggle` 

打开和关闭行突出显示（默认为关闭）：

- 打开 `:GitGutterLineHighlightsEnable`
- 关闭 `:GitGutterLineHighlightsDisable`
- 切换 `:GitGutterLineHighlightsToggle` 
