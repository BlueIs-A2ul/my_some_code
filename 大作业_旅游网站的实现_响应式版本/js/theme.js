// 按钮跳转功能优化
const initButtonNavigation = () => {
  const btnEls = document.querySelectorAll('.btn');
  const divEls = document.querySelectorAll('div');
  divEls.forEach(div => {
    const href = div.dataset.href;
    if (href) {
      div.addEventListener('click', () => {
        window.location.href = href;
      });
    }
  });
  btnEls.forEach(btn => {
    const href = btn.dataset.href;
    if (href) {
      btn.addEventListener('click', () => {
        window.location.href = href;
      });
    }
  });
};

// 初始化所有功能
document.addEventListener('DOMContentLoaded', () => {
  initButtonNavigation();
  initializeTheme();
});

function initializeTheme() {
  // 获取存储的主题值
  const savedTheme = localStorage.getItem('theme') || 'light';
  const themeToggle = document.querySelector('.theme-controller');

  // 设置初始主题
  document.documentElement.setAttribute('data-theme', savedTheme);

  // 同步切换按钮状态
  themeToggle.checked = savedTheme === 'dark';

  // 绑定主题切换事件
  themeToggle.addEventListener('change', handleThemeToggle);
}

function handleThemeToggle(event) {
  const isDark = event.target.checked;
  const theme = isDark ? 'dark' : 'light';

  // 保存主题设置
  localStorage.setItem('theme', theme);

  // 应用主题
  document.documentElement.setAttribute('data-theme', theme);
}