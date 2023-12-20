function dx=rhs_pochylenie(u, x, theta, kp, K, H, F)
% x wektor dwuelementowy zmiennej
% theta wektor trzyelementowy parametrów
    dx = [x(2); 
          theta(1) * x(2) + theta(2)* sin(x(1) - theta(3)) + kp * (F(1).*x(3).^3 + F(2).*x(3).^2 + F(3).*x(3) + F(4));
          K * (u - ((H(1).*x(3).^3 + H(2).*x(3).^2 + H(3).*x(3) + H(4))))];
end