@echo off

echo generate project files...

if exist FruitAvoid2D (
    echo Already exist FruitAvoid2D...
)

echo run premake5.exe...
Engine\\Bin\\premake5.exe vs2019
PAUSE