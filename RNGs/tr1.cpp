#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#include "RandF.h"

using namespace std;

int main(){
    RandF q(time(NULL));//inicializando com o time

    for(int i=0;i<10;i++){
       cout << "\n x = " << q.mlcg_Mod64()<<endl;
    }

    return 0;
}
