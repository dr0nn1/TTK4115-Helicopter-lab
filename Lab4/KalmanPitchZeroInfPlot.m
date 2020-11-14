%Tror vi må ta dissa målingene her på nytt !!
clc
clear
close
Data = load('KalmanPitchInf.mat');
figure(1);
plot(Data.ans(1,:), Data.ans(2,:),'r')

hold on

plot(Data.ans(1,:), Data.ans(3,:),'g')


hold on
plot(Data.ans(1,:), Data.ans(4,:),'b')

title('Q = inf');
legend('Kalman filter','IMU','Encoder','Location','best');
hold off