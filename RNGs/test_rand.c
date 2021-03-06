/*testa função nativa do c :
funcao  rand() ,
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>

void testPara(int nit, int n);
void teste_chi_square(int nit,int vtotal[],int n);

int main(){
    
    printf("----Ininciando Testes-----\n");
    int iteracao;
    int nvar;
    nvar=10;//dez variaveis

    //Fazendo os testes
    //10^5
    iteracao = 100000;
    printf("\n\n---------------------\n\nTeste 1\n---------------------\n",iteracao);
    testPara(iteracao,nvar);

    //10^6
    iteracao = 1000000;
    printf("\n\n---------------------\n\nTeste 2\n---------------------\n",iteracao);
    testPara(iteracao,nvar);

    //10^7
    iteracao = 10000000;
    printf("\n\n---------------------\n\nTeste 3\n---------------------\n",iteracao);
    testPara(iteracao,nvar);

     printf("\n\n\n----Fim do Testes-----\n");

    return 0;

}

void testPara(int nit,int n){
    srand(time(NULL));   // seed é o time
    int *total;
    total=(int *)malloc(sizeof(int)*n);
    int it = nit; //numero de interacoes
    int i;
    for (i=0; i<n; i++){
        total[i] = 0;
        }

    struct timeb start, end;//para o tempo de execução
    int diff;
    ftime(&start);
    for(i=0;i<it;i++){
        total[rand()%10]++;// incrementa total com frequencia do numeros de  0 a 9
    }
     ftime(&end); 

     diff = (int) (1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));

    printf("Feito em: %d (miliseconds)\nResultados:\n-> N  : Frequencia\n",diff);

    for(i=0;i<10;i++){
        printf("-> %d : %d \n",i,total[i]);
    }
    teste_chi_square(nit,total,n);
}


void teste_chi_square(int nit,int *vtotal,int n){
    //teste chi-square
    double exp = (double)nit/(double) n;//esperado
    double c = 0;//valor chi-square
    int i;

    for(i=0;i<n;i++){
        c = c + pow((double)vtotal[i] - exp,2)/exp;
    }
    //teste de hipotese
    double tc = 16.919;
    printf("\nTeste Chi-Square:\nPara %d variaveis: X^2 = 16.919 (95%%), e para : %d iterações",n,nit);

    if (tc > c) 
        printf("\n-O valor de chi-square e: %f\n-A hipotese passou no teste!!",c);
    else
        printf("\n-Hipotese não válida:\nValor de chi-square: %f",c);
}

