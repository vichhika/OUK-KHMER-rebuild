#include "oukpieceway.h"

oukpieceway::oukpieceway()
{

}

int oukpieceway::chooser(Krorla *temp){
    switch(temp->pieceName)
    {
    case 'P': allowValid=validateFish(temp);
              break;

    case 'R': allowValid=validateTuk(temp);
              break;

    case 'H': allowValid=validateHorse(temp);
              break;

    case 'K': allowValid=validateKing(temp);
              break;

    case 'Q': allowValid=validateNeang(temp);
              break;

    case 'B': allowValid=validateKol(temp);
              break;

    }
    openWay();

    return allowValid;
}

//tuk
int oukpieceway::validateFish(Krorla *temp){
    int row,col;

    col=temp->col;
    row=temp->row;
    returnValid=0;

    //White Tuk
    if(temp->colorPiece)
    {
        if(row-1>=0 && !tile[row-1][col]->piece) //general walk white tuk
        {
            way[max++]=tile[row-1][col]->numKrorla;

            returnValid=1;
        }

        if(row-1>=0 && col-1>=0) //white tuk eat on the left
        {

            if(tile[row-1][col-1]->colorPiece!=temp->colorPiece && tile[row-1][col-1]->piece) // improve tile[row-1][col-1]->pieceColor!=temp->pieceColor && tile[row-1][col-1]->piece
            {

            way[max++]=tile[row-1][col-1]->numKrorla;

            returnValid=1;
            }
        }

        if(row-1>=0 && col+1<=7) //white tuk eat on the right
        {
            if(tile[row-1][col+1]->colorPiece!=temp->colorPiece && tile[row-1][col+1]->piece) //improve tile[row-1][col+1]->pieceColor!=temp->pieceColor && tile[row-1][col+1]->piece
            {
                way[max++]=tile[row-1][col+1]->numKrorla;

                returnValid=1;
            }
        }
    }
    //Black tuk
    else
    {
        if(row+1<=7 && !tile[row+1][col]->piece)//general walk black tuk
        {
            way[max++]=tile[row+1][col]->numKrorla;
            returnValid=1;
        }

        if(row+1<=7 && col-1>=0) //black tuk eat on the left
        {
            if(tile[row+1][col-1]->colorPiece!=temp->colorPiece && tile[row+1][col-1]->piece)
            {
                way[max++]=tile[row+1][col-1]->numKrorla;
                returnValid=1;
            }
        }

        if(row+1<=7 && col+1<=7) //white tuk eat on the right
        {
            if(tile[row+1][col+1]->colorPiece!=temp->colorPiece && tile[row+1][col+1]->piece)
            {
                way[max++]=tile[row+1][col+1]->numKrorla;
                returnValid=1;
            }
        }
    }

    return returnValid;
}


//tuk
int oukpieceway::validateTuk(Krorla *temp)
{
    int r,c;

    returnValid=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)//walk up
    {
        if(!tile[r][c]->piece)//ដើរទៅមុខបើគ្មាន object
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
        }

        else if(tile[r][c]->colorPiece==temp->colorPiece)//អត់សុីបើសិនជាមាន កូនអុក color ដូចគ្នា //retval 0 បើគ្មានផ្លូវដើរ
            break;

        else if(tile[r][c]->colorPiece!=temp->colorPiece)//សុីបើសិនជាមាន កូនអុក color មិនដូចដូចគ្នា
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)//walk down
    {
        if(!tile[r][c]->piece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
        }

        else if(tile[r][c]->colorPiece==temp->colorPiece)
            break;

        else if(tile[r][c]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)//walk right
    {
        if(!tile[r][c]->piece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
        }

        else if(tile[r][c]->colorPiece==temp->colorPiece)
            break;

        else if(tile[r][c]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)//walk left
    {
        if(!tile[r][c]->piece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
        }

        else if(tile[r][c]->colorPiece==temp->colorPiece)
            break;

        else if(tile[r][c]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r][c]->numKrorla;
            returnValid=1;
            break;
        }
    }


    return returnValid;
}


//HORSE
int oukpieceway::validateHorse(Krorla *temp)
{
    int r,c;
    returnValid=0;

    r=temp->row;
    c=temp->col;

    if(r-2>=0 && c-1>=0)//1
    {
        if(tile[r-2][c-1]->colorPiece!=temp->colorPiece || !tile[r-2][c-1]->piece) //eat or walk
        {
            way[max++]=tile[r-2][c-1]->numKrorla;
            returnValid=1;
        }
    }

    if(r-2>=0 && c+1<=7)//2
    {
        if(tile[r-2][c+1]->colorPiece!=temp->colorPiece || !tile[r-2][c+1]->piece)
        {
            way[max++]=tile[r-2][c+1]->numKrorla;
            returnValid=1;
        }
    }

    if(r-1>=0 && c-2>=0)//3
    {
        if(tile[r-1][c-2]->colorPiece!=temp->colorPiece || !tile[r-1][c-2]->piece)
        {
            way[max++]=tile[r-1][c-2]->numKrorla;
            returnValid=1;
        }
    }

    if(r-1>=0 && c+2<=7)//4
    {
        if(tile[r-1][c+2]->colorPiece!=temp->colorPiece || !tile[r-1][c+2]->piece)
        {
            way[max++]=tile[r-1][c+2]->numKrorla;
            returnValid=1;
        }
    }

    if(r+2<=7 && c+1<=7)//5
    {
        if(tile[r+2][c+1]->colorPiece!=temp->colorPiece || !tile[r+2][c+1]->piece)
        {
            way[max++]=tile[r+2][c+1]->numKrorla;
            returnValid=1;
        }
    }

    if(r+2<=7 && c-1>=0)//6
    {
        if(tile[r+2][c-1]->colorPiece!=temp->colorPiece || !tile[r+2][c-1]->piece)
        {
            way[max++]=tile[r+2][c-1]->numKrorla;
            returnValid=1;
        }
    }

    if(r+1<=7 && c-2>=0)//7
    {
        if(tile[r+1][c-2]->colorPiece!=temp->colorPiece || !tile[r+1][c-2]->piece)
        {
            way[max++]=tile[r+1][c-2]->numKrorla;
            returnValid=1;
        }
    }

    if(r+1<=7 && c+2<=7)//8
    {
        if(tile[r+1][c+2]->colorPiece!=temp->colorPiece || !tile[r+1][c+2]->piece)
        {
            way[max++]=tile[r+1][c+2]->numKrorla;
            returnValid=1;
        }
    }

    return returnValid;
}


