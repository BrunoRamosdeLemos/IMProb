#MLCG Modulo 2^64
#missing : x have to be 64 bit
#(F) MLCG with m >> 2^32, m Prime, and a(m- 1)~ 2^64
#
#state: x (unsigned 64-bit)
#initialize: 1 =< x => m - 1
#update:  x = ax (mod m)
#can use as random: x (1 =< x => m - 1) or low 32 bits
#can us in bit mix :as( but don't use both ax nad x) 
#can improve by: output 64-bit xorshift successor of ax
#period : m-1
#Recommended values
#ID 		m	 		                   a
#F1 1148 x 2^32 + 11 = 4930622455819 	3741260
#F2 1264 x 2^32 + 9 = 5428838662153 	3397916
#F3 2039 x 2^32 + 3 = 8757438316547 	2106408
#

import time

class mlcg :
    seed=1
    a = 3741260
    x =None

    def __init__(self,seed):
        self.seed =seed
        self.x = (self.a * seed) % 4930622455819

    def randF(self):
        self.x = (self.a * self.x) % 4930622455819
        return self.x%10
#fim classe

