[TOC]



# ES6

## 1.let和const

### 1.let的使用

#### 基本用法

ES6中新增let来声明变量，与var相比，let存在作用域，只会在代码块中生效。出于这个机制，我们可以很简单的解决for循环中`var i = 0`的声明问题

#### 不存在变量提升

var声明的变量，可以在声明以前使用，这是不符合我们预期的，而let不存在这样的问题

#### 暂时性死区

只要块级作用域内存在`let`命令，它所声明的变量就“绑定”（binding）这个区域，不再受外部的影响。

所以当你使用let的时候，就会产生一个区块，如果你在这个区块以前使用这个变量，那么就会报错。我们称这种情况叫做`暂时性死区`。这可以帮助我们养成良好的编程习惯

总之，暂时性死区的本质就是，只要一进入当前作用域，所要使用的变量就已经存在了，但是不可获取，只有等到声明变量的那一行代码出现，才可以获取和使用该变量。

#### 不允许重复声明

let不允许在相同的作用域内重复声明相同的变量

### 2.块级作用域

#### 为什么需要它？

ES5只有全局作用域和函数作用域，没有块级作用域。这带来很多不合理的场景。

1. 内层变量可能覆盖外层变量

   ```javascript
   var tmp = new Date();
   
   function f() {
     console.log(tmp);
     if (false) {
       var tmp = 'hello world';
     }
   }
   
   f(); // undefined
   ```

2. 用来计数的循环变量泄露为全局变量

   ```javascript
   var s = 'hello';
   
   for (var i = 0; i < s.length; i++) {
     console.log(s[i]);
   }
   
   console.log(i); // 5
   ```



#### ES6的块级作用域

let实际上为JS新增了块级作用域，

```javascript
function f1() {
  let n = 5;
  if (true) {
    let n = 10;
  }
  console.log(n); // 5
}
```

<font color = '#7acebe'>块级作用域的出现，实际上使得获得广泛应用的匿名立即执行函数表达式（匿名 IIFE）<font size = '4px' color ='#df7f12'>不再必要了。</font></font>

```javascript
// IIFE 写法
(function () {
  var tmp = ...;
  ...
}());

// 块级作用域写法
{
  let tmp = ...;
  ...
}
```

#### 块级作用域和函数声明

函数能不能在块级作用域之中声明？

在ES5来说，这是非法的

ES6 引入了块级作用域，明确允许在块级作用域之中声明函数。ES6 规定，块级作用域之中，函数声明语句的行为类似于`let`，在块级作用域之外不可引用。

```javascript
function f() { console.log('I am outside!'); }

(function () {
  if (false) {
    // 重复声明一次函数f
    function f() { console.log('I am inside!'); }
  }

  f();
}());
```

报错的这是

> Uncaught TypeError: f is not a function
>     at \<anonymous>:9:3
>     at \<anonymous>:10:2

