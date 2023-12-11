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
%%  Calculate minimum phase(MP)
MP_M_4 = poly(zeros_M_4);
MP_M_16 = poly(zeros_M_16);
MP_M_64 = poly(zeros_M_64);

[data_3500hz_M4] = through_new_LPF(sin3500Hz,MP_M_4);
[data_3500hz_M16] = through_new_LPF(sin3500Hz,MP_M_16);
[data_3500hz_M64] = through_new_LPF(sin3500Hz,MP_M_64);

data_3500hz_M4 = data_3500hz_M4./30;
data_3500hz_M16 = data_3500hz_M16./300;
data_3500hz_M64 = data_3500hz_M64./3000;

[data_5000hz_M4] = through_new_LPF(sin5000Hz,MP_M_4);
[data_5000hz_M16] = through_new_LPF(sin5000Hz,MP_M_16);
[data_5000hz_M64] = through_new_LPF(sin5000Hz,MP_M_64);

data_5000hz_M4 = data_5000hz_M4./30;
data_5000hz_M16 = data_5000hz_M16./300;
data_5000hz_M64 = data_5000hz_M64./3000;


sin3500Hz_M4 = load('sin3500Hz_M4.txt');
sin3500Hz_M16 = load('sin3500Hz_M16.txt');
sin3500Hz_M64 = load('sin3500Hz_M64.txt');
sin5000Hz_M4 = load('sin5000Hz_M4.txt');
sin5000Hz_M16 = load('sin5000Hz_M16.txt');
sin5000Hz_M64 = load('sin5000Hz_M64.txt');

%% plot f = 3500hz

figure(1);
subplot(4,1,1)
plot(sin3500Hz_M4);
title('f = 3500Hz, M = 4');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(data_3500hz_M4);
title('f = 3500Hz, M = 4 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,3)
plot(sin3500Hz_M16);
title('f = 3500Hz, M = 16');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,4)
plot(data_3500hz_M16);
title('f = 3500Hz, M = 16 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 3500Hz, M = 4,16');

figure(2);
subplot(2,1,1)
plot(sin3500Hz_M64);
title('f = 3500Hz, M = 64');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(2,1,2)
plot(data_3500hz_M64);
title('f = 3500Hz, M = 64 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 3500Hz, M = 64');

%% plot f = 5000hz

figure(3);
subplot(4,1,1)
plot(sin5000Hz_M4);
title('f = 5000Hz, M = 4');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(data_5000hz_M4);
title('f = 5000Hz, M = 4 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,3)
plot(sin5000Hz_M16);
title('f = 5000Hz, M = 16');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,4)
plot(data_5000hz_M16);
title('f = 5000Hz, M = 16 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 5000Hz, M = 4,16');

figure(4);
subplot(2,1,1)
title('123');
plot(sin5000Hz_M64);
title('f = 5000Hz, M = 64');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(2,1,2)
plot(data_5000hz_M64);
title('f = 5000Hz, M = 64 (Minimum phase)');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 5000Hz, M = 64');




%% Function
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