#include <iostream>
#include "Chauvenet.h"


int main ()
{
    // vetor que armazena as amostras a serem avaliadas
    double medidas[] = {1.0, 2.0, 3.0, 4.0, 100.0};

    // cria o objeto chauvenet
    Chauvenet chauvenet;

    // Imprime o vetor de amostras
    std::cout << "\n\nLista de amostras: ";
     for (int i = 0; i < 5; i++)
    {
        std::cout << medidas[i] << " ";
    }

    // passa o vetor de amostras e seu tamano para o objeto chauvenet
    if (!chauvenet.setAmostras(medidas,5))
    {
        std::cout << "ERRO! A QUANTIDADE DE MEDIDAS DEVE SER ENTRE 4 E 30";
        return 0;
    }

    //verifica quais amostras serão mantidas e quais serão descartadas
    chauvenet.verificaAmostras();
    std::cout << "\n\nMedia das amostras apos o descarte: "<< chauvenet.getMediaAposDescarte() << "\n";

    // Declara um ponteiros constante para dados constantes que aponta para o vetor de amostras descartadas
    const double* const amostrasDescartadas = chauvenet.getAmostrasRejeitadas();

    // imprime o vetor que armazena as amostras descartadas
    std::cout << "\n\nLista de amostras descartadas: ";

    for (int i = 0; i < chauvenet.getQtdAmostrasRejeitadas(); i++)
    {
        std::cout << amostrasDescartadas[i];
    }

    // Declara um ponteiros constante para dados constantes que aponta para o vetor de amostras NAO descartadas
     const double* const amostrasNaoDescartadas = chauvenet.getAmostrasNaoRejeitadas();

    // imprime o vetor que armazena as amostras descartadas
    std::cout << "\n\nLista de amostras NAO descartadas: ";

    for (int i = 0; i < chauvenet.getQtdAmostrasNaoRejeitadas(); i++)
    {
        std::cout << amostrasNaoDescartadas[i] << " ";
    }

     std::cout << "\n\n";
    return 0;
}
