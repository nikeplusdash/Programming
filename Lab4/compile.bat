set var=%1
set con=%2
masm.exe %var%;
link.exe %var%;
if %con%==1 goto td
%var%.exe
goto end
:td
td.exe %var%
:end