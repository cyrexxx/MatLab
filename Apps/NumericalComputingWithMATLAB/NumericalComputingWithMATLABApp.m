classdef NumericalComputingWithMATLABApp < handle
%
% Usage:
%     app.NumericalComputingWithMATLABApp

  properties
      AppPath = {'/NumericalComputingWithMATLAB'};
	  AppClass = 'NumericalComputingWithMATLABApp';
	  AppHandle;
	  AppCount = 0;
      Increment = 1;
	  Decrement = 0;
      Output;
      CurrClass;
      Version = '13a';
  end  
  methods (Static)
      function count = refcount(increment)
          persistent AppCount;
          if(isempty(AppCount))              
              AppCount = 1;
          else
              if(increment)
                  AppCount = plus(AppCount,1);
              else
                  AppCount = minus(AppCount,1);
              end
          end
          count = AppCount;
       end
  end
  
  methods
    % Create the application object
    function obj = NumericalComputingWithMATLABApp()      
      obj.CurrClass = metaclass(obj);
      startApp(obj)
    end

    function value = get.AppPath(obj)
       appview = com.mathworks.appmanagement.AppManagementViewSilent;
       appAPI = com.mathworks.appmanagement.AppManagementApiBuilder.getAppManagementApiCustomView(appview);
           
       myAppsLocation = char(appAPI.getMyAppsLocation);
       
       value = cellfun(@(x) fullfile(myAppsLocation, x), obj.AppPath, 'UniformOutput', false);
    end

    % Start the application
    function startApp(obj)
        % Put the application directory on the path
        %allpaths = genpath(obj.AppPath{:});
        %addpath(strrep(allpaths, [obj.AppPath{:} filesep 'metadata;'], ''));      

        % Must load function (force by using function handle) or nargout lies.
        % Check if the app is a GUIDE app
        if nargout(@ncmgui) == 0  
            eval('ncmgui');
        else
			obj.AppHandle = eval('ncmgui');   
        end 
        % Increment the reference count by one    
        NumericalComputingWithMATLABApp.refcount(obj.Increment);
        if(ishandle(obj.AppHandle))
		% Setup cleanup code on figure handle using onCleanup object
            cleanupObj = onCleanup(@()appinstall.internal.stopapp([],[],obj));
	    appdata = getappdata(obj.AppHandle);
	    appfields = fields(appdata);
	    found = cellfun(@(x) strcmp(x,'AppCleanupCode'), appfields);
	    if(~any(found))
		setappdata(obj.AppHandle, 'AppCleanupCode', cleanupObj);     
	    end  
        end
    end
  end
end