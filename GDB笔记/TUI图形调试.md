## 命令汇总
|命令|作用|
|---|---|
|gdb -tui|命令行启动TUI|
|tui enable|gdb里启动TUI|
|Ctrl + x + a|快捷键启动TUI|
|focus src/asm/cmd/regs|聚焦到源代码/汇编/命令行/寄存器窗口|
|focus next/prev|聚焦到下个/上个窗口|
|Ctrl + x + o|聚焦到下一个窗口|
|layout src/asm/cmd/regs|显示源代码/汇编/命令行/寄存器窗口|
|layout split|显示源代码和汇编窗口|
|layout next/prev|显示下个/上个窗口|
|tui new-layout name window weight|创建新的TUI窗口布局|
|Ctrl + L|刷新窗口|
|Ctrl + x，再按1|：单窗口模式|
|Ctrl + x，再按2|：双窗口模式|
|info win|显示当前所有窗口的大小
|winheight src/asm/cmd +/-N|源代码/汇编/命令行窗口高度增加/减小N行|
|方向键、page up/down|翻阅当前窗口显示内容|
|ctrl + p/n|浏览上条/下条命令（previous/next）|
|ctrl + f/b|光标前移/后移（forward/back）|
|tui reg general/float/system/vector/all|显示通用/浮点/系统/向量/所有寄存器|
|tui reg next/prev|循环显示上组/下组寄存器|

## TUI启动方式

- 在命令行加-tui参数启动：`gdb -tui`
- 启动gdb后，通过命令启动：`tui enable`
- 启动gdb后，通过快捷键启动：`Ctrl + x + a`

## 窗口聚焦`focus`

- `focus src`：聚焦到源代码窗口

- `focus asm`：聚焦到汇编窗口

- `focus cmd`：聚焦到命令行窗口，此时方向键功能就恢复正常了。

- `focus regs`：聚焦到寄存器窗口

- `focus next/prev`：聚焦到下个/上个窗口

- `Ctrl + x + o`：切换窗口，聚焦到下一个窗口。

  ![tui_focus](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122051312.gif)


## 窗口分割`layout`

- `layout src`：显示源代码窗口

- `layout asm`：显示汇编窗口

- `layout regs`：显示源代码/汇编和寄存器窗口

- `layout split`：显示源代码和汇编窗口

- `layout next`：显示下一个layout

- `layout prev`：显示上一个layout

  ![tui_layout](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122054412.gif)

**快捷键：**

- `Ctrl + L`：刷新窗口，或者使用gdb命令`refresh`
- `Ctrl + x`，再按1：单窗口模式，显示一个窗口
- `Ctrl + x`，再按2：双窗口模式，显示两个窗口

**窗口自定义分割：**

- `tui new-layout name window weight`：创建新的TUI窗口布局，新布局将命名为name，可以使用`layout name`命令切换到新窗口。

> 每个窗口参数要么是要显示的窗口的名称，要么是窗口描述。窗口将按列出的顺序从上到下显示。窗口的名称与焦点命令的名称相同（见下文）；此外，还可以指定状态窗口。请注意，由于其高度固定，因此分配给状态窗口的权重并不重要。这里通常使用“0”。窗口描述看起来有点像对tui新布局的调用，格式为{[-horizontal]window weight[window weight…]}。这将指定子布局。如果给定-horizontal，则本说明中的窗口将并排排列，而不是从上到下排列。每个权重都是一个整数。它是此窗口相对于布局中所有其他窗口的权重。这些数字用于计算每个窗口的屏幕面积。

例如：
(gdb) tui new-layout example src 1 regs 1 status 0 cmd 1
在这里，新布局被称为“示例”。它显示源窗口和注册窗口，然后是状态窗口，最后是命令窗口。非状态窗口都具有相同的权重，因此终端将被分成三个大致相等的部分。

![new-layout1](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122041611.gif)

(gdb) tui new-layout example {-horizontal src 1 asm 1} 2 status 0 cmd 1
这将导致并排的源窗口和程序集窗口；状态和命令窗口位于这些窗口之下，填充了终端的整个宽度。因为它们的权重为2，所以源窗口和集合窗口的高度将是命令窗口的两倍。

![new-layout2](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122041605.gif)

**我个人比较喜欢的分割样式：**

![new-layout3](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122045704.gif)

## 窗口大小调整`winheight`

- `info win`：显示当前所有窗口的大小
- `winheight src/asm/cmd +N`：源代码/汇编/命令行窗口高度增加N行
- `winheight src/asm/cmd -N`：源代码/汇编/命令行窗口高度减小N行

![tui_winheight](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122104273.gif)

## TUI模式下方向键

- `方向键、page up/down`：翻阅当前窗口显示内容
- `ctrl + p/n`：浏览上条/下条命令（previous/next）	
- `ctrl + f/b`：光标前移/后移（forward/back）

## 单键模式`Ctrl + x + s`

进入单键模式后，gdb命令行会有提示，此时输入一个按键就可以进行调试了，gdb内部有些默认的按键映射，用户也可以通过`.inputrc`文件设置键盘映射关系。

|按键|功能|
|---|--|
|c|continue|
|d|down|
|f|finish|
|n|next|
|o|nexti. The shortcut letter ‘o’ stands for “step Over”.|
|q|exit the SingleKey mode.|
|r|run|
|s|step|
|i|stepi. The shortcut letter ‘i’ stands for “step Into”.|
|u|up|
|v|info locals|
|w|where|

如下图，通过`Ctrl + x + s`进入单键模式后，通过按键s进行单步快速调试。

![tui_singlekey](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122106958.gif)

## 寄存器组显示`tui reg`

- `tui reg general/float/system/vector/all`：显示通用/浮点/系统/向量/所有寄存器
- `tui reg next/prev`：循环显示上组/下组寄存器

![tui_reg_reggroup](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122119639.gif)

![tui_regs_next](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122121188.gif)

## 断点状态显示

- `B`：表示该断点已命中
- `b`：表示该断点未命中
- `H`：表示该硬件断点已命中
- `h`：表示该硬件断点未命中
- `+`：表示断点生效中
- `-`：表示断点已失效

![image-20230112211137402](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301122111524.png)


## 其他效果图

![image-20230112163625635](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301121636834.png)


![image-20230112163820303](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301121638461.png)



![image-20230112163927617](https://cdn.jsdelivr.net/gh/HanxuLiu/CDN1/img/2023/202301121639926.png)
