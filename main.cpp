#include <QApplication>
#include "mainwindow.h"
#include "krorla.h"
#include "accessory.h"
#include <QDebug>
#include <QMovie>

int count=0,turn=0,way[60],max=0,check_king = 0,winSound = 0;//FOR VALIDATION
Krorla *konDerm;//CHANGE OBJECT
QLabel *tempTurn;
QLabel *tempwinner;
QMovie *tempWinner;
QWidget *tempWiget;
MainWindow *tempUI;
Krorla *tile[8][8];
extern Sound *soundChess;
int x = 1366;
int y = 552;
class Border
{
public:
    //Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget); //create label

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,552,20);        //Horizontal Borders

        else
            outLabel->setGeometry(xPos,yPos,20,512);        //Vertical Borders

        outLabel->setStyleSheet("QLabel { border-image: url(:/Image/Angkor.jpg);}"); //style freme
    }
};

void accessories(QWidget *baseWidget)
{
    QLabel *moves = new QLabel(baseWidget); //Object ណាប្រកាស់មុនគេនឹងចេញមុនគេ

    QLabel *player1 = new QLabel(baseWidget);
    QLabel *player2 = new QLabel(baseWidget);
    accessory *home = new accessory(baseWidget);
    accessory *restart = new accessory(baseWidget);
    QLabel *turnText[2];
    QLabel *white = new QLabel(baseWidget);

    turnText[0] =  new QLabel(baseWidget);
    turnText[1] =  new QLabel(baseWidget);

    turnText[0]->setGeometry(x/8,552/2,240,70);
    turnText[0]->setPixmap(QPixmap(":/Image/turn.png"));


    turnText[1]->setGeometry(x-2*(x/8 + 25),552/2,240,70);
    turnText[1]->setPixmap(QPixmap(":/Image/turn.png"));

    white->setGeometry(0,y/2+260,x,123);
    white->setStyleSheet("QLabel {background-color: White;}");



    home->numButton = 0;
    home->setCursor(mouse::get2());
    home->setGeometry(20,20,74,74);
    home->setStyleSheet("QLabel {border-image: url(:/Image/home.png);}:hover{border-image:url(:Image/home.png);border-width:-10%;}");


    restart->numButton = 1;
    restart->setCursor(mouse::get2());
    restart->setGeometry(110,20,78,78);
    restart->setStyleSheet("QLabel {border-image: url(:/Image/restart.png);}:hover{border-image:url(:Image/restart.png);border-width:-10%;}");

    moves->setGeometry(0,0,1366,768);
    moves->setStyleSheet("QLabel {border-image: url(:/Image/background.jpg);}");

    player1->setGeometry(x/8 + 35,y/6+25,128,128);
    player1->setStyleSheet("QLabel {border-image: url(:/Image/profile1.png);}");

    player2->setGeometry(x/2 + x/4,y/6+25,128,128);
    player2->setStyleSheet("QLabel {border-image: url(:/Image/profile2.png);}");



}

void chessBoard(QWidget *baseWidget, Krorla *tile[8][8])
{
    int i,j,k=0,hor,ver;
    Border *border[4];

    //borderDisplay
    {
    border[0]->outline(baseWidget,(1366/2)-(552/2),(768/2)-(512/2)-20,0); //frame chessboard up //1366 maxWidthScreen //768 maxHeightScreen
    border[1]->outline(baseWidget,(1366/2)-(552/2),((768/2)-(512/2))+512,0);//frame chesssboard down
    border[2]->outline(baseWidget,(1366/2)-(552/2),((768/2)-(512/2)),1); //frame chessboard left
    border[2]->outline(baseWidget,(1366/2)-(552/2)+532,((768/2)-(512/2)),1);//frame chessboard right
    }

    //Create Krorla ouk
    ver=((768/2)-(512/2)); // y cordinate board
    for(i=0;i<8;i++)
    {
        hor=(1366/2)-(552/2)+20; // x cordinate board
        for(j=0;j<8;j++)
        {
            tile[i][j] = new Krorla(baseWidget); //Qt::WindowFlags f=0
            tile[i][j]->colorKrorla=(i+j)%2; //ដាក់ក្រឡារ
            tile[i][j]->piece=0; //ក្បាលដំណើរការកូនអុកនីមួយៗ
            tile[i][j]->row=i;//ដំណើរការ
            tile[i][j]->col=j;//ដំណើរការ
            tile[i][j]->numKrorla=k++;//លេខក្រឡារ
            tile[i][j]->displayKrorla();// display color ក្រឡាលើកូនអុក
            tile[i][j]->setGeometry(hor,ver,64,64); //ទំហំក្រឡារនីមួយៗ
            tile[i][j]->setCursor(mouse::get2());
            hor+=64; //size ពី១ទៅ១ = 64
        }
        ver+=64;//size ពី១ទៅ១ = 64
    }


    //Add pieceOuk to krorla ouk

    //black fish
    for(j=0;j<8;j++)
    {
        tile[2][j]->piece=1;
        tile[2][j]->colorPiece=0; //give color value
        tile[2][j]->display('P');
    }

    //white fish
    for(j=0;j<8;j++)
    {
        tile[5][j]->piece=1;
        tile[5][j]->colorPiece=1;
        tile[5][j]->display('P');
    }

    //white and black comfirming
    for(j=0;j<8;j++)
    {
        tile[0][j]->piece=1;
        tile[0][j]->colorPiece=0;
        tile[7][j]->piece=1;
        tile[7][j]->colorPiece=1;
    }
    //kon ouk at row 0 black
    {
    tile[0][0]->display('R'); //tuk
    tile[0][1]->display('H'); //horse
    tile[0][2]->display('B'); //kol
    tile[0][3]->display('Q'); //neang
    tile[0][4]->display('K'); //king
    tile[0][5]->display('B'); //kol
    tile[0][6]->display('H'); // house
    tile[0][7]->display('R'); // rock
    }

    //kon ouk at row 7 white
    {
    tile[7][0]->display('R');//tuk
    tile[7][1]->display('H');//horse
    tile[7][2]->display('B');//kol
    tile[7][3]->display('K');//king
    tile[7][4]->display('Q');//neang
    tile[7][5]->display('B');//kol
    tile[7][6]->display('H');//horse
    tile[7][7]->display('R');//tuk
    }

    tempTurn->setGeometry(x/8 + 50,y/2 + 80,100,100);
    tempTurn->setStyleSheet("QLabel {border-image: url(:/Image/king_black.png);}");

}

