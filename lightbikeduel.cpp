#include "lightbikeduel.h"
#include<QMessageBox>

LightBikeDuel::LightBikeDuel(QWidget *parent) : QWidget(parent)
{
   setFixedSize(800,800);
   _gameManager=new GameManager(500);
   _tableLayout=new QGridLayout();
   _mainLayout=new QVBoxLayout();
   _newGameButtonsLayout=new QHBoxLayout();

   _12game=new QPushButton("12 x 12 game");
   connect(_12game,SIGNAL(clicked()),this,SLOT(newGameButtonClicked()));

   _24game=new QPushButton("24 x 24 game");
   connect(_24game,SIGNAL(clicked()),this,SLOT(newGameButtonClicked()));

   _36game=new QPushButton("36 x 36 game");
   connect(_36game,SIGNAL(clicked()),this,SLOT(newGameButtonClicked()));

   _newGameButtonsLayout->addWidget(_12game, 0, Qt::AlignHCenter);
   _newGameButtonsLayout->addWidget(_24game, 0, Qt::AlignHCenter);
   _newGameButtonsLayout->addWidget(_36game, 0, Qt::AlignHCenter);
   _mainLayout->addLayout(_newGameButtonsLayout);
   _mainLayout->addLayout(_tableLayout);
   setLayout(_mainLayout);
   connect(_gameManager,SIGNAL(draw()),this,SLOT(draw()));
   connect(_gameManager,SIGNAL(gameOver(int)),this,SLOT(gameOver(int)));
   connect(_gameManager,SIGNAL(newStep(int,int,int,int,QString,QString)),this,SLOT(newStep(int,int,int,int,QString,QString)));
}
void LightBikeDuel::newGameButtonClicked()
{
    foreach(QVector<QLabel*> row,_field)
    {
        foreach(QLabel* label,row)
        {
        _tableLayout->removeWidget(label);
        delete label;
        }
    }
   if(QObject::sender()==_12game) _size=12;
   else if(QObject::sender()==_24game) _size=24;
   else if(QObject::sender()==_36game) _size=36;
   _field.resize(_size);
   for(int i=0;i<_size;i++)
   {
       _field[i].resize(_size);
       for(int j=0;j<_size;j++)
       {
           _field[i][j]=new QLabel();
           _field[i][j]->setFixedSize(10,10);
           _field[i][j]->setStyleSheet("QLabel {background-color:rgb(255,255,255)}");
           _tableLayout->addWidget(_field[i][j],i,j);
       }
   }
   _gameManager->newGame(_size);
}
void LightBikeDuel::keyPressEvent(QKeyEvent* event)
{
    _gameManager->keyPressed(event->key());
}
void LightBikeDuel::draw()
{
    QMessageBox::information(this, trUtf8("Játék vége"),
                             trUtf8("Döntetlen! "));
}
void LightBikeDuel::gameOver(int winner)
{
    QMessageBox::information(this, trUtf8("Játék vége"),
                             trUtf8("Játékos")+ QString::number(winner) + trUtf8(" nyert!"));
}

void LightBikeDuel::newStep(int p1x,int p1y,int p2x, int p2y,QString p1color,QString p2color)
{
    _field[p1x][p1y]->setStyleSheet(p1color);
    _field[p2x][p2y]->setStyleSheet(p2color);
}

LightBikeDuel::~LightBikeDuel()
{
    delete _gameManager;

    foreach(QVector<QLabel*> row,_field)
    {
        foreach(QLabel* label,row)
        {
        _tableLayout->removeWidget(label);
        delete label;
        }
    }
}
