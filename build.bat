@ECHO OFF

REM checks if the directory already exists
IF NOT EXIST build (
  mkdir build
)

IF %1==rel (
  ECHO Building For Release
  cmake -B build -DCMAKE_BUILD_TYPE=Release
  cmake --build build --config Release
  build\release\my_application.exe
) ELSE (
  ECHO Building for Debug
  cmake -B build
  cmake --build build
  build\debug\my_application.exe
)
