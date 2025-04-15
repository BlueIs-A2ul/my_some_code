[TOC]



1. 布局为什么要使用不同的盒子：标签存在一定的语义，合理使用，产品标题就要使用h，大量文字片段就要使用p 
2. 使用margin还是padding：可以混用，但各有优缺点，根据实际情况总有更简单方法实现





# 基础部分

###### 1. 圆角边框

  border-radius: 10px; /* 圆角半径 */
  圆角边框的逻辑是用r=lenth的圆去与每个角相切
  这是一种简写方法，实际后面可以跟四个数据从左上角开始顺时针，左上到右上到右下到左下，每个角的半径可以单独设置，也可以统一设置

###### 2.  盒子阴影

    box-shadow: h-shadow v-shadow blur spread color insert;
    box-shadow: 0 0 10px #888888; /* 阴影的水平偏移量 垂直偏移量 阴影模糊半径 阴影颜色 */
    默认是外阴影，可以设置内阴影，设置inset关键字，设置outset会导致失效
    阴影不属于盒子的一部分，不会导致间距问题

```html
<style>
    div {
        width: 100px;
        height: 100px;
        background-color: #f00;
    }
    div:hover {
        box-shadow: 0 0 10px #888888;
    }
</style>

<body>
    <div>这是一个盒子</div
</body>
```

###### 3.文字阴影

  ```css
  text-shadow: x-offset y-offset blur color;
      text-shadow: 1px 1px 1px #888888; /* 阴影的水平偏移量 垂直偏移量 阴影模糊半径 阴影颜色 */
  ```

  



## 1.css浮动效果

**1.为什么需要浮动：**

`标准流的局限性`，比如多个div放在同一排的间隙问题；同一个盒子中两个盒子的左右对齐

1. `标准流负责竖着排列盒子，浮动可以让盒子横着排列`
2. 先设置盒子大小，再设置盒子的位置

###### 2. 浮动的排列特性：

   选择器{ float: left/right/none; }

​	/* 左右浮动/不浮动 */

​	1.浮动的元素会`脱标`，则会存在一个覆盖的情况
​	动的元素会一行内显示，并且元素`顶部对齐`

​	2.浮动的元素具有`行内块元素`的特性：也就是说原本的display:inline的元素，可以变成display:inline-block的元素，并且可以设置宽高比如		span本身不能设置宽和高，但设置float以后可以设置宽高

**3.为了`约束浮动元素`的位置，我们采取的策略是：**

​	先用标准的父元素排列上下位置，之后内部子元素采取浮动排列左右位置
​	一个元素浮动，理论来说其他兄弟元素也要浮动。浮动的盒子只会影响浮动盒子后面的标准流，不会影响前面的标准流

**4.常见的布局方式：**

​	本质就是`利用css来摆放盒子`:标准，浮动，定位

**5.为什么需要清除浮动：**

​	在实际应用情况下可能会需要不给父盒子的高度，但子盒子浮动后又会影响父盒子高度，导致标准流的问题。这个时候就要清除浮动

###### 5. 清除浮动的方法:

​     选择器{ clear: both/left/right/none; }  几乎只用both

   1. `额外标签法` 隔墙法
      新增一个盒子，但这个盒子必须是块级元素不能是行内元素
   
   2. 父级元素添加`overflow属性` overflow: hidden; 无法显示溢出的部分

   3. 父级元素添加`after伪元素` 额外标签法plus
        ```css
        <style>
        	.clearfix:after {
                content: "";
                display: block;
                height: 0;
                clear: both;
                visibility: hidden;
            }
        	.clearfix {
                <!-- ie6,7专有 -->
                *zoom: 1;
            }
        	</style>
        <div class="clearfix">
        	<div>子元素1</div>
        	<div>子元素2</div> 
        </div>
       ```
   4. 父级元素添加`双伪元素`
        ```css
            .clearfix:before,.clearfix:after {
                content: "";
                display: table;
            }
            .clearfix:after {
                clear: both;
            }
            .clearfix {
                *zoom: 1;
            }
        ```
6. ps插件的切图
    1) 常见的图片格式:
        1) jpg,产品常用
        2) png,支持透明背景
        3) gif,动画效果
        4) psd,ps的专用格式，可以用来切出目标图片，测量像素距离

