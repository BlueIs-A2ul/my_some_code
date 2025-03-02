document.addEventListener('DOMContentLoaded', function () {
  // 获取排序按钮
  const priceSort = document.querySelector('.info_right .dropdown-content li:first-child a');
  let isAscending = true; // 排序方向状态

  priceSort.addEventListener('click', function () {
    // 获取所有卡片
    const cardBox = document.querySelector('.card_box');
    const cards = Array.from(document.querySelectorAll('.card_item'));

    // 对卡片进行排序
    cards.sort((a, b) => {
      const priceA = parseFloat(a.querySelector('.after_price').textContent.replace('￥', ''));
      const priceB = parseFloat(b.querySelector('.after_price').textContent.replace('￥', ''));

      // 根据排序方向返回比较结果
      return isAscending ? priceA - priceB : priceB - priceA;
    });

    // 清空原有卡片
    cardBox.innerHTML = '';

    cards.forEach(card => {
      cardBox.appendChild(card);
    });

    isAscending = !isAscending;

    // 更新按钮文本
    this.textContent = `按价格${isAscending ? '升序' : '降序'}排序`;
  });
});
