#include "accessory.h"
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtTest/QTest>

extern MainWindow *tempUI;
extern void gotoRestart();
extern QWidget *tempWiget;
extern Sound *soundChess;
extern QLabel *tempsound;
extern int checkMusic;

void accessory::mousePressEvent(QMouseEvent *event){
    check(this);
}
void accessory::check(accessory *temp){
    if(temp->numButton == 1) gotoRestart();
    else if(temp->numButton == 2){
        if(soundChess->turn) soundChess->turn = 0;
        else soundChess->turn = 1;
        if(soundChess->turn == 1){
            //soundChess->turn = 1;
            tempsound->setPixmap(QPixmap(":/Image/switch-on-icon.png"));
        }else {
            //soundChess->turn = 0;
            tempsound->setPixmap(QPixmap(":/Image/switch-off-icon.png"));
}
    }
    else {
        gotoRestart();
        tempWiget->hide();
        tempUI->ui->stackedWidget->setCurrentIndex(0);
        if(checkMusic) tempUI->play.music_play();
        else tempUI->play.music_pause();
        tempUI->show();
        if(soundChess->turn) {
            tempUI->ui->sound_button->setStyleSheet("#sound_button {\n"
                                                        "background	-color: transparent;\n"
                                                        "border-image: url(:/images/check.png);\n"
                                                        "max-width:54px;\n"
                                                        "height:54px;\n"
                                                        "border-width:15%;\n"
                                                        "}");
        }
        else{
            tempUI->ui->sound_button->setStyleSheet("#sound_button {\n"
                                                "background	-color: transparent;\n"
                                                "border-image: url(:/images/uncheck.png);\n"
                                                "max-width:54px;\n"
                                                "height:54px;\n"
                                                "border-width:15%;\n"
                                                "}");
        }


    }
}
