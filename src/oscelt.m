function OE = oscelt(sv)

%##########################################################################
%  Oscelt program
%##########################################################################

sv=sv*1000; %%% km to m
r=sv(1:3);
V=sv(4:6);
%%%% Compute orbital elements from spacecraft state vector %%%%
epsilon=norm(V)^2/2-mu/norm(r);

fprintf('---------------------------------------------------------------\n')
fprintf('---- Orbital Elements with this subroutine\n')
fprintf('---------------------------------------------------------------\n')

%%% semi-major axis
a=-mu/(2*epsilon);

%%% spacecraft angular momentum 
h=cross(r,V);
%%% eccentricity vector
eccv=cross(V,h)/mu-r/norm(r);
%%% eccentricity 
e=norm(eccv);
%%% inclination
i=rad2deg(acos(h(3)/norm(h)));
%%% nodal vector
n=cross([0,0,1],h);
if(n(2)>0)
%%% Right ascension
Omega=rad2deg(acos(n(1)/norm(n)));
else
Omega=360-rad2deg(acos(n(1)/norm(n)));
end

if(eccv(3)>0)
%%% Right ascension
omega=rad2deg(acos(dot(n,eccv)/(norm(n)*e)));
else
omega=360-rad2deg(acos(dot(n,eccv)/(norm(n)*e)));
end

if(dot(r,V)>0)
%%% Right ascension
nu=rad2deg(acos(dot(eccv,r)/(norm(r)*e)));
else
nu=360-rad2deg(acos(dot(eccv,r)/(norm(r)*e)));
end

OE(1) = a;
OE(2) = e;
OE(3) = i;
OE(4) = Omega;
OE(5) = omega;
OE(6) = nu;

