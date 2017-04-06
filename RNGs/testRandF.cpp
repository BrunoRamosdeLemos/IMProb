
/*testa função Rand F definida em "RandF.h":
funcao  rand() ,
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>
#include "RandF.h"

void testPara(int it);

int main(){
    
    printf("----Iniciando Testes-----\n");
    int iteracao;

    //Fazendo os testes
    //10^5
    iteracao = 100000;
    printf("\n\n---------------------\n\nTeste 1\n---------------------\n",iteracao);
    testPara(iteracao);

    //10^6
    iteracao = 1000000;
    printf("\n\n---------------------\n\nTeste 2\n---------------------\n",iteracao);
    testPara(iteracao);

    //10^7
    iteracao = 10000000;
    printf("\n\n---------------------\n\nTeste 3\n---------------------\n",iteracao);
    testPara(iteracao);

     printf("\n\n\n----Fim do Testes-----\n");

    return 0;

}

void testPara(int nit){
    RandF q(time(NULL));   // seed é o time
    int total[10]={0,0,0,0,0,0,0,0,0,0};
    int it = nit; //numero de iteracoes
    
    int i;
    struct timeb start, end;//para o tempo de execução
    int diff;
    ftime(&start);
    for(i=0;i<it;i++){
        total[q.mlcg_Mod64()]++;// incrementa total com frequencia do numeros de  0 a 9
    }
     ftime(&end); 

     diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));

    printf("Feito em: %d (miliseconds)\nResultados:\n-> N  : Frequencia\n",diff);

    for(i=0;i<10;i++){
        printf("-> %d : %d \n",i,total[i]);
    }

    //teste chi-square
    double exp = (double)it/10;
    double c = 0;

    for(i=0;i<10;i++){
        c = c + pow((double)total[i] - exp,2)/exp;
    }
    //teste de hipotese
    double tc = 16.919;
    printf("\nPara 10 variaveis: X^2 = 16.919 (95%%), e para : %d interações",it);

    if (tc > c) 
        printf("\n-O valor de chi-square e: %f\n-A hipotese passou no teste!!",c);
    else
        printf("\n-Hipotese não válida:\nValor de chi-square: %f",c);
}

