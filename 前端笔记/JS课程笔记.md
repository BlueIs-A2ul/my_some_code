[TOC]



## 函数:

数字的格式化练习:

[点击这里](C:\Users\17383\Desktop\code\ht_css_js\JS\案例练习\数字的格式化练习.html)

> 可以利用下划线分割数字，这是符合es语法规范的

涉及到工具函数的封装

每一个函数内部默认存在一个arguments参数(是一个object类，类数组对象)

这个对象里面包括所有传入函数的参数



作用域范围:

在ES*5*以前只有函数会形成自己的作用域；



在函数内部调用全局变量:

```js
  <script>
    let mm = 'hello world';//全局变量

    function show() {
      let nn = 'rest';//局部变量，这是函数内部的
      //外部变量是相对的，只要不在自己的作用域就是外部变量
      console.log("访问这个mm", mm);
    }

    show();//这里是'hello world'
  </script>
```



代码规范:

```html
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>

<body>
  <script>
    function pow(x, n) {
      let result = 1;

      for (let i = 0; i < n; i++) {
        result *= x;
      }

      return result;
    }

    let x = prompt("x?", "");
    let n = prompt("n?", "");

    if (n < 0) {
      alert("n must be a positive integer");
    } else {
      alert(pow(x, n));
    }
  </script>
</body>

</html>
```



函数表达式:

在JS里面，函数并不是一种神奇的语法结构，而是一种特殊的值

并且在JS里面，函数是被当作头等公民的，这意味着函数可以作为参数，可以作为返回值，赋值给变量或存储在数据结构当中。

[函数表达式](C:\Users\17383\Desktop\code\ht_css_js\JS\案例练习\函数表达式.html)

- 声明是单独语句的函数
- 函数表达式在一个表达式或另一个语法结构中创建的函数

[函数作为参数](C:\Users\17383\Desktop\code\ht_css_js\JS\案例练习\函数作为参数.html)

- 函数式编程就是将函数作为头等公民

立即执行函数:

> 一个函数定义完成后被立即执行，要加括号

```js
  <script>
		(		function fn(){
    console.log("立即执行");
  })
  </script>
```

- 使用场景，实际项目开发的命名冲突，需要函数来实现作用域的避免，还涉及到对象

[事件监听的立即执行 ](C:\Users\17383\Desktop\code\ht_css_js\JS\案例练习\立即执行函数监听.html)(是为了避免var的泄露，用let即可)

```js
(function(fn){
  
}())
```

debug使用:

chrome调试；监听

debugger就是在代码中打断点的方式

恢复是对断点的恢复

F9(单步调试)和F11(进入函数调试)的区别主要在异步函数，涉及到一些浏览器的函数需要用单步调试才能进入函数内部进行查看

## 对象:

```js
let object {
	key: value;
}
```

将函数放在对象中，作为对象的一个属性就叫做方法

```js
let obj1 = {
	name: "hhh";
}

;et obj2 = new object()
obj2.name = "eee";

function Person(){};
let obj3 = new Person()
```

使用delete操作符来删除对象

我们通常使用点来访问，在变量时使用括号来访问

```js
let obj = {
	"teststring": "hhh";
}

let tt = "teststring";
console.log(obj.tt);//不能实现，会去找boj的tt，但实际没有这个成员
console.log(obj[tt]);//可以实现
```

### 对象的遍历

> Object.keys()，返回对象中所有可枚举成员组成的数组

> ​	for(let key in object){
>
> } 有点类似于cpp中 
>
> for(auto ch:x)(获取x中所有ch，auto自动类型)

- 原始类型在栈内存中分配
- 对象类型在堆内存中分配

```js
let m ={};
let n ={};
//m===n是假
```

- 值传递和引用传递

[点击这里有具体示例和解释]("C:\Users\17383\Desktop\code\ht_css_js\AI答疑\值传递和引用传递.txt")

> 简单来说是类似于c/cpp的swap指针处理，在我们不使用&取地址的时候，是只有函数内部的值交换
>
> 但是呢，在js中我们不存在指针的概念，因此就要利用数组和对象来形成这种效果

### this

> 函数中存在一个变量this，除了箭头函数，大多数情况指向一个对象

1. 普通函数被调用，this指向window
2. 函数被对象引用并调用，this指向对象

this会出现绑定问题 具体请见

[点击这里是this]("C:\Users\17383\Desktop\code\ht_css_js\AI答疑\this的绑定问题.txt")

### 创建一系列对象:

```js
function creatObj(name='eee',age=18,hei = 1.88){
	let obj={};
	obj.name = name;
	obj.age = age;
	obj.hei = hei;
	obj.ff = function(){
		console.log("test");
	}
	return obj;
}

let obj1 = creatObj();
let obj2 = creatObj();
let obj3 = creatObj();
```

