%% Save Data
 
 
%%%% Creating a lookup table model
% 1. Create a model with a 2-D Lookup Table block.

simulink
new_system( 'G24i_normal' )% give specific name to the block
open_system( 'G24i_normal' )% use the same name as above
add_block( 'Simulink/Lookup Tables/2-D Lookup Table',... 
    'G24i_normal/0 -5k Lux lookup',...
    'BreakpointsForDimension1', 'Irradiance',...
    'BreakpointsForDimension2', 'ArrayVoltage',...
    'Table', 'ArrayCurrent');
% 2. Populate the Lookup Table with speed breakpoints, load breakpoints, and a lookup table.

set_param( 'G24i_normal/0 -5k Lux lookup',...% change my_model and surfaceblock to specifc block name as above and to relevant block name
    'BreakpointsForDimension1', 'Irradiance',...
    'BreakpointsForDimension2','ArrayVoltage',...
    'Table', 'ArrayCurrent' );
% 3. Examine the populated Lookup Table block.