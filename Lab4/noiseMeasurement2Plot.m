clc
clear
close
Data = load('noiseMeasurement2.mat');
figure(1);
plot(Data.ans(1,:), Data.ans(2,:),'k')

hold on

plot(Data.ans(1,:), Data.ans(3,:),'b')

hold on
plot(Data.ans(1,:), Data.ans(4,:),'m')

hold on
plot(Data.ans(1,:), Data.ans(5,:),'c')

hold on
plot(Data.ans(1,:), Data.ans(6,:),'r')


title('Noise when flying');
legend('Pitch','Pitch rate','Elevation','Elevation rate','Lambda rate','Location','best');
hold off