function [R,S,T] = pzpd(A,Bpl,Bmin,k,Am,Bm,A0,Ag)
    % Ewentualnie zwrócić więcej rzeczy idk 
    % pole zero placement   
    nAm = length(Am)-1;
    nA0 = length(A0)-1;
    nA = length(A)-1;
    nAg = length(Ag)-1;
    nBmin = length(Bmin)-1;

    AA = conv(A, Ag);  %AAg
    if k == 0
        BB = Bmin;
    else
        BB = conv(Bmin, [zeros(1, k) 1]); % z^(-k)Bmin
    end
    nF = k-1+nBmin;
    nG = max(nA+nAg-1, nA0+nAm-k-nBmin);

    CC = conv(Am, A0); % AmA0
    [F, G] = diofeq(AA, BB, CC, nF, nG); %AAgF + z^(-k)Bmin S = AmA0
    
    % F = epfilt(F);
    R = conv(conv(Ag, F), Bpl); % R = AgBplF
    S = G; % epfilt(G)
    T = conv(Bm, A0); % T=BmA0

    R = R/R(1);
    S = S/R(1);
    T = T/R(1);

    % Q = polysum(conv(AA, F), conv(BB, S));
    % Q = epfilt(Q);
end