set var=%1
set con=%2
masm.exe %var%;
pause
link.exe %var%;
pause
if %con%==1 goto td
if %con%==0 goto end
%var%.exe
goto end
:td
    td.exe %var%
    goto end
:end