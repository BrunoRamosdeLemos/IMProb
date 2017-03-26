#testa função nativa do python 3.6 modulo secrets ,funcao randbelow

from secrets import randbelow
import math

total=[0,0,0,0,0,0,0,0,0,0]

it = 100 # numero de iteracoes

for i in range(0,it):
    total[randbelow(10)]+=1


print("Resultados:\n-> N  : Frequencia")
for i in range(0,10):
    print("->",i," : ",total[i])    

#teste chi-square

exp= it/10

c =0.0

for i in range(0,10):
    c = c + (math.pow(( float(total[i]) - exp ),2))/exp  

tc = 21.666
print("Para 10 variaveis: X^2 = 21.666, e para :",it,"interações")

if tc > c :
    print("o valor de chi-square e: ",c,"\n-A hipotese passou no teste!!")
else:
    print("Hipotese não válida:\nValor de chi-square:",c)



