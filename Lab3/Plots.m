%%
clc
clear
close
Data = load('PitchRategyrovsencoderoneaxis.mat');
Data2 = load('ElevationRategyrovsencoderoneaxis.mat');
Data3 = load('TravelRategyrovsencoderoneaxis.mat');

%%
figure(1);

plot(Data.ans(1,2001:4225), Data.ans(2,2001:4225),'r')
hold on

plot(Data.ans(1,2001:4225), Data.ans(3,2001:4225),'b')
hold on
title('Pitch solo')
legend({'Pitch rate Encoder','Gyroscope'},'FontSize',35,'Location','best');


%%
figure(2);

plot(Data.ans(1,9001:13942), Data.ans(2,9001:13942),'r')
hold on

plot(Data.ans(1,9001:13942), Data.ans(3,9001:13942),'b')
hold on
title('Pitch all axis')
legend({'Pitch rate Encoder','Gyroscope'},'FontSize',35,'Location','best');

%%
figure(3);

plot(Data2.ans(1,4001:6501), Data2.ans(2,4001:6501),'r')
hold on

plot(Data2.ans(1,4001:6501), Data2.ans(3,4001:6501),'b')
hold on
title('Elevation solo')
legend({'Elevation rate Encoder','Gyroscope'},'FontSize',35,'Location','best');
%%
figure(4);

plot(Data2.ans(1,9001:13942), Data2.ans(2,9001:13942),'r')
hold on

plot(Data2.ans(1,9001:13942), Data2.ans(3,9001:13942),'b')
hold on
title('Elevation all axis')
legend({'Elevation rate Encoder','Gyroscope'},'FontSize',35,'Location','best');

%%
figure(5);

plot(Data3.ans(1,6501:9001), Data3.ans(2,6501:9001),'r')
hold on

plot(Data3.ans(1,6501:9001), Data3.ans(3,6501:9001),'b')
hold on
title('Travel solo')
legend({'Travel rate Encoder','Gyroscope'},'FontSize',35,'Location','best');

%%
figure(6);

plot(Data3.ans(1,9001:13942), Data3.ans(2,9001:13942),'r')
hold on

plot(Data3.ans(1,9001:13942), Data3.ans(3,9001:13942),'b')
hold on
title('Travel all axis')
legend({'Travel rate Encoder','Gyroscope'},'FontSize',35,'Location','best');

%%
clear all
close
clc
Data = load('Acceleration.mat');

figure(7);
plot(Data.ans(1,:), Data.ans(2,:),'r')
title('Acceleration in X direction')
legend({'X direction'},'FontSize',50,'Location','best');

figure(8);
plot(Data.ans(1,:), Data.ans(3,:),'r')
title('Acceleration in Y direction')
legend({'Y direction'},'FontSize',50,'Location','best');

figure(9);
plot(Data.ans(1,:), Data.ans(4,:),'r')
title('Acceleration in Z direction')
legend({'Z direction'},'FontSize',50,'Location','best');

%%
clear all
close
clc
Data = load('TransformedPitch.mat');
Data1 = load('TransformedPitchRate.mat');
Data2 = load('TransformedElevation.mat');
Data3 = load('TransformedElevationRate.mat');
Data4 = load('TransformedTravelRate.mat');


figure(10);
plot(Data.ans(1,:), Data.ans(2,:),'r')
hold on
plot(Data.ans(1,:), Data.ans(3,:),'b')
title('Pitch')
legend({'Transformed pitch','Encoder pitch'},'FontSize',35,'Location','best');

figure(11);
plot(Data1.ans(1,:), Data1.ans(2,:),'r')
hold on
plot(Data1.ans(1,:), Data1.ans(3,:),'b')
title('Pitch Rate')
legend({'Transformed pitch rate','Encoder pitch rate'},'FontSize',35,'Location','best');

figure(12);
plot(Data2.ans(1,:), Data2.ans(2,:),'r')
hold on
plot(Data2.ans(1,:), Data2.ans(3,:),'b')
title('Elevation')
legend({'Transformed Elevation','Encoder Elevation'},'FontSize',35,'Location','best');

figure(13);
plot(Data3.ans(1,80:14869), Data3.ans(2,80:14869),'r')
hold on
plot(Data3.ans(1,80:14869), Data3.ans(3,80:14869),'b')
title('Elevation rate')
legend({'Transformed Elevation rate','Encoder Elevation rate'},'FontSize',25,'Location','best');

figure(14);
plot(Data4.ans(1,:), Data4.ans(2,:),'r')
hold on
plot(Data4.ans(1,:), Data4.ans(3,:),'b')
title('Travel rate')
legend({'Transformed Travel rate','Encoder Travel rate'},'FontSize',35,'Location','best');

%%

clear all
close
clc

Data = load('StatePitch.mat');
Data1 = load('StatePitchR.mat');
Data2 = load('StateElevation.mat');
Data3 = load('StateElevationR.mat');
Data4 = load('StateTravelR.mat');


figure(15);
plot(Data.ans(1,:), Data.ans(2,:),'r')
hold on
plot(Data.ans(1,:), Data.ans(3,:),'b')
title('Pitch')
legend({'Encoder pitch','SE pitch'},'FontSize',35,'Location','best');

figure(16);
plot(Data1.ans(1,:), Data1.ans(2,:),'r')
hold on
plot(Data1.ans(1,:), Data1.ans(3,:),'b')
title('Pitch rate')
legend({'Encoder pitch rate','SE pitch rate'},'FontSize',35,'Location','best');

figure(17);
plot(Data2.ans(1,:), Data2.ans(2,:),'r')
hold on
plot(Data2.ans(1,:), Data2.ans(3,:),'b')
title('Elevation')
legend({'Encoder elevation','SE elevation'},'FontSize',35,'Location','best');

figure(18);
plot(Data3.ans(1,122:8855), Data3.ans(2,122:8855),'r')
hold on
plot(Data3.ans(1,122:8855), Data3.ans(3,122:8855),'b')
title('Elevation rate')
legend({'Encoder elevation rate','SE elevation rate'},'FontSize',35,'Location','best');

figure(19);
plot(Data4.ans(1,:), Data4.ans(2,:),'r')
hold on
plot(Data4.ans(1,:), Data4.ans(3,:),'b')
title('Travel rate')
legend({'Encoder travel rate','SE travel rate'},'FontSize',35,'Location','best');