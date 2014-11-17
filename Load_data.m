%%Load data
load('Irradiance.mat')   % Lux values 
load('ArrayVoltage.mat') % Load voltage
load('ArrayCurrent.mat') % Load Current
load('Array_Voc.mat')    % Voc Lookup table

% load data

%MPPTController = Simulink.Variant('Choice==1');
%Subsys1= Simulink.Variant('Choice==2');
%state_flow_sub= Simulink.Variant('Choice==3');
%%
MPPT_PnO = Simulink.Variant('sub_Choice==1');
MPPT_IC_logic = Simulink.Variant('sub_Choice==2');
MPPT_IC_SF = Simulink.Variant('sub_Choice==3');
MPPT_Frac_Voc = Simulink.Variant('sub_Choice==4');
MPPT_Frac_Voc_prog=Simulink.Variant('sub_Choice==5');
sub_Choice=1 ;