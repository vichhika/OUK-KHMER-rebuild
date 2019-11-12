#include "mouse.h"

QCursor mouse::get1(){
    return QCursor(QPixmap(":images/mouse/mouse.png"),15,5);
}
QCursor mouse::get2(){
    return QCursor(QPixmap(":images/mouse/mouse2.png"),30,0);
}
