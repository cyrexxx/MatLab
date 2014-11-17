%%%% Creating a lookup table model
% 1. Create a model with a 2-D Lookup Table block.

simulink
new_system( 'G24i_Voc' )% give specific name to the block
open_system( 'G24i_Voc' )% use the same name as above
add_block( 'Simulink/Lookup Tables/1-D Lookup Table',... 
    'G24i_Voc/V_oc lookup',...
    'BreakpointsForDimension1', 'Irradiance',...
    'Table', 'Array_Voc');
% 2. Populate the Lookup Table with speed breakpoints, load breakpoints, and a lookup table.

set_param( 'G24i_Voc/V_oc lookup',...% change my_model and surfaceblock to specifc block name as above and to relevant block name
    'BreakpointsForDimension1', 'Irradiance',...
    'Table', 'Array_Voc' );
% 3. Examine the populated Lookup Table block.