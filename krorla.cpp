#include "krorla.h"
#include "oukpieceway.h"
#include <QDebug>
#include <QMovie>
#include "sound.h"

extern int count,turn,x,y,check_king;
extern QLabel *tempTurn;
extern QWidget *tempWiget;
extern Krorla *konDerm;
extern Krorla *tile[8][8];

oukpieceway *valid = new oukpieceway();
Sound *soundChess = new Sound();

void validate(Krorla *temp,int c);
void closeWay();
void Turn(QLabel * baseLabel);
extern void findWinner(int check_king);
extern void findKing();

void Krorla::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count); //this = all of variable and method

}

void Krorla::display(char elem)
{
    this->pieceName=elem; //pieceName in title.h = char តាងកូនអុក ex 'R' , 'Q'

    if(this->colorPiece && this->piece) //title color value and value
    {
        switch(elem)
        {
            case 'P': this->setPixmap(QPixmap(":/Image/fish_white.png"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/Image/tuk_white.png"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/Image/horse_white.png"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/Image/king_white.png"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/Image/neang_white.png"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/Image/kol_white.png"));
                      break;
        }
    }

    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/Image/fish_black.png"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/Image/tuk_black.png"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/Image/horse_black.png"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/Image/king_black.png"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/Image/neang_black.png"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/Image/kol_black.png"));
                  break;
        }
    }
    else
        this->clear();
}

void validate(Krorla *temp, int c) // c = ++count //tile temp = this
{
    int retValue,i;

    if(c==1) //mouse click
    {
        if(temp->piece && (temp->colorPiece==turn)) //turn = 1
        {

            //exp[max++]=temp->tileNum;
            retValue=valid->chooser(temp);

            if(retValue)
            {
                //swap temp to click1
                konDerm= new Krorla();
                temp->setStyleSheet("QLabel {background-color: green;}");
                konDerm=temp;
                //soundChess->chess();
            }
            else
            {
                temp->setStyleSheet("QLabel {background-color: red;}");
                //count=0;
                konDerm=temp;
            }
        }
        else
        {
            count=0;
            //ចុចលើក្រឡារគ្មានកូនអុក​ដែល​ retvalue = 0
            //skip
        }
    }

    else //unclick or//click again that count = 2 or upto
    {
        //temp ក្លាយជាក្រឡារ

        if(temp->numKrorla==konDerm->numKrorla) //check ថាតើចុចត្រូវកន្លែងចាស់អត់
        {
            konDerm->displayKrorla();//reset color លើក្រឡារអុកទៅដូចដើម
            closeWay(); //reset orange color លើក្រឡារអុកទៅដូចដើម
            max=0; //reset max
            count=0; //reset count
        }

        for(i=0;i<max;i++)
        {

            if(temp->numKrorla==way[i])//tile[row][col] walk on yellow way or eat
            {
                //check king
                if(temp->colorPiece == 0 && temp->pieceName == 'K') check_king = 1;
                if(temp->colorPiece == 1 && temp->pieceName == 'K') check_king = 2;

                //temp តំណាងអោយ object ដែល object ដើម click សុី
                //click គី object ដើមដែលត្រួវសុីគេ
                ////////////////////////

                if(konDerm->pieceName == 'P' && konDerm->colorPiece && konDerm->row == 3 ) konDerm->pieceName = 'Q';//បក កូនស
                    //if(click1->tileNum >= 16 || click1->tileNum <=23)click1->pieceName = 'Q';
                if(konDerm->pieceName == 'P' && !konDerm->colorPiece && konDerm->row == 4 ) konDerm->pieceName = 'Q';//បក កូនខ្មៅ
                    //if(click1->tileNum >= 40 || click1->tileNum <=47)click1->pieceName = 'Q';
                ////////////////////////
                konDerm->piece=0;// ក្រឡាទទេរ //false condition in display to load picture
                temp->piece=1;//មានកូនអុកដើរចូលទៅ

                temp->colorPiece=konDerm->colorPiece;//ដាក់ color កូនអុក
                temp->pieceName=konDerm->pieceName;//ដាក់​ name កូនអុក
                konDerm->display(konDerm->pieceName);//load picture កូនអុកអោយ click1
                temp->display(konDerm->pieceName);//load picture កូនអុក click1

                konDerm->displayKrorla();//reset​ color ក្រឡារអុក
                temp->displayKrorla();//reset​ color ក្រឡារអុក
                konDerm->pieceName = 'Z'; //ការពារ win lose ពេលដើរផ្លួវចាស់របស់ king
                retValue=0;// improve valid->check();

                closeWay(); //remove orange way

                max=0; //reset max

                turn=(turn+1)%2; //change turn when count = 2 or upto
                count=0; //reset count
                soundChess->chess();
            }

            else
                count=count; // or count = 0;
        }
    }

    findWinner(check_king);
    Turn(tempTurn);
}

void Krorla::displayKrorla() /*colorលើក្រឡារchess*///reset color ក្រឡាអុកអោយទៅដូចដើមវិញ
{

    if(this->colorKrorla)
        this->setStyleSheet("QLabel {background-image: url(:/Image/white.png);}:hover{border-image: url(:/Image/Select.png);background-color: transparent;}");
    else
        this->setStyleSheet("QLabel {background-image: url(:/Image/black.png);}:hover{border-image: url(:/Image/Select.png);background-color: transparent;}");
}

void closeWay()
{
    int i;

    for(i=0;i<max;i++){
        tile[way[i]/8][way[i]%8]->displayKrorla(); //remove yellow display when unclick
    }



}

void Turn(QLabel * baseLabel){

    if(turn == 1){
        baseLabel->setGeometry(x - 2*(x/8),y/2 + 80,100,100);
        baseLabel->setStyleSheet("QLabel {border-image: url(:/Image/king_white.png);}");
    }
    else if(turn == 0){
        baseLabel->setGeometry(x/8 + 50,y/2 + 80,100,100);
        baseLabel->setStyleSheet("QLabel {border-image: url(:/Image/king_black.png);}");
    }
    else {
        baseLabel->setStyleSheet("QLabel {border-image: none;}");
    }
};
