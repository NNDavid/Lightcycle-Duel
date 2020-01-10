#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QTimer>
class LightBike;

class GameManager : public QObject
{
    Q_OBJECT
public:
GameManager(int length);
~GameManager();
void newGame(int size);
void keyPressed(int key);

signals:
void draw();
void gameOver(int winner);
void newStep(int p1x,int p1y,int p2x, int p2y,QString p1color,QString p2color);
private slots:
void timerTimeOut();

private:
int _size;
QTimer* _timer;
LightBike*_player1;
LightBike*_player2;
int** _gameTable;
void stepGame();
};

#endif // GAMEMANAGER_H
