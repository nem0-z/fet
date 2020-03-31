%unos dva cijela broja n i m, a zatim ispisivanje matrice y dimenzija nxn.
%Matrica ima elemente jednake 3m^2, osim elemenata dijagonale koji su
%jednaki 2n. Ukoliko je n<=0 ili m<=0, skripta javlja gresku. Ako matrica
%ima paran broj redova ukloniti dva srednja reda iz matrice, a ako je broj
%redova neparan, ukloniti srednji red. Program kreirati bez koristenja
%petlji.

n = input('Upisi prvi broj -> ');
m = input('Upisi drugi broj -> ');
if n<=0 || m<=0
    error('n i m moraju biti pozitivni')
end
y = zeros(n);
x(1:n) = 2*n;
y = diag(x);
y(find(y==0)) = 3*m^2;
if mod(n,2) == 0
    y([n/2,n/2+1],:) = [];
else
   y(ceil(n/2),:) = []; 
end


