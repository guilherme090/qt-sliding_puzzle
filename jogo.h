#ifndef JOGO_H
#define JOGO_H
#include<QObject>


class jogo : public QObject
{
private:
    int sentinela; //posicao relativa ao espaco em branco no quebra cabeca

public:
    jogo();

public slots:
    int procurarEspaco (int linha, int coluna);
    void trocarDois (int matriz [4][4], int linA, int colA, int linB, int colB);

signals:
    void houveTroca (int peca1, int peca2);

private:
    int posicoes [4][4];
};

#endif // JOGO_H
