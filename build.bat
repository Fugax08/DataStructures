
@echo off
SET BAT_BASE_PATH=%~dp0
SET PRJ_BASE_PATH=%BAT_BASE_PATH%
SET BIN_PATH=%PRJ_BASE_PATH%\bin
SET APP_PATH=%PRJ_BASE_PATH%\app
SET CORE_PATH=%PRJ_BASE_PATH%\core
SET TEST_PATH=%PRJ_BASE_PATH%\test

MD %BIN_PATH%

clang ^
    -I%CORE_PATH%\include ^
    -o bin\data-struct.lib %CORE_PATH%\src\*.c ^
    -fuse-ld=llvm-lib

clang ^
    -I%APP_PATH%\include ^
    -I%CORE_PATH%\include ^
    -o %BIN_PATH%\app.exe %APP_PATH%\src\*.c ^
    -L %BIN_PATH% -l data-struct

clang ^
    -I%TEST_PATH%\include ^
    -I%CORE_PATH%\include ^
    -o %BIN_PATH%\test.exe %TEST_PATH%\src\*.c ^
    -L %BIN_PATH% -l data-struct