### 2.css属性的书写顺序：

1) 布局定位属性:display/position/float/clear/visibility
2) 自身属性:width/height/margin/padding/border/backgrounr
3) 文本属性:color/font/text-decoration/text-align
4) 其他属性:content/cursor/box-shadow/text-shadow

### 3.页面布局思路：

1) 确定页面的版心，通过测量得知
2) 分析行模块，以及行模块中的列模块
3) 行模块常用浮动布局，先确定列的大小，再修改列的位置
4) 制作html结构，先有结构，再有样式，结构是主体

### 4.元素塌陷问题:

1.使用margin定义块元素的垂直外边距,可能会出现外边距的合并

2.对于两个嵌套关系的块元素,父元素和子元素同时有上边距,父元素会坍陷较大值的外边距

解决方法:为父元素定义上边框

​					为父元素定义上内边距

​					为父元素添加overflow:hidden



## 1.css定位效果

1) 为什么需要定位：可以实现一个窗口始终显示在屏幕中；部分的浮动因为会在同一排显示完不成目的

2) 定位的组成：定位也是在摆放盒子，按照定位的方式移动
    `定位模式+边偏移`
    1) 定位模式：position：静态定位，相对定位，绝对定位，固定定位
    2) 边偏移：top bottom left right
    
3) 静态定位：默认定位、无定位，标准流

###### 4.相对定位：

移动位置，相对于原来的位置来说：
    选择器 :   { position : relative}，虽然显示的位置变化，但是盒子始终在原本的位置不变，也就是说后面的盒子不会上去，不脱标；
        `因此他并不脱标，主要引用是给绝对定位作父`

###### 5.绝对定位：

​		在移动位置的时候，是相对于它的祖先元素来说的

​		选择器 :   { position : absolute}

1) <strong>如果没有父元素或者父元素没有定位，则以浏览器为基准</strong>
2) <strong>如果祖先元素有定位，则以最近一级有定位的祖先元素为参考点移动位置</strong>
3) <strong>绝对定位不再占有原先的位置</strong>
4) 子绝父相：子级使用绝对定位 父亲就要使用相对定位

**绝对定位的盒子居中算法**：不能通过margin:0 auto来水平居中

​		1.left走50%；2.往回走自己盒子宽度的一半

​		水平居中类似的,top走50%,往上走盒子宽的一半

###### 6.固定定位：
元素固定于浏览器可视区的位置。主要使用场景：在浏览器页面滚动时的元素位置不会改变

选择器 :   {position : fixed}

1) <strong>以浏览器的可视窗口为参照点移动元素,这跟父元素是没有关系的</strong>
2) 不随滚动条滚动的
3) 不再占有原先的位置，也就是会脱标，特殊的绝对定位

固定定位，如何固定在版心右侧：1.先走left的50%，再走margin-left的版心的一半距离;

###### 7.粘性定位：
相对定位和固定定位的混合，选择器 :   { position : sticky;top:10px;}(导航应该可以使用，用来放在顶部)

1) 以浏览器的可视窗口为参照点移动元素
2) **占有原先的位置，不会脱标**
3) 必须添加top left right botton中的一个才有效

| 定位模式 | 是否脱标 |      移动位置      |
| :------: | :------: | :----------------: |
| 静态定位 |    否    |     不适用偏移     |
| 相对定位 |    否    | 相对于自身位置移动 |
| 绝对定位 |    是    |   带有定位的父级   |
| 固定定位 |    是    |    浏览器可视区    |
| 粘性定位 |    否    |    浏览器可视区    |
8.定位的叠放顺序，使用__选择器{z-index：1；}控制盒子的前后次序

###### 9.定位的特殊特性:

  1.行内元素添加绝对或固定定位,可以设置高度和宽度;
  2.块级元素添加绝对或固定定位,如果不给高度和宽度,默认是内容大小
  3.绝对定位会完全压住盒子,浮动元素不同,只会压住下面标准流的盒子,不会压住下面标准流的文字或者图片

## 2.网页布局总结:

大部分html标签是一个盒子,我们通过css浮动定位让每一个盒子排列成为网页

