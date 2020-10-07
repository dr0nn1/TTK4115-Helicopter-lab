clc
clear
close
Data = load('pitch1lqr.mat');
Data2 = load('pitch2lqr.mat');
Data3 = load('pitch3lqr.mat');
Data4 = load('pitch4lqr.mat');
Data5 = load('pitch5lqr.mat');

figure(1);
plot(Data.ans(1,:), Data.ans(2,:),'k')

hold on

plot(Data.ans(1,:), Data.ans(3,:),'y')

hold on
plot(Data2.ans(1,:), Data2.ans(3,:),'m')

hold on
plot(Data3.ans(1,:), Data3.ans(3,:),'c')

hold on
plot(Data4.ans(1,:), Data4.ans(3,:),'r')

title('Pitch');
legend('Step=0.3','Test 1','Test 2','Test 3','Test 4');
hold off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Data = load('elevationRate1lqr.mat');
Data2 = load('elevationRate2lqr.mat');
Data3 = load('elevationRate3lqr.mat');
Data4 = load('elevationRate4lqr.mat');
Data5 = load('elevationRate5lqr.mat');

figure(2);
plot(Data.ans(1,:), Data.ans(2,:),'k')

hold on

plot(Data.ans(1,:), Data.ans(3,:),'y')

hold on
plot(Data2.ans(1,:), Data2.ans(3,:),'m')

hold on
plot(Data3.ans(1,:), Data3.ans(3,:),'c')

hold on
plot(Data4.ans(1,:), Data4.ans(3,:),'r')
xlim([14.9 16.6]);
ylim([-0.2 0.2]);
title('Elevation rate');
legend('Step=0.1','Test 1','Test 2','Test 3','Test 4','Location','southeast');

