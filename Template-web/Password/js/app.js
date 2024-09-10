

// selector

const pwdField = document.querySelector('#password')
const iconFiled = document.querySelector('#eye-loop')

iconFiled.addEventListener('mousedown', () => {
    pwdField.setAttribute('type', 'text')
});


iconFiled.addEventListener('mouseup', () => {
    pwdField.setAttribute('type', 'password')
});

