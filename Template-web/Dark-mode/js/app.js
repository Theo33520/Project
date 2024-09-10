

const body = document.body;
const toggler = document.getElementById('toggler');

toggler.addEventListener('click', () => {
    body.classList.toggle('dark');
    toggler.classList.toggle('fa-moon');
    toggler.classList.toggle('fa-sun');
});