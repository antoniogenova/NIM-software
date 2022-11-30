clear all
close all
clc

%% $$$ ADD FOLDERS AND LOADING KERNELS $$$ %%

% Folders
%addpath('c:\Users\tomma\Documents\MATLAB\borsa\mice\src\mice\');
%addpath('c:\Users\tomma\Documents\MATLAB\borsa\mice\lib\' );

% Kernels loading
%cspice_furnsh( '.\kernels\mykernels.furnsh' );


%% $$$ DATA $$$ %%

% Central Body
lmax = 4; 
mi = 398600.435507;  % km^3/s^2
Rp = 6371;  % km
J = zeros(lmax,1);
C = zeros(lmax,lmax);
S = zeros(lmax,lmax);

% STATE
x_in = 13426.726354;  % km
y_in = -20645.023752;  % km
z_in = 10108.071628;  % km
u_in = 2.638622;  % km/s
v_in = 0.329454;  % km/s
w_in = -2.805018;  % km/s
R0 = [ x_in ; y_in ; z_in ];
V0 = [ u_in ; v_in ; w_in ];
X0 = [ R0 ; V0 ];

load('topo.mat');

% Integration Time Span
epoch0   = '11/14/2022 00:00:00.000';
epochf   = '11/24/2022 00:00:00.000';
et0 = cspice_str2et( epoch0 );
etf = cspice_str2et( epochf );
% tspan = linspace(et0,etf,4e4);
tspan = (0:60:(24*60*60*10));


%% Trajectory Propagation

[t,X] = ode89(@(t,state) int2(t,state,mi),tspan,X0In);
x = X(:,1); y = X(:,2); z = X(:,3);


%% Orbital elements evolution

for i = 1:length(t)
    [in(i,1),OMEGA(i,1),a(i,1),e(i,1),omega(i,1),ni(i,1)] = rvI2coe(X(i,1:3),X(i,4:6),mi);
    %epochs{i} = cspice_et2utc(t(i),'C',4);
end
in = in * 180/pi; OMEGA = OMEGA * 180/pi; omega = omega * 180/pi; ni = ni * 180/pi;



%% $$$ PLOTS $$$

% figure(2)
figure()

subplot(3,2,1)
plot(t,a)
title('Semimajor Axis Variation')
ylim([2.5e4,2.7e4])
xlabel('Time [s]')
ylabel('a [km]')

subplot(3,2,2)
plot(t,in)
title('Inclination Variation')
ylim([54,56])
xlabel('Time [s]')
ylabel('i [°]')

subplot(3,2,3)
plot(t,e)
title('Eccentricity Variation')
ylim([0,0.1])
xlabel('Time [s]')
ylabel('e')

subplot(3,2,4)
plot(t,OMEGA)
title('RA of Asc. Node Variation')
ylim([0,360])
xlabel('Time [s]')
ylabel('\Omega [°]')

subplot(3,2,5)
plot(t,omega)
title('Arg. of Periapsis Variation')
ylim([0,360])
xlabel('Time [s]')
ylabel('\omega [°]')

subplot(3,2,6)
plot(t,ni)
title('True Anomaly')
ylim([0 360])
xlabel('Time [s]')
ylabel('\nu [°]')

