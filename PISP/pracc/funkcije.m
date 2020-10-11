clear all
close all
clc

%fja za pronalazenje najveceg elementa vektora x
x = [45 -3 18 2 4 3 16 -25];
max = maxfun(x);



%funkcija overallScore racuna ukupan broj brodova studenta za tri uradjena
%testa, ulazi su vektor red scores i vektor red weights a izlaz je skalar 

scores = [75 80 71];
weights = [0.2 0.3 0.5];
bod = overallScore(scores,weights);

%funkcija dijagonala koja uzima vektor x i vraca matricu m takvu da su svi
%rubni elementi jednaki 1 a sporednu dijagonalu submatrice cine elementi
%vektora x

matrix = dijagonala([4 1 7 8 5]);

%funkcija plotSin(f1), crta sinusoidu s frekvencijom f1 na intervalu
%[0,2pi], koristiti 16 tacaka po periodu

%plotSin(5);

%faktorijel broja, ako je ulaz manji od 0, vrati NaN

faktorijel(5);

%funkcija par_nepar(value)

par_nepar(4965437);

%funkcija FtoC(donja,gornja,korak) koja temp iz F pretvori u C. Funkcija
%prima 3 argumenta i daje tablerni prikaz temperatura u opsegu od donja do
%gornja sa korakom korak. funkcija nema povratnih vrijednosti i jos trazi
%da svaki broj prikazes sa .2f

FtoC(50,100,2);

function FtoC(donja,gornja,korak)
    fahr = donja;
    fprintf("Fahr\tCels\n");
    while(fahr<=gornja)
       cels = 5/9*(fahr-32);
       fprintf("%.2f\t%.2f\n",fahr,cels);
       fahr = fahr+korak;
    end
end

function par_nepar(value)
    if value == 0 
        fprintf("%d nije nista hahaha\n",value);
    elseif mod(value,2) == 0 
        fprintf("%d je paran broj.\n",value);
    else fprintf("%d je neparan broj.\n",value);
    end
end

function rez = faktorijel(n)
if n<0
    rez = NaN;
elseif n == 0
    rez = 0;
else
    rez = 1;
    for i = n:-1:1
        rez = rez*i;
    end
end
end

    

function plotSin(f1,f2) %ovo je kad ne vraca nista tj void
    x = linspace(0,2*pi,f1*16+1);
    if nargin == 1
        plot(x,sin(f1*x));
    elseif nargin == 2
        disp('Zadali ste dvije ulazne vrijednosti');
    end
end

function m = dijagonala(x)
   m = ones(length(x)+2);
   m(end-1:-1:2,2:end-1) = diag(x);
end

function bodovi = overallScore(funScores,funWeights)
    bodovi = funScores*funWeights';
end

function maxVal = maxfun(vektor)

if nargin ~=1
    error('Funkcija ima samo jedan ulaz')
end

if nargout ~=1
    error('Funkcija ima samo jedan izlaz')
end

n = length(vektor);
maxVal = vektor(1);
for i = 1:n
    if vektor(i)>maxVal
        maxVal = vektor(i);
    end
end

end
    