> 类似于这样的函数就称为工厂函数
>
> 这也是一种设计模式

但是这个对Javascript的OOP模式不够符合

实际上可以

```javascript
function creatObj(name='eee',age=18,hei = 1.88){
	this.name = name;
	this.age = age;
	this.hei = hei;
	this.ff = function(){
		console.log("test");
	}
}
//关键在于new的关键字创建对象
let obj1 = new creatObj();
```

## 类/构造函数:

使用大驼峰命名

```js
function Person(){
}
let pl = new Person()
console.log(pl)//Person类
let tl = new Object()
console.log(tl)//Object类
```

> 浏览器存在全局变量window
>
> 1. 查找变量时，最终会找到window上
> 2. 将全局提供变量/函数/对象，都放在window的对象上面

函数也是对象

[AI答疑点击查看]("C:\Users\17383\Desktop\code\ht_css_js\AI答疑\函数也是对象.txt")

```js
function greet() {
  console.log("Hello, world!");
}

// 给函数添加一个属性
greet.language = "English";

console.log(greet.language); // 输出: English
```

### \__包装类型__

- js的原始类型并非对象类型，从理论上来说，是没有办法获取属性或者调用方法的

> 为什么可以呢？为了可以获取属性和调用方法就封装了对应的包装类型

常见包装类型有:String Number Boolean Symbol Biglnt

方法;toString toFixed parseInt parseFloat

### 查找字符串

- obj.indexOf(searchString,fromIndex)

  搜索到返回索引，否则返回-1

- obj.includes(searchString)

  这是一个布尔函数

- obj.startsWith 

  是否以什么开头

- obj.endsWith

  是否以什么结尾 

## 数组:

### 创建数组的方式

1.一般方法

```js
let names={"john","marry","mark"};

let product = {name:"apples",price:10};

```

2.Array的类方法

```js
let arr1 = new Array();
let arr2 = new Array("mark","banana");
let arr3 = new Array(5);//类似于c中的T arr[5];
```

3.index索引访问

```js
console.log(names[names.lenth-1]);
```

4.修改可以直接修改，新增可以直接新增

```js
// 动态添加元素，类似于 C++ 的 vector.push_back()
arr.push(10); // arr 现在是 [10]
arr.push(20); // arr 现在是 [10, 20]

// 动态删除元素
arr.pop();    // 删除最后一个元素，arr 现在是 [10]
//还可以利用索引和delete直接删除

// 动态插入元素
arr.unshift();//头部添加
arr.shift()//头部删除
arr.splice(0, 0, 50);//添加，删除，替换均可
```

```js
arr.splice(1,2)//从1开始，删除2个元素，添加空
arr.splice(1,0,"why")//从1开始，删除0个元素，添加"why"
arr.splice(1,1,"why")//从1开始，删除1个元素，添加"why"
//实际表现效果就是替换
```

### 遍历数组

```js
for(let i = 0;i < arr.length; i++){
	console.log(arr[i]);
}
```

```js
for(let i in arr){
	console.log(arr[i]);
}

for(let it of arr){
	console.log(it);
}
```

### 数组方法

```js
//语法糖
//如果arr1，arr2都是数组
//push方法形成二维数组，可以这样
arr1.push(...arr2);
//等效于arr1.concat(arr1,arr2);
```



> slice方法截取数组
>
> concat方法拼接数组
>
> join方法插入数组

### 数组中查找元素

1. indexOf查找(不太适用于存储对象的数组)
2. for遍历查找
   find方法(高阶函数，将函数作为自己的参数)查找元素
3. includes方法
4. findIndex查找元素索引(也是高阶函数)

```js
//find方法
//这里students是obj数组
let stu = students.find(function(it){
  if(it.id === id) return ture;
})
//箭头函数
let stu = students.find(item => item.id === id);
```

### 数组的排序

sort(高阶函数，和cpp的.sort方法是类似的)

```js
//stu是一个obj数组
stu.sort(function(item1,item2){
	return item2.age - item1.age;
})
```

## 时间:

### 时间的表示方式

#### 创建Date对象 

```js
let date1 = new Date();//获取当前时间
let date2 = new Date("2022-08-08")//以目标获取时间
let date3 = new Date(2023,10,10,09)//年月日时分秒毫秒
let date4 = new Date(10000004563)//传入Unix时间戳，整数值，从1970年1月1日00:00:00 UTC以来的毫秒数
```

- RFC 2822标准

- ISO 8601标准 YYYY MM DD T(分隔符) HH mm ss .sss Z(时区)

  '2022-05-13T09:15:34.504Z'

