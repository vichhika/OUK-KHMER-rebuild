#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
#include "mouse.h"
#include "sound.h"
#include "music.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_options_button_clicked();

    void on_back_button_clicked();

    void on_music_button_clicked();

    void on_sound_button_clicked();

    void on_exit_button_clicked();

    void on_play_button_clicked();

public:
    Ui::MainWindow *ui;


public:
    Sound click;
    music play;
    QTimer *timer;
    QMovie *movie;
    void wait_label();
    void loading();

};

#endif // MAINWINDOW_H
