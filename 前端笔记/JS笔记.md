[TOC]



### 0.js

#### 1.做什么:

1.网页特效
2.表单验证
3.数据交互
4.服务端编程

#### 2.组成:

ECMAScript(语言基础)
Web APIs( DOM + BOM )

### 1.输入输出

#### 1.书写位置

可以写在head部分，更推荐写在body部分，因为有网站的渲染顺序

#### 2.注释和结束符

​	1.//单行 /**/多行

​	2.结束符作为 ;   可写可不写，但是要保证风格的统一

#### 3.输入和输出语法

##### 1.输出语法:

```js
document.write('内容')
```

虽然写在script部分，但可以写入网页body部分

```js
document.write('<h1>内容</h1>')
```

同样可以这样规定输出标签

```js
alert('内容')
```

这是一个警示框

```js
console.log('打印')
```

控制台的输出语法

##### 2.输入语法:

```js
prompt('输入一个文本')
```

弹出一个对话框

```js
var nn
nn = prompt('输入一个数字')
```



#### 4.字面量:

数字字面量 数组字面量 对象字面量



### 2.变量和数据类型

#### 1.变量和赋值:

##### 1.变量的声明:

```js
let nn
```

##### 2.变量的赋值:

```js
various = 2//数字
str = 'ssss' //字符串
```

3.更新变量:

4.声明多个变量:

5.交换变量的值:

无需多言的`swap`函数

##### 6.变量命名的规则和规范:

1.规则:

1.不能用关键字

2.只能用下划线 字母 数字 $组成，且数字不能作为开头

3.严格区分大小写

2.规范

1.起名要有意义

2.驼峰命名法

##### 3.let和var的区别:

var声明:

先使用再声明，可以重复声明(不推荐使用)

#### 2.数组的使用:

```js
let arr = [1,2,3,4,5]//声明
console.log(arr)//打印全部
console.log(arr[0])//打印指定索引元素
console.log(arr.lenth)//打印对应数组的长度
```

#### 3.常量:

```js
const g=9.8//const声明常量
```

常量不允许重新赋值，声明的时候必须初始化

#### 4.1.数据类型:

##### 1.基本数据类型:

number string boolean undefined null

作为弱数据类型语言，只有赋值之后我们才能确认类型

并且不存在如果

```js
let nn;
nn=10;
nn='pink';
```

会报错，Javascript允许这样的语法

##### 2.引用数据类型:

object 

##### 3.NaN:

表示not a number，错误地比如对字符串进行加减乘除的运算会得到这个

并且作为粘性的，对NaN的任何运算还是NaN

##### 4.字符串类型:

可以嵌套，尽量`外单内双`或者`外双内单`

使用转义字符\输出单引号和双引号

使用加号实现字符串的拼接

##### 4.1.模板字符串:

用于拼接字符串和变量

语法`:反引号`，拼接变量时，用`${}`包住变量

例:

```js
document.write(`这是${year}年`)
```

##### 5.布尔类型:

即true和false

##### 6.未定义类型:

一个变量未被赋值就是undefined，经常出现在数据未被传递的时候

##### 7.null类型:

官方解释是将null作为一个尚未创建的对象；

我们可以在创建一个对象的时候，先将他命作null

#### 4.2.检测数据类型

##### 1.控制台输出语句:

##### 2.typeof:

既是运算符也是函数:1.typeof x 2.typeof(x) 常用运算符的写法

##### 4.3.类型转换:

###### 1.为什么需要类型转换:

JavaScript是弱数据类型的，使用表单和prompt获取的数据默认是字符串类型的，此时不能直接进行一些运算

###### 2.隐式转换:

+号旁边有任意一个字符串，就将另一个转换为字符串

除了加号，其他都转化为数字

```js
console.log(2+2);//4
console.log(2+'2');//22
console.log(2-2);//0
console.log(2-'2');//0
```

还可以写＋表示

```js
let nn = +prompt('')
console.log(typeof nn)//应该是Number
```

###### 3.显式转换:

```javascript
let str = '123'
console.log(Number(str))
```

Number(数据) parseInt(整数) parseFloat (浮点数)

以下是一个用户输入与网页互动的实例:
[点击查看](C:\Users\17383\Desktop\code\ht_css_js\实例实践\JS表格互动.html)

### 3.运算符:

#### 1.赋值运算符:

​	= 和 +=

#### 2.自增运算符:

也是一元运算符

依然存在前置自增和后置自增的顺序问题

