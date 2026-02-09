const soldiers = [];
let numberOfSoldiers;
let step;
let currentIndex = 0;
let prevIndex = 0;
let startButton;
let numberOfSoldiersInput;
let stepInput;

const getNextUserIndex = (currentIndex) => (currentIndex + step) % numberOfSoldiers;

function setup() {
    const canvas = createCanvas(800, 800);
    canvas.parent('canvas-container'); // Attach the canvas to the container
    console.log("Canvas created"); // Add this line to confirm canvas creation
    textSize(20);
    frameRate(5);
    strokeWeight(8);

    // Create input fields and start button
    numberOfSoldiersInput = createInput('10');
    numberOfSoldiersInput.position(10, height + 10);
    stepInput = createInput('2');
    stepInput.position(150, height + 10);
    startButton = createButton('Start Simulation');
    startButton.position(300, height + 10);
    startButton.mousePressed(startSimulation);
}

function startSimulation() {
    numberOfSoldiers = parseInt(numberOfSoldiersInput.value());
    step = parseInt(stepInput.value());

    soldiers.length = 0; // Clear the array
    currentIndex = 0;
    prevIndex = 0;
    Soldier.numberOfAliveSoldiers = numberOfSoldiers;

    const r = 300; // Increase the radius for larger canvas
    const theta = 360 / numberOfSoldiers;

    for (let i = 1; i <= numberOfSoldiers; i++) {
        const x = height / 2 + r * cos(radians(theta * i));
        const y = width / 2 + r * sin(radians(theta * i));
        const soldier = new Soldier(x, y, i - 1);
        soldiers.push(soldier);
        console.log(`Soldier ${i} created at (${x}, ${y})`); // Add this line to confirm soldier creation
    }

    loop();
}

function draw() {
    background(220);
    soldiers.forEach(soldier => soldier.show());
    if (Soldier.numberOfAliveSoldiers === 1) {
        const aliveSoldier = soldiers.find((soldier) => soldier.isAlive);
        console.log(`Soldier number ${aliveSoldier.index + 1} lives`);
        noLoop();
        return;
    }

    prevIndex = currentIndex;
    currentIndex = getNextUserIndex(currentIndex);

    while (!soldiers[currentIndex].isAlive) {
        currentIndex = getNextUserIndex(currentIndex);
    }

    console.log(`Soldier number ${prevIndex + 1} kills Soldier number ${currentIndex + 1}`);

    soldiers[prevIndex].kill(soldiers[currentIndex]);

    while (!soldiers[currentIndex].isAlive) {
        currentIndex = getNextUserIndex(currentIndex);
    }
}
