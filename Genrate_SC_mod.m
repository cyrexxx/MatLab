%funftion for gen mod 

%% create fit 
[fitresult_normal_g42, gof] = createFit(Voltage, Lux, Current);



%%% Create irradiance and voltage vectors
 Irradiance = (min(Lux):50:max(Lux));
 ArrayVoltage = (0:0.01:max(Voltage));
 [V,G]=meshgrid(ArrayVoltage,Irradiance);
 %Use surface fit object
 ArrayCurrent= fitresult_normal_g42(V,G); % change fitresult to relevant output of createFit4
 
%% Save Data
 
 
%%%% Creating a lookup table model
% 1. Create a model with a 2-D Lookup Table block.

simulink
new_system( 'my_model' )% give specific name to the block
open_system( 'my_model' )% use the same name as above
add_block( 'Simulink/Lookup Tables/2-D Lookup Table',... 
    'my_model/surfaceblock',...
    'BreakpointsForDimension1', 'Irradiance',...
    'BreakpointsForDimension2', 'ArrayVoltage',...
    'Table', 'ArrayCurrent');
% 2. Populate the Lookup Table with speed breakpoints, load breakpoints, and a lookup table.

set_param( 'my_model/surfaceblock',...% change my_model and surfaceblock to specifc block name as above and to relevant block name
    'BreakpointsForDimension1', 'Irradiance',...
    'BreakpointsForDimension2','ArrayVoltage',...
    'Table', 'ArrayCurrent' );
% 3. Examine the populated Lookup Table block.