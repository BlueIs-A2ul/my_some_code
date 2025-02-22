const backgroundImages = [
  './img/index_bg1.jpg',
  './img/index_bg2.jpg',
  './img/index_bg3.jpg',
  './img/index_bg4.jpg',
];

let currentImageIndex = 0;

function changeBackground() {
  currentImageIndex = (currentImageIndex + 1) % backgroundImages.length;
  document.body.style.backgroundImage = `url(${backgroundImages[currentImageIndex]})`;
}

// 建议添加图片预加载
window.onload = function () {
  // 预加载所有图片
  backgroundImages.forEach(imgSrc => {
    const img = new Image();
    img.src = imgSrc;
  });

  // 开始轮播
  setInterval(changeBackground, 5000);
};