```js
let x = 10;
let y = ++x; // y = 11, x = 11 (先递增x，然后赋值给y)
console.log(x); // 输出: 11
console.log(y); // 输出: 11

let z = 10;
let w = z++; // w = 10, z = 11 (先赋值z给w，然后递增z)
console.log(z); // 输出: 11
console.log(w); // 输出: 10
```

#### 3.比较运算符:

大于小于一类的是类似的，

特殊的是

==: 左右两边的**值**是否相等(同理的 !=)

===: 左右两边的**值和类型**是否都相等(同理的!==)

```js
let nn =ture;
        (nn == 1) ? console.log("true") : console.log("false");//这里返回true,因为==只关心值是否相同，而我们认为true的值就是1
        (nn === 1)? console.log("true") : console.log("false");//这里返回false,因为===还要考虑类型是否相同，Number和bollean类型的值不同
```

类似的，如果比较2和'2'，在==的时候认为值是相同的，发生隐式转换；在===的时候认为是不同的，因为他们的类型本身是不同的

在对比字母的时候，实际对比的是对应的字符串

#### 4.逻辑运算符及优先级

&& || ! 和C是一样的

##### 优先级:

| 运算符     | 顺序          |
| ---------- | ------------- |
| 小括号     | ()            |
| 一元运算符 | ++ -- !       |
| 算术运算符 | * / % 和 + -  |
| 关系运算符 | > < >= <=     |
| 相等运算符 | == != === !== |
| 逻辑运算符 | 先&& 后\|\|   |
| 赋值运算符 | =             |
| 逗号运算符 | ,             |

### 4.语句:

#### 1.表达式和语句:

表达式是可以求值的代码

语句是一段可执行的代码

#### 2.分支语句:

流程控制结构:1.顺序结构2.分支结构3.循环结构

分支语句包括:if分支 三元运算符 switch语句

##### 1.if语句:

```js
	if(条件1){
    //当条件不是布尔类型时，会隐式转换为布尔类型
    //除了0，所有的数字都是真
    //除了''空字符串，所有的字符串都为真
		代码块
  }else if(条件2){
		另一个代码块
  }else if(条件3){
		另一个代码块
  }
```

##### 2.三元运算符:

```js
(条件) ? 条件为真运行的 : 条件为假运行的
```

```js
let num = 3 > 5 ? 3 : 5 //条件为假，所以num = 5
```

##### 3.switch语句:

```js
switch (expression) {
  case choice1:
    // 运行这段代码
    break;

  case choice2:
    // 否则，运行这段代码
    break;

  // 包含尽可能多的情况

  default:
    // 此外，仅运行这段代码
    break;
}

```

一个 `break` 语句，分号结尾。如果先前的选择与表达式/值匹配，则浏览器在此停止执行代码块，并执行 switch 语句之后的代码

#### 3.循环语句:

##### 1.for循环:

```js
for (initializer; condition; final-expression) {
  // 要运行的代码
}
for(let i = 0 ;i < n ;i++)
```

```js
var cats = ["Bill", "Jeff", "Pete", "Biggles", "Jasmin"];
var info = "My cats are called ";
var para = document.querySelector("p");

for (var i = 0; i < cats.length; i++) {
  info += cats[i] + ", ";
}

para.textContent = info;
```

###### 1.break语句使用案例:

(包含button的监听)

```js
<label for="search">Search by contact name: </label>
<input id="search" type="text" />
<button>Search</button>

<p></p>

const contacts = [
  "Chris:2232322",
  "Sarah:3453456",
  "Bill:7654322",
  "Mary:9998769",
  "Dianne:9384975",
];
const para = document.querySelector("p");
const input = document.querySelector("input");
const btn = document.querySelector("button");

btn.addEventListener("click", function () {
  let searchName = input.value.toLowerCase();
  input.value = "";
  input.focus();
  for (let i = 0; i < contacts.length; i++) {
    let splitContact = contacts[i].split(":");
    if (splitContact[0].toLowerCase() === searchName) {
      para.textContent =
        splitContact[0] + "'s number is " + splitContact[1] + ".";
      break;
    } else if (i === contacts.length - 1) {
      para.textContent = "Contact not found.";
    }
  }
});

```

###### 2.continue语句:

continue 语句以类似的方式工作，而不是完全跳出循环，而是跳过当前循环而执行下一个循环。

以下是一个案例，把数字作为一个输入，并且返回开方后为整数的数字

