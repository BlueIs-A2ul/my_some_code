// 获取导航容器
const containerEl = document.querySelector('.container');
const navMenu = containerEl.querySelector('.menu');

// 事件委托处理点击
navMenu.addEventListener('click', (event) => {
  // 1. 定位目标元素
  const clickedItem = event.target.closest('a');
  if (!clickedItem) return;

  // 2. 获取所有导航项
  const allItems = navMenu.querySelectorAll('a');

  // 3. 批量移除active类
  allItems.forEach(item => item.classList.remove('activ'));

  // 4. 为点击项添加active类
  clickedItem.classList.add('activ');

});



// 获取所有 data-page="page" 的元素
const pages = [...document.querySelectorAll('a[data-page="page"]')];

// 定义一个数组，存储对应的 href 链接
const hrefLinks = [
  'JavaScript.html',
  'JavaScript_intro.html',
  'JavaScript_usage.html',
  'JavaScript-regex.html'
];

// 确保 hrefLinks 的长度与 pages 的长度一致
if (pages.length !== hrefLinks.length) {
  console.error('Error: Length of hrefLinks does not match the number of pages');
} else {
  // 遍历 pages 数组，为每个元素添加 href
  pages.forEach((element, index) => {
    element.href = hrefLinks[index];
  });
}

// 测试：点击链接会跳转到相应的页面
// 可以在浏览器中查看效果

let colEl = document.querySelector('.col');
let btnEls = colEl.querySelectorAll('.btn');
console.log(btnEls);
//先获取元素
btnEls.forEach((btn) => {
  const href = btn.getAttribute('data-href'); // 获取 data-href 属性
  if (href) {
    btn.href = href; // 设置 href 属性
    btn.addEventListener('click', () => {
      window.location.href = href; // 跳转到相应的页面
    });
  }
});