原来，如果改变了块级作用域内声明的函数的处理规则，显然会对老代码产生很大影响。为了减轻因此产生的不兼容问题，ES6 在[附录 B](http://www.ecma-international.org/ecma-262/6.0/index.html#sec-block-level-function-declarations-web-legacy-compatibility-semantics)里面规定，浏览器的实现可以不遵守规定，有自己的[行为方式](http://stackoverflow.com/questions/31419897/what-are-the-precise-semantics-of-block-level-functions-in-es6)。

- 允许在块级作用域内声明函数。
- 函数声明类似于`var`，即会提升到全局作用域或函数作用域的头部。
- 同时，函数声明还会提升到所在的块级作用域的头部。

必须要提到的是，ES6的块级作用域必须有大括号，如果没有大括号，引擎就认为不存在块级作用域。

并且在严格模式下，函数只能声明在当前定义域的顶层

### 3.const命令

#### 基本用法

const声明一个只读的变量，并且一旦声明，常量的值就是不能改变的。

存在这个特性的情况，const的变量就必须在声明的同时赋值，同时类似于let的，const也存在作用域

#### 本质

const实际上保证的，不是变量的值不能改动，而是变量指向的内存地址保存的数据，不能改动

对于复合类型的数据（主要是对象和数组），变量指向的内存地址，保存的只是一个指向实际数据的指针，`const`只能保证这个指针是固定的（即总是指向另一个固定的地址）

所以就会有以下的诡异情况

```javascript
const a = [];
a.push('Hello'); // 可执行
a.length = 0;    // 可执行
a = ['Dave'];    // 报错
```

如果真的想将对象冻结，就应该使用`Object.freeze`方法。

#### ES6 声明变量的六种方法

ES5 只有两种声明变量的方法：`var`命令和`function`命令。ES6 除了添加`let`和`const`命令，后面章节还会提到，另外两种声明变量的方法：`import`命令和`class`命令。所以，ES6 一共有 6 种声明变量的方法。

### 4.顶层对象的属性

这个顶层对象指window，

ES5 之中，顶层对象的属性与全局变量是等价的。

`顶层对象的属性与全局变量挂钩，被认为是 JavaScript 语言最大的设计败笔之一。`

为什么呢？

1. 没法在编译时就报出变量未声明的错误，只有运行时才能知道（因为全局变量可能是顶层对象的属性创造的，而属性的创造是动态的）
2. 程序员很容易不知不觉地就创建了全局变量（比如打字出错）
3. 顶层对象的属性是到处可以读写的，这非常不利于模块化编程

ES6 为了改变这一点

一方面规定，为了保持兼容性，`var`命令和`function`命令声明的全局变量，依旧是顶层对象的属性；

另一方面规定，`let`命令、`const`命令、`class`命令声明的全局变量，不属于顶层对象的属性。也就是说，从 ES6 开始，全局变量将逐步与顶层对象的属性脱钩。

### 5.globalThis对象

JavaScript 语言存在一个顶层对象，它提供全局环境（即全局作用域），所有代码都是在这个环境中运行。但是，顶层对象在各种实现里面是不统一的。

同一段代码为了能够在各种环境，都能取到顶层对象，现在一般是使用`this`关键字，但是有局限性。



## 2.变量的解构赋值

### 1.数组的解构赋值

#### 基本用法

ES6 允许按照一定模式，从数组和对象中提取值，对变量进行赋值，这被称为解构（Destructuring）。

有了解构以后我们可以这样；

```javascript
let [a, b, c] = [1, 2, 3];
```

来代替这样

```javascript
let a = 1;
let b = 2;
let c = 3;
```

本质上，这种写法属于“模式匹配”，只要等号两边的模式相同，左边的变量就会被赋予对应的值。下面是一些使用嵌套数组进行解构的例子。

```javascript
let [foo, [[bar], baz]] = [1, [[2], 3]];
foo // 1
bar // 2
baz // 3

let [ , , third] = ["foo", "bar", "baz"];
third // "baz"

let [x, , y] = [1, 2, 3];
x // 1
y // 3

let [head, ...tail] = [1, 2, 3, 4];
head // 1
tail // [2, 3, 4]

let [x, y, ...z] = ['a'];
x // "a"
y // undefined
z // []
```

如果解构不成功，变量的值就等于`undefined`。

事实上，只要某种数据结构具有 Iterator 接口，都可以采用数组形式的解构赋值。

```javascript
function* fibs() {
  let a = 0;
  let b = 1;
  while (true) {
    yield a;
    [a, b] = [b, a + b];
  }
}

let [first, second, third, fourth, fifth, sixth] = fibs();
sixth // 5
```

在这里的fibs函数作为生成器，原生就是迭代的对象

#### 默认值

解构赋值允许指定默认值。

```js
let [foo = true] = [];
foo // true

let [x, y = 'b'] = ['a']; // x='a', y='b'
let [x, y = 'b'] = ['a', undefined]; // x='a', y='b'
```

但是ES6使用严格相等符号去判定一个位置是否有值，所以只有严格等于undefined才会采取默认值

换句话说，如果定义为null，是自然而然不会采取默认值的

如果默认值是一个表达式，那么这个表达式是惰性求值的，即只有在用到的时候，才会求值。

```javascript
function f() {
  console.log('aaa');
}

let [x = f()] = [1];
```

但实际这里f()并不会触发

默认值可以引用解构赋值的其他变量，但该变量必须已经声明。

```javascript
let [x = 1, y = x] = [];     // x=1; y=1
let [x = 1, y = x] = [2];    // x=2; y=2
let [x = 1, y = x] = [1, 2]; // x=1; y=2
let [x = y, y = 1] = [];     // ReferenceError: y is not defined
```

上面最后一个表达式之所以会报错，是因为`x`用`y`做默认值时，`y`还没有声明。也就是暂时性死区

### 2.对象的解构赋值

解构不止可以用于数组，还可以用于对象

和数组不同的是，对象的解构赋值，可以不按次序来。它是按照key来赋值的。

如果解构失败，默认的value是undefined



对象的解构赋值，可以很方便地将现有对象的方法，赋值到某个变量。

```javascript
// 例一
let { log, sin, cos } = Math;

// 例二
const { log } = console;
log('hello') // hello

//有了这个，我们就不必再Math.sin()，而是可以直接sin()。
//有点类似于using namespace ?
```



如果变量名与属性名不一致，必须写成下面这样。

```javascript
let { foo: baz } = { foo: 'aaa', bar: 'bbb' };
baz // "aaa"

let obj = { first: 'hello', last: 'world' };
let { first: f, last: l } = obj;
f // 'hello'
l // 'world'
```

也就是说，对象的解构赋值的内部机制，是先找到同名属性，然后再赋给对应的变量。真正被赋值的是后者，而不是前者。

```javascript
let { foo: baz } = { foo: 'aaa', bar: 'bbb' };
baz // "aaa"
foo // error: foo is not defined
```

上面代码中，`foo`是匹配的模式，`baz`才是变量。真正被赋值的是变量`baz`，而不是模式`foo`。

> 在 JavaScript 的对象解构赋值中，语法 `{ 属性名: 变量名 }` 表示将对象的某个属性值赋给一个**新变量**，而非直接使用属性名作为变量名。这是对象解构语法中常见的误解点，需要特别注意。

> - `{ foo: baz }` 表示：
>   - 从右侧对象中找到 `foo` 属性。
>   - 将 `foo` 的值赋给变量 `baz`。
> - 此时，`baz` 是变量名，`foo` 是对象属性名。

与数组一样，解构也可以用于嵌套结构的对象。

```javascript
let obj = {
  p: [
    'Hello',
    { y: 'World' }
  ]
};

let { p: [x, { y }] } = obj;
x // "Hello"
y // "World"
```

但是在这里p是模式不是变量，如果要将p作为变量赋值，应该写成

```javascript
let obj = {
  p: [
    'Hello',
    { y: 'World' }
  ]
};

let { p, p: [x, { y }] } = obj;
x // "Hello"
y // "World"
p // ["Hello", {y: "World"}]
```



注意，对象的解构赋值可以取到继承的属性。

```javascript
const obj1 = {};
const obj2 = { foo: 'bar' };
Object.setPrototypeOf(obj1, obj2);

const { foo } = obj1;
foo // "bar"
```

上面代码中，对象`obj1`的原型对象是`obj2`。`foo`属性不是`obj1`自身的属性，而是继承自`obj2`的属性，解构赋值可以取到这个属性。



#### 默认值

和数组的解构赋值一样都可以指定默认值，生效条件是属性值严格等于undefined

```javascript
var {x = 3} = {x: undefined};
x // 3

var {x = 3} = {x: null};
x // null
```



#### 注意点

1. 对于一个已经声明的变量，用于解构赋值时，必须在最外面添加括号，防止引擎将其理解为代码块

   ```javascript
   // 正确的写法
   let x;
   ({x} = {x: 1});
   ```

2. 由于数组本质是特殊的对象，因此可以对数组进行对象属性的解构。
    ```javascript
   let arr = [1, 2, 3];
   let {0 : first, [arr.length - 1] : last} = arr;
   first // 1
   last // 3



### 3.字符串的解构赋值

字符串也可以解构赋值。这是因为此时，字符串被转换成了一个类似数组的对象。

```javascript
const [a, b, c, d, e] = 'hello';
a // "h"
b // "e"
c // "l"
d // "l"
e // "o"
```

类似数组的对象都有一个`length`属性，因此还可以对这个属性解构赋值。

```javascript
let {length : len} = 'hello';
len // 5
```



### 4.数值和布尔值的解构赋值

解构赋值时，如果等号右边是数值和布尔值，则会先转为对象。

```javascript
let {toString: s} = 123;
s === Number.prototype.toString // true

let {toString: s} = true;
s === Boolean.prototype.toString // true
```

上面代码中，数值和布尔值的包装对象都有`toString`属性，因此变量`s`都能取到值。

解构赋值的规则是，

<font color = '#aa5550'>只要等号右边的值不是对象或数组，就先将其转为对象。</font>

由于`undefined`和`null`无法转为对象，所以对它们进行解构赋值，都会报错。

```javascript
let { prop: x } = undefined; // TypeError
let { prop: y } = null; // TypeError
```

### 5.函数参数的解构赋值

函数的参数也可以使用解构赋值。

```javascript
function add([x, y]){
  return x + y;
}

add([1, 2]); // 3
```

这里虽然传入的数组，但实际效果就是传入不同参数

下面是另一个例子。

```javascript
[[1, 2], [3, 4]].map(([a, b]) => a + b);
// [ 3, 7 ]
//可以等同于上文的函数匿名后处理
```

函数参数的解构也可以使用默认值。

```javascript
function move({x = 0, y = 0} = {}) {
  return [x, y];
}

move({x: 3, y: 8}); // [3, 8]
move({x: 3}); // [3, 0]
move({}); // [0, 0]
move(); // [0, 0]
```

上面代码中，函数`move`的参数是一个对象，通过对这个对象进行解构，得到变量`x`和`y`的值。如果解构失败，`x`和`y`等于默认值。

注意，下面的写法会得到不一样的结果。

```javascript
function move({x, y} = { x: 0, y: 0 }) {
  return [x, y];
}

move({x: 3, y: 8}); // [3, 8]
move({x: 3}); // [3, undefined]
move({}); // [undefined, undefined]
move(); // [0, 0]
```

上面代码是为函数`move`的参数指定默认值，而不是为变量`x`和`y`指定默认值，所以会得到与前一种写法不同的结果。

`undefined`就会触发函数参数的默认值。

```javascript
[1, undefined, 3].map((x = 'yes') => x);
// [ 1, 'yes', 3 ]
```

### 6.圆括号问题

解构赋值虽然方便，但是解析却不容易，一个式子到底是模式还是表达式，一开始不能知道

由此带来的问题是，如果模式中出现圆括号怎么处理。ES6 的规则是，**只要有可能导致解构的歧义，就不得使用圆括号。**

但是在实践中，只要可以，我们就一律不放置括号

1. 变量声明语句不能使用圆括号
2. 函数参数不能使用圆括号
3. 赋值语句的模式

可以使用圆括号的情况只有一种：赋值语句的非模式部分，可以使用圆括号

```javascript
[(b)] = [3]; // 正确
({ p: (d) } = {}); // 正确
[(parseInt.prop)] = [3]; // 正确
```

### 7.用途

#### 1.交换变量的值

```、javascript
let x = 1;
let y = 2;

[x, y] = [y, x];
```

#### 2.从函数返回多个值

```javascript
// 返回一个数组

function example() {
  return [1, 2, 3];
}
let [a, b, c] = example();

// 返回一个对象

function example() {
  return {
    foo: 1,
    bar: 2
  };
}
let { foo, bar } = example();
```

众所周知，JSreturn只能返回一个参数，所以我们采取数组和对象返回多个值，这个时候用解构来获取这些值就很方便

#### 3.函数参数的定义

```javascript
// 参数是一组有次序的值
function f([x, y, z]) { ... }
f([1, 2, 3]);

// 参数是一组无次序的值
function f({ x, y, z }) {
  console.log(`x=${x}, y=${y}, z=${z}`);
}
f({ x: 1, z: 4, y: 3 });//x=1, y=3, z=4
```

#### 4.提取JSON的数据

```javascript
let jsonData = {
  id: 42,
  status: "OK",
  data: [867, 5309]
};

let { id, status, data: number } = jsonData;
//这里同样可以乱序
console.log(id, status, number);
// 42, "OK", [867, 5309]
```

#### 5.函数的参数的默认值

```javascript
jQuery.ajax = function (url, {
  async = true,
  beforeSend = function () {},
  cache = true,
  complete = function () {},
  crossDomain = false,
  global = true,
  // ... more config
} = {}) {
  // ... do stuff
};
```

避免了大量的默认值写法

#### 6.遍历MAP结构

任何可迭代的对象，都可以用for of循环来遍历，map原生就是可迭代的，所以

```javascript
const map = new Map();
map.set('first', 'hello');
map.set('second', 'world');

for (let [key, value] of map) {
  console.log(key + " is " + value);
}
```

## 4. 字符串的扩展

### 1.字符的Unicode表示

ES6加强了对Unicode的支持，允许使用`\uxxxxx`形式来表示字符，xxxx表示字符的码点

但是，这种表示法只限于码点在`\u0000`~`\uFFFF`之间的字符。超出这个范围的字符，必须用两个双字节的形式表示。

***

ES6 对这一点做出了改进，只要将码点放入大括号，就能正确解读该字符。

```javascript
"\u{20BB7}"
// "𠮷"

"\u{41}\u{42}\u{43}"
// "ABC"

let hello = 123;
hell\u{6F} // 123

'\u{1F680}' === '\uD83D\uDE80'
// true
```



有了这种表示法之后，JavaScript 共有 6 种方法可以表示一个字符。

```javascript
'\z' === 'z'  // true
'\172' === 'z' // true
'\x7A' === 'z' // true
'\u007A' === 'z' // true
'\u{7A}' === 'z' // true
```

### 2.字符串的遍历

根据原型链，字符串自然是一个对象，就可以迭代。即使用`for of`方法，这个比起一般的for()方法好在哪里呢？

这个方法可以识别大于`0xFFFF`的码点，传统的`for`循环无法识别这样的码点。

### 3.字符的转义

但是，JavaScript 规定有5个字符，不能在字符串里面直接使用，只能使用转义形式。

- U+005C：反斜杠（reverse solidus)
- U+000D：回车（carriage return）
- U+2028：行分隔符（line separator）
- U+2029：段分隔符（paragraph separator）
- U+000A：换行符（line feed）

举例来说，字符串里面不能直接包含反斜杠，一定要转义写成`\\`或者`\u005c`。

### 4.JSON.stringify()的改造

根据标准，JSON 数据必须是 UTF-8 编码。但是，现在的`JSON.stringify()`方法有可能返回不符合 UTF-8 标准的字符串。

为了确保返回的是合法的 UTF-8 字符，ES2019改变了`JSON.stringify()`的行为。如果遇到`0xD800`到`0xDFFF`之间的单个码点，或者不存在的配对形式，它会返回转义字符串，留给应用自己决定下一步的处理。

```javascript
JSON.stringify('\u{D834}') // ""\\uD834""
JSON.stringify('\uDF06\uD834') // ""\\udf06\\ud834""
```

### 5.模板字符串

为了避免一些写法上的不便，ES6引入了模板字符串

**模板字符串**（template string）是增强版的字符串，用反引号（`）标识。它可以当作普通字符串使用，也可以用来定义多行字符串，或者在字符串中嵌入变量。

为了避免歧义，正常使用反引号要使用反斜杠转义

并且如果使用模板字符串表示多行字符串，所有的空格和缩进都会被保留在输出之中。

如果大括号中的值不是字符串，将按照一般的规则转为字符串。比如，大括号中是一个对象，将默认调用对象的`toString`方法。



如果需要引用模板字符串本身，在需要时执行，可以写成函数。

```javascript
let func = (name) => `Hello ${name}!`;
func('Jack') // "Hello Jack!"
```

上面代码中，模板字符串写成了一个函数的返回值。执行这个函数，就相当于执行这个模板字符串了。













































































































































## 5. 字符串的新增方法

### 1.String.fromCodePoint()

ES5 提供`String.fromCharCode()`方法，用于从 Unicode 码点返回对应字符，但是这个方法不能识别码点大于`0xFFFF`的字符。

为此ES6提供了String.formCodePoint()方法

在作用上，正好与下面的`codePointAt()`方法相反。

```javascript
String.fromCodePoint(0x20BB7)
// "𠮷"
String.fromCodePoint(0x78, 0x1f680, 0x79) === 'x\uD83D\uDE80y'
// true
```

### 2.String.raw()

ES6 还为原生的 String 对象，提供了一个`raw()`方法。该方法返回一个**斜杠都被转义（即斜杠前面再加一个斜杠）的字符串**，往往用于模板字符串的处理方法。

但是如果本身字符串的斜杠已经被转义，也会再次进行转义。可以说是把\替换成\\\

```javascript
String.raw`\index\om`
//=>`\\index\\om`
```



### 3.实例方法includes(),startsWith(),endsWith()

传统上，JavaScript 只有`indexOf`方法，可以用来确定一个字符串是否包含在另一个字符串中。ES6 又提供了三种新方法。

- **includes()**：返回布尔值，表示是否找到了参数字符串。
- **startsWith()**：返回布尔值，表示参数字符串是否在原字符串的头部。
- **endsWith()**：返回布尔值，表示参数字符串是否在原字符串的尾部。

```javascript
let s = 'Hello world!';

s.startsWith('Hello') // true
s.endsWith('!') // true
s.includes('o') // true
```

这三个方法都支持第二个参数，表示开始搜索的位置。

```javascript
let s = 'Hello world!';

s.startsWith('world', 6) // true
s.endsWith('Hello', 5) // true
s.includes('Hello', 6) // false
```

### 4.实例方法repeat()

`repeat`方法返回一个新字符串，表示将原字符串重复`n`次。

```javascript
'x'.repeat(3) // "xxx"
'hello'.repeat(2) // "hellohello"
'na'.repeat(0) // ""
```

参数如果是小数，会被取整。

```javascript
'na'.repeat(2.9) // "nana"
```

如果`repeat`的参数是负数或者`Infinity`，会报错。

```javascript
'na'.repeat(Infinity)
// RangeError
'na'.repeat(-1)
// RangeError
```

但是，如果参数是 0 到-1 之间的小数，则等同于 0，这是因为会先进行取整运算。0 到-1 之间的小数，取整以后等于`-0`，`repeat`视同为 0。

```javascript
'na'.repeat(-0.9) // ""
```

参数`NaN`等同于 0。

```javascript
'na'.repeat(NaN) // ""
```

如果`repeat`的参数是字符串，则会先转换成数字。

```javascript
'na'.repeat('na') // ""
'na'.repeat('3') // "nanana"
```

### 5.实例方法padStart(),padEnd()

ES2017 引入了字符串补全长度的功能。如果某个字符串不够指定长度，会在头部或尾部补全。`padStart()`用于头部补全，`padEnd()`用于尾部补全。

```javascript
'x'.padStart(5, 'ab') // 'ababx'
'x'.padStart(4, 'ab') // 'abax'

'x'.padEnd(5, 'ab') // 'xabab'
'x'.padEnd(4, 'ab') // 'xaba'
```

- 长度到达则不补全
- 长度之和超过，只补全部分
- 省略第二个参数时，默认空格补全



### 6.实例方法trimStart(),trimEnd()

`trimStart()`消除字符串头部的空格，`trimEnd()`消除尾部的空格。它们返回的都是新字符串，不会修改原始字符串。(即是纯函数)

### 7.实例方法replaceAll()

以前的replace方法只能替换第一个匹配，后面出现了replaceAll就可以替换所有匹配了，这个方法也是返回一个新的字符串

```javascript
// $& 表示匹配的字符串，即`b`本身
// 所以返回结果与原字符串一致
'abbc'.replaceAll('b', '$&')
// 'abbc'

// $` 表示匹配结果之前的字符串
// 对于第一个`b`，$` 指代`a`
// 对于第二个`b`，$` 指代`ab`
'abbc'.replaceAll('b', '$`')
// 'aaabc'

// $' 表示匹配结果之后的字符串
// 对于第一个`b`，$' 指代`bc`
// 对于第二个`b`，$' 指代`c`
'abbc'.replaceAll('b', `$'`)
// 'abccc'

// $1 表示正则表达式的第一个组匹配，指代`ab`
// $2 表示正则表达式的第二个组匹配，指代`bc`
'abbc'.replaceAll(/(ab)(bc)/g, '$2$1')
// 'bcab'

// $$ 指代 $
'abc'.replaceAll('b', '$$')
// 'a$c'
```

### 8.实例方法at()

索引返回指定字符，超出范围返回undefined









































































































































































































## 6. 正则的扩展

## 7. 数值的扩展
## 8. 函数的扩展
## 9. 数组的扩展
## 10. 对象的扩展
## 11. 对象的新增方法
## 12. 运算符的扩展
## 13. Symbol
## 14. Set 和 Map 数据结构
## 15. Proxy
## 16. Reflect
## 17. Promise 对象
## 18. Iterator 和 for...of 循环
## 19. Generator 函数的语法
## 20. Generator 函数的异步应用
## 21. async 函数
## 22. Class 的基本语法
## 23. Class 的继承
## 24. Module 的语法
## 25. Module 的加载实现
## 26. 编程风格
## 27. 读懂规格
## 28. 异步遍历器
## 29. ArrayBuffer
## 30. 最新提案
## 31. Decorator
## 32. 参考链接