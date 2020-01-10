#ifndef LIGHTBIKE_H
#define LIGHTBIKE_H

#include<QString>
class LightBike
{
public:
    static const int UP=8;
    static const int DOWN=2;
    static const int LEFT=4;
    static const int RIGHT=6;
    LightBike(QString color,int forward,int backward,int left, int right):_color(color),_forward(forward),_backward(backward),_left(left),_right(right){}
    QString getColor() const {return _color;}
    void setColor(QString value){_color=value;}
    int getX() const{return _x;}
    int getY() const{return _y;}
    void setXY(int x,int y);
    void keyPressed(int key);
    void Step();
    void setMovingWay(const int way){_movingWay=way;}

private:
QString _color;
int _forward;
int _backward;
int _left;
int _right;
int _movingWay;
int _x;
int _y;
};

#endif // LIGHTBIKE_H
