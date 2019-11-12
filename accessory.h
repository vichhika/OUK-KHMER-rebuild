#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <QWidget>
#include <QLabel>

class accessory:public QLabel
{
public:
    int numButton;

    accessory(QWidget* pParent=nullptr,Qt::WindowFlags f = 0): QLabel(pParent){}

    void mousePressEvent(QMouseEvent *event);
    void check(accessory* temp);
};

#endif // ACCESSORY_H
