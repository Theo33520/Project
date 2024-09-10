

const colors =  ["red", "green", "blue"]
const randomIndex = getRandomInt(colors.length)

document.body.style.backgroundColor = colors[randomIndex]

function getRandomInt(max) {
    return Math.floor(Math.random() * max)
}

