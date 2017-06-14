/******************************************************************************************
Chauvenet.h
Autor: Gabriel Daltro Duarte
Data: 14 de junho de 2017

Descri��o: Os objetos dessa classe recebem um vetor de leituras, avalia estat�sticamente
cada elemento do vetor de leituras utlilizando o m�todo de Chauvenet, para determinar se
a leitura deve ser descartada ou n�o, por fim, calcula a m�dia das leituras que n�o foram
rejeitadas.
*******************************************************************************************/


#define TAM_MAX 30
//#define ARDUINO // Descomente quando compilar no Arduino
#define PC // Descomente quando compilar em um PC
#define DEBUG_ON_PC // Descomente para visualizar o calculo etapa a etapa - s� funciona no PC


#ifdef ARDUINO
    #include <math.h>
#endif // ADUINO

#ifdef PC
    #include <cmath>
#endif


class Chauvenet {
    public:
        Chauvenet( double* const ptrAmostras, int qtdAmostras); // Construtores da classe
        Chauvenet();

        bool setAmostras( double* const ptrAmostras, int qtdAmostras); // Passa para o objeto Chauvenet o vetor das amostras a serem avaliadas e o tamanho desse vetor
        void verificaAmostras(void); // Verifica cada amostra e determina quais ser�o descartadas
        double getMediaAposDescarte(void); // retorna a m�dia das amostras n�o descartadas

    private:
        int quantidadeDeAmostras;
        static float DS_CRITICO[27];
        double amostras[TAM_MAX];
        bool flagDeDescarte [TAM_MAX];
        double desvioPadrao;
        double mediaInicial;
        double mediaAposDescarte;

        void calculaMediaInicial(void);
        void calculaDesvioPadrao(void);
        void calculaMediaAposDescarte(void);
        double modulo (double);
};

