function [t, x]=rk4_pochylenie(u, x0, tf, nt, theta, kp, K, H, F)
% x0 wektor 3 elementowy na warunki początkowe 
% tf final time 
% nt number of time steps
% theta wektor 3 elementowy na parametry układu 
% kp do wyznaczenia jest
% K, H i F to jest K_opt itd z identyfikacji silnika

n = size(x0, 1); % number of control variables 
h = tf/nt; % step size  
x = zeros(nt+1, n);  t = zeros(nt+1, 1); %solution and time
xtmp = x0; 
x(1, :) = x0; 
tt = 0;

h_2 = h/2;  h_6 = h/6;  h_3 = h/3;

for i = 1:nt
    dx1 = rhs_pochylenie(u(i,:), xtmp, theta, kp, K, H, F);
        tmp = xtmp + h_2*dx1;   tt = tt + h_2;
    dx2 = rhs_pochylenie(u(i,:), tmp, theta, kp, K, H, F); 
        tmp = xtmp + h_2*dx2;
    dx3 = rhs_pochylenie(u(i,:), tmp, theta, kp, K, H, F); 
        tmp = xtmp+h*dx3;   tt = tt + h_2;
    dx4 = rhs_pochylenie(u(i,:), tmp, theta, kp, K, H, F);
        xtmp = xtmp + h_6*(dx1 + dx4) + h_3*(dx2 + dx3);
    x(i+1, :) = xtmp;
    t(i+1) = tt;
end
