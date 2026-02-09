class Soldier {
    static numberOfSoldiers = 0;
    static numberOfAliveSoldiers = 0;

    constructor(x, y, index, alive = true) {
        this.x = x;
        this.y = y;
        this.alive = alive;
        this.index = index;
        Soldier.numberOfSoldiers++;
        Soldier.numberOfAliveSoldiers++;
    }

    get isAlive() {
        return this.alive;
    }

    kill(soldier) {
        strokeWeight(5);
        soldier._die();
        stroke(1);
        line(this.x, this.y, soldier.x, soldier.y);
    }

    _die() {
        this.alive = false;
        Soldier.numberOfAliveSoldiers--;
    }

    hide() {
        stroke(200);
    }

    show() {
        noStroke();
        const txt = String(this.index + 1);
        if (this.alive) {
            fill('black');
        } else {
            fill('red');
        }
        ellipse(this.x, this.y, 60, 60);
        fill('white');
        let textX = this.x - textWidth(txt) / 2;
        let textY = this.y + textAscent() / 2 - textDescent() / 2;
        text(txt, textX, textY);
    }
}