void findWinner(int check_king){

    if(check_king == 2){
        tempwinner->setGeometry(-15,y/2+260,436,123);
        tempWinner->start();
        tempwinner->setMovie(tempWinner);
        turn = 3;
    }else if(check_king == 1){
        tempwinner->setGeometry(x-421,y/2+260,436,123);
        tempWinner->start();
        tempwinner->setMovie(tempWinner);        
        turn = 3;
    }
    if(turn == 3 && winSound == 0){
        soundChess->winning();
        winSound = 1;
    }
}

void findKing(){
    int black = 0,white = 0;

    for(int i = 0;i<8;i++){
        for(int j = 0;i<8;i++){
            if(tile[j][i]->colorPiece == 0 && tile[i][j]->pieceName == 'K') black = 1;
            if(tile[j][i]->colorPiece == 1 && tile[i][j]->pieceName == 'K') white = 1;
        }
    }
    if(black == 0) check_king = 1;
    if(white == 0) check_king = 2;
}

void gotoRestart(){
    count=0;turn=0;max=0;check_king=0;winSound = 0;
    int i,j,k=0,hor,ver;

    ver=((768/2)-(512/2));
    for(i=0;i<8;i++)
    {
        hor=(1366/2)-(552/2)+20;
        for(j=0;j<8;j++)
        {

            tile[i][j]->colorKrorla=(i+j)%2;
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->numKrorla=k++;
            tile[i][j]->displayKrorla();
            tile[i][j]->setGeometry(hor,ver,64,64);
            tile[i][j]->display('z');

            hor+=64;
        }
        ver+=64;
    }


    for(j=0;j<8;j++)
    {
        tile[2][j]->piece=1;
        tile[2][j]->colorPiece=0; //give color value
        tile[2][j]->display('P');
    }


    for(j=0;j<8;j++)
    {
        tile[5][j]->piece=1;
        tile[5][j]->colorPiece=1;
        tile[5][j]->display('P');
    }


    for(j=0;j<8;j++)
    {
        tile[0][j]->piece=1;
        tile[0][j]->colorPiece=0;
        tile[7][j]->piece=1;
        tile[7][j]->colorPiece=1;
    }

    {
    tile[0][0]->display('R');
    tile[0][1]->display('H');
    tile[0][2]->display('B');
    tile[0][3]->display('Q');
    tile[0][4]->display('K');
    tile[0][5]->display('B');
    tile[0][6]->display('H');
    tile[0][7]->display('R');
    }


    {
    tile[7][0]->display('R');
    tile[7][1]->display('H');
    tile[7][2]->display('B');
    tile[7][3]->display('K');
    tile[7][4]->display('Q');
    tile[7][5]->display('B');
    tile[7][6]->display('H');
    tile[7][7]->display('R');
    }

    tempTurn->setGeometry(x/8 + 50,y/2 + 80,100,100);
    tempTurn->setStyleSheet("QLabel {border-image: url(:/Image/king_black.png);}");
    tempwinner->clear();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWidget *myWidget = new QWidget();
    tempUI = &w;
    tempWiget = myWidget; //extern to global
    accessories(myWidget);
    QLabel *Turn = new QLabel(myWidget); //for swap turn display
    QLabel *winner = new QLabel(tempWiget); //for swap winner
    tempwinner = winner;
    QMovie *Winner = new  QMovie(":/Image/winner.gif");
    tempWinner = Winner;
    tempTurn = Turn; //extern to global

    chessBoard(myWidget,tile);
    w.setMinimumSize(QSize(854,580));
    w.show();
    myWidget->setCursor(mouse::get1());
    myWidget->showFullScreen();
    myWidget->close();
   // myWidget->show();

    return a.exec();
}
