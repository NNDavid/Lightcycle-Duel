#ifndef LIGHTBIKEDUEL_H
#define LIGHTBIKEDUEL_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <QtGui>
#include "gamemanager.h"

class LightBikeDuel : public QWidget
{
    Q_OBJECT

public:
    explicit LightBikeDuel(QWidget *parent = nullptr);
    ~LightBikeDuel();

private slots:
void newGameButtonClicked();
void draw();
void gameOver(int winner);
void newStep(int p1x,int p1y,int p2x, int p2y,QString p1color,QString p2color);
void keyPressEvent(QKeyEvent* event);
private:
    GameManager* _gameManager;
    QPushButton* _12game;
    QPushButton* _24game;
    QPushButton* _36game;
    QVector<QVector<QLabel*>> _field;
    QGridLayout* _tableLayout;
    QVBoxLayout* _mainLayout;
    QHBoxLayout * _newGameButtonsLayout;
    int _size;



};

#endif // LIGHTBIKEDUEL_H
