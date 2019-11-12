#include "mainwindow.h"
#include "ui_mainwindow.h"
extern QWidget *tempWiget;
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
    click.next();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{ui->stackedWidget->setCurrentIndex(1);ui->wait->clear();timer->stop();});
    timer->start(800);
}

void MainWindow::on_back_button_clicked()
{
    click.back();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{ui->stackedWidget->setCurrentIndex(0);ui->wait->clear();timer->stop();});
    timer->start(800);

}

void MainWindow::on_music_button_clicked()
{
    static short int toggle = 1;
    if(toggle == 0){
        toggle = 1;
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
        toggle = 0;
        play.music_pause();
        ui->music_button->setStyleSheet("#music_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/uncheck.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");

    }
    click.check();
}

void MainWindow::on_sound_button_clicked()
{
    static short int toggle = 1;
    if(toggle == 0){
        toggle = 1;
        ui->sound_button->setStyleSheet("#sound_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/check.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");

    }
    else {
        toggle = 0;
        ui->sound_button->setStyleSheet("#sound_button {\n"
                                            "background	-color: transparent;\n"
                                            "border-image: url(:/images/uncheck.png);\n"
                                            "max-width:54px;\n"
                                            "height:54px;\n"
                                            "border-width:15%;\n"
                                            "}");
    }
    click.check();
    click.Soundswitch(&toggle);
}

void MainWindow::on_exit_button_clicked()
{
    click.exit();
    this->wait_label();
    connect(timer, &QTimer::timeout, this,&MainWindow::close);
    timer->start(1500);


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
    click.back();
    this->wait_label();
    connect(timer, &QTimer::timeout, [=]{this->hide();tempWiget->show();ui->wait->clear();timer->stop();});
    timer->start(1000);
}
