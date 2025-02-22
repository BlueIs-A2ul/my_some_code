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

document.addEventListener('DOMContentLoaded', function () {
  // 获取排序按钮
  const priceSort = document.querySelector('.info_right .dropdown-content li:first-child a');

  priceSort.addEventListener('click', function () {
    // 获取所有卡片
    const cardBox = document.querySelector('.card_box');
    const cards = Array.from(document.querySelectorAll('.card_item'));

    // 对卡片进行排序
    cards.sort((a, b) => {
      // 获取价格文本并转换为数字
      const priceA = parseFloat(a.querySelector('.after_price').textContent.replace('￥', ''));
      const priceB = parseFloat(b.querySelector('.after_price').textContent.replace('￥', ''));

      return priceA - priceB; // 升序排序
    });

    // 清空原有卡片
    cardBox.innerHTML = '';

    // 重新添加排序后的卡片
    cards.forEach(card => {
      cardBox.appendChild(card);
    });
  });
});

