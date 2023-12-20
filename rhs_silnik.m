function dx=rhs_silnik(x, u, K, wsp)
    dx = K*(u - (wsp(1).*x.^3 + wsp(2).*x.^2 + wsp(3).*x + wsp(4)));
end