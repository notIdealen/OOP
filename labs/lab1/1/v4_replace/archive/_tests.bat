@echo off
set PROG=r.exe

echo CONSOLE INPUT
echo ------------------------------------------
echo TEST1
set "PATTERN=qw"
set "FILLER=@"
set "TEXT1=the goqw q"
set "TEXT2=w q asqwas"
(
    echo %PATTERN%
    echo %FILLER%
    echo %TEXT1%
    echo %TEXT2%
) | %PROG%
fc .\data\t1_utf8.txt .\data\out.txt || goto err

echo ------------------------------------------
@REM echo swap matrix
@REM set "EXPECTED=5050"
@REM set "RESULT="
@REM for /f "delims=" %%i in ('%PROG% .\data\cm4x4.txt .\data\qm4x4.txt 2^>nul') do (
@REM     echo %%i
@REM     if not defined RESULT set "RESULT=%%i"
@REM )
@REM set "RESULT=%RESULT: =%"
@REM if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
@REM echo ------------------------------------------ 
@REM echo diagonal != 0
@REM echo ------------------------------------------
@REM echo calculate matrix 10x10 
@REM set "EXPECTED=42386"
@REM set "RESULT="
@REM for /f "delims=" %%i in ('%PROG% .\data\qm10x10.txt .\data\cm10x10.txt 2^>nul') do (
@REM     echo %%i
@REM     if not defined RESULT set "RESULT=%%i"
@REM )
@REM set "RESULT=%RESULT: =%"
@REM if "%RESULT%"=="%EXPECTED%" (echo [OK] valid) else (goto err)
@REM echo ------------------------------------------
@REM echo calculate matrix 1x1 
@REM echo ------------------------------------------
@REM echo calculate matrix 2x2 
@REM echo ------------------------------------------
@REM echo calculate matrix 20x20
@REM %PROG% 20
@REM echo ------------------------------------------
@REM echo calculate matrix 50x50
@REM %PROG% 50
@REM echo Universe age: 1.38e+10
@REM exit /b 0


exit /b 0

:err
echo [FAIL]
exit /b 1 
