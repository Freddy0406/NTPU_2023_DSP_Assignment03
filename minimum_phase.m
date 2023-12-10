clc;
clear
close all;

fs=44100;
%% Load data
sin3500Hz = load('sin3500Hz.txt');
sin5000Hz = load('sin5000Hz.txt');
M_4 = load('h_M_4.txt');
M_16 = load('h_M_16.txt');
M_64 = load('h_M_64.txt');
%% Find roots(Zeros)
zeros_M_4 = roots(M_4);
zeros_M_16 = roots(M_16);
zeros_M_64 = roots(M_64);

%% conjugate reciprocal if abs(z)>1
for i = 1:length(zeros_M_4)
    if(abs(zeros_M_4(i))>1)
        zeros_M_4(i) = 1/conj(zeros_M_4(i));
    end
end

for i = 1:length(zeros_M_16)
    if(abs(zeros_M_16(i))>1)
        zeros_M_16(i) = 1/conj(zeros_M_16(i));
    end
end

for i = 1:length(zeros_M_64)
    if(abs(zeros_M_64(i))>1)
        zeros_M_64(i) = 1/conj(zeros_M_64(i));
    end
end
%% 
MP_M_4 = fliplr(poly(zeros_M_4));
MP_M_16 = fliplr(poly(zeros_M_16));
MP_M_64 = fliplr(poly(zeros_M_64));


[data_3500hz_M4] = through_new_LPF(sin3500Hz,MP_M_4);
[data_3500hz_M16] = through_new_LPF(sin3500Hz,MP_M_16);
[data_3500hz_M64] = through_new_LPF(sin3500Hz,MP_M_64);


data_3500hz_M4 = rescale(data_3500hz_M4,-1,1);
data_3500hz_M16 = rescale(data_3500hz_M16,-1,1);
data_3500hz_M64 = rescale(data_3500hz_M64,-1,1);
audiowrite('3500hz_MP_M4.wav',data_3500hz_M4,fs);
audiowrite('3500hz_MP_M16.wav',data_3500hz_M16,fs);
audiowrite('3500hz_MP_M64.wav',data_3500hz_M64,fs);






%% function
function [output] = through_new_LPF(data,channel)
    output = zeros(1,length(data));
    for n = 1:length(data)
        y = 0;
        for k = 1:length(channel)
            if((n-k)>0)
                y = y+channel(k)*data(n-k);
            end
        output(n) = round(y);
        end
    end
end