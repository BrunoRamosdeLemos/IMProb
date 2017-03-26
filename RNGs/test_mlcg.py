#testando para a randF

import math
import time
from mlcg_Mod64 import mlcg 

total=[0,0,0,0,0,0,0,0,0,0]

it = 100000 # numero de iteracoes
#inicializa
t=mlcg(int(time.time()))

for i in range(0,it):
    total[t.randF()]+=1

print("Resultados:\n-> N  : Frequencia")
for i in range(0,10):
    print("->",i," : ",total[i])    

#teste chi-square

exp= it/10

c =0.0

for i in range(0,10):
    c = c + (math.pow(( float(total[i]) - exp ),2))/exp  

tc = 16.919
print("Para 10 variaveis: X^2 = 16.919, e para :",it,"interações")

if tc > c :
    print("o valor de chi-square e: ",c,"\n-A hipotese passou no teste!!")
else:
    print("Hipotese não válida:\nValor de chi-square:",c)

