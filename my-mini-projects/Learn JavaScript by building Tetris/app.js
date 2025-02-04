document.addEventListener('DOMContentLoaded', () => {
  const grid = document.querySelector('.grid')
  let squares = Array.from(document.querySelectorAll('.grid div'))
  const ScoreDisplay = document.querySelector('#score')
  const StartButton = document.querySelector('#start-button')
  const width = 10
  let timerID
  let score = 0
  let nextRandom = 0

  const colours = [
    'orange',
    'red',
    'purple',
    'green',
    'blue'
  ]

  //height is 12 blocks, width is 10

  //console.log(squares)

  //tetramino shapes

  const lshape = [
    [1, width + 1, width * 2 + 1, 2],
    [width, width + 1, width + 2, width * 2 + 2],
    [1, width + 1, width * 2 + 1, width * 2],
    [width, width * 2, width * 2 + 2, width * 2 + 1],
  ]

  const zshape = [
    [0, width, width + 1, width * 2 + 1],
    [width + 1, width + 2, width * 2, width * 2 + 1],
    [0, width, width + 1, width * 2 + 1],
    [width+1, width+2, width*2, width*2+1],
]

const tshape = [
    [1, width, width + 1, width + 2],
    [1, width + 1, width + 2, width * 2 + 1],
    [width, width + 1, width + 2, width * 2 + 1],
    [1, width, width+1, width*2+1],
]

const oshape = [
    [0, 1, width, width + 1],
    [0, 1, width, width + 1],
    [0, 1, width, width + 1],
    [0, 1, width, width + 1],
]

const ishape = [
    [1, width + 1, width * 2 + 1, width * 3 + 1],
    [width, width + 1, width + 2, width + 3],
    [1, width + 1, width * 2 + 1, width * 3 + 1],
    [width, width+1, width+2, width+3],
]

const allshapes = [lshape, zshape, tshape, oshape, ishape]

let currentPosition = 4
let currentRotation = 0

//randomly select a shape and the first rotation of that shape
let random = Math.floor(Math.random()*allshapes.length)
//console.log(random)
let current = allshapes[random][currentRotation]

//draws the shape

function draw() {
  current.forEach(index => {
    squares[currentPosition + index].classList.add('shape')
    squares[currentPosition + index].style.backgroundColor = colours[random]
  })
}

draw()
//undraw shape and current rotation

function undraw() {
  current.forEach(index => {
    squares[currentPosition + index].classList.remove('shape')
    squares[currentPosition + index].style.backgroundColor = ''
  })
}


//moves down shape every second

//timerID = setInterval(moveDown, 1000)

//assign functions to keycodes using https://uiwjs.github.io/keycode-info/

function control(e){
  if (e.keyCode === 37){
    moveLeft()
  } else if (e.keyCode === 38){
    rotate()
  } else if (e.keyCode === 39){
    moveRight()
  } else if (e.keyCode === 40){
    moveDown()
  }
}
document.addEventListener('keyup', control)



//moveDown function

function moveDown() { //deletes the shape and redraws it one block down so it appears to be moving down
  undraw()
  currentPosition += width
  draw()
  freeze()
}

//freeze function

function freeze() {
  if (current.some(index => squares[currentPosition + index + width].classList.contains('taken'))) {
    current.forEach(index => squares[currentPosition + index].classList.add('taken'))
    //make another shape fall
    random = nextRandom
    nextRandom =  Math.floor(Math.random() * allshapes.length)
    current = allshapes[random][currentRotation]
    currentPosition = 4
    draw()
    displayShape()
    addScore()
    gameOver()
  }
}

//move shape left unless at the end of the grid

function moveLeft(){
  undraw()
  const AtLeftEdge = current.some(index => (currentPosition + index) % width === 0)

  if(!AtLeftEdge) currentPosition -=1

  if (current.some(index => squares[currentPosition + index].classList.contains('taken'))){
    currentPosition +=1
  }
  draw()
  }

  //move shape right unless at the end of the grid

  function moveRight(){
    undraw()
    const AtRightEdge = current.some(index => (currentPosition + index) % width === width -1)

    if(!AtRightEdge) currentPosition +=1

    if (current.some(index => squares[currentPosition + index].classList.contains('taken'))){
      currentPosition -=1
    }
    draw()
    }

  //rotate the shape using the up button

  function rotate(){
    undraw()
    currentRotation ++
    if (currentRotation === current.length){
      currentRotation = 0 //if rotation goes to 4, it returns back to 0
    }
    current = allshapes[random][currentRotation]
    draw()
  }

  //show next shape in mini grid next to playing area

  const displaySquares = document.querySelectorAll('.mini-grid div')
  const displayWidth = 4
  const displayIndex = 0

  //shapes without rotation

  const upNextShape = [
    [1, displayWidth + 1, displayWidth * 2 + 1, 2], //l shape
    [0, displayWidth, displayWidth + 1, displayWidth * 2 + 1], //z shape
    [1, displayWidth, displayWidth + 1, displayWidth + 2], //t shape
    [0, 1, displayWidth, displayWidth + 1], //o shape
    [1, displayWidth + 1, displayWidth * 2 + 1, displayWidth * 3 + 1], //i shape
  ]

  //displays upcoming shapes in the mini-grid display

  function displayShape(){
    displaySquares.forEach(square =>{
      square.classList.remove('shape')
      square.style.backgroundColor = ''
    })
    upNextShape[nextRandom].forEach(index => {
      displaySquares[displayIndex + index].classList.add('shape')
      displaySquares[displayIndex + index].style.backgroundColor = colours[nextRandom]
    })
  }

  StartButton.addEventListener('click', () => {
    if (timerID) {
      clearInterval(timerID)
      timerID = null
    } else {
      draw()
      timerID = setInterval(moveDown, 1000)
      nextRandom = Math.floor(Math.random()*allshapes.length)
      displayShape()
    }
  })

  //add score

  function addScore() {
    for(let i = 0; i < squares.length - width; i += width){
      const row = [i, i+1, i+2, i+3, i+4, i+5, i+6, i+7, i+8, i+9]

      if(row.every(index => squares[index].classList.contains('taken'))){
        score +=10
        ScoreDisplay.innerHTML = score
        row.forEach(index => {
          squares[index].classList.remove('taken')
          squares[index].classList.remove('shape')
          squares[index].style.backgroundColor = ''
        })
        const squaresRemoved = squares.splice(i,width)
        //console.log(squaresRemoved)
        squares = squaresRemoved.concat(squares)
        squares.forEach(cell => grid.appendChild(cell))
      }

    }

    }

    //game over

    function gameOver(){
      if (current.some(index => squares[currentPosition + index].classList.contains('taken'))) {
        ScoreDisplay.innerHTML = 'Game Over!'
        clearInterval(timerID)
      }
    }





  })
