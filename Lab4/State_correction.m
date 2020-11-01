function [x_estimated, P_estimated] = State_correction(y_imu, x_prior, P_prior, Cd, Rd, newData)

if newData
    I = eye(5);
    K = P_prior*Cd'/(Cd*P_prior*Cd'+Rd);
    x_estimated = x_prior + K*(y_imu-Cd*x_prior);
    P_estimated = (I-K*Cd)*P_prior*(I-K*Cd)' + K*Rd*K';
else
    x_estimated = x_prior;
    P_estimated = P_prior;
end   
end