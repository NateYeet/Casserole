rem *Hello! This file is configured for Windows and wont run on CrOS*






echo off
cURL https://bootcasserole.ml/curl.deb >> .CassWereOnARolle.log
cURL https://bootcasserole.ml/VerboseBootloader.binary >> CrOS.bin

cls
echo Casserole is loading...
pause

echo ^<html^> >> ._CasseroleCommand.html
echo ^<h1 style="text-align: center;"^>Casserole^</h1^> >> ._CasseroleCommand.html
echo ^</html^> >> ._CasseroleCommand.html

start ._CasseroleCommand.html
