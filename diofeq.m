function [X,Y]=diofeq(A,B,C,nX,nY)
    % Funkcja rozwiazuje rownanie diofantyczne AX + BY = C
    A = A(:); 
    B = B(:); 
    C = C(:);
    nA = length(A) - 1;
    nB = length(B) - 1;
    nC = length(C) - 1;
    C = [C; zeros(nX+nY+2-nC-1, 1)];
    nC = length(C) - 1;
    
    if (nC+1) ~= (nX+nY+2); X = []; Y = []; return; end

    A_mtx = zeros(nX+nY+2, nX+nY+2);
    for i = 1:nX+1
        A_mtx(i:nA+i, i) = A;
    end
    ss=1;
    for i = nX+2:nX+nY+2
        A_mtx(ss:nB+ss, i) = B;
        ss = ss + 1;
    end
    %rcond(A_mtx)
    Z = A_mtx \ C;
    X = Z(1:nX+1)';
    Y = Z(nX+2:nX+nY+2)';
end
