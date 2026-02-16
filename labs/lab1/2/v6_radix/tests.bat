@echo off
set "PROG=radix.exe"
echo RADIX tests
echo ------------------------------------------
echo TEST1: 10 2 254
set "RADFROM=10"
set "RADTO=2"
set "VALUE=254"
set "EXPECTED=11111110"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
echo TEST2: 10 16 0
set "RADFROM=10"
set "RADTO=16"
set "VALUE=0"
set "EXPECTED=0"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
echo TEST3: 10 2 MAXINT
set "RADFROM=10"
set "RADTO=2"
set "VALUE=2147483647"
set "EXPECTED=1111111111111111111111111111111"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
echo TEST4: 10 2 MAXINT+1
set "RADFROM=10"
set "RADTO=2"
set "VALUE=2147483648"
set "EXPECTED=INT Overflow"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
echo TEST5: 10 2 MIXINT
set "RADFROM=10"
set "RADTO=2"
set "VALUE=-2147483648"
set "EXPECTED=-10000000000000000000000000000000"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
echo TEST6: 10 2 MIXINT-1
set "RADFROM=10"
set "RADTO=2"
set "VALUE=-2147483649"
set "EXPECTED=INT Overflow"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
set "RADFROM=16"
set "RADTO=35"
set "VALUE=23"
echo TEST7: %RADFROM% %RADTO% %VALUE%
set "EXPECTED=10"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
set "RADFROM=f6"
set "RADTO=35"
set "VALUE=23"
echo TEST8: %RADFROM% %RADTO% %VALUE% (invalid from)
set "EXPECTED=INVALID RADIX"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
set "RADFROM=16"
set "RADTO=36"
set "VALUE=23"
echo TEST9: %RADFROM% %RADTO% %VALUE% (invalid to)
set "EXPECTED=INVALID RADIX"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
echo ------------------------------------------
set "RADFROM=16"
set "RADTO=10"
set "VALUE=2-3"
echo TEST10: %RADFROM% %RADTO% %VALUE% (invalid value)
set "EXPECTED=INVALID VALUE"
for /f "delims=" %%i in ('%PROG% %RADFROM% %RADTO% %VALUE% 2^>nul') do (set "RESULT=%%i")
if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)

echo Сделать тест с отрицательным числом




exit /b 0

:err
echo [FAIL] Result invalid: expected %EXPECTED%, recived %RESULT%
exit /b 1
