//获取手机号
const phone = document.querySelector('.phone-input');
const errorMsg = document.querySelector('.phone-input-error');

//检验手机号是否合法
//这里有一个要实现的是onfucus的时候消除错误提示
// phone.addEventListener('focus', function () {
//   errorMsg.style.visibility = 'hidden';
// });
phone.addEventListener('blur', function () {
  // 手机号正则表达式
  const phoneRegex = /^1[3-9]\d{9}$/;

  if (!phoneRegex.test(this.value)) {
    errorMsg.style.visibility = 'visible';
  } else {
    errorMsg.style.visibility = 'hidden';
  }
});


//获取验证码





