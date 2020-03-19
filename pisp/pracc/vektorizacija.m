%vjezbanje 
clear all
close all
clc

x = rand(1,100);
indeksi = x(find(x>0.4 & x<0.6)); %nalazi elemente s tim uslovom 
%i formira vektor 'indeksi' na osnovu pronadjenih vrijednosti


y1 = linspace(1,100);
y2 = linspace(1,5,4); %linspace se moze overloadat, pazi koju verziju f-je koristis

a = [2 6 10 14 18 22];
b = [5 8 11 14 17 20];
c = [2 6 10 14 18 22];
d = [a;b;c]
d(3,:)
d(:,2)
d(:,2:4)
d(:,[2 4]) %pazi razlika izmedju ovog i linije iznad
d([3 2],[5 1])%ipak broji naopako

%kreiraj vektor od 100 random brojeva i izdvoji one manje od 40
s = rand(1,100)*100;
rez = s(find(s<40))

%kreiraj m-u A dimenzija 5x5, random brojevi [10,30]
%vrati treci red, swap 2nd col sa linspace vec[5:15,5]
%izbrisi 5th row i 1st col
%nadji indekse elemanata <15

A = 20*rand(5)+10;
r = A(3,:);
A(:,2) = linspace(5,15,5);
A(5,:) = []
A(:,1) = []
indeksi = find(A<15);

%kreiraj matricu y nxn dimenzija, elementi = 3m^2 osim dijagonale koji su
%2*n (zahtjevaj input m i n)
m = input('Unesi m ');
n = input('Unesi n ');
if (m<0 | n<0)
    error('Pogresan unos');
end
y = zeros(n);
t(1:n) = 2*n;
y = diag(t);
y(find(y==0)) = 3*m^2


