%Tror vi må ta dissa målingene her på nytt !!
clc
clear
close
Data = load('KalmanPitchInf.mat');
figure(2);
plot(Data.ans(1,:), Data.ans(3,:),'g')

hold on

plot(Data.ans(1,:), Data.ans(2,:),'r')


hold on
plot(Data.ans(1,:), Data.ans(4,:),'b')

title('Q = inf');
legend({'IMU','Kalman filter','Encoder'},'FontSize',35,'Location','best');
%%

clc
clear
close
Data = load('KalmanPitchZero.mat');
figure(3);
plot(Data.ans(1,:), Data.ans(2,:),'r')

hold on

plot(Data.ans(1,:), Data.ans(3,:),'g')


hold on
plot(Data.ans(1,:), Data.ans(4,:),'b')

title('Q = 0');
legend('Kalman filter','IMU','Encoder','Location','best');
