clc
clear
close
Data = load('Pitch1.mat');
Data2 = load('Pitch2.mat');
Data3 = load('Pitch3.mat');

figure(1);
plot(Data.ans(1,:), Data2.ans(2,:),'k')
hold on

plot(Data.ans(1,:), Data2.ans(3,:),'b')
hold on

hold on
plot(Data2.ans(1,:), Data.ans(3,:),'m')

hold on
plot(Data3.ans(1,:), Data3.ans(3,:),'c')

legend({'Step= 0.3','Test 1','Test 2','Test 3'},'FontSize',60);