###### 1.标准流:
盒子上下左右排列,垂直的块级盒子显示就用标准流布局

###### 2.浮动:
让多个块级元素一行显示或者左右对齐盒子,多个块级盒子水平显示就用浮动布局

###### 3.定位:
有层叠的概念,让多个盒子前后叠压来显示,如果元素自由在某个盒子内移动就用定位布局



### 3.元素的显示与隐藏:

本质是让一个元素在页面中隐藏或显示出来;

###### :star:1.display显示隐藏:

在display:none表示隐藏对象,与之相反的就是display:block

隐藏元素之后,不会再占有原来的位置,会脱标

###### 2.visibility显示隐藏:

visibility:visible元素可视

visibility:hidden元素隐藏

隐藏元素后,占有原先的位置,不会脱标

###### 3.overflow溢出显示隐藏：

overflow:hidden表示内容溢出隐藏,溢出的内容不会显示,内容会被裁剪

overflow:visible表示内容溢出显示,溢出的内容会显示出来,内容不会被裁剪

overflow:scroll表示内容溢出显示,溢出的内容会显示出来,内容不会被裁剪,可以滚动

overflow:auto,一个自动模板,如果内容过多,显示滚动条;不超出就不显示滚动条

有定位的盒子要慎用隐藏,可能会导致一些显示错误,隐藏掉多余的部分



##### 4.精灵技术:

1.为了避免多次对服务器请求图片,我们将多张小的图片合在同一张图片里面进行请求,这钟图片称为精灵图

2.主要针对背景图片的使用,移动图片位置使用background-position

3.移动目标照片的x轴和y轴

4.一般情况都是从上往左移动,多以数值的负数

5.由上,使用精灵图的时候需要精确测量每一个小背景图片的大小和位置



##### 5.字体图标:

使用场景:主要用于显示网页中通用.常用的一些小图标

精灵图的缺点:图片本身文件大,放大缩小会导致失真,制作完毕再更换非常麻烦

因此出现了字体图标iconfont,展示的是图标,本质上是文字

优点:轻量级,灵活性,兼容性

1.icomoon官网下载需要图案并将fonts引入对应的文件夹

2.在下载的demo文件中打开网页，查看对应的框

3.在style中修改字体:

​		选择器:{font-famliy:'icomoon';}



##### 6.CSS三角的做法：

如果一个盒子的高和宽都是0px，那么此时我们给每一个边的颜色都会是对应的三角形变色。如果我们需要一个三角形，将其他变成透明即可

```css
<style>
div {
	width:0;
  height:0;
  border: 5px solid transparent;<!--宽度任选-->
  位置任选
  border-bottom-color:
}
</style>
```



#### 7.界面样式

###### 1.鼠标样式：

{cursor:pointer}

|   属性值    | 描述     |
| :---------: | -------- |
|   default   | 默认样式 |
|   pointer   | 小手     |
|    move     | 移动     |
|    text     | 文本     |
| not-allowed | 禁止     |

###### 2.表单：

1.去除表单的轮廓线：
input:{ putline:none; }

2.防止文本框的拖拽：
textarea:{resize:none}

###### 3.vertical-align：

实现行内块元素和文字的垂直居中：

可以实现图片和文本的对齐，以及文本域和文本的对齐

vertical-align:baseline | top |middle|bottom

baseline:默认元素放置在父元素基线上

top:将元素顶端与行中最高的元素的顶端对齐

middle:将元素放置在父元素的中部

bottom:将元素顶端与行中最低的元素的顶端对齐

###### 4.图片底部的默认空白缝隙：

原因：行内块元素和文字的基线对齐

解决方法：1.添加vertical-align属性

​					2.将图片转换为行内块元素，display:block

###### 5.溢出的文字省略号表示：

1.单行文本溢出省略号：

```css
<style>
选择器:{
  white-space:nowrap;//强制一行内显示
  overflow:hidden;//超出部分隐藏
  text-overflow:ellipsis;//省略号代替超出部分
}
</style>
```

2.多行文本溢出省略号（兼容性问题）

