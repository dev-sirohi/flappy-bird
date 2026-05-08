@echo off

cd build
premake5.exe gmake
cd ..
make clean
make config=debug_x64

if /I "%1"=="gdb" (
    gdb .\bin\Debug\flappy-bird.exe
) else (
    .\bin\Debug\flappy-bird.exe
)