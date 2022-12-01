function ParEphemerides = init_ParEphemerides()

%% $$$ DATA $$$ %%

% Initial Spacecraft State
ParEphemerides.X0 = [156.83823102932;
                   702.62457550758;
                   -1634.2087990962998;
                   1.6296309043729;
                   0.18839925972895;
                   0.23916961931733371];
    
ParEphemerides.time0 = 3.155761323669245e+08;  %%% Second past J2000
