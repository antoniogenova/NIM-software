clear all

%% Parameter Initialization

%%%% Load Bus structure
load('BUSstructure')

%% Ephemeris
ParEphemerides = init_ParEphemerides()

%% Central body
ParBody = init_ParBody()

%% Spacecraft
ParSpacecraft = init_ParSpacecraft()


%% Sensor 
ParAltimeter = init_ParAltimeter()
ParRadio = init_ParRadio()
ParCamera = init_ParCamera()


