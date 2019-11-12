#ifndef OUKPIECEWAY_H
#define OUKPIECEWAY_H
#include "krorla.h"

extern Krorla *tile[8][8];
extern int way[60],max;

class oukpieceway
{
    int allowValid,returnValid;

public:
    oukpieceway();
    int chooser(Krorla *temp);
    int validateKol(Krorla *temp);
    int validateNeang(Krorla *temp);
    int validateKing(Krorla *temp);
    int validateHorse(Krorla *temp);
    int validateTuk(Krorla *temp);
    int validateFish(Krorla *temp);
    void openWay();
};

#endif // VALIDATION_H
