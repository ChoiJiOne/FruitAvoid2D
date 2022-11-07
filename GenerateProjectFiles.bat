@echo off

echo generate project files...

if not exist Dump (
    echo don't exist dump directory...
    mkdir Dump
)

if exist FruitAvoid2D (
    echo already exist FruitAvoid2D...
)

echo run premake5.exe...
Engine\Bin\premake5.exe vs2019
start FruitAvoid2D\\FruitAvoid2D.sln
PAUSE
