function createfigure(X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, X6, Y6, X7, Y7, X8, Y8, X9, Y9, X10, Y10, X11, Y11, X12, Y12, X13, Y13, X14, Y14, X15, YMatrix1, X16, Y15)
%CREATEFIGURE(X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, X6, Y6, X7, Y7, X8, Y8, X9, Y9, X10, Y10, X11, Y11, X12, Y12, X13, Y13, X14, Y14, X15, YMATRIX1, X16, Y15)
%  X1:  vector of x data
%  Y1:  vector of y data
%  X2:  vector of x data
%  Y2:  vector of y data
%  X3:  vector of x data
%  Y3:  vector of y data
%  X4:  vector of x data
%  Y4:  vector of y data
%  X5:  vector of x data
%  Y5:  vector of y data
%  X6:  vector of x data
%  Y6:  vector of y data
%  X7:  vector of x data
%  Y7:  vector of y data
%  X8:  vector of x data
%  Y8:  vector of y data
%  X9:  vector of x data
%  Y9:  vector of y data
%  X10:  vector of x data
%  Y10:  vector of y data
%  X11:  vector of x data
%  Y11:  vector of y data
%  X12:  vector of x data
%  Y12:  vector of y data
%  X13:  vector of x data
%  Y13:  vector of y data
%  X14:  vector of x data
%  Y14:  vector of y data
%  X15:  vector of x data
%  YMATRIX1:  matrix of y data
%  X16:  vector of x data
%  Y15:  vector of y data

%  Auto-generated by MATLAB on 02-Sep-2014 13:17:10

% Create figure
figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'all');

% Create plot
plot(X1,Y1,'Color',[1 0 1]);

% Create xlabel
xlabel('Voltage');

% Create ylabel
ylabel('Current');

% Create title
title('V-I Curve');

% Create plot
plot(X2,Y2,'Color',[1 1 1]);

% Create plot
plot(X3,Y3,'Color',[1 0 0]);

% Create plot
plot(X4,Y4,'Color',[1 1 0]);

% Create plot
plot(X5,Y5,'Color',[0 0 1]);

% Create plot
plot(X6,Y6,'Color','m');

% Create plot
plot(X7,Y7);

% Create plot
plot(X8,Y8);

% Create plot
plot(X9,Y9);

% Create plot
plot(X10,Y10);

% Create plot
plot(X11,Y11);

% Create plot
plot(X12,Y12);

% Create plot
plot(X13,Y13);

% Create plot
plot(X14,Y14);

% Create multiple lines using matrix input to plot
plot(X15,YMatrix1,'Parent',axes1);

% Create plot
plot(X16,Y15);

