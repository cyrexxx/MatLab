a = -0.5; b = 10;c=5000;
xr = linspace(0,c,50); % 0 Lux to 5000 luc with 50 intervals in between
yr = linspace(a,4.4,20); % -2 to 7v with 21 intervals in between 
[Xr, Yr] = meshgrid(xr,yr);

%% Calculate the difference between the two surfaces
resid = Mesured_data_mdl(Xr(:), Yr(:)) - model_dump_out(Xr(:), Yr(:));

% Create a Fit Object describing the residuals
Diff_Contour =  fit([Xr(:), Yr(:)], resid, 'linearinterp');

%% Generate a contour plot of the residuals
figure('Numbertitle', 'off', 'name', 'Contour Map of Residuals: Uniform Grid');

xlim = [0, 5000];
ylim = [-1, 5];
obj = Diff_Contour;

[xi, yi] = meshgrid( linspace( xlim(1), xlim(2), 49 ), ...
    linspace( ylim(1), ylim(2), 51 ) );

zi = feval( obj, xi, yi );


[~, h] = contourf( xi, yi, zi, 21 );

grid on
colorbar
caxis ([-0.5 0.5])