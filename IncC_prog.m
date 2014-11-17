function D  = IncC_P(Param, Enable, V, I)
% MPPT controller block based on the incremental conductance algorithm
% MPPT controller based on the Perturb & Observe algorithm.

% D output = Duty cycle  (value between 0 and 1)
%
% Enabled input = 1 to enable the MPPT controller
% V input = PV array terminal voltage (V)
% I input = PV array current (A)
%
% Param input:
Dinit = Param(1);  %Initial value for D output
Dmax = Param(2);   %Maximum value for D
Dmin = Param(3);   %Minimum value for D
deltaD = Param(4); %Increment value used to increase/decrease the duty cycle D

% ( increasing D = decreasing Vref )
persistent Vold  Dold Iold;

dataType = 'double';

if isempty(Vold)
    Vold=0;
    Iold=0;
    Dold=Dinit;
    D=Dinit;
    
end

dV= V - Vold;
dI= I- Iold;


if Enable == 1
   if dV==0
       if dI ~= 0
           if dI >0
               D = Dold + deltaD;
           else 
               D = Dold - deltaD;
           end
       else
           D=Dold;
       end
       Dold=D;
       Vold=V;
       Iold=I;
   else
       if ((dI/dV) ~= (-I/V))
           if ((dI/dV) > (-I/V))
               D = Dold - deltaD;
           else 
               D = Dold + deltaD;
           end
       else
           D=Dold;
       end
       Dold=D;
       Vold=V;
       Iold=I;
   end
  
else
    D=Dold;
end

if D >= Dmax | D<= Dmin
    D=Dold;
end

