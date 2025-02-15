// function initializeTheme() {
//   const savedTheme = localStorage.getItem('theme') || 'light';
//   document.documentElement.setAttribute('data-theme', savedTheme);
// }

// // 主题切换事件处理
// document.addEventListener('DOMContentLoaded', () => {
//   initializeTheme();

//   document.querySelector('.theme-toggle').addEventListener('change', (e) => {
//     const newTheme = e.target.checked ? 'dark' : 'light';
//     localStorage.setItem('theme', newTheme);
//     document.documentElement.setAttribute('data-theme', newTheme);
//   });
// });

// // theme.js
// document.addEventListener('DOMContentLoaded', function () {
//   const themeController = document.querySelector('.theme-controller');
//   themeController.addEventListener('change', function () {
//     if (this.checked) {
//       document.documentElement.setAttribute('data-theme', 'dark');
//     } else {
//       document.documentElement.setAttribute('data-theme', 'light');
//     }
//   });
// });


// function initializeTheme() {
//   // 获取存储的主题值（如果没有则使用默认值）
//   const savedTheme = localStorage.getItem('theme') || 'light';
//   const themeToggle = document.querySelector('.theme-controller');

//   // 设置初始主题
//   document.documentElement.setAttribute('data-theme', savedTheme);

//   // 同步切换按钮状态
//   themeToggle.checked = savedTheme === 'dark'; // 如果使用 dark/light 切换
//   // 如果使用具体主题名称（如synthwave），需要根据存储值判断：
//   // themeToggle.checked = savedTheme === 'synthwave';
// }

// // 主题切换处理函数
// function handleThemeToggle() {
//   const themeToggle = document.querySelector('.theme-controller');
//   const currentTheme = themeToggle.checked ? 'dark' : 'light';
//   // 如果使用具体主题名称：
//   // const currentTheme = themeToggle.checked ? 'synthwave' : 'light';

//   // 保存到 localStorage
//   localStorage.setItem('theme', currentTheme);
//   // 应用主题到 HTML
//   document.documentElement.setAttribute('data-theme', currentTheme);
// }

// // 页面加载时初始化主题
// document.addEventListener('DOMContentLoaded', () => {
//   initializeTheme();

//   // 绑定切换事件
//   document.querySelector('.theme-controller').addEventListener('change', handleThemeToggle);
// });
document.addEventListener('DOMContentLoaded', () => {
  // 初始化主题
  initializeTheme();

  // 绑定主题切换事件
  document.querySelector('.theme-controller').addEventListener('change', handleThemeToggle);
});

function initializeTheme() {
  // 获取存储的主题值（如果没有则使用默认值）
  const savedTheme = localStorage.getItem('theme') || 'light';
  const themeToggle = document.querySelector('.theme-controller');

  // 设置初始主题
  document.documentElement.setAttribute('data-theme', savedTheme);

  // 同步切换按钮状态
  themeToggle.checked = savedTheme === 'dark'; // 如果使用 dark/light 切换
  // 如果使用具体主题名称（如synthwave），需要根据存储值判断：
  // themeToggle.checked = savedTheme === 'synthwave';
}

function handleThemeToggle() {
  const themeToggle = document.querySelector('.theme-controller');
  const currentTheme = themeToggle.checked ? 'dark' : 'light';
  // 如果使用具体主题名称：
  // const currentTheme = themeToggle.checked ? 'synthwave' : 'light';

  // 保存到 localStorage
  localStorage.setItem('theme', currentTheme);
  // 应用主题到 HTML
  document.documentElement.setAttribute('data-theme', currentTheme);
}
const navbarEl = document.querySelector('.navbar');
const btn = navbarEl.querySelector('.btn');
btn.addEventListener('click', () => {
  window.location.href = "bref.html";
});