> date.toDateString
>
> date.toISOString

> 可以利用date.get的方法获取各种日期时间

但是这里存在时间个位数的问题，所以我们需要将其格式化；涉及到正则表达式一类的处理。

```js
//如何获取时间戳
//1.当前时间戳
let timestamp1 = Date.now();
//date对象
let timestamp2 = date.getTime();
let timestamp3 = date.valueOf();
//Number强转换
console.log(+date);
```

```js
//计算操作花费的时间
let startTime = Date.now();
//一系列操作
let endTime = Date.now();
//做差即是毫秒数
//再将时间戳转为秒数
```

### 时间戳转换
> 最好按照标准来转换

```js
let timestr = "2025-02-08";
//方式一
let date = new Date(timestr);
let timesta = date.getTime();
//方法二
let timesta = Date.parse(timestr);
```

## DOM操作

### 什么是DOM BOM

Document Object Model 操作网页中的对象

Browser Object Model 浏览器对象模型，浏览器提供的用于处理文档之外的所有内容的其他对象

### DOM tree

经由html结构形成的**结构树**

1.DOM元素之间的关系

2.获取DOM元素

3.节点的type tag content

4.DOM节点的attributes，properies

5.节点的创建 插入 克隆 删除

6.DOM节点的样式 类

7.DOM元素的大小滚动坐标

### DOM的整体结构

节点形成的DOM tree

