%B=1.0e-03*[-0.848170287584330   0.940238391138237];
%A=[1.000000000000000  -1.517299252907555   0.037957711373835   0.479841512347687];


% B = epfilt(B) ;
% 
% % zakłócenia deterministyczne
% Ag = [1 -1] ;
% 
% % faktoryzacja B  Bpl - stabilny , Bmin - niestabilny
% [Bpl, Bmin] = B_factor(B);
% 
% % Cel
% q = 0.983;
% al = 0.85;
% Am = conv([1 -2*q q^2],[1 -q]); % tu należy wpisać mianownik układu zamkniętego
% roots(Am)
% A0 = [1 -al];
% Bm = 1e4*Bmin*sum(Am)/sum(Bmin); % 
% 
% 
% %synteza regulatora
% [R,S,T] = pzpd(A,Bpl,Bmin,1,Am,Bm,A0,Ag);  

% LQ Regulator::::
Q = eye(3);
R2 = 2;
N = 0;
format long

[K,S,P] = lqr(A,B,Q,R2,N)
sys = ss((A - B*K), B, C, D)