```css
<style>
选择器:{
  overflow:hidden;//超出部分隐藏
  text-overflow:ellipsis;//省略号代替超出部分
  display:-webkit-box;
  -webkit-line-clamp:2;//限制文本显示的行数
  -webkit-box-orient:vertical;//子元素的排列方式
}
</style>
```



##### 8.布局技巧

###### 1.margin负值的运用：

1.盒子之间的细线边框：

每个盒子都加边框，会有边框的紧贴导致边框距离变大，利用margin负值形成一个覆盖

先执行浮动的紧贴，再依次执行每一个的margin负值，所以看起来貌似每个都走-1，是一个平行效果。但还是能完成目的

另外：如果实现边框的hover变色效果，只需添加position的相对定位即可，因为相对定位会压住标准流。

如果已经在子绝父相的情况下添加了相对定位呢？可以利用z-index来提高层级实现

###### 2.文字围绕浮动元素：

在一个大盒子里面，对需要被围绕的元素加入浮动即可，文字会自动环绕

###### 3.行内块的运用：

在网页的页码选择上的使用

详细请见该文件    [页面导航](C:\Users\17383\Desktop\code\ht_css_js\语法案例\页面导航.html)

###### 4.CSS三角的运用

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <style>
    .box{ 
      width: 0;
      height: 0;
      border-top: 100px solid grey;
      border-bottom: 0px solid greenyellow;
      border-left: 50px solid #f00;
      border-right: 50px solid skyblue;
      /*同时也可以
      border-color： transparent transparent transparent red;
      border： 1px 1px 0 0;
      这里是上右下左的顺序*/
    }
  </style>
</head>
<body>
    <!-- 这样就可以形成一个比较特殊的三角形 -->
  <div class="box"></div>
</body>
</html>
```



###### 5.CSS的初始化

```css
/* 把我们所有标签的内外边距清零 */
* {
    margin: 0;
    padding: 0
}
/* em 和 i 斜体的文字不倾斜 */
em,
i {
    font-style: normal
}
/* 去掉li 的小圆点 */
li {
    list-style: none
}

img {
    /* border 0 照顾低版本浏览器 如果 图片外面包含了链接会有边框的问题 */
    border: 0;
    /* 取消图片底侧有空白缝隙的问题 */
    vertical-align: middle
}

button {
    /* 当我们鼠标经过button 按钮的时候，鼠标变成小手 */
    cursor: pointer
}

a {
    color: #666;
    text-decoration: none
}

a:hover {
    color: #c81623
}

button,
input {
    /* "\5B8B\4F53" 就是宋体的意思 这样浏览器兼容性比较好 */
    font-family: Microsoft YaHei, Heiti SC, tahoma, arial, Hiragino Sans GB, "\5B8B\4F53", sans-serif
}

body {
    /* CSS3 抗锯齿形 让文字显示的更加清晰 */
    -webkit-font-smoothing: antialiased;
    background-color: #fff;
    font: 12px/1.5 Microsoft YaHei, Heiti SC, tahoma, arial, Hiragino Sans GB, "\5B8B\4F53", sans-serif;
    color: #666
}

.hide,
.none {
    display: none
}
/* 清除浮动 */
.clearfix:after {
    visibility: hidden;
    clear: both;
    display: block;
    content: ".";
    height: 0
}

.clearfix {
    *zoom: 1
}
```







# 提高部分

## HTML5部分：

##### 1.新增语义化标签：

在以前布局基本使用div，div对于搜索引擎是没有语义的。因此引入:

\<header> 头部标签  \<nav>导航标签 \<article>内容标签 \<section>定义文档某个区域 \<aside>侧边栏标签 \<footer>尾部标签

这些标签主要是针对搜索引擎

##### 2.新增视频标签：

\<audio>音频标签\<video>视频标签

```html
<video width="320" height="240" controls>
  <source src="movie.mp4" type="video/mp4">
  <source src="movie.ogg" type="video/ogg">
您的浏览器不支持Video标签。
</video>
```

\<video>的常见属性：autopaly，controls，loop，preload，src，poster，muted

\<audio>各种浏览器都支持mp3

```html
<audio controls>
  <source src="horse.ogg" type="audio/ogg">
  <source src="horse.mp3" type="audio/mpeg">