![DOM HTML tree](https://www.runoob.com/wp-content/uploads/2013/09/ct_htmltree.gif)

### 节点和元素的导航

```js
 //获取节点的导航
    let bodyEl = document.body;
    //1.1获取所有子节点
    console.log(bodyEl.childNodes);
    //1.2获取第一个子节点
    let firstChild = bodyEl.firstChild;
    //1.3获取body中的注释
    let commentChild = firstChild.nextSibling;
    console.log(commentChild);
    //1.4获取body父节点
    let parentNode = bodyEl.parentNode;
    console.log(parentNode);
```



[点击这里文档实例](C:\Users\17383\Desktop\code\ht_css_js\JS\DOM相关的API操作\02_网页的对象模型_document对象.html)

table表格的navigator导航

```js
<body>

  <table>
    <thead>
      <tr>
        <th>姓名</th>
        <th>年龄</th>
        <th>身高</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>ww</td>
        <td>ss</td>
        <td>xx</td>
      </tr>
      <tr>
        <td>ee</td>
        <td>dd</td>
        <td>cc</td>
      </tr>
    </tbody>
  </table>

  <script>

    let tableEl = document.body.firstElementChild; //as HTMLTableElement;帮助vscode识别类型


    console.log(tableEl.tHead);
    console.log(tableEl.rows);

    let rwoEl = tableEl.rows[2]; //as HTMLTableRowElement;
    console.log(rwoEl.cells[0]);

  </script>

</body>
```



### 获取元素的方法

熟悉节点的关系，通过父子，兄弟的关系来获取

```js
<body>
  <!-- 这是注释 -->
  这是文本

  <div class="box">测试文字</div>
  <ul>
    <li>1</li>
    <li>2</li>
    <li>3</li>
    <li>4</li>
    <li>5</li>
  </ul>

  <script>

    let bodyEl = document.body;

    //根据body元素去获取子元素(element)
    let childEl = bodyEl.children;
    console.log(childEl);

    //获取box元素
    let boxEl1 = bodyEl.firstElementChild;
    let boxEl2 = bodyEl.children[0];
    console.log(boxEl1 === boxEl2);

    //获取ul元素
    let ulEl = boxEl1.nextElementSibling;
    console.log(ulEl);

    // 获取li元素
    let liEls = ulEl.children;
    console.log(liEls);

  </script>
</body>
```



> 获取任意元素的方法

```js
<body>

  <div class="box">
    <h2>biaoti</h2>
    <div class="container">
      <p>
        这是段落，<span class="keyword">coder</span>，这还是段落
      </p>
    </div>
  </div>

  <script>
    // 获取任意元素对象
    let boxEl = document.body.firstElementChild
    console.log(boxEl); // <div class="box">

    let containerEl = boxEl.lastElementChild;
    console.log(containerEl); // <div class="container">

    let pEl = containerEl.firstElementChild;
    let keywordEl = pEl.lastElementChild;

    keywordEl.style.color = "red"; // 给关键字加红色样式
  </script>

</body>
```

> 这里的小关键在于直接使用**firstChild**等类似方法会导致获取到文本内容；为了保证获得的是节点，这里要使用**firstElementChild**等Element方法

但是这种方法存在说当嵌套过深时获取存在较大难度，毕竟要一层一层往下获取，所以还有

```js
let keywordEl = document.getElementsByClassName("keyword");
    console.log(keywordEl); // <span class="keyword">coder</span>
    keywordEl[0].style.color = "red"; // 给关键字加红色样式
```

> 在这里采用**getElementsByClassName**，直接在body中经由类名来获取元素

这是一个选择器方法

```js
let keywordEl = document.querySelector(".keyword");
let keywordEls = document.querySelectorAll(".keyword");//这里得到的是一个可迭代的对象，所以这里得到的是一个节点
    keywordEl.style.color = "red"; // 给关键字加红色样式
```



| 方法                   |  搜索方式    |  是否可以在元素上调用    |  是否实时    |
| --------------------- | ---- | ---- | ---- |
| querySelector         | CSS-selector     | 可 |      |
| querySelectorAll      |  CSS-selector    | 可 |      |
| getElementById        |  id    |      |      |
| getElementByName      |  name    |      | 是 |
| getElementByTagName   |  tag    | 可 | 是 |
| getElementByClassName |   class   | 可 | 是 |

### Node节点的属性

```js
<body>
  <!-- 我是注释 -->
  我是文本
  <div class="box">我是box</div>


  <script>
    //1.获取三个节点
    let bodyNodeChild = document.body.childNodes;
    let commentNode = bodyNodeChild[0];
    let textNode = bodyNodeChild[1];
    let divNode = bodyNodeChild[2];

    //节点属性
		//nodeName节点的名称
		//tagName针对元素(element)
    console.log(commentNode.nodeType); //8
    console.log(commentNode.nodeName); //#comment
    console.log(commentNode.nodeValue); //我是注释

//date/innerHTML/textContent
//data针对非元素的节点获取数据，textContent获取文本内容，innerHTML获取对应的html元素

  </script>
</body>
```

元素的属性和特性:
全局属性:
hidden

特性:attribute

>   分类：
>
>   *1.HTML标准制定的，称为标准属性*
>
>   *2.自定义的，称为非标准属性*

```js
//elem.hasAttribute(attrName)：判断元素是否有指定属性
    //elem.getAttribute(attrName)：获取元素指定属性的值
    //elem.setAttribute(attrName, value)：设置元素指定属性的值
    //elem.removeAttribute(attrName)：移除元素指定属性
    //attributes，是一个类似数组的对象，包含了元素的所有属性节点
```

属性:对象的属性称property

对于标准的attribute，会在DOM对象上创建对应的property属性

```js
<body>
  <!-- 对象里的属性称property -->
  <!-- 标准的attribute在对应的对象模型中都有对应的property -->
  <div id="myid" class="box">
    我是box
  </div>

  <input type="checkbox" name="" id="" checked>

  <script>

    let boxEl = document.querySelector('.box');

    console.log(boxEl.id);//这里是property，获取的是id属性的值

    let inputEl = document.querySelector('input');
    if (inputEl.getAttribute('checked')) {
      console.log('checked');
    }//但这里实际没有输出,因为get这个方法得到的是空字符串
    if (inputEl.checked) {
      console.log('checked');
    }//这里才是正确的输出,因为checked属性是布尔值

    //attribute和property是相互影响的
    boxEl.id = 'newid';
    console.log(boxEl.getAttribute('id'));

    boxEl.setAttribute('class', 'newclass');
    console.log(boxEl.className);
    //直接设置存在一个优先度
    // boxEl.className = 'newclass2';
    // boxEl.setAttribute('class', 'newclass3');
  </script>
```

[为什么要区分attribute和property]("C:\Users\17383\Desktop\code\ht_css_js\AI答疑\属性与属性.txt")

class的属性;

因为直接对style即样式进行处理实际是一个很麻烦的事情，所以在实际生产过程中，我们经常使用的是对这个元素的类进行增删改的操作

```js
  <script>

    let boxEl = document.querySelector('.box');

    //1.直接修改class属性
    boxEl.className = 'new-class';

    //2.添加class
    boxEl.classList.add('new-class2');

    //3.删除class
    boxEl.classList.remove('new-class');

    //4.切换class,如果不存在就添加，如果存在就删除
    boxEl.classList.toggle('new-class3');

    //5.判断是否存在class
    console.log(boxEl.classList.contains('new-class')); //true
  </script>
```

> classList是一个可迭代对象，可以for循环遍历

对于style，我们有以下的一些操作

```js
 <script>
    // 获取元素
    let boxEl = document.querySelector('.box');

    // 获取元素的样式
    console.log(boxEl.style);//这里得到的是对象
    //并且在这里是小驼峰命名
    //如果设置为空字符串，则会设置html的默认样式

    // 设置元素的样式,重新设置,会导致覆盖
    boxEl.style.cssText = 'background-color: blue; color: white;';
 let boxEl = document.querySelector('.box');
    console.log(boxEl.style.backgroundColor); // red
    console.log(boxEl.style.border); // 读取不到

    console.log(getComputedStyle(boxEl).backgroundColor); // red
    console.log(getComputedStyle(boxEl).border); // 读取到 border: 1px solid black;

  </script>
```

> console.log(boxEl.style.border)，这个方法并不好，不能获取到border的复杂格式，由此我们诞生了getComputedStyle(boxEl).border

### dataset的使用

我们在实际生产中可能会对一些东西进行自己的属性命名，为了查询和使用的方便，我们就有了dataset方法

```js
<body>

  <div class="box">
    <button data-action="remove">移除</button>
    <button data-action="add">追加</button>
    <button data-action="search">搜索</button>
  </div>

  <script>

    let boxEl = document.querySelector('.box');

    boxEl.addEventListener('click', function (event) {
      let target = event.target;
      let action = target.dataset.action;
      console.log(`点击了${action}`);
    });
  </script>
</body>
```

在一个自定义属性前面加上'data-'，这样它就加入了obj.dataset这个对象里面

### 创建插入移除克隆元素

#### 1.创建插入

```js
<script>
    let boxEl = document.querySelector('.box');

    //通过innerHTML创建元素
    //boxEl.innerHTML = '<p class = "aaa" >Hello World</p>';

    //真实创建DOM对象
    let pEl = document.createElement('p');
    pEl.className = 'aaa';
    pEl.classList.add('bbb');
    pEl.textContent = 'Hello World';

    //元素插入boxEl中
    //boxEl.append(pEl);//追加到最后
    //boxEl.prepend(pEl);//插入到最前
    //boxEl.before(pEl);//插入到前面
    //boxEl.after(pEl);//插入到后面
    //boxEl.replaceWith(pEl);//替换

    //插入到两个元素之间
    // let spanEl = document.querySelector('span');//可能会查询到其他span
    // let spanEl = boxEl.children[0];
    // let spanEl = boxEl.querySelector('span');
  </script>
```

#### 2.移除克隆

```js
 //移除方法
    btnEl.addEventListener('click', function () {
      boxEl.remove();//移除自己
    })

    //克隆方法
    cloneBtnEl.addEventListener('click', function () {
      let newnode = boxEl.cloneNode(true);//克隆自己
		//这里的布尔值表示克隆节点还是元素
      boxEl.append(newnode);
    })
```



### 获取 元素/窗口 的大小位置

#### 1.元素方法

```js
<script>

    let boxEl = document.querySelector('.box');

    // 获取元素的宽度和高度
    let boxStyle = getComputedStyle(boxEl);
    console.log(boxStyle.width); // 200px
    console.log(boxStyle.height); // 200px
    console.log(boxEl.clientHeight);// 内容区和内边距宽度
    console.log(boxEl.clientWidth); // 200px

    console.log(boxEl.offsetWidth); // 200// 内容区、内边距和边框宽度
    console.log(boxEl.offsetHeight); // 200

    console.log(boxEl.scrollWidth);
    console.log(boxEl.scrollHeight);// 内容区的完整宽度（包括溢出）


  </script>
```

#### 2.window方法 

[点击有实例](C:\Users\17383\Desktop\code\ht_css_js\JS\DOM相关的API操作\22_窗口_window_大小_滚动信息.html)

```js
<script>

    //包含滚动条
    console.log(window.innerWidth); // 窗口宽度
    console.log(window.innerHeight); // 窗口高度
    //整个窗口,包含调试工具
    console.log(window.outerWidth);
    console.log(window.outerHeight); // 包含滚动条的窗口高度
    //不包含宽度
    console.log(document.documentElement.clientWidth)

    //获取window的滚动区域
    console.log(window.scrollX); // 水平滚动距离
    console.log(window.scrollY); // 垂直滚动距离

    window.onscroll = function () {
      let scrollTop = window.scrollY;
      if (scrollTop > 300) {
        scrollbtn.style.display = 'block';
      } else {
        scrollbtn.style.display = 'none';
      }
    }

    const scrollbtn = document.querySelector('.scrollbtn');

    scrollbtn.addEventListener('click', function () {
      window.scrollTo(0, 0);
    })
  </script>
```



### 实例: 列表创建 倒计时显示

[列表](C:\Users\17383\Desktop\code\ht_css_js\JS\DOM相关的API操作\23_1todo列表的创建.html)

[倒计时](C:\Users\17383\Desktop\code\ht_css_js\JS\DOM相关的API操作\25_倒计时的显示.html)

## 事件处理

Javascript和事件之间的桥梁；

> onclick作为属性存在，再次赋值会覆盖
>
> addEventListener作为方法存在，再次赋值是追加方法

### 事件冒泡捕获：

事件流:当我们对着某一个元素进行点击的时候，不只是对这个元素进行点击

默认情况下是:**从最内层的span向外依次传递的顺序**，这个顺序叫做**事件冒泡**

反之，**从最外层依次向内传递**就是**事件捕获**

当一个事件发生的时候，首先从window出发逐层下降捕获，再逐渐向上去冒泡

但是触发顺序是冒泡

```js
  <script>
    // 1.gettEventListeners()
    let span = document.querySelector('.box span');
    let box = document.querySelector('.box');
    let body = document.querySelector('body');

    // 2.绑定点击事件
    function clickEvent(obj) {
      console.log(obj.innerHTML + '点击事件触发');
    }
    // span.addEventListener('click', clickEvent);
    // box.addEventListener('click', clickEvent);
    // body.addEventListener('click', clickEvent);

    //这里默认是事件冒泡
    // 3.阻止事件冒泡
    span.addEventListener('click', clickEvent, true);
    box.addEventListener('click', clickEvent, true);
    body.addEventListener('click', clickEvent, true);
  </script>
```



### 事件对象event

1.当一个事件发生的时候，会有很多与之相关的信息

如事件类型，点击的哪一个元素，点击的位置

这些信息会被封装到一个event对象中

2.如何获取event对象

对象会在传入的事件处理函数回调时，被系统传入，在回调函数中拿到这个event对象

> .type
>
> .eventPhase

> .offsetX/Y
>
> .clientX/y
>
> .pageX/Y
>
> .screenX/Y

> .target
>
> .currentTarget

```js
//我们可以使用.target和.currentTarget
//这样就可以解决事件流导致的元素不清情况
//.target是实际发生的元素
//.currentTarget是处理事件的元素
```

```js
 divEl.onclick = function (event) {
      console.log('div click');
      console.log(event.type); //事件类型
      console.log(event.eventPhase);
      console.log(event.target); //点击的元素
      console.log(event.currentTarget); //处理事件的元素
   //比如这里我们点击btn，实际触发的是div的事件
   //target返回btn，.currentTarget返回div
      console.log(event.offsetX, event.offsetY);
    }
```

我们在之前接触到了事件冒泡与事件捕获，如果我希望它在某一个部分停止呢？

我们就在这里使用prevent和propagation方法

```js
<script>

    let a = document.querySelector('a');
    //1.阻止默认行为
    a.addEventListener('click', function (event) {
      alert(event.type);
      event.preventDefault();
    });

    //2.阻止事件进一步传递
    let btn = document.querySelector('button');
    let span = document.querySelector('span');
    let box = document.querySelector('.box');

    box.addEventListener('click', function (event) {
      console.log(event.type + 'box捕获');
    }, true);
    span.addEventListener('click', function (event) {
      console.log(event.type + 'span捕获');
      event.stopPropagation();
    }, true);
    btn.addEventListener('click', function (event) {
      console.log(event.type + 'btn捕获');
    }, true);
  </script>
```


事件处理中，我们可能会需要对这个元素本身进行使用，这里我们使用this

```js
<script>

    let btn = document.querySelector('button');
    let div = document.querySelector('div');

    btn.onclick = function () {
      console.log(this); // 输出button元素
    }
    div.onclick = function () {
      console.log(this); // 输出div元素
    }
  </script>
```



### Event_Target使用

> 所有的节点和元素都继承自EventTatget，它作为一个DOM接口，主要用于添加，删除，派发Event事件

- addEventListener
- removeEventListener //使用匿名函数是无法移除的

```js
 <script>
    //实现类似事件总线的功能
    window.addEventListener('test', function () {
      console.log(event.target); // window
    });


    //事件的派发
    setTimeout(function () {
      window.dispatchEvent(new Event('test'));
    }, 3000);
  </script>
```



### 事件委托使用

为了子类的一些效果，我们将事件委托给父类

#### 1.列表委托

例如这里的列表，我们要对li产生效果，但是对每个li都添加函数务必会有负担，所以我们只对ul添加事件

```js
<body>
  <ul>
    <li>1</li>
    <li>2</li>
    <li>3</li>
    <li>4</li>
    <li>5</li>
    <li>6</li>
    <li>7</li>
    <li>8</li>
    <li>9</li>
    <li>10</li>
  </ul>

  <script>

    let liEls = document.querySelectorAll('li');
    const ul = document.querySelector('ul');
    // 1.每一个li都拥有一个自己的函数
    // for (let liEl of liEls) {
    //   liEl.onclick = function () {
    //     this.classList.toggle('active');
    //   };
    // };

    //2.统一在ul中监听
    // let ulEl = document.querySelector('ul');
    // ulEl.onclick = function (event) {
    //   console.log(event.target);
    //   event.target.classList.toggle('active');
    // };

    //3.排他性，只有一个li可以被激活
  </script>

</body>
```



#### 2.btn委托(dataset使用)

类似的，我们有时还可能使用到dataset的方法

```js
<body>

  <div class="box">
    <button data-action="remove">移除</button>
    <button data-action="add">追加</button>
    <button data-action="search">搜索</button>
  </div>

  <script>

    let boxEl = document.querySelector('.box');

    boxEl.addEventListener('click', function (event) {
      let target = event.target;
      let action = target.dataset.action;
      console.log(`点击了${action}`);
    });
  </script>
</body>
```



### 常见的事件

#### 1.鼠标事件

```js
click
contextmenu//右键
dbclick//双击
mousedown//鼠标按下
mouseup//鼠标松开
mouseover//hover支持冒泡
mouseout//支持冒泡
mouseenter//不支持冒泡
mouoseleave//不支持冒泡
//进入子元素依然属于在该元素
mousemove//鼠标移动
```

```js
//这里在讲mouseenter和mouseover
//mouseleave和mouseout
//前面一对不支持冒泡，后面一对支持冒泡
<script>

    let boxEl = document.querySelector('.box');

    boxEl.addEventListener('mouseenter', function () {
      console.log('mouseenter');
    });
    boxEl.addEventListener('mouseleave', function () {
      console.log('mouseleave');
    });


    boxEl.addEventListener('mouseover', function () {
      console.log('mouseover');
    });
    boxEl.addEventListener('mouseout', function () {
      console.log('mouseout');
    });
    //在这里盒子嵌套的情况下
    //第一组只有div盒子被监听了，意思就是子元素并没有被监听
    //是将整个div作为一个被监听的整体

    //第二组div盒子和span都被监听了，在盒子内部，div与span之间发生鼠标移动
    //实际是将div和span分开来看，都被监听，并且span是独立于div的



  </script>
```


```js
<body>

  <div class="box">
    <button>删除</button>
    <button>追加</button>
    <button>搜索</button>
  </div>

  <script>
    let btnEls = document.querySelectorAll('.box button');

    // console.log(btnEls);
    //1.给全部btn事件
    // for (let i = 0; i < btnEls.length; i++) {
    //   btnEls[i].addEventListener('mouseenter', function (event) {
    //     console.log(event.target.innerHTML + '按钮被点击了');
    //   });
    // }
    //2.事件委托，这里用mouseover事件代替mouseenter事件
    //mouseenter没法做事件委托
    let boxEl = document.querySelector('.box');
    boxEl.addEventListener('mouseover', function (event) {
      let target = event.target;
      if (target.tagName.toLowerCase() === 'button') {
        console.log(target.innerHTML + '按钮被点击了');
      }
    });
  </script>
</body>
```



#### 2.键盘事件

[key和code选择谁？]("C:\Users\17383\Desktop\code\ht_css_js\AI答疑\key和code.txt")

> key取决于具体内容，code取决于机械位置

```js
onkeydown//按下
onkeypress//按下
onkeyup//抬起
//down=>press=>up，顺序
event.key/event.code//都可以区分
//key还可以区分大小写
```
```js
  <script>
    let input = document.querySelector('input');
    let button = document.querySelector('button');

    button.addEventListener('click', function () {
      console.log(input.value);
    });

    input.addEventListener('onkeyup', function (event) {
      if (event.keyCode === 13) {
        console.log(input.value);
      }
    });

    //按下s,自动焦点
    document.addEventListener('keydown', function (event) {
      if (event.key === 's') {
        input.focus();
      }
    });
  </script>
```

#### 3.表单事件

```js
onchange//内容改变
oninput//获取输入
onfocus//获取焦点
onblur//失去焦点
onreset//表单重置
onsubmit//表单提交
```
```js
<body>
  <form action="">
    <input type="text" name="" id="">
    <button type="reset"></button>
    <button type="submit"></button>
  </form>


  <script>
    let input = document.querySelector('input');

    //1.获取焦点
    input.onfocus = function () {
      console.log('获取焦点');
    };

    input.onblur = function () {
      console.log('失去焦点');
    };

    //2.输入内容
    input.oninput = function () {
      console.log('输入内容');
    };//只要输入就会发生
    input.onchange = function () {
      console.log('内容改变');
    };//失去焦点才发生

    //3.监听重置
    let resetBtn = document.querySelector('button[type="reset"]');
    resetBtn.onclick = function (event) {
      console.log('重置');
      event.preventDefault(); //阻止默认行为
    };
  </script>
</body>
```

#### 4.Document事件

```js
DOMContentLoaded//内容加载完成时即可
//要区分文档和内容
//这个加载完成的时候还有img
```


CSS事件

#### window定时器

```js
  <script>

    function showTime() {
      console.log('hello world');
    }

    //1.setTimeout()方法，执行一次
    setTimeout(showTime, 1000);
    //2.setInterval()方法，重复执行
    setInterval(showTime, 1000); // 每隔1秒调用一次showTime()函数

    let btn = document.querySelector('button');
    btn.addEventListener('click', function () {
      clearTimeout(timerId); // 取消setTimeout()定时器
    });

  </script>
```

## BOM

我们将BOM看成是连接JS脚本和浏览器的桥梁

### BOM操作

#### window对象

window对象的作用：

```
大量的属性 大量的方法 大量的事件 从EventTarget继承过来的方法
```

```js
  <script>
    //1.window查看角度
    //ES规范:全局对象=>globalThis
    console.log(globalThis === window); //window对象
    //2.补充的方法
    //close只能关闭通过open打开的窗口
    let btn = document.querySelector('.open');
    btn.addEventListener('click', function () {
      window.open('../DOM相关的API操作/vue_btn绑定与监听.html');
    });

    //3.常见的事件
    window.onfocus = function () {
      console.log('窗口获得焦点');
    }
    //hash的改变，前端路由
    window.onhashchange = function () {
      console.log('hash值改变');
    }
  </script>
```

MDN文档符号含义

- 删除符号 点踩符号(不规范兼容问题) 实验符号(兼容问题)

#### location对象

- href
- protocol 协议
- host 主机地址
- hostname 不带端口的主机地址
- port端口
- pathname路径
- search查询字符串
- hash哈希值



- assign赋值一个新的URL，并跳转
- replace打开一个新的URL，并且跳转到该URL中，不会留下之前的记录
- reload重新加载页面，可传入一个Boolean类型

**URLSearchParams**

get 获取参数的值 set 设置一个搜索参数和值 append 追加一个搜索参数和值 

使用encode和uncode编码和解码

```js
//**URLSearchParams**
    let URLSearchParams = "?name=zhangsan&age=18"
    console.log(URLSearchParams.split('&'));
    let searchParams = new URLSearchParams(URLSearchParams);
    console.log(searchParams.get('name')); //zhangsan
    console.log(searchParams.get('age')); //18
```



#### history对象

属性

- length会话中的记录条数
- state保留的状态值

方法

- back forward go pushState replaceState:打开新地址并使用replace

```js
<script>

    // 前端路由的核心，修改URL，但是页面不刷新
    //修改hash值
    //修改history对象

    // 1.对应对象
    console.log(history);
    console.log(history.length);
    console.log(history.state);

    // 2.修改history对象
    let btn = document.querySelector('button');
    btn.addEventListener('click', function () {
      history.pushState('state', 'title', 'url');
      console.log(history.state);
    });

    let back = document.querySelector('.back');
    back.addEventListener('click', function () {
      // history.back();
      // history.forward();
      // history.go(-1);//类似于上面的方法
    });

  </script>
```



#### navigator，screen

navigator对象获取用户的一些数据

#### JSON，Storage

JSON是数据格式，是一种在服务器和客户端之间传输的数据格式。

其他传输格式

XML protobuf

网络数据的传输 环境的配置 非关系性数据库将json作为存储格式

<u>**基本语法**</u>

不包括注释

**<u>简单值</u>**，数字，字符串，布尔，null

**<u>对象值</u>**，由key和value组成，key是字符串，必须双引号，值可以是对象值，简单值，数组值

**<u>数组值</u>**，包含自己和以上

```json
{
  "name": "ceshi",
  "age": 11,
  "func": {
		"name":test,
  }
}
```

序列化

希望将js中的复杂类型转化为json格式得到字符串，方便处理 

```js
<script>
    let obj = {
      name: "John",
      age: 30,
      city: "New York"
    };
    //1.将obj对象序列化
    let jsonStr = JSON.stringify(obj);

    //2.将jsonStr字符串存储到localStorage中
    localStorage.setItem("info", jsonStr);

    //3.反序列化
    let item = localStorage.getItem("info");
    let newobj = JSON.parse(item);
  </script>
```

```js
let str = JSON.stringify(obj, (key, val) => {
      if (key === "age") {
        return val + 10;
      }
    });
```

