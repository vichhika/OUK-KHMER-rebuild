#include "accessory.h"
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtTest/QTest>

extern MainWindow *tempUI;
extern void gotoRestart();
extern QWidget *tempWiget;

void accessory::mousePressEvent(QMouseEvent *event){
    check(this);
}
void accessory::check(accessory *temp){
    if(temp->numButton) gotoRestart();
    else {
        gotoRestart();
        tempWiget->close();
        tempUI->ui->stackedWidget->setCurrentIndex(0);
        tempUI->show();
        tempUI->play.music_play();

    }
}
