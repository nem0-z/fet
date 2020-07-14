def printaj(lista):
    print([f'{i} of {type(i)}' for i in lista])


lista = ['1', '2', '3']
#printaj(lista)

nova_lista = map(int, lista)
#printaj(nova_lista)

class student:
    __slots__ = 'name', 'grade', 'uni'

    def __init__(self):
        pass

    def __str__(self):
        return '\nName: {}, Grade: {}, Uni: {}'.format(self.name,self.grade,self.uni)

    def compare(self,other):
        return self.grade < other.grade

    def addinfo(self,name_,grade_,other_):
        self.name = name_
        self.grade = grade_
        self.uni = other_

haso = student()
haso.addinfo('haso',9.54,'fet')

sinisa = student()
sinisa.addinfo('sinisa',9.32,'med')

print(haso, sinisa)
print(haso.compare(sinisa))
sinisa.grade = 9.76
print(haso.compare(sinisa))


def reversestr(s):
    return s[::-1]


test_string = "zlatan"
rev = reversestr(test_string)
print(rev, test_string)
edited_string = test_string.replace('a','4')
print(edited_string)

listica = [i for i in range(10)]
listica_reverse = reversed(listica)


for indices,vals in enumerate(zip(listica,listica_reverse)):
    print(f'\nValues {vals[0]} and {vals[1]} at index: {indices}')




