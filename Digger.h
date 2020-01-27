#ifndef CHAINOFRESPONSIBLITY490_DIGGER_H
#define CHAINOFRESPONSIBLITY490_DIGGER_H

class Digger {
public:
    Digger();
    Digger(int xPos, int yPos);

    void move(int dx, int dy);
    void setPos(int xPos, int yPos);
    int getXPos();
    int getYPos();
private:
    int _xPos, _yPos;
};

#endif //CHAINOFRESPONSIBLITY490_DIGGER_H
