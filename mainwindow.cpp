#include "mainwindow.h"
#include "ui_mainwindow.h"
extern QWidget *tempWiget;
extern Sound *soundChess;
extern QLabel *tempsound;
int checkMusic = 1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setCursor(mouse::get1());
    ui->setupUi(this);
    ui->play_button->setCursor(mouse::get2());
    ui->options_button->setCursor(mouse::get2());
    ui->exit_button->setCursor(mouse::get2());
    ui->music_button->setCursor(mouse::get2());
    ui->sound_button->setCursor(mouse::get2());
    ui->back_button->setCursor(mouse::get2());
    //play.music_play();
    ui->stackedWidget->setCurrentIndex(3);
    this->loading();
    connect(timer,&QTimer::timeout, [=]{ui->stackedWidget->setCurrentIndex(0);ui->loading->clear();timer->stop();play.music_play();});
    timer->start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_options_button_clicked()
{
    soundChess->next();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{ui->stackedWidget->setCurrentIndex(1);ui->wait->clear();timer->stop();});
    timer->start(100);
}

void MainWindow::on_back_button_clicked()
{
    soundChess->back();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{ui->stackedWidget->setCurrentIndex(0);ui->wait->clear();timer->stop();});
    timer->start(100);

}

void MainWindow::on_music_button_clicked()
{
    if(checkMusic == 0){
        checkMusic = 1;
        play.music_play();
        ui->music_button->setStyleSheet("#music_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/check.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");

    }
    else {
        checkMusic = 0;
        play.music_pause();
        ui->music_button->setStyleSheet("#music_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/uncheck.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");

    }
    soundChess->check();
}

void MainWindow::on_sound_button_clicked()
{
    if(soundChess->turn) soundChess->turn = 0;
    else soundChess->turn = 1;
    if(soundChess->turn == 1){
        //soundChess->turn = 1;
        tempsound->setPixmap(QPixmap(":/Image/switch-on-icon.png"));
        ui->sound_button->setStyleSheet("#sound_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/check.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");

    }
    else {
        //soundChess->turn = 0;
        tempsound->setPixmap(QPixmap(":/Image/switch-off-icon.png"));
        ui->sound_button->setStyleSheet("#sound_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/uncheck.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");
    }
    soundChess->check();
}

void MainWindow::on_exit_button_clicked()
{
    soundChess->exit();
    this->wait_label();
    connect(timer, &QTimer::timeout, this,&MainWindow::close);
    timer->start(500);


}
void MainWindow::wait_label(){
    movie = new QMovie(":images/mouse/wait.gif");
    ui->wait->setMovie(movie);
    movie->setSpeed(200);
    movie->start();
    timer = new QTimer(this);
}
void MainWindow::loading(){
    movie = new QMovie(":images/loading/loading.gif");
    ui->loading->setMovie(movie);
    movie->setSpeed(300);
    movie->start();
    timer = new QTimer(this);

}

void MainWindow::on_play_button_clicked()
{
    play.music_pause();
    ui->stackedWidget->setCurrentIndex(2);
    soundChess->back();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{this->close();tempWiget->show();ui->wait->clear();timer->stop();});
    timer->start(1500);
}
