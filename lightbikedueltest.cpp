#include <QString>
#include <QtTest>
#include "lightbikeduel.h"

class LightBikeDuelTest : public QObject // tesutkörnyezet
{
    Q_OBJECT
private:
    LightBikeDuel* _model;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testNewGame();
    void testStepGame();
    void testStepGameErrors();
};



//QTEST_APPLESS_MAIN(LightBikeDuelTest);

