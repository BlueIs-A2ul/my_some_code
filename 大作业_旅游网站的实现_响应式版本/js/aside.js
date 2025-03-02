document.addEventListener("DOMContentLoaded", function () {
  const images = [
    'url(./upload/font1.png)',
    'url(./upload/font2.png)',
    'url(./upload/font3.png)',
    'url(./upload/font4.png)'
  ];
  console.log(images);
  const links = document.querySelectorAll('.treasure_item a');
  console.log(links);
  links.forEach((link, index) => {
    if (images[index]) {
      // 创建一个新的 span 元素来包含图标
      const iconSpan = document.createElement('span');
      iconSpan.style.display = 'inline-block';
      iconSpan.style.width = '20px';
      iconSpan.style.height = '20px';
      iconSpan.style.marginRight = '5px';
      iconSpan.style.backgroundImage = images[index];
      iconSpan.style.backgroundRepeat = 'no-repeat';
      iconSpan.style.backgroundPosition = 'center';
      iconSpan.style.backgroundSize = '20px 20px';
      iconSpan.style.filter = 'var(--icon-filter)';
      iconSpan.style.verticalAlign = 'middle';

      // 将原来的文本内容保存
      const text = link.textContent;

      // 清空链接内容，添加图标和文本
      link.textContent = '';
      link.appendChild(iconSpan);
      link.appendChild(document.createTextNode(text));

      // 重置链接样式
      link.style.display = 'flex';
      link.style.alignItems = 'center';
    }
  });
});
