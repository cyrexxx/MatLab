%% Script to autogenerate IV and PV curves for multiple lux values
% Initialize variables
clf
filename = 'testdata_out.xlsx';
Illuminance_1= 100:50:1000; % step size 100
Illuminance_2= 1050:50:5000; % step size 500
Illuminance_used= [Illuminance_1'; Illuminance_2'];%[10.9;19.9;40.2;50.1;75.4;99.2;124.8;150;201;299;394;500;747;908;1001;1247;1480;2030;2550;3060;4030;5040];
lux_vals=size(Illuminance_used)
plot_vi = zeros(1,lux_vals(1,1));
plot_vp = zeros(1,lux_vals(1,1));
plot_voc= zeros(1,lux_vals(1,1));
MPPT = zeros(lux_vals(1,1),5);
MPPT_oc = zeros(lux_vals(1,1),4);
colour = ['b','g','r','c','m','k'];
colour_index=1;
% M=double(Illuminance_used);
%M={'Lux=100','200','300','400','500','600','700','100','200','300','400','500','600','700','100','200','300','400'};
load_system('my_model');
%%
% run the script for all the Lux values 
for i=1:1:lux_vals(1,1)

    lux_ws(:,1)=i;                % values fed to the Model
    lux_ws(:,2) = Illuminance_used(i);
    simOut = sim('my_model');     %%('my_model','SaveOutput','on');% run simulation 
    
    sheet = i;
    current_size=size(Simulation_out.signals(1).values);
    Ai=repmat(Illuminance_used(i),1,current_size(1,1));
    ai_T=transpose(Ai);
    
    xlswrite(filename,Simulation_out.signals(2).values,sheet,'A1');
    xlswrite(filename,Simulation_out.signals(1).values,sheet,'B1');
    xlswrite(filename,ai_T,sheet,'C1');
    %xlswrite(filename,Simulation_out.signals(3).values,sheet,'D1');
    
    %results= zeros([10000,3]);
    %results = simOut.get( 'yout' );
    
    %block to compute Index at Max power Point, and record V,I and P at MPP
    
     %diff(sign(Simulation_out.signals(1).values))
    [MPPT_p,Index] = max(Simulation_out.signals(3).values);
    [dummy idx0] = min(abs(Simulation_out.signals(2).values-Simulation_out.signals(4).values(Index)));
    
    MPPT(i,1) = Simulation_out.signals(1).values(Index);  % Current @ MPP for that perticular LUX {i} value
    MPPT(i,2) = Simulation_out.signals(2).values(Index);  % Voltage @ MPP for that perticular LUX {i} value
    MPPT(i,3) = Simulation_out.signals(3).values(Index);  % Power   @ MPP for that perticular LUX {i} value
    MPPT(i,4) = Simulation_out.signals(2).values(idx0);%V_oc(2);  % Voc 
    MPPT(i,5) = Illuminance_used(i);
    Index
    idx0
    MPPT_oc(i,1)= Simulation_out.signals(1).values(idx0);
    MPPT_oc(i,2)= Simulation_out.signals(2).values(idx0);
    MPPT_oc(i,3)= Simulation_out.signals(3).values(idx0);
    MPPT_oc(i,4)= Simulation_out.signals(4).values(Index);
    
    %MPPT(i,1) = results(Index,1);
    %MPPT(i,2) = results(Index,2);
    %MPPT(i,3) = results(Index,3);
    
    figure(1)
    hold all
    plot_vi(i)=plot(Simulation_out.signals(2).values,Simulation_out.signals(1).values,'Color',colour(colour_index), 'DisplayName', sprintf('%d lux',Illuminance_used(i))); % plot of I vs V
    %%plot(results(:,2),results(:,1),'Color',colour(i))
    legend(plot_vi,'Location','NorthWest');
    
    % Set DisplayNames for the lines for use by the legend
    xlabel('Voltage');
    ylabel('Current');
    title('I-V Curve');
    
    %%'Location','BestOutside');
    figure(2)
    plot_vp(i)=plot(Simulation_out.signals(2).values,Simulation_out.signals(3).values,'Color',colour(colour_index),'DisplayName',sprintf('%d lux',Illuminance_used(i))); % plot of P vs V
    legend(plot_vp,'Location','NorthWest');
    %%plot(results(:,2),results(:,3),'Color',colour(i))
    hold on
    
    xlabel('Voltage');
    ylabel('Power');
    title('P-V Curve');
      
    
  
    
    colour_index=colour_index+1;
    if colour_index == 6
        colour_index=1;
    end

end
%%Plot the Max power point onto the graphs 
figure(1)
plot(MPPT(:,2),MPPT(:,1),'b*');%,'Color','b');

figure(2)
plot(MPPT(:,2),MPPT(:,3),'b*');


%% I V P curves for the last Lux value
figure(3)
subplot(3,1,1);plot(Simulation_out.signals(1).values);
subplot(3,1,2);plot(Simulation_out.signals(2).values);
subplot(3,1,3);plot(Simulation_out.signals(3).values);
%%
figure(4)
plot(MPPT(:,2),MPPT_oc(:,2));
plot(MPPT(:,2),MPPT(:,4),'r');
xlabel('Voltage @ MPP');
ylabel('Voc');

%%
figure(6)
plot(MPPT(:,2),MPPT(:,4),'b');
xlabel('Voltage @ MPP');
ylabel('Voc');

%save to excel
filename = 'MPPT_v.xlsx';
xlswrite(filename,MPPT,'A','B2');


%%free up memory 
clear_list={'plot_vp','plot_vi','colour_index','colour','Illuminance_used','lux_vals','V_oc','lux_ws','MPPT_p','Index','i','Illuminance_1','Illuminance_2','simOut'};
clear(clear_list{:});
clear clear_list;
