% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring

clear
close
%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

%%%%%%%%%%Caltulated variabels
Vs_o = 7.743;
Kf = 0.129;
L1= Kf*l_p;
K1 =(L1)/(2*m_p*(l_p)^2);
L3 = l_h*Kf;

Je = m_c*(l_c)^2 + 2*m_p*(l_h)^2;
Jl = m_c * (l_c)^2 + 2 * m_p * ((l_h)^2 + (l_p)^2);
K2 = L3/Je;
K3 = L3 * Vs_o/Jl;
%%%%%%%%%Choose desiered poles:
Pole1= -1+2j;
Pole2 = -1-2j;
%%%%%%%%%
Kpp = (Pole1*Pole2)/K1;
Kpd = (-Pole1-Pole2)/K1;

A = [0 1 0 0 0;
    0 0 0 0 0;
    0 0 0 0 0;
    1 0 0 0 0;
    0 0 1 0 0];
B = [0 0;
    0 K1;
    K2 0;
    0 0;
    0 0];
C = [1 0 0 0 0;
    0 0 1 0 0];
p =[-1 -1.2 -1.3];
q1 = 200;
q2 = 1;
q3 = 300;
q4 = 80;
q5 = 150;
r1 = 1;
r2 = 1;
Q = [q1 0 0 0 0;
    0 q2 0 0 0;
    0 0 q3 0 0;
    0 0 0 q4 0;
    0 0 0 0 q5];
R = [r1 0;
    0 r2];
K = lqr(A,B,Q,R);
%K= place(A,B,p);
%F1 = inv((B*K)-A);
%F2= inv(C*F1*B);
F = [K(1,1) K(1,3);
    K(2,1) K(2,3)];

%%%LAB3%%%%%
A1 = [0 1 0 0 0;
    0 0 0 0 0;
    0 0 0 1 0;
   0 0 0 0 0;
    K3 0 0 0 0];
B1 = [0 0;
    0 K1;
    0 0;
    K2 0;
    0 0];
C1 = eye(5);
D1 = zeros(5,2);

PORT = 7;


%%Lab4
%Task1
%Data = load('noiseMeasurement2.mat');
Data = load('noiseMeasurement3.mat');
Rd = cov(Data.ans(2:6,:)');

% figure(1);
% subplot(231);
% plot(Data.ans(1,:),Data.ans(2,:))
% subplot(232);
% plot(Data.ans(1,:),Data.ans(3,:))
% subplot(233);
% plot(Data.ans(1,:),Data.ans(4,:))
% subplot(234);
% plot(Data.ans(1,:),Data.ans(5,:))
% subplot(235);
% plot(Data.ans(1,:),Data.ans(6,:))

%Task2
A4 = [0 1 0 0 0 0;
    0 0 0 0 0 0;
    0 0 0 1 0 0;
    0 0 0 0 0 0;
   0 0 0 0 0 1;
    K3 0 0 0 0 0];
B4 = [0 0;
    0 K1;
    0 0;
    K2 0;
    0 0;
    0 0];
C4 = [1 0 0 0 0 0;
      0 1 0 0 0 0;
      0 0 1 0 0 0;
      0 0 0 1 0 0;
      0 0 0 0 0 1];
D4 = zeros(6,2);
Ts = 0.002;
[Ad,Bd] = c2d(A4,B4,Ts);
Cd = C4;

qd1 = 0.00001;
qd2 = 0.00001;
qd3 = 0.000001;
qd4 = 0.0000001;
qd5 = 0.00001;
qd6 = 0.00001;

Qd = [qd1 0 0 0 0 0;
      0 qd2 0 0 0 0;
      0 0 qd3 0 0 0;
      0 0 0 qd4 0 0;
      0 0 0 0 qd5 0;
      0 0 0 0 0 qd6];
x0 = [0;
      0;
     -0.46;
      0;
      0;
      0];
pvec = [(0.0001) (0.0001) (1.57) (0.0001) (0.0001) (0.0001)];
P0 = diag(pvec); 
