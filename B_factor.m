function [Bpl, Bmin] = B_factor(B)
    % faktoryzacja wielomianu B
    Bmin = B(1);    % niestabilny
    Bpl = 1;        % stabilny
    nB = length(B)-1;
    if nB > 0
        rB = roots(B);
        kk = 1;
        ss = 1;
        for i = 1:nB
            if abs(rB(i)) >= 1
                rBmin(1, ss) = rB(i);
                ss = ss + 1;
            else
                rBpl(1, kk) = rB(i) ;kk = kk + 1 ;
            end
        end
        if ss > 1, Bmin = B(1) * poly(rBmin); end
        if kk > 1, Bpl = poly(rBpl); end
    end
end