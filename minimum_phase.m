clc;
clear
close all;

fs=44100;

sin3500Hz = load('sin3500Hz.txt');
sin5000Hz = load('sin5000Hz.txt');

M_1 = fliplr(load('h_M_1.txt'));
M_4 = fliplr(load('h_M_4.txt'));
M_16 = fliplr(load('h_M_16.txt'));
M_64 = fliplr(load('h_M_64.txt'));
M_256 = fliplr(load('h_M_256.txt'));
M_512 = fliplr(load('h_M_512.txt'));
M_1024 = fliplr(load('h_M_1024.txt'));
M_2048 = fliplr(load('h_M_2048.txt'));

zeros_M_1 = roots(M_1);
zeros_M_4 = roots(M_4);
zeros_M_16 = roots(M_16);
zeros_M_64 = roots(M_64);
zeros_M_256 = roots(M_256);
zeros_M_512 = roots(M_512);
zeros_M_1024 = roots(M_1024);
zeros_M_2048 = roots(M_2048);







