function [t, x]=rk4_silnik(x0, u, tf, K, wsp)
% nt-number of time steps, nu-number of control variables
% size(u)=ntxnu, size(x)=nx1, tf- final time,
% wsp - parameters, size(wsp)=nwspx1.

nt=size(u,1) - 1;
n=length(x0);
h=tf/nt; % constant step
x=zeros(nt+1,n);
t=zeros(nt+1,1);%solution and time
xtmp=x0; x(1,:)=x0; tt=0;

h_2=h/2; h_6=h/6; h_26=2*h_6;

for i=1:nt
    dx1=rhs_silnik(xtmp, u(i,:), K, wsp); tmp=xtmp+h_2*dx1;tt=tt+h_2;
    dx2=rhs_silnik(tmp, u(i,:), K, wsp); tmp=xtmp+h_2*dx2;
    dx3=rhs_silnik(tmp, u(i,:), K, wsp); tmp=xtmp+h*dx3;tt=tt+h_2;
    dx4=rhs_silnik(tmp, u(i,:), K, wsp);
    xtmp=xtmp+h_6*(dx1+dx4)+h_26*(dx2+dx3);
    x(i+1,:)=xtmp;t(i+1)=tt;
end
