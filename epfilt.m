function Qf = epfilt(Q)
    % usuwanie zbędnych zer
    err = 100 * eps;
    nQ = length(Q);

    for i = nQ:-1:1
       if abs(Q(i)) < err
          Q(i) = 0;
       end
    end
    Qf = Q;
    for i = nQ:-1:2
       if Q(i)==0
          Qf = Q(1:i-1);
       end
    end
end