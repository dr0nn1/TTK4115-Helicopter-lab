function [x_prior, P_prior] = State_prediction(x_estimated, P_estimated,u,Ad,Bd,Qd,newData)

if newData
    % Update state estimate
    x_prior = Ad*x_estimated + Bd*u;
    % Update estimate error covariance
    P_prior = Ad*P_estimated*Ad'+Qd;
else
    x_prior = x_estimated;
    P_prior = P_estimated;
end
end