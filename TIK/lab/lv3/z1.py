import numpy as np
from numpy import random, sum, log2
import matplotlib.pyplot as plt

pYX = np.array([[0.6, 0.3, 0.1],
                [0.3, 0.3, 0.4],
                [0.4, 0.1, 0.5]])

px = np.array([1 / len(pYX) for _ in range(len(pYX))])

# a)
HYX = -sum(px * sum(pYX * log2(pYX)))

# b)
HX = -sum(px * log2(px))

# c)
HYXZ = HX + HYX

# zdruzene vjerovatnoce i entropija
min = 0.00001  # log2(0) no no
pxy = np.array([[px[0], min, min],
                [min, px[1], min],
                [min, min, px[2]]]) * pYX
Hyx = -sum(sum(pxy * log2(pxy)))

n = 10000;
s = 1
x = 0

pyIx = np.array([[0.6, 0.1, 0.3],
                 [0.3, 0.3, 0.4],
                 [0.4, 0.1, 0.5]])

a = random.rand(n)
x = np.zeros(n)
for i in range(n):
    b = round(0.51 + 2.98 * random.rand())
    if pyIx[b - 1, 0] > a[i]:
        s = 1
    elif (pyIx[b - 1, 0] + pyIx[b - 1, 1]) > a[i]:
        s = 2
    else:
        s = 3
    x[i] = s

py1 = sum([x == 1]) / len(x)
py2 = sum([x == 2]) / len(x)
py3 = sum([x == 3]) / len(x)

