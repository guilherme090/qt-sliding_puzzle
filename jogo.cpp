#include "jogo.h"
#include <QObject>
#include <cstdlib>


jogo::jogo()
{
    sentinela = 0;
}

int jogo::procurarEspaco(int linha, int coluna){
    int n = sentinela; // tratar n como see a matriz fosse transformada em uma linha so

    if(coluna>0) if (posicoes[linha][coluna-1] == sentinela){
        n = 4*linha+(coluna-1)+1;
    }
    if(coluna<3) if (posicoes[linha][coluna+1] == sentinela){
        n = 4*linha+(coluna+1)+1;
    }
    if(linha>0) if (posicoes[linha-1][coluna] == sentinela){
        n = 4*(linha-1)+coluna+1;
    }
    if(linha<3) if (posicoes[linha+1][coluna] == sentinela){
        n = 4*(linha+1)+coluna+1;
    }
    return n;
}

void trocarDois(int matriz [4][4], int linA, int colA, int linB, int colB){
    int temp = matriz [linA][colA];
    matriz [linA][colA] = matriz [linB][colB];
    matriz [linB][colB] = temp;
}


void sortearPosicoes (int posicoes[4][4], int sentinela){
    //zerar todas as posicoes
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            posicoes [i][j] = sentinela;
        }
    }

    //Distribuir as posicoes
    //fingir que a matriz e um vetor e aplicar a funcao sobre um vetor
    for(int i=0; i<15; i++){
       int posSorteada = 1 + (rand() % 14) - i; //sorteia uma posicao vaga
       int cursor = 0; //pula as casas ja ocupadas
       for (int j=0; j<posSorteada; j++){
           if (posicoes [cursor/4][cursor%4] != 0){ //equivalente a posicoes [cursor] unidimensional
               cursor++;
           }
           cursor++;
       }
       posicoes [cursor/4][cursor%4] = posSorteada;
    }
}

bool estaCompleto (int matriz [4][4]){
    //adaptar ao espaco vazio na quarta posicao
    trocarDois(matriz, 0, 3, 3, 3);
    
    int pecaSequencial = 1;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if(matriz[i][j] != pecaSequencial) {
                //retornar matriz ao estado original
                trocarDois(matriz, 0, 3, 3, 3);
                return false;
            }
        }   
    }
    //retornar matriz ao estado original
    trocarDois(matriz, 0, 3, 3, 3);
    return true;
}
