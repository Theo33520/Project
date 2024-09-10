const btn_cookie = document.querySelector('#cookie-btn');
const counterField = document.querySelector('#counter-field');
const buyCookieField = document.querySelector('#buy-cookie');


let count = 0;

btn_cookie.addEventListener('click', () => {
    updateCookies(count++)
    if (count >= 11) {
        buyCookieField.classList.remove('hidden');
    }

})

buyCookieField.addEventListener('click', () => {
    if (count > 9) {
        count -= 11;
        updateCookies(count);
    }
    if (count < 10) {
        buyCookieField.classList.add('hidden');
    }
});


function updateCookies(nbCookies) {
    counterField.textContent = nbCookies;
}