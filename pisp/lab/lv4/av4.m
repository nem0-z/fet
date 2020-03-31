clear all
close all
clc

%ispisuje trougao zvjezdica u n(input) redova

n = input('Can we input anything in MATLAB without stupid string :)? ');

for rows = 1:n
    for stars = 1:rows
        fprintf('*');
    end
    fprintf('\n');
end

% ok let's improve this thing
% ok let's not it's not as easy as in C

%broj pozitivnih brojeva u vektoru

x = input('Unesi vektor -> ');
count = 0;
for i = 1:length(x)
    if (x(i) > 0)
        count = count + 1;
    end
end
fprintf("Broj pozitivnih brojeva je %d\n",count);

%indeks najveceg broja u vektoru, moze onaj odozgo
maxVal = x(1);
maxInd = 1;
for i = 1:length(x)
    if(x(i)>maxVal)
        maxVal = x(i);
        maxInd = i;
    end
end

%izracunaj vrijednost izraza k^2-50 za sve cijele brojeve u intervalu
%[-10,10] ali samo dok je k^2-50 >=0

for k = -10:1:10
   if (k^2-50)<0
       break;
   end
   val = k^2-50;
   fprintf("\nk = %d val = %g",k,val);
end
fprintf('\n');
%try catch nema potrebe probavati, najlakse je ovo objasniti kao da matlab
%sam baca iznimke automatski cim nesto ne valja ali budu neuhvacene pa
%crashuju program, ako hos da hvatas bilo sta gdje matlab moze da pukne
%onda to stavi u try catch uz odredjene ispise i to je to

%testing eval and feval

%eval interprets strings
testString = 'sin(n)';
n = 5;
y = eval(testString);

%get more info on eval and feval, they seem useless to you at this point
