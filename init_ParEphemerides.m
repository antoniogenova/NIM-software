function ParEphemerides = init_ParEphemerides()

%% $$$ DATA $$$ %%

% Initial Spacecraft State
x_in = 13426.726354;  % km
y_in = -20645.023752;  % km
z_in = 10108.071628;  % km
u_in = 2.638622;  % km/s
v_in = 0.329454;  % km/s
w_in = -2.805018;  % km/s
R0 = [ x_in ; y_in ; z_in ];
V0 = [ u_in ; v_in ; w_in ];
ParEphemerides.X0 = [ R0 ; V0 ];
