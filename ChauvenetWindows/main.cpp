#include <iostream>
#include "Chauvenet.h"


int main ()
{
    double medidas[] = {1.0, 2.0, 3.0, 4.0, 100.0};

    // preencheu o vetor de amostras
    Chauvenet chauvenet;

    if (!chauvenet.setAmostras(medidas,5))
    {
        std::cout << "ERRO! A QUANTIDADE DE MEDIDAS DEVE SER ENTRE 4 E 30";
        return 0;
    }
    chauvenet.verificaAmostras();
    std::cout << "\n\nMedia das amostras apos o descarte: "<< chauvenet.getMediaAposDescarte() << "\n";

    return 0;
}
