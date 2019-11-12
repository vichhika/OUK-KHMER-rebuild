#ifndef KRORLA_H
#define KRORLA_H
#include <QLabel>

class Krorla: public QLabel
{
public:

    //Fields
    int colorKrorla,piece,colorPiece,row,col,numKrorla;
    char pieceName;

    //Constructors
    Krorla(QWidget* pParent=nullptr,Qt::WindowFlags f = 0): QLabel(pParent){} /*the initializer list*/

    //Methods
    void mousePressEvent(QMouseEvent *event);
    void display(char elem);
    void displayKrorla();

};
#endif // TILE_H
