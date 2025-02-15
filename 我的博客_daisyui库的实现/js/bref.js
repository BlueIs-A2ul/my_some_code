//获取box节点
const boxEl = document.querySelector('.box');
//获取box中的btn-primary类的btn
let btns = boxEl.querySelectorAll('.btn-primary');
//遍历btns数组，为每个btn添加点击事件
for (let i = 0; i < btns.length; i++) {
  btns[i].addEventListener('click', function () {
    //获取当前btn的索引
    window.location.href = "JavaScript.html";
  });
};