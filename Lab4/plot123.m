%% Q = 0
load('dag4_Q0.mat')

% Pitch
figure
plot(data(1,:), data(8,:),'r') % nr. 8: pitch (Estimated value)
title('Q = 0')
hold on
plot(data(1,:),data(4,:),'b') % nr. 4: pitch (Encoder value)
legend({'Kalman pitch', 'Encoder pitch'},'FontSize',25,'Location','best');

%%
% Pich rate
figure
plot(data(1,:), data(9,:)) % nr. 9: pitch rate (Estimated value)
title('Q = 0')
xlabel('Time[sec]')
ylabel('Rad/sec')
hold on
plot(data(1,:),data(5,:)) % nr. 5: pitch rate (Encoder value)
legend('pitch rate (estimate)', 'pitch rate (encoder)')


% Elevation 
figure
plot(data(1,:), data(10,:)) % nr. 10: elevation (Estimated value)
title('Q = 0')
xlabel('Time[sec]')
ylabel('Rad/sec')
hold on
plot(data(1,:),data(6,:)) % nr. 6: elevation (Encoder value)
legend('elevation (estimate)', 'elevation (encoder)')


% Elevation rate
figure
plot(data(1,:), data(11,:)) % nr. 11: elevation rate (Estimated value)
title('Q = 0')
xlabel('Time[sec]')
ylabel('Rad/sec')
hold on
plot(data(1,:),data(7,:)) % nr. 7: elevation rate (Encoder value)
legend('elevation rate (estimate)', 'elevation rate (encoder)')


% Travel
figure
plot(data(1,:), data(12,:)) % nr. 12: travel (Estimated value)
title('Q = 0')
xlabel('Time[sec]')
ylabel('Rad/sec')
hold on
plot(data(1,:),data(2,:)) % nr. 2: travel (Encoder value)
legend('travel (estimate)', 'travel (encoder)')


% Travel rate
figure
plot(data(1,:), data(13,:)) % nr. 13: travel rate (Estimated value)
title('Q = 0')
xlabel('Time[sec]')
ylabel('Rad/sec')
hold on
plot(data(1,:),data(3,:)) % nr. 3: travel rate (Encoder value)
legend('travel rate (estimate)', 'travel rate (encoder)')