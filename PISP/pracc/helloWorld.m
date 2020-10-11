%vjezba
clear all
close all
clc

disp('Hello World!');
fprintf('Ja cu nauciti Matlab!\n');
load helloWorld
str = ['Ja sam poceo uciti Matlab u: ', start1];
fprintf('%s\n',str);

secPerMin = 60;
secPerHour = 60*secPerMin;
secPerDay = 24*secPerHour;
secPerMonth = 30.5*secPerDay;
secPerYear = 12*secPerMonth;
endOfClass = 5*secPerDay;
tau = 1.5*secPerDay;

secondConversion = [secPerYear secPerMonth secPerDay
                    secPerHour secPerMin 1];
                
currentTime = clock;
elapsedTime = currentTime - start;

%t = secondConversion*elapsedTime';
%ovo ne radi iz nekog razloga
%mislim da sam samo glup jer ovo radim u 3 ujutro
%ako neko skonta nek edituje :)...

tVec = linspace(0,endOfClass,10000);
knowledgeVec = 1-exp(-tVec/tau);

[val,i] = min(abs(knowledgeVec-0.5));
halfTime = tVec(i); %broj dana (pazi u sekundama ti je vec)
fprintf("Ja cu znati MATLAB nakon %g dana\n",halfTime/secPerDay);

