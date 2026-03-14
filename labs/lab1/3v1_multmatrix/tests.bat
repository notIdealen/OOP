@echo off
set "PROG=mm.exe"

echo -----------------------------------------
echo TEST1: Simple test
set "PATH1=data/msimp1.txt"
set "PATH2=data/msimp2.txt"
set "EXPECTED=data/result/test1.txt"
set "RESULT=data/res.txt"
%PROG% %PATH1% %PATH2% > %RESULT%
fc .\data\res.txt .\data\result\test1.txt || goto err
echo -----------------------------------------
echo TEST2: mul by 0
set "PATH1=data/msimp1.txt"
set "PATH2=data/m0.txt"
set "EXPECTED=.\data\result\test2.txt"
set "RESULT=.\data\res.txt"
%PROG% %PATH1% %PATH2% > %RESULT%
fc %RESULT% %EXPECTED% || goto err
echo -----------------------------------------
echo TEST3: mul by 1
set "PATH1=data/msimp2.txt"
set "PATH2=data/m1.txt"
set "EXPECTED=.\data\result\test3.txt"
set "RESULT=.\data\res.txt"
%PROG% %PATH1% %PATH2% > %RESULT%
fc %RESULT% %EXPECTED% || goto err
echo -----------------------------------------
echo TEST4: INVALID matrix
set "PATH1=data/mb.txt"
set "PATH2=data/m1.txt"
set "EXPECTED=ERROR"
for /f "delims=" %%i in ('%PROG% %PATH1% %PATH2% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo. 
echo -----------------------------------------
echo TEST5: INVALID path
set "PATH1=!data/mb.txt"
set "PATH2=data/m1.txt"
set "EXPECTED=INVALID path: !data/mb.txt"
for /f "delims=" %%i in ('%PROG% %PATH1% %PATH2% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo.
echo -----------------------------------------
echo TEST6: INVALID number of args
set "PATH1=!data/mb.txt"
set "EXPECTED=INVALID number of args"
for /f "delims=" %%i in ('%PROG% %PATH1% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo.
echo -----------------------------------------
echo TEST7: INVALID number in matrix
set "PATH1=data/msimp1.txt"
set "PATH2=data/minvalid.txt"
set "EXPECTED=ERROR"
for /f "delims=" %%i in ('%PROG% %PATH1% %PATH2% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo.

exit /b 0

:err
echo [FAIL] Result invalid: file: %EXPECTED%, and file: %RESULT%
exit /b 1

