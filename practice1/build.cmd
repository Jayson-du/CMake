@echo off
echo cmake build vs2022 x64
set builderDir=%~dp0

cmake -S %builderDir% -B %builderDir% -A x64 -DPLATFORM=Windows

pause
