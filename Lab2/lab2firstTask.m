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


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/  s^2]
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
K2 = L3/Je;

%%%%%%%%%Choose desiered poles:
Pole1= -1+2j;
Pole2 = -1-2j;
%%%%%%%%%
Kpp = (Pole1*Pole2)/K1;
Kpd = (-Pole1-Pole2)/K1;

A = [0 1 0;
    0 0 0 ;
    0 0 0];
B = [0 0;
    0 K1;
    K2 0];
C = [1 0 0 0 0;
    0 0 1 0 0];
p =[-2 -1-2*j -1+2*j];

K= place(A,B,p);

F = [K(1,1) K(1,3);
    K(2,1) K(2,3)];



