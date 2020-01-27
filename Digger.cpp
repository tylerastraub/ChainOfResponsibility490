#include "Digger.h"

Digger::Digger() {
    _xPos = _yPos = 0;
}

Digger::Digger(int xPos, int yPos) {
    _xPos = xPos;
    _yPos = yPos;
}

void Digger::move(int dx, int dy) {
    _xPos += dx;
    _yPos += dy;
}

void Digger::setPos(int xPos, int yPos) {
    _xPos = xPos;
    _yPos = yPos;
}

int Digger::getXPos() {
    return _xPos;
}

int Digger::getYPos() {
    return _yPos;
}