您的浏览器不支持 audio 元素。
</audio>
```

##### 3.新增input标签：

|    属性值    |        说明         |
| :----------: | :-----------------: |
| type="email" | 限制输入类型为email |
|     url      |  限制输入类型为url  |
|     date     | 限制输入类型为日期  |
|     time     | 限制输入类型为时间  |
|    mooth     | 限制输入类型为月份  |
|     week     |  限制输入类型为周   |
|    number    | 限制输入类型为数字  |
|     tel      |      手机号码       |
|    search    |       搜索框        |
|    color     |    颜色选择表单     |

验证的时候要添加form表单域，要有submit提交来检验

##### 4.新增表单属性：

|     属性     | 值        | 说明                                                         |
| :----------: | --------- | ------------------------------------------------------------ |
|   required   | required  | 拥有该属性的不能为空                                         |
| placeholder  | 提示文本  | 表单的提示信息，存在默认值则不显示                           |
|  autofocus   | autofocus | 自动聚焦属性，完成加载自动聚焦到指定表单                     |
| autocomplete | off/on    | 在字段开始键入的时候，基于之前键入过的值，显示出字段中填写的选项。<br />默认是打开的 |
|   multiple   | multiple  | 可以多选文件提交                                             |

```css
input::placeholder{
	color:pink；
    可以修改颜色
}
```

## CSS3部分:

##### 1.新增属性选择器：

| 选择器        | 简介                                  |
| ------------- | ------------------------------------- |
| E[att]        | 选择具有att属性的E元素                |
| E[att="val"]  | 选择具有att属性的E元素，属性值等于val |
| E[att^="val"] | 选择具有att属性的E元素，以val开头     |
| E[att$="val"] | 选择具有att属性的E元素，以val结尾     |
| E[att*="val"] | 选择具有att属性的E元素，含有val元素   |

类选择器，属性选择器，伪类选择器，权重为10

##### 2.结构伪类选择器：

| 选择器           | 简介                          |
| ---------------- | ----------------------------- |
| E:first-child    | 匹配父元素中的第一个子元素E   |
| E:last-child     | 匹配父元素中的最后一个子元素E |
| E:nth-child(n)   | 匹配父元素中的第n个子元素E    |
| E:first-of-type  | 指定类型E的第一个             |
| E:last-of-type   | 指定类型E的最后一个           |
| E:nth-of-type(n) | 指定类型E的第n个              |

这里的n可以是数字，关键词，公式

新增的nth-child原则器:
关键字：even偶数，odd奇数

这里的公式指什么呢如以下图表：

| 公式 |        取值        |
| :--: | :----------------: |
|  2n  |        偶数        |
| 2n+1 |        奇数        |
|  5n  |      5的倍数       |
| n+5  | 从第五个开始到最后 |
| -n+5 | 前五个(包括第五个) |

nth-child:会把所有盒子都排列序号，执行的时候:nth-child(1),再去看前面的类型，例如section div:nth-child(1)

nth-type:会把指定元素的盒子排列序号，先看前面的类型是否满足，再看是第几个孩子

##### 3.伪元素选择器:

帮助我们利用CSS来创建新的标签元素，而不需要HTML标签，从而简化HTML结构

| 选择符   | 简介                     |
| -------- | ------------------------ |
| ::before | 在元素内部的前面插入内容 |
| ::after  | 在元素内部的后面插入内容 |

<ul>
  <li>before和after创建一个元素，但是属于行内元素</li>
  <li>新创建的这个元素，无法再文档树中搜索到</li>
  <li>语法：element::before{}</li>
  <li><strong>before和after必须要有content属性</strong></li>
  <li>before在父元素内容的前面创建元素，after在父元素内容的后面插入元素(位置关系)</li>
  <li>和标签选择器相同，权重为1</li>
</ul>

###### 使用场景1:伪元素字体图标

[点击查看实例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\伪元素实现三角.html)

这里需要注意的是如何icomoon引入新的字体，以及如何使用转义符号来表示我们的字体符号。

使用iomoon的字体要注意首先是引入css，以及更改字体

###### 使用场景2:伪元素实现遮罩层

[点击查看实例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\伪元素实现遮盖.html)

这里为了实现鼠标经过的效果CSS有一个

<p>.tudou:hover::before</p>

###### 使用场景3:伪元素清除浮动

可以算是额外标签法的升级和优化

```css
.clearfix:after {
        content: "";
        display: block;
  		  clear: both;
        height: 0;  
        visibility: hidden;
				/*后两行的目的是让这个盒子不可视*/
    }