```js
var num = input.value;

for (var i = 1; i <= num; i++) {
  var sqRoot = Math.sqrt(i);
  if (Math.floor(sqRoot) !== sqRoot) {
    continue;
    //在这里的continue就是跳过了现在的循环而没有执行进一步操作
  }

  para.textContent += i + " ";
}
```

##### 2.while循环:

```js
initializer
while (condition) {
  // 要运行的代码

  final-expression
}
```

##### 3.do...while循环:

```js
initializer
do {
  // 要运行的代码

  final-expression
} while (condition)
```

两者的差别和cpp是类似的，while和for循环总是在代码开始钱进行条件的检查，因此可能一次都不运行；而do…while是在代码运行后才开始检查，因此至少会运行一次。

以下是一个循环案例:
[点击查看](C:\Users\17383\Desktop\code\ht_css_js\语法案例\css的文本属性测试.html)

### 5.函数:

#### 1.函数和方法:

对象的成员函数可以被称为方法

#### 2.调用函数:

```js
function myFunction() {
  alert("你好");
}

myFunction();
// 调用一次该函数
```

#### 3.函数参数:

和c类似的，我们同样是在函数名后加一个括号，在这个括号中去包含我们需要调用的参数

同时，JS支持默认参数，我们可以直接在括号中对参数赋值，如果我们在调用函数时，就可在调用函数时使用默认值

#### 4.匿名函数和箭头函数:

##### 1.匿名函数:

```js
(function () {
  alert("你好");
});
```

以下是一个将函数转换为匿名函数使用的例子:
这里对keydown进行了监听

```js
function logKey(event) {
  console.log(`You pressed "${event.key}".`);
}

textBox.addEventListener("keydown", logKey);
```

```js
textBox.addEventListener("keydown", function (event) {
  console.log(`You pressed "${event.key}".`);
});
```

##### 2.箭头函数:

```js
textBox.addEventListener("keydown", (event) => {
  console.log(`You pressed "${event.key}".`);
});
```

这是不包含返回值即return的情况

如果我们需要使用到与参数直接相关的返回值，可以有如下:

```js
const originals = [1, 2, 3];

const doubled = originals.map(item => item * 2);

console.log(doubled); // [2, 4, 6]
```

运用类似的方法可以简化上面的addEventListener函数:

```js
textBox.addEventListener("keydown", (event) =>
  console.log(`You pressed "${event.key}".`),
);
```

以下是一个函数案例:
[点击查看](C:\Users\17383\Desktop\code\ht_css_js\JS\函数案例.html)

#### 5.函数作用域和冲突:

##### 1.作用域:

当创建一个函数时，函数内定义变量和其他东西都在他们自己的单独的作用域内，这意味着他们被锁在函数中，不能被函数以外的代码访问。

##### 2.冲突:

如果现在有这样的HTML文件:

```js
<!-- Excerpt from my HTML -->
<script src="first.js"></script>
<script src="second.js"></script>
<script>
  greeting();
</script>

// first.js
const name = "Chris";
function greeting() {
  alert(`Hello ${name}: welcome to our company.`);
}

// second.js
const name = "Zaptec";
function greeting() {
  alert(`Our company is called ${name}.`);
}

```

因为两个js文件运用了相同的函数名，所以在调用时，只能访问到第一个函数，第二个函数则被忽略。

以下是一个更加生产化的函数实践，涉及到button的监听与一个div框的产生

[点击查看](C:\Users\17383\Desktop\code\ht_css_js\JS\函数实践.html)

#### 6.返回值:

返回值是指函数执行完毕之后返回的值

主要方法是与C相类似的

### 6.事件:

#### 1.什么是事件:

事件就是你正在编程中的系统发生的事情，当事件发生时，系统产生或触发某种信号，提供一种机制，当事情发生时，可以自动采取一些行动(运行一些代码)



例如:

用户在键盘中按下某个按键

网页结束加载

表单提交



为了对一个事件做出反应，我们要给它附加一个事件处理器。

这是一个有关button的事件处理器

```js
<button>改变颜色</button>

const btn = document.querySelector("button");

function random(number) {
  return Math.floor(Math.random() * (number + 1));
}

btn.addEventListener("click", () => {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  document.body.style.backgroundColor = rndCol;
});
```

[点击在网页中实现](C:\Users\17383\Desktop\code\ht_css_js\JS\事件监听案例.html)

#### 2.使用addEventListener()

