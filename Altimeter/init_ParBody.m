function ParBody = init_ParBody()

%% $$$ DATA $$$ %%

% Central Body
%%% Maximum Degree Spherical Harmonics Expansion
lmax = 4;
%%% Central body GM
ParBody.mi = 4902.800;  % km^3/s^2
%%% Central body Radius
ParBody.Rp = 1737.4;  % km
ParBody.J = zeros(lmax,1);
ParBody.C = zeros(lmax,lmax);
ParBody.S = zeros(lmax,lmax);