//KING
int oukpieceway::validateKing(Krorla *temp)
{
    int r,c;
    returnValid=0;

    r=temp->row;
    c=temp->col;

    if(r-1>=0)//1 up
    {
        if(!tile[r-1][c]->piece || tile[r-1][c]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r-1][c]->numKrorla;
            returnValid=1;
        }
    }

    if(r+1<=7)//2 down
    {
        if(!tile[r+1][c]->piece || tile[r+1][c]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r+1][c]->numKrorla;
            returnValid=1;
        }
    }

    if(c-1>=0)//3 left
    {
        if(!tile[r][c-1]->piece || tile[r][c-1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r][c-1]->numKrorla;
            returnValid=1;
        }
    }

    if(c+1<=7)//4 right
    {
        if(!tile[r][c+1]->piece || tile[r][c+1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r][c+1]->numKrorla;
            returnValid=1;
        }
    }

    if(r-1>=0 && c-1>=0)//5 left up
    {
        if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r-1][c-1]->numKrorla;
            returnValid=1;
        }
    }

    if(r-1>=0 && c+1<=7) //6 right up
    {
        if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r-1][c+1]->numKrorla;
            returnValid=1;
        }
    }

    if(r+1<=7 && c-1>=0) //7 left down
    {
        if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r+1][c-1]->numKrorla;
            returnValid=1;
        }
    }

    if(r+1<=7 && c+1<=7)//8 right down
    {
        if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->colorPiece!=temp->colorPiece)
        {
            way[max++]=tile[r+1][c+1]->numKrorla;
            returnValid=1;
        }
    }

    return returnValid;
}


//QUEEN
int oukpieceway::validateNeang(Krorla *temp)
{

    int r,c;
        returnValid=0;

        r=temp->row;
        c=temp->col;


        if(r-1>=0 && c-1>=0)//5 left up
        {
            if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r-1][c-1]->numKrorla;
                returnValid=1;
            }
        }

        if(r-1>=0 && c+1<=7) //6 right up
        {
            if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r-1][c+1]->numKrorla;
                returnValid=1;
            }
        }
        if(r+1<=7 && c-1>=0) //7 left down
        {
            if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r+1][c-1]->numKrorla;
                returnValid=1;
            }
        }

        if(r+1<=7 && c+1<=7)//8 right down
        {
            if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r+1][c+1]->numKrorla;
                returnValid=1;
            }
        }

        return returnValid;
}

//BISHOP
int oukpieceway::validateKol(Krorla *temp)
{

    int r,c;
        returnValid=0;

        r=temp->row;
        c=temp->col;
        if(tile[r][c]->colorPiece){ //white bishop
            if(r-1>=0)//1 up
                {
                    if(!tile[r-1][c]->piece || tile[r-1][c]->colorPiece!=temp->colorPiece)
                    {
                        way[max++]=tile[r-1][c]->numKrorla;
                        returnValid=1;
                    }
                }
        }else{ //black bishop
            if(r+1<=7)//2 down
            {
                if(!tile[r+1][c]->piece || tile[r+1][c]->colorPiece!=temp->colorPiece)
                {
                    way[max++]=tile[r+1][c]->numKrorla;
                    returnValid=1;
                }
            }
        }

        if(r-1>=0 && c-1>=0)//5 left up
        {
            if(!tile[r-1][c-1]->piece || tile[r-1][c-1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r-1][c-1]->numKrorla;
                returnValid=1;
            }
        }

        if(r-1>=0 && c+1<=7) //6 right up
        {
            if(!tile[r-1][c+1]->piece || tile[r-1][c+1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r-1][c+1]->numKrorla;
                returnValid=1;
            }
        }
        if(r+1<=7 && c-1>=0) //7 left down
        {
            if(!tile[r+1][c-1]->piece || tile[r+1][c-1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r+1][c-1]->numKrorla;
                returnValid=1;
            }
        }

        if(r+1<=7 && c+1<=7)//8 right down
        {
            if(!tile[r+1][c+1]->piece || tile[r+1][c+1]->colorPiece!=temp->colorPiece)
            {
                way[max++]=tile[r+1][c+1]->numKrorla;
                returnValid=1;
            }
        }

        return returnValid;
}


void oukpieceway::openWay() //color ផ្លូវដើរកូនអុក
{
    int i;

    for(i=0;i<max;i++){

        tile[way[i]/8][way[i]%8]->setStyleSheet("QLabel {background-image: url(:/Image/Select.png);background-color:gray;background-blend-mode: multiply;}:hover{border-image: url(:/Image/Select.png);background-color: green;}");
    }
}
