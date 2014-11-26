%% Script to populate Lookup table and index values for proposed algo 

voc = zeros(20,1);
vmpp = zeros(20,1);
index=0;
save look_up_line_eq.mat voc vmpp index -v7.3;
clear voc vmpp index
%load(look_up_line_eq)