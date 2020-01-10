#include "lightbike.h"
#include<QDebug>
void LightBike::keyPressed(int key)
{
    if(key==_forward)
    {
        switch(_movingWay)
        {
            case LightBike::LEFT: _movingWay=LightBike::UP;break;
            case LightBike::RIGHT: _movingWay=LightBike::UP;break;
            default:break;
        }
    }
    else if(key==_backward)
    {
        switch(_movingWay)
        {
            case LightBike::LEFT: _movingWay=LightBike::DOWN;break;
            case LightBike::RIGHT: _movingWay=LightBike::DOWN;break;
            default:break;
        }

    }
    else if(key==_left)
    {
        switch(_movingWay)
        {
            case LightBike::UP: _movingWay=LightBike::LEFT;break;
            case LightBike::DOWN: _movingWay=LightBike::LEFT;break;
            default:break;
        }

    }
    else if(key==_right)
    {
        switch(_movingWay)
        {
            case LightBike::UP: _movingWay=LightBike::RIGHT;break;
            case LightBike::DOWN: _movingWay=LightBike::RIGHT;break;
            default:break;
        }
    }
}
void LightBike::Step()
{
    switch(_movingWay)
    {
        case LightBike::UP:_x--;break;
        case LightBike::DOWN:_x++;break;
        case LightBike::LEFT:_y--;break;
        case LightBike::RIGHT:_y++;break;
        default:break;
    }
}
void LightBike::setXY(int x,int y)
{
    _x=x;
    _y=y;
}
