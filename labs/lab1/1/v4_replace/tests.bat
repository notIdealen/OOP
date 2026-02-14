@echo off
set PROG=r.exe

echo CONSOLE INPUT
echo ------------------------------------------
echo TEST1: simple input
(
echo ma
echo mama
echo asdmamamaasd
) | %PROG%
fc .\data\t1.txt .\data\out.txt || goto err
echo.
echo FILE INPUT
echo ------------------------------------------
echo TEST2: Four args
set "IF=./data/in.txt"
set "OF=./data/out.txt"
set "PATTERN=qw"
set "FILLER=@"
%PROG% %IF% %OF% %PATTERN% %FILLER%
fc .\data\t2.txt .\data\out.txt || goto err
echo ------------------------------------------
echo TEST3: wo filler
set "IF=./data/in.txt"
set "OF=./data/out.txt"
set "PATTERN=qw"
set "FILLER="
%PROG% %IF% %OF% %PATTERN% %FILLER%
fc .\data\t3.txt .\data\out.txt || goto err
echo ------------------------------------------
echo TEST4: wo pattern
set "IF=./data/in.txt"
set "OF=./data/out.txt"
set "PATTERN="
set "FILLER="
%PROG% %IF% %OF% %PATTERN% %FILLER%
fc .\data\t4.txt .\data\out.txt || goto err
echo ------------------------------------------
echo TEST5: invalid path outputfile
set "EXPECTED=ERROR"
set "IF=./data/in.txt"
set "OF=./!data/out.txt"
set "PATTERN=qw"
set "FILLER=@"
%PROG% %IF% %OF% %PATTERN% %FILLER%
for /f "delims=" %%i in ('%PROG% %IF% %OF% %PATTERN% %FILLER% 2^>nul') do set "RESULT=%%i"
if "%RESULT%"=="%EXPECTED%" (echo valid [OK]) else (goto err)
echo.
echo ------------------------------------------
echo TEST6: invalid path inputfile
set "EXPECTED=ERROR"
set "IF=./!data/in.txt"
set "OF=./data/out.txt"
set "PATTERN=qw"
set "FILLER=@"
%PROG% %IF% %OF% %PATTERN% %FILLER%
for /f "delims=" %%i in ('%PROG% %IF% %OF% %PATTERN% %FILLER% 2^>nul') do set "RESULT=%%i"
if "%RESULT%"=="%EXPECTED%" (echo valid [OK]) else (goto err)
echo.
echo ------------------------------------------
echo TEST7: empty input
set "IF=./data/empty_in.txt"
set "OF=./data/out.txt"
set "PATTERN=qw"
set "FILLER=@"
%PROG% %IF% %OF% %PATTERN% %FILLER%
fc .\data\empty_in.txt .\data\out.txt || goto err
echo ------------------------------------------
echo TEST8: -h
%PROG% -h
echo.
echo ------------------------------------------
echo TEST9: not -h
%PROG% -m
echo.

exit /b 0

:err
echo [FAIL]
exit /b 1