```

添加双伪元素:

```css
.clearfix:before,.clearfix:after {
        content: "";
        display: table;
    }
    .clearfix:after {
        clear: both;
    }
```

##### 4.CSS3盒子模型:

CSS3中可以通过box-sizing来指定盒模型，有2个值:即可指定为content-box，border-box，计算盒子大小的方式就发生了变化

1.content-box 盒子大小是width+padding+border(默认的)

2.border-box 盒子大小是width

在第二种情况下，padding和border就不会撑大盒子了

##### 5.其他特性：

###### 1.图片模糊：

使用滤镜filter 可以将模糊或颜色偏移等图形效果应用于元素

filter: 函数() 例如模糊 filter:blur(5px) blur的模糊处理

###### 2.宽度函数：

clac()函数可以在声明属性值的时候进行一些计算

clac(100%-80px) 加减乘除都可以使用

##### 6.CSS3过渡:

我们可以在不使用flash动画或者JS技术的情况下，当元素从一种样式变换为另一种样式时为元素添加效果

经常和:hover一起使用

transition:要过渡的属性 花费时间 运动曲线 何时开始

1.属性，宽度高度，背景颜色，内外边距

2.时间，要求为s

3.曲线，默认为ease

4.开始，默认单位，可以设置延迟触发时间

谁做过渡就给谁加，后面两个可省略，多个属性逗号同时写

[进度条的实例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\过渡实现进度条.html)

##### 7.2D转换:

移动盒子位置:定位 盒子的外边距 2d转换移动

转换(transform)，可以实现元素的位移旋转缩放等效果 

<ul>
  <li>移动:translate
  </li>
  <li>旋转:rotate
  </li>
  <li>缩放:scale
  </li>
</ul>
###### 1.二维坐标系:

2D转换是改变标签在二维平面上的位置和形状的一种技术

###### 2.translate：

类似于定位，改变元素在页面中的位置

```css
transform:translate(x,y);
transform:translateX(n);
transform:translateY(n);
```

<ul>
  <Li>不会影响到其他元素的位置
  </Li>
  <Li>百分比单位是相对于自身元素的宽度或者高度
  </Li>
  <Li>对行内标签没有效果
  </Li>
</ul>

让一个盒子水平垂直居中:
首先利用子绝父相，再利用translate移动

[点击查看](C:\Users\17383\Desktop\code\ht_css_js\语法案例\transform实现盒子居中.html)

###### 3.rotate:

让元素在2d平面内进行顺逆时针的旋转

```css
transform:rotate(度数)
/*度数的单位是deg，
  角度为正时顺时针
	角度为负时逆时针
	默认旋转中心是元素的中心点*/
```

[点击查看图片旋转案例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\图像的旋转.html)

<img src="C:\Users\17383\AppData\Roaming\Typora\typora-user-images\image-20250126125909761.png" alt="image-20250126125909761" style="zoom:33%;" />

[点击查看rotate实现三角](C:\Users\17383\Desktop\code\ht_css_js\语法案例\rotate实现三角.html)

设置中心点:

```
  transform-origin: x y;
