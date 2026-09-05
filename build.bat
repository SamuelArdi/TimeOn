@ECHO OFF

REM checks if the directory already exists
IF NOT EXIST build (
  mkdir build
)

IF %1==rel (
  cmake -B build -DCMAKE_BUILD_TYPE=Release
  cmake --build build --config Release
) ELSE (
  cmake -B build
  cmake --build build
  build\debug\my_application.exe
)
