clc
clear
close
Data = load('pitch.mat');
Data2 = load('pitch2.mat');
Data3 = load('pitch3.mat');
Data4 = load('pitch4.mat');
Data5 = load('pitch5.mat');
Data6 = load('pitch6.mat');
Data7 = load('pitch7.mat');


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

hold on
plot(Data5.ans(1,:), Data5.ans(3,:),'g')

hold on
plot(Data6.ans(1,:), Data6.ans(3,:))

hold on
plot(Data7.ans(1,:), Data7.ans(3,:),'b')


legend({'Step=0.6','Test 1','Test 2','Test 3','Test 4','Test 5','Test 6','Test 7'},'FontSize',25);
