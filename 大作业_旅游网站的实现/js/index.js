document.addEventListener('DOMContentLoaded', function () {
  const carousel = document.querySelector('.carousel');
  const items = carousel.querySelectorAll('.carousel-item');
  const prevBtn = document.querySelector('.prev');
  const nextBtn = document.querySelector('.next');
  let currentIndex = 0;

  // 显示指定索引的图片
  function showImage(index) {
    items.forEach(item => item.classList.remove('active'));
    items[index].classList.add('active');
  }

  // 下一张图片
  function nextImage() {
    currentIndex = (currentIndex + 1) % items.length;
    showImage(currentIndex);
  }

  // 上一张图片
  function prevImage() {
    currentIndex = (currentIndex - 1 + items.length) % items.length;
    showImage(currentIndex);
  }

  // 绑定按钮事件
  prevBtn.addEventListener('click', prevImage);
  nextBtn.addEventListener('click', nextImage);

  // 自动轮播
  setInterval(nextImage, 5000);
});