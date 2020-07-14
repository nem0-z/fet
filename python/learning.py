with open('foo.py', 'r') as f:
    file_contents = f.read()

from math import factorial as fact

#print(file_contents.split('\n'))

list = [1, 2, 3, 4, 5]
for ind, num in enumerate(list):
    list[ind] = fact(num)

print(list)

str = 'sinisa'
