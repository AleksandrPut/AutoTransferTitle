setlocal enabledelayedexpansion
::
::
::remove quotes
set OBJECT_TO_SIGN=%~1
::
::
::sign
set SIGN_COMMAND="!UGII_BASE_DIR!\UGOPEN\signcpp.exe" "!OBJECT_TO_SIGN!"
echo Executing ... !SIGN_COMMAND!
call !SIGN_COMMAND!
if !ERRORLEVEL! neq 0 exit /b !ERRORLEVEL!
::
::
::verify
set VERIFY_COMMAND="!UGII_BASE_DIR!\UGOPEN\signcpp.exe" -verify "!OBJECT_TO_SIGN!"
echo Executing ... !VERIFY_COMMAND!
call !VERIFY_COMMAND!
if !ERRORLEVEL! neq 0 exit /b !ERRORLEVEL!
::
::
exit /b 0
::
::