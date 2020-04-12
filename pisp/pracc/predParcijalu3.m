clear all
close all
clc

test([1 2 3 4]);
% c = 'a';
% c = char(c+1)
% c = char(c+1)
% c = char(c+1)
% c = char(c+1)
% 
function test(n)
    s = size(n);
    if s(1)==1 && s(2)==1
        x = n.*eye(4);
        for i = 1:4
            n = n+2;
            x = x +diag(n.*ones(1,4-i),i) +diag(n.*ones(1,4-i),-i) ;
        end
        x = fliplr(x)
    end
    if s(1)==1 && s(2)>1
        l = length(n);
        m = max(n);
        b = round(4*rand(l)+5);
        b = b - diag(diag(b)) + diag(n);
        b = fliplr(b);
        a = zeros(l+2);
        a(2:end-1,2:end-1) = b;
        a(find(a==0)) = m
    end
    if s(1)>1 && s(2)>1
        disp('mat');
    end
end