正如上文的案例，我们看到触发对象的有一个addEventListener()方法

我们在这里调用addEventListener()函数，传入了两个参数:

<ul>
  <li>字符串 "click"，表示我们要监听点击事件。按钮可以触发很多其他的事件，比如当用户将鼠标移到按钮上时（"mouseover" 事件），或者当用户按下一个键并且按钮被聚焦时（"keydown" 事件）
  </li>
  <li>当事件发生时所调用的函数。在我们的例子中，该函数生成一个随机的 RGB 颜色，并将页面 <body> 的 background-color 设置为该颜色</li>
</ul>

除此以外我们还可以监听除了click以外的一些其他事件:

<ul>
  <li>focus 和 blur：当按钮被聚焦或失焦时，颜色会改变；尝试按下 tab 键来聚焦于按钮，再次按下该键来使按钮失去焦点。这些事件通常用于在聚焦时显示填入表单字段的信息，或者在表单字段填入不正确的值时显示错误信息
  </li>
  <li>dblclick：颜色只在按钮被双击时改变
  </li>
  <li>mouseover 和 mouseout：当鼠标指针在按钮上悬停，或指针移出按钮时，颜色分别会改变
  </li>
</ul>

一些事件，比如点击事件(click)，几乎对任何元素都可用。但对于一些更具体的事件，只在部分情况下有用，例如<video>的paly事件。

#### 3.移除监听器:

