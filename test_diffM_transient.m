clc
clear 
close all

%% Load data
sin3500Hz_M1 = load('sin3500Hz_M1.txt');
sin3500Hz_M4 = load('sin3500Hz_M4.txt');
sin3500Hz_M16 = load('sin3500Hz_M16.txt');
sin3500Hz_M64 = load('sin3500Hz_M64.txt');
sin3500Hz_M256 = load('sin3500Hz_M256.txt');
sin3500Hz_M512 = load('sin3500Hz_M512.txt');
sin3500Hz_M1024 = load('sin3500Hz_M1024.txt');
sin3500Hz_M2048 = load('sin3500Hz_M2048.txt');

sin5000Hz_M1 = load('sin5000Hz_M1.txt');
sin5000Hz_M4 = load('sin5000Hz_M4.txt');
sin5000Hz_M16 = load('sin5000Hz_M16.txt');
sin5000Hz_M64 = load('sin5000Hz_M64.txt');
sin5000Hz_M256 = load('sin5000Hz_M256.txt');
sin5000Hz_M512 = load('sin5000Hz_M512.txt');
sin5000Hz_M1024 = load('sin5000Hz_M1024.txt');
sin5000Hz_M2048 = load('sin5000Hz_M2048.txt');



%% 3500Hz with different M
subplot(4,1,1)
title('123');
plot(sin3500Hz_M1);
title('f = 3500Hz, M = 1');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(sin3500Hz_M4);
title('f = 3500Hz, M = 4');
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
plot(sin3500Hz_M64);
title('f = 3500Hz, M = 64');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 3500Hz, M = 1,4,16,64');

figure(2);
subplot(4,1,1)
title('123');
plot(sin3500Hz_M256);
title('f = 3500Hz, M = 256');
xlim([44100 45100]);
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(sin3500Hz_M512);
title('f = 3500Hz, M = 512');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,3)
plot(sin3500Hz_M1024);
title('f = 3500Hz, M = 1024');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,4)
plot(sin3500Hz_M2048);
title('f = 3500Hz, M = 2048');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 3500Hz, M = 256,512,1024,2048');



%% 5000Hz with different M

figure(3);
subplot(4,1,1)
plot(sin5000Hz_M1);
title('f = 5000Hz, M = 1');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(sin5000Hz_M4);
title('f = 5000Hz, M = 4');
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
plot(sin5000Hz_M64);
title('f = 5000Hz, M = 64');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 5000Hz, M = 1,4,16,64');


figure(4);
subplot(4,1,1)
plot(sin5000Hz_M256);
title('f = 5000Hz, M = 256');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,2)
plot(sin5000Hz_M512);
title('f = 5000Hz, M = 512');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,3)
plot(sin5000Hz_M1024);
title('f = 5000Hz, M = 1024');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')

subplot(4,1,4)
plot(sin5000Hz_M2048);
title('f = 5000Hz, M = 2048');
xlim([44100 45100])
xlabel('Data points')
ylabel('Amplitude')
sgtitle('Observe transient state, f = 5000Hz, M = 256,512,1024,2048');



clear;