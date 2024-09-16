from sage.all import *
from pwn import *
from Crypto.Cipher import AES
from Crypto.Hash import SHA256
from Crypto.Util.number import long_to_bytes
from random import randrange
from Curve import Curve
from Point import Point
from tqdm import trange
import time

p = 270879100143337507464856055339906615359
a = 172544107435811290184412131185681457851
b = 118856083945281878017061978061042082014
G = Point(197825721128800711261224196133971055239, 45407307839018770101667029022945930684)

#Novotney: ”Weak Curves In Elliptic Curve Cryptography”, 2010, http://wstein.org/edu/2010/414/projects/novotney.pdf
def PohligHellman(P, Q): # Q = dP
    
    n = P.order()
    factors = factor(n)
    factorList = []
    kList = []
    for p in factors:
        zList = [0]
        P0 = ZZ(n/p[0]) * P
        factorList.append(p[0]**p[1])
        ki = 0
        for e in range(p[1]):
            Qpart = Q
            for j in range(1, e+1):
                Qpart -= ZZ(zList[j]*(p[0]**(j-1))) * P
            Qi = ZZ(n/(p[0]**(e+1))) * Qpart
            zList.append(discrete_log(Qi, P0, operation='+')) # Qi = ki * P0
            ki += zList[e+1]*(p[0]**e)
        kList.append(ki)

    return crt(kList, factorList)



d = randrange(p)
Z = Zmod(p)
E = EllipticCurve(Z, [a, b])
P = E([G.x, G.y])
Q = d*P

start = time.time()
if d == PohligHellman(P, Q):
    print('Success')
end = time.time()
print(f'time : {end-start}')

start = time.time()
print(discrete_log(Q, P, operation='+'))
end = time.time()
print(f'time : {end-start}')