如果你使用 `addEventListener()` 添加了一个事件处理器，你可以使用 [`removeEventListener()`](https://developer.mozilla.org/zh-CN/docs/Web/API/EventTarget/removeEventListener) 方法再次删除它。例如，这将删除 `changeBackground()` 事件处理器：

```js
btn.removeEventListener("click", changeBackground);

```

对于简单的小程序，清理旧的、未使用的事件处理器是没有必要的，但对于更大的、更复杂的程序，它可以提高效率。另外，删除事件处理器的能力允许你让同一个按钮在不同的情况下执行不同的动作：你所要做的就是添加或删除处理程序。

在单个事件添加多个监听器:

```js
myElement.addEventListener("click", functionA);
myElement.addEventListener("click", functionB);
```

关于更多addEventListener的机制请点击[这里]([EventTarget.addEventListener() - Web API | MDN](https://developer.mozilla.org/zh-CN/docs/Web/API/EventTarget/addEventListener))

#### 4.事件处理器属性:

例如我们仍然以上面的随机颜色为例子，可以有如下代码:

```js
const btn = document.querySelector("button");

function random(number) {
  return Math.floor(Math.random() * (number + 1));
}

btn.onclick = () => {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  document.body.style.backgroundColor = rndCol;
};
```

在这里出现了`onclick`，也就是说可以触发事件的对象（如按钮）通常也有属性，其名称是 `on`，后面是事件的名称。

也可以将处理器属性分配给一个具名函数

```js
const btn = document.querySelector("button");

function random(number) {
  return Math.floor(Math.random() * (number + 1));
}

function bgChange() {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  document.body.style.backgroundColor = rndCol;
}

btn.onclick = bgChange;
```

但是对于事件处理器属性，就不能添加多个处理程序了，任何的后续尝试都会覆盖较早设置的属性。

#### 5.内联事件处理器--不要使用:

和事件处理器属性类似的，但是我们将其放在HTML部分，也就是

```js
<button onclick="bgChange()">按下我</button>
```

```js
function bgChange() {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  document.body.style.backgroundColor = rndCol;
}
```

但是这会导致一定的维护的难度，并且作为安全措施，很多服务器配置也禁止内联JAVAscript，所以不要使用

#### 6.事件对象:

有时候在事件处理的函数内部，可能会有一个固定指定名称的参数，例如`event`，`evt`，`e`。这些被称为事件对象，它被自动传递给事件处理函数，提供额外的功能和信息。

依旧是随机颜色的实例:

```js
const btn = document.querySelector("button");

function random(number) {
  return Math.floor(Math.random() * (number + 1));
}

function bgChange(e) {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  e.target.style.backgroundColor = rndCol;
  console.log(e);
}

btn.addEventListener("click", bgChange);

```

在这里btn确定了html里面的对象，click确定了function的触发行为，bgChange确定了click这个行为发生后的函数

#### 7.事件对象的额外属性:

大多数事件对象都有一套标准的属性和方法，请参阅 [`Event`](https://developer.mozilla.org/zh-CN/docs/Web/API/Event) 对象参考，以获得完整的列表。

一些事件对象添加了与该特定类型的事件相关的额外属性。例如，[`keydown`](https://developer.mozilla.org/zh-CN/docs/Web/API/Element/keydown_event) 事件在用户按下一个键时发生。它的事件对象是 [`KeyboardEvent`](https://developer.mozilla.org/zh-CN/docs/Web/API/KeyboardEvent)，它是一个专门的 `Event` 对象，有一个 `key` 属性，告诉你哪个键被按下

#### 8.阻止默认行为:

有时候我们会希望事件不执行他的默认行，就比如说提交自定义的注册表单，我们就希望当用户没有正确提交数据的时候，返回给他们错误提示，告诉他们什么做错了，该如何修改。

[表单错误](C:\Users\17383\Desktop\code\ht_css_js\JS\表单错误.html)

事件冒泡:

事件冒泡描述了浏览器如何处理针对嵌套元素的事件

在父元素上设置监听器

```js
<div id="container">
  <button>点我！</button>
</div>
<pre id="output"></pre>

```

这里的button是在div内部的元素，如果我们有如下的js

```js
const output = document.querySelector("#output");
function handleClick(e) {
  output.textContent += `你在 ${e.currentTarget.tagName} 元素上进行了点击\n`;
}

const container = document.querySelector("#container");
container.addEventListener("click", handleClick);

```

我们对于div做的监听器，但实际对button做click也有效果。这是因为div是button的父元素。

冒泡示例:

如果同时添加事件处理器会发生什么?

[点击查看示例](https://developer.mozilla.org/zh-CN/play)

```js
const output = document.querySelector("#output");
function handleClick(e) {
  output.textContent += `你在 ${e.currentTarget.tagName} 元素上进行了点击\n`;
}

const container = document.querySelector("#container");
const button = document.querySelector("button");

document.body.addEventListener("click", handleClick);
container.addEventListener("click", handleClick);
button.addEventListener("click", handleClick);

```

可以注意到，三个元素都触发了单击事件，在这种情况下

- 最先触发button的单击
- 然后是button的父元素div
- 然后是div的父元素body

我们可以这样描述：事件从被点击的最里面的元素冒泡而出

**冒泡修复**

使用stopPropagation()修复问题:

但是这样的特性在一定情况下会导致意想不到的错误所以我们对于event对象有了一个可用函数来防止问题

[问题的产生](https://developer.mozilla.org/zh-CN/play)

```js
const btn = document.querySelector("button");
const box = document.querySelector("div");
const video = document.querySelector("video");

btn.addEventListener("click", () => box.classList.remove("hidden"));

video.addEventListener("click", (event) => {
  event.stopPropagation();
  video.play();
});

box.addEventListener("click", () => box.classList.add("hidden"));

```

在这里我们所做的是在 `<video>` 元素的 `'click'` 事件的处理器中对事件对象调用 `stopPropagation()`。这将阻止该事件向盒子内传递。

事件捕获:

事件传播的另一种形式是事件捕获。这和事件冒泡的顺序是相反的，事件不是先在最内层的目标元素上发生，而是现在最小嵌套元素上发生，然后在连续更多的嵌套元素上发生，直至到达目标。

事件捕获默认是禁用的，需要在 `addEventListener()` 的 `capture` 选项中启用它。

```js
<body>
  <div id="container">
    <button>点我！</button>
  </div>
  <pre id="output"></pre>
</body>

```

```js
const output = document.querySelector("#output");
function handleClick(e) {
  output.textContent += `你在 ${e.currentTarget.tagName} 元素上进行了点击\n`;
}

const container = document.querySelector("#container");
const button = document.querySelector("button");

document.body.addEventListener("click", handleClick, { capture: true });
container.addEventListener("click", handleClick, { capture: true });
button.addEventListener("click", handleClick);

```

在这种情况下，消息出现的顺序发生了颠倒：`<body>` 事件处理器首先触发，然后是 `<div>` 的，最后是 `<button>` 的

事件委托:

事件冒泡特别的是它可以实现事件委托，在这种做法中，当我们想在用户与大量的子元素中的任何一个互动时运行一些代码时，我们在它们的父元素上设置事件监听器，让发生在它们身上的事件冒泡到它们的父元素上，而不必在每个子元素上单独设置事件监听器。

以下是一个案例，我们将一个页面分成十六个区域，点击时切换成随机颜色

```html
<div id="container">
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
  <div class="tile"></div>
</div>

```

```css
.tile {
  height: 100px;
  width: 25%;
  float: left;
}

```

```js
function random(number) {
  return Math.floor(Math.random() * number);
}

function bgChange() {
  const rndCol = `rgb(${random(255)}, ${random(255)}, ${random(255)})`;
  return rndCol;
}

const container = document.querySelector("#container");

container.addEventListener("click", (event) => {
  event.target.style.backgroundColor = bgChange();
});
/*在这里我们可以对每个区域添加单击事件处理器，
但是更简单的选择是在父节点上设置事件处理器，
依靠事件冒泡确保用户点击每个区域时处理程序被执行*/
```

[点击查看](https://developer.mozilla.org/zh-CN/play)

### 7.对象基础:

对象是一个包含相关数据和方法的集合（通常由一些变量和函数组成，我们称之为对象里面的属性和方法）

类似于其他变量的，我们使用const和let来初始化一个对象

```js
const person = {
  name: ["Bob", "Smith"],
  age: 32,
  bio: function () {
    console.log(`${this.name[0]} ${this.name[1]} 现在 ${this.age} 岁了。`);
  },
  introduceSelf: function () {
    console.log(`你好！我是 ${this.name[0]}。`);
  },
};

```

我们可以像下面这样访问这个对象的成员

```js
person.name;
person.name[0];
person.age;
person.bio();
// "Bob Smith 现在 32 岁了。"
person.introduceSelf();
// "你好！我是 Bob。"

```

一个对象由许多成员来组成，每个成员都拥有一个名字。每一组名字/值必须由逗号来隔开。

对象成员的值可以是任意的，前两个数据项被称为对象的属性，后两个允许对象对该数据进行某些操作的函数，被称为对象的方法。

并且在对象的成员是函数是语法更简单，我们可以使用 `bio()` 来代替 `bio: function()`

一个如上所示的对象，称为对象字面量。手动的写出对象的内容来创建一个对象。这不同于从类实例化一个对象。

#### 1.点表示法:

在上面的例子中，我们使用点表示法来访问对象的属性和方法。对象的名字表现为一个命名空间。

##### 子命名空间:

除此以外，我们还可以用一个对象来做另一个对象成员的值，从

```js
const person = {
  name: ["Bob", "Smith"],
};

```

到

```js
const person = {
  name: {
    first: "Bob",
    last: "Smith",
  },
  // …
};

```

需要访问这些属性，只需要链式的再使用一次点表示法。

#### 2.括号表示法:

```js
person.age;//等效于person["age"]
person.name.first;//等效于person["name"]["first"]

```

这看起来很像访问一个数组的元素，并且基本上是相同的——使用关联了值的名称，而不是索引来选择元素。因此对象有时被称为**关联数组**——对象将字符串映射到值，而数组将数字映射到值。

虽然点表示法更加简洁更易于阅读。但是在某些情况下我们必须使用括号。例如，如果对象属性名称保存在变量中，则不能使用点表示法访问。

在下面的示例中，`logProperty()` 函数可以使用 `person[propertyName]` 来检索 `propertyName` 中指定的属性的值。

```js
const person = {
  name: ["Bob", "Smith"],
  age: 32,
};

function logProperty(propertyName) {
  console.log(person[propertyName]);
}

logProperty("name");
// ["Bob", "Smith"]
logProperty("age");
// 32

```

#### 3.设置对象成员:

我们可以通过声明设置或者更新对象成员的值，

```js
person.age = 45;
person["name"]["last"] = "Cratchit";

```

同时，我们还可以利用这种方法创建新的成员

```js
person["eyes"] = "hazel";
person.farewell = function () {
  console.log("再见！");
};

```

括号表示法一个有用的地方是它不仅可以动态的去设置对象成员的值，还可以动态的去设置成员的名字。假设我们想让用户能够通过在两个文本输入框中键入成员名称和值，在他们的人员数据中存储自定义的值类型。我们可以像这样获取这些值：

```js
const myDataName = nameInput.value;
const myDataValue = nameValue.value;
//我们可以像这样把这个新的成员的名字和值加到 person 对象中：
person[myDataName] = myDataValue;
//为了测试它，尝试在你的代码里添加以下几行，就在 person 对象的右花括号的下面：
const myDataName = "height";
const myDataValue = "1.75m";
person[myDa现在，保存并刷新页面，在输入框里输入以下代码：
       taName] = myDataValue;
//现在，保存并刷新页面，在输入框里输入以下代码：
person.height;

```

这是使用点表示法无法做到的，点表示法只能接受字面量的成员的名字，不接受表示名称的变量。

#### 4."this"的含义:

在这个例子中

```js
introduceSelf() {
  console.log(`你好！我是 ${this.name[0]}。`);
}

```

在我们创建多个对象时，this可以让你对每一个创建的对象都使用相同的方法定义

当手工编写对象字面量时，这并不是很有用，但是当我们开始使用**构造函数**从单个对象定义创建多个对象时，这将是必不可少的

#### 5.构造函数:

使用对象字面量在只需要创建一个对象时是可以的，但如果你需要创建多个对象，如前面章节所示，它们就不够用了。我们必须为每个创建的对象编写相同的代码，如果我们想要更改对象的某些属性，比如添加一个 `height` 属性，那么我们必须手动更新每个对象。

我们希望有一种方法来定义对象的“特征”，即方法集和属性集，然后可以创建任意多个对象，只需更新不同属性的值。

```js
function createPerson(name) {
  const obj = {};
  obj.name = name;
  obj.introduceSelf = function () {
    console.log(`你好！我是 ${this.name}。`);
  };
  return obj;
}

```

在这里每次调用这个函数，都会创建并返回一个新对象，该对象具有name属性和introduceSelf() 方法

这可以正常工作，但是显得有些冗长，我们必须创建一个空对象，初始化它，并返回它。更好的办法是构造函数。

构造函数只是使用 `new` 关键字调用的函数。当你调用构造函数时，它将：

- 创建一个新对象
- 将 `this` 绑定到新对象，以便你可以在构造函数代码中引用 `this`
- 运行构造函数中的代码
- 返回新对象

按照惯例，构造函数以大写字母开头，并且以创建对象类型命名。因此，示例重写如下:

```js
function Person(name) {
  this.name = name;
  this.introduceSelf = function () {
    console.log(`你好！我是 ${this.name}。`);
  };
}

```

要使用构造函数就要使用`new`

```js
const salva = new Person("Salva");
salva.name;
salva.introduceSelf();
// "你好！我是 Salva。"

const frankie = new Person("Frankie");
frankie.name;
frankie.introduceSelf();
// "你好！我是 Frankie。"

```

### 8.操作文档:

如果我们想要以某种方式操纵文档结构，就要使用DOM(文档对象模型)

#### 1.web浏览器的重要部分:

##### 窗口:

是载入网页的浏览器标签；在JS中，它由window对象表示。使用这个对象上的方法，你可以返回窗口的大小，操作加载到窗口的文档，在客户端存储文档的数据

##### 导航器:

代表浏览器的状态和身份，用Navigator表示。可以使用这个对象检索用户的首选语言等信息

##### 文档:

是加载到窗口的实际页面，由Document对象表示。可以使用这个对象来返回和操作构成文档的HTML和CSS的信息，例如在DOM中获取一个元素的引用，改变其文本内容，应用新的样式，创建新的元素

##### 文档对象模型:

目前在你的每一个浏览器标签中加载的文档是由一个文档对象模型表示的。这是一个由浏览器创建的“树状结构”表示法，使 HTML 结构能够被编程语言轻松访问

我们可以根据HTML结构生成DOM树状图

在这个树上会生成很多节点:

- 根节点:树中顶层节点，在HTML的情况下，总是一个HTML节点
- 子节点
- 后代节点:位于另一个节点内任意位置的节点
- 父节点:里面有另一个节点的节点
- 兄弟节点:DOM树中位于同一父节点同一等级的节点

#### 2.基本的DOM操作:

在这里我们引入一个html文件

```html
<!DOCTYPE html>
<html lang="en-US">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple DOM example</title>
  </head>
  <body>
      <section>
        <img src="dinosaur.png" alt="A red Tyrannosaurus Rex: A two legged dinosaur standing upright like a human, with small arms, and a large head with lots of sharp teeth.">
        <p>Here we will add a link to the <a href="https://www.mozilla.org/">Mozilla homepage</a></p>
      </section>
  </body>
</html>
```

##### 选择一个元素:

```js
const link = document.querySelector("a");

```

##### 更新一个元素

```js
link.textContent = "Mozilla Developer Network";

```

##### 创建并放置新的节点

- 先获取到父节点的引用:

```js
const sect = document.querySelector("section");

```

- 选择并更新元素:

```js
const para = document.createElement("p");
para.textContent = "We hope you enjoyed the ride.";

```

- 追加元素:

这里我们使用Node.appendChild().方法

```js
sect.appendChild(para);

```

- 添加文本节点:

使用Document.createTextNode()创建文本节点

```js
const text = document.createTextNode(
  " — the premier source for web development knowledge.",
);

```

- 获取引用，附加节点:

```js
const linkPara = document.querySelector("p");
linkPara.appendChild(text);

```

##### 移动和删除元素:

移动:

```js
sect.appendChild(linkPara);

```

删除:

使用Node.removeChild()方法

```js
sect.removeChild(linkPara);

```

或者Element.remove()

```js
linkPara.remove();

```

#### 3.操作样式:

##### 第一种方法:

将内联样式添加到需要动态样式的元素上，通过HTMLElement.style属性实现，

```js
para.style.color = "white";
para.style.backgroundColor = "black";
para.style.padding = "10px";
para.style.width = "250px";
para.style.textAlign = "center";

```

##### 第二种方法:

在\<head>部分添加如下

```css
<style>
  .highlight {
    color: white;
    background-color: black;
    padding: 10px;
    width: 250px;
    text-align: center;
  }
</style>

```

使用Element.setAttribute()方法

```js
para.setAttribute("class", "highlight");

```

Web API简介

什么是API？
应用程序接口（API）是基于编程语言构建的结构，让开发者更容易地创建复杂的功能。它们抽象了复杂的代码，并提供一些简单的接口规则直接使用。

比如说，编程显示3D图形，使用js和py就会比c和cpp更加简单

客户端JS中的API

客户端的JS中有很多可用的API，它们本身并不属于JS语言，但是建立在核心JS语言之上，为使用JS代码提供额外功能

- 浏览器API内置在web浏览器中，能从浏览器和电脑周边环境中提取数据
- 第三方API缺省情况下不会内置于浏览器中，通常必须在 Web 中的某个地方获取代码和信息

JS，API和其他JS工具的关系

- JavaScript——一种内置于浏览器的高级脚本语言，可以用来实现 Web 页面/应用中的功能。注意 JavaScript 也可用于其他像 [Node](https://developer.mozilla.org/zh-CN/docs/Learn_web_development/Extensions/Server-side/Express_Nodejs/Introduction) 这样的编程环境。
- 客户端 API——内置于浏览器的结构程序，位于 JavaScript 语言之上，使你可以更容易的实现功能。
- 第三方 API——置于第三方普通的结构程序（例如 Disqus、Facebook），使你可以在自己的 Web 页面中使用这些平台的某些功能（例如在你的 Web 页面显示 Disqus 评论）。
- JavaScript 库——通常是包含具有[自定义函数](https://developer.mozilla.org/zh-CN/docs/Learn_web_development/Core/Scripting/Functions)的一个或多个 JavaScript 文件，把这些文件关联到你的 Web 页以加快或启用常见的功能的编码。示例包括 jQuery、Mootools 和 React。
- JavaScript 框架——从库开始的下一步，JavaScript 框架（例如 Angular 和 Ember）视图把 HTML、CSS、JavaScript 和其他安装的技术打包在一起，然后用来从头编写一个完整的 Web 应用。库和框架的主要区别在于“控制反转”。调用库中的方法时，开发人员处于控制地位。而框架的控制权则相反：框架调用开发人员的代码。

在主流浏览器中有大量的可用 API，你可以在代码中做许多的事情。参见 [MDN API 索引页](https://developer.mozilla.org/zh-CN/docs/Web/API)。

常见浏览器的API

- 操作文档的API
- 从服务器获取数据的API，用于更新网页的部分而非重新加载整个页面，将使网站或应用程序的相应更加迅速，使用[Fetch API](https://developer.mozilla.org/zh-CN/docs/Web/API/Fetch_API)。
- 绘制和操作图形的API，允许使用在标签canvas编程更新创建2D或者3D场景
- 音频和视频API
- 设备API，允许网页与设备的硬件进行交互，使用地理位置API访问设备的GPS,查找用户的位置
- 客户端存储API

API如何工作？

它们是基于对象的

API 使用一个或多个 [JavaScript 对象](https://developer.mozilla.org/zh-CN/docs/Learn_web_development/Extensions/Advanced_JavaScript_objects)在你的代码中进行交互，这些对象用作 API 使用的数据（包含在对象属性中）的容器以及 API 提供的功能（包含在对象方法中）。
