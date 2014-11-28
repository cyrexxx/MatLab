%% Script to populate Lookup table and index values for proposed algo 

voc = zeros(20,1);
vmpp = zeros(20,1);
x1=zeros(1,2);
x2=zeros(1,2);;
idx=0;
save look_up_line_eq.mat voc vmpp idx x1 x2 -v7.3;
clear voc vmpp index x1 x2
%load(look_up_line_eq)