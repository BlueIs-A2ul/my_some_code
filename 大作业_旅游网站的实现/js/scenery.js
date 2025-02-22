const nameOfFile = window.location.href;
const fileName = nameOfFile.substring(nameOfFile.lastIndexOf('/') + 1).split('.')[0];


const sceneryItem = document.querySelectorAll('.scenery-item');

sceneryItem.forEach(item => {
  if (item.dataset.href) {
    //为了防止给没有href的也加上监听器导致的一些bug，这里先做判定
    item.addEventListener('click', () => {
      window.location.href = item.dataset.href;
    });
  }
});



