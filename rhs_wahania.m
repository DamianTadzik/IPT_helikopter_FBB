function dx=rhs_wahania(x, theta)
% x wektor dwuelementowy zmiennej
% theta wektor trzyelementowy parametrów
    dx = [x(2); 
          theta(1) * x(2) + theta(2)* sin(x(1) - theta(3))];
end