function [fitresult, gof] = createFit(Voltage, Lux, Current)
%CREATEFIT(VOLTAGE,LUX,CURRENT)
%  Create a fit.
%
%  Data for 'a-si' fit:
%      X Input : Voltage
%      Y Input : Lux
%      Z Output: Current
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 20-Aug-2014 15:28:47


%% Fit: 'a-si'.
[xData, yData, zData] = prepareSurfaceData( Voltage, Lux, Current );

% Set up fittype and options.
ft = 'linearinterp';
opts = fitoptions( ft );
opts.Normalize = 'on';

% Fit model to data.
[fitresult, gof] = fit( [xData, yData], zData, ft, opts );

% Plot fit with data.
figure( 'Name', 'a-si' );
h = plot( fitresult, [xData, yData], zData );
legend( h, 'a-si', 'Current vs. Voltage, Lux', 'Location', 'NorthEast' );
% Label axes
xlabel( 'Voltage' );
ylabel( 'Lux' );
zlabel( 'Current' );
grid on
view( 38.5, 32.0 );

