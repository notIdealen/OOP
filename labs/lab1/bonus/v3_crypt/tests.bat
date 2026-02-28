@echo off
set PROG=crypt.exe

echo FILE INPUT
echo ------------------------------------------
echo TEST1: encode decode
set "IF=./data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=93"
%PROG% crypt %IF% %ENF% %KEY%
%PROG% decrypt %ENF% %DEF% %KEY%
fc .\data\textMS.bin .\data\de.bin || goto err
echo ------------------------------------------
echo TEST2: invalid input path
set "IF=./!data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=93"
%PROG% crypt %IF% %ENF% %KEY%
echo ------------------------------------------
echo TEST3: invalid encode path
set "IF=./data/textMS.bin"
set "ENF=./!data/en.bin"
set "DEF=./data/de.bin"
set "KEY=93"
%PROG% crypt %IF% %ENF% %KEY%
echo ------------------------------------------
echo TEST4: invalid decode path
set "IF=./data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./!data/de.bin"
set "KEY=93"
%PROG% crypt %IF% %ENF% %KEY%
%PROG% decrypt %ENF% %DEF% %KEY%
echo ------------------------------------------
echo TEST5: invalid mode
set "IF=./data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=93"
%PROG% c!rypt %IF% %ENF% %KEY%
echo ------------------------------------------
echo TEST6: invalid key
set "IF=./data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=256"
%PROG% crypt %IF% %ENF% %KEY%
echo ------------------------------------------
echo TEST7: invalid args number
set "IF=./data/textMS.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=251"
%PROG% %IF% %ENF% %KEY%
echo ------------------------------------------
echo TEST8: empty input
set "IF=./data/empty.bin"
set "ENF=./data/en.bin"
set "DEF=./data/de.bin"
set "KEY=93"
%PROG% crypt %IF% %ENF% %KEY%
%PROG% decrypt %ENF% %DEF% %KEY%
fc .\data\empty.bin .\data\de.bin || goto err
echo ------------------------------------------

exit /b 0

:err
echo [FAIL]
exit /b 1
