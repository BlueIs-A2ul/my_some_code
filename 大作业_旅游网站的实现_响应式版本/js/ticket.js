/**
 * 为按钮数组添加点击事件，实现类名切换
 * @param {Array} buttonArray - 按钮数组
 * @param {string} activeClass - 激活类名（默认为 'btn_active'）
 */
function addToggleActiveClass(buttonArray, activeClass = 'btn_active') {
  buttonArray.forEach(btn => {
    btn.addEventListener('click', function () {
      // 移除所有按钮的激活类
      buttonArray.forEach(btn => {
        btn.classList.remove(activeClass);
      });

      // 添加激活类到当前按钮
      this.classList.add(activeClass);
    });
  });
}

const divEl1 = document.querySelector('.ticket-type');
const btns = divEl1.querySelectorAll('.btn_type');
addToggleActiveClass(btns);

const divEl2 = document.querySelector('.latest-tickets');
const btns2 = divEl2.querySelectorAll('.btn_type');
addToggleActiveClass(btns2);
