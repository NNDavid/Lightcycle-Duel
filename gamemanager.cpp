#include "gamemanager.h"
#include "lightbike.h"
#include <QDebug>
#include <iostream>

GameManager::GameManager(int length)
{
    _timer=new QTimer();
    _timer->setInterval(length);
    connect(_timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));

    _player1=new LightBike("QLabel {background-color:rgb(255,0,0)}",Qt::Key_W,Qt::Key_S,Qt::Key_A,Qt::Key_D);
    _player2=new LightBike("QLabel {background-color:rgb(0,0,255)}",Qt::Key_8,Qt::Key_2,Qt::Key_4,Qt::Key_6);

}
GameManager::~GameManager()
{
    _timer->stop();
    delete _timer;
    for(int i=0;i<_size;i++)
        delete[] _gameTable[i];
    delete[] _gameTable;
}
void GameManager::newGame(int size)
{

    if(_timer->isActive()) _timer->stop();
    _size=size;
    _gameTable=new int*[_size];
    for(int i=0;i<_size;i++)
    {
        _gameTable[i]=new int[_size];
        for(int j=0;j<_size;j++)
            _gameTable[i][j]=0;
    }

    _player1->setXY(0,0);
    _player2->setXY(0,_size-1);
    _player1->setMovingWay(LightBike::RIGHT);
    _player2->setMovingWay(LightBike::LEFT);
    emit newStep(0,0,0,_size-1,_player1->getColor(),_player2->getColor());
    _timer->start();

}
void GameManager::timerTimeOut()
{
    if(_timer->isActive())
        stepGame();

}
void GameManager::stepGame()
{
    _player1->Step();
    _player2->Step();

    int p1x=_player1->getX();
    int p1y=_player1->getY();
    int p2x=_player2->getX();
    int p2y=_player2->getY();

    bool p1lose=p1x<0||p1x>=_size||p1y<0||p1y>=_size;
    bool p2lose=p2x<0||p2x>=_size||p2y<0||p2y>=_size;
    if(!p1lose) p1lose=_gameTable[p1x][p1y]!=0;
    if(!p2lose) p2lose=_gameTable[p2x][p2y]!=0;
    if(p1lose&&p2lose)
    {
        _timer->stop();
        emit draw();
    }

    else if(p1lose)
    {

        _timer->stop();
        emit gameOver(2);
    }
    else if(p2lose)
    {

        _timer->stop();
        emit gameOver(1);
    }
    else
    {
        _gameTable[p1x][p1y]=1;
        _gameTable[p2x][p2y]=2;
        emit newStep(p1x,p1y,p2x,p2y,_player1->getColor(),_player2->getColor());
    }

}
void GameManager::keyPressed(int key)
{
    if(key==Qt::Key_P)
    {
        if(_timer->isActive()) _timer->stop();
        else _timer->start();
    }
    else
    {
         _player1->keyPressed(key);
         _player2->keyPressed(key);
    }
}
