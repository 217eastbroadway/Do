if not exist "build\" mkdir "build"
cd build    
cmake ..
cmake --build .
cd build/Debug
Do.exe