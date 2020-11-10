from collections import Counter
import matplotlib.pyplot as plt
from pprint import pprint


#file = open('jezeva_kucica.txt', encoding='utf-8').read().lower().replace(' ', '').replace('\n', '')

file = open('aaiw.txt').read().lower().replace(' ', '').replace('\n', '')

c = Counter(file)

charCount = sum([freq for freq in c.values()])
x = dict()

for symbol, freq in zip(c.keys(), c.values()):
    x[freq/charCount] = symbol

mostCommon = x[sorted(x.keys(), reverse=True)[0]]
print(f'Najcesci simbol: {mostCommon}')

leastCommon = x[sorted(x.keys())[0]]
print(f'Najrijedji simbol: {leastCommon}')

secondMostCommon = x[sorted(x.keys(), reverse=True)[1]]
print(f'Dva najcesca simbola: "{mostCommon}" i "{secondMostCommon}"')

plt.stem(x.values(), x.keys())
plt.xlabel('Simbol')
plt.ylabel('Vjerovatnoca')
plt.grid()
plt.show()




