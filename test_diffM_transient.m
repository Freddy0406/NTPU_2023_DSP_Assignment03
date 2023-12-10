clc
clear 
close all


sin3500Hz_M4 = load('sin3500Hz_M4.txt');
sin3500Hz_M16 = load('sin3500Hz_M16.txt');
sin3500Hz_M64 = load('sin3500Hz_M64.txt');

sin5000Hz_M4 = load('sin5000Hz_M4.txt');
sin5000Hz_M16 = load('sin5000Hz_M16.txt');
sin5000Hz_M64 = load('sin5000Hz_M64.txt');


subplot(3,1,1)
title('123');
plot(sin3500Hz_M4);
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(3,1,2)
plot(sin3500Hz_M16);
title('Observe transient state');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(3,1,3)
plot(sin3500Hz_M64);
title('Observe transient state');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

sgtitle('Subplot Grid Title');

figure(2);
subplot(3,1,1)
plot(sin5000Hz_M4);
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(3,1,2)
plot(sin5000Hz_M16);
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(3,1,3)
plot(sin5000Hz_M64);
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')