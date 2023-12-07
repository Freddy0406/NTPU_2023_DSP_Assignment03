clc
clear 
close all

M_1 = load('M_1_LPF.txt');
M_4 = load('M_4_LPF.txt');
M_16 = load('M_16_LPF.txt');
M_64 = load('M_64_LPF.txt');
M_256 = load('M_256_LPF.txt');
M_512 = load('M_512_LPF.txt');
M_1024 = load('M_1024_LPF.txt');
M_2048 = load('M_2048_LPF.txt');


figure(1);
subplot(2,1,1)
x =linspace(-pi,pi,length(M_1));
plot(x,M_1)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=1 filter(Hamming window)');
subplot(2,1,2)
x =linspace(-pi,pi,length(M_4));
plot(x,M_4)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=4 filter(Hamming window)');


figure(2);
subplot(2,1,1)
x =linspace(-pi,pi,length(M_16));
plot(x,M_16)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=16 filter(Hamming window)');
subplot(2,1,2)
x =linspace(-pi,pi,length(M_64));
plot(x,M_64)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=64 filter(Hamming window)');


figure(3);
subplot(2,1,1)
x =linspace(-pi,pi,length(M_256));
plot(x,M_256)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=256 filter(Hamming window)');
subplot(2,1,2)
x =linspace(-pi,pi,length(M_512));
plot(x,M_512)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=512 filter(Hamming window)');


figure(4);
subplot(2,1,1)
x =linspace(-pi,pi,length(M_1024));
plot(x,M_1024)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=1024 filter(Hamming window)');
subplot(2,1,2)
x =linspace(-pi,pi,length(M_2048));
plot(x,M_2048)
xlabel("\omega");
xticks([-pi -0.8*pi -0.6*pi -0.4*pi -0.2*pi 0 0.2*pi 0.4*pi 0.6*pi 0.8*pi pi])
xticklabels({'-\pi','-0.8\pi','-0.6\pi','-0.4\pi','-0.2\pi','0','0.2\pi','0.4\pi','0.6\pi','0.8\pi','\pi'})
title('M=2048 filter(Hamming window)');
