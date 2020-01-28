#ifndef CHAINOFRESPONSIBLITY490_DIGGER_H
#define CHAINOFRESPONSIBLITY490_DIGGER_H

class Digger {
public:
    Digger();
    Digger(int xPos, int yPos);

    void move(int dx, int dy);
    void setPos(int xPos, int yPos);
    void setMaxDigDepth(int maxDigDepth);
    int getXPos();
    int getYPos();
    int getMaxDigDepth();
private:
    int _xPos, _yPos, _maxDigDepth;
};

#endif //CHAINOFRESPONSIBLITY490_DIGGER_H
