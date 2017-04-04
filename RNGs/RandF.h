/*
Baseado em:
''''''''
(F) MLCG with m >> 2^32, m Prime, and a(m- 1)~ 2^64

state: x (unsigned 64-bit)
initialize: 1  =< x => m - 1
update:  x = ax (mod m)
can use as random: x (1 =< x => m - 1) or low 32 bits
can us in bit mix :as( but don't use both ax nad x) 
can improve by: output 64-bit xorshift successor of ax
period : m-1

Recommended values
ID 		m	 		a
F1 1148 x 2^32 + 11 = 4930622455819 	3741260
F2 1264 x 2^32 + 9 = 5428838662153 	3397916
F3 2039 x 2^32 + 3 = 8757438316547 	2106408
''''''''''
Do livro Numerical Recipes

*/
#ifndef RANDF_H
#define RANDF_H

class RandF{
    unsigned long long  x;// a =3741260; m =4930622455819;
    unsigned long long  s;//SEED
    public:
    RandF(unsigned long long seed) : s(seed),x((3741260 * s)% 4930622455819){
    }
    int mlcg_Mod64(){
        x=(3741260 * x)% 4930622455819;
        return x%10;
    }

};

#endif