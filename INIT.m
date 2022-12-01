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