```
- 默认转换的中心点是元素的中心点(50% 50%)
- 还可以给x y设置像素或者方位名词(top buttom left right center)

[点击查看案例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\旋转图标.html)

###### 4.scale:

```css
transform:scale(x,y);
```

- x和y用逗号来隔开
- transform:scale(1,1)都放大一倍，相当于没有放大
- transform:scale(x)只写一个参数则认为两个参数取相同的值
- 优势:可以设置转换中心点缩放，默认以中心点缩放的，而且不影响其他盒子

[点击查看图片缩放](C:\Users\17383\Desktop\code\ht_css_js\语法案例\缩放案例.html)

[点击查看分页按钮](C:\Users\17383\Desktop\code\ht_css_js\语法案例\分页按钮.html)

###### 5.综合写法:

同时使用多个转换中间用空格隔开

其顺序会影响转换的效果，先旋转就会改变坐标轴方向

同时有位移和其他属性的时候，要将位移放在最前面

##### 8.CSS动画:

animation，可以通过设置多个节点来精确控制一个或一组动画，常用来实现复杂的动画效果 。

1.动画基本使用:

先定义动画，再调用动画

###### 1.用keyframes定义动画:

```css
@keyframes 动画名称{
	0%{
		width:100px;
	}
	100%{
		width:200px;
	}
}
```

- 0%是动画的开始，100%是动画的完成。这样的规则就是动画序列
- 在@keyframes中规定某项css格式，就能创建由当前样式逐渐改为新样式的动画效果
- 动画是使元素从一种样式逐渐变化为另一种样式的效果。可以改变任意多样式任意多次数
- 使用百分比规定变化发生的事件，或用关键词from和to，等同于0%和100%  

```css
div {
			animation-name: 动画名称;
      animation-duration: 持续时间;
}
```

[点击查看一个动画案例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\动画案例1.html)

[这是一个多个划分序列](C:\Users\17383\Desktop\code\ht_css_js\语法案例\动画案例2.html)

![](C:\Users\17383\Desktop\code\ht_css_js\res\Snipaste_2025-01-26_15-04-10.png)

[这是多属性动画案例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\动画案例3.html)

###### 2.动画简写属性:

animation:动画名称 持续时间 运动曲线 何时开始 播放次数 是否反方向 动画起始或结束的状态

animation: myfirt 5s linear 2s infinite alternate; 

前两个属性一定要写

简写属性里面不包括animation-play-state

想要动画走回来不是跳回来:animation-direction : alternate

结束后停在结束位置:animation-fill-mode:forwards

[热点图案例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\动画案例4.html)

###### 3.速度曲线:

|     值      |              描述              |
| :---------: | :----------------------------: |
|   linear    |              匀速              |
|    ease     |           慢到快到慢           |
|   ease-in   |           以低速开始           |
|  ease-out   |           以低速结束           |
| ease-in-out |        以低速开始和结束        |
|   steps()   | 指定时间函数中的间隔数量即步长 |

[打字机效果实现](C:\Users\17383\Desktop\code\ht_css_js\语法案例\动画案例5.html)

##### 9.3D转换:

###### 1.三维坐标系:

**x水平向右,y垂直向下,z垂直屏幕向外**

常用3D位移和3D旋转

###### 2.3D translate:

```css
transform:translate3d(x,y,z);
```

###### 3.perspective:

要在网页中产生3D效果就需要透视,模拟人类的视觉位置,透视的单位是像素

距离视觉点越近的在电脑平面成像越大,越远就越小

**透视写在被观察元素的父盒子上面**

d:就是视距,视距就是人的眼睛到屏幕的距离

z:就是z轴,物体距离屏幕的距离

```css
perspective: px;
```

###### 4.3D rotate:

```css
transform:rotateX(45deg);
transform:rotateY(45deg);
transform:rotateZ(45deg);
transform:rotate3d(x,y,z,deg);
```

[x轴旋转](C:\Users\17383\Desktop\code\ht_css_js\语法案例\3d旋转1.html)

左手准则:左手拇指指向x轴正方向,其余手指弯曲的方向就是该元素沿着x轴旋转的方向

z轴的旋转, perspective是没有意义的

```css
transform:rotate3d(x,y,z,deg);
```

对于这个语句是形成一个矢量关系,方向不是简单叠加,而是方向的合成.

###### 5.3D呈现transform-style:

控制子盒子是否开启三维立体空间;

代码写给父级,影响子盒子

[点击查看样例](C:\Users\17383\Desktop\code\ht_css_js\语法案例\3d旋转4.html)

[两面翻转盒子](C:\Users\17383\Desktop\code\ht_css_js\语法案例\3d旋转5.html)

##### 服务器:

服务器是提供计算服务的设备，也是一台计算机

web服务器一般指网站服务器

根据在网络中所在位置的不同，又可分为本地服务器和远程服务器 