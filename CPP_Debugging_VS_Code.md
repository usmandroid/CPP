# Guide on How to debug using VS Code with CMake and GDB On Ubuntu 
This guide is more useful than the basic guide officially provided by Microsoft (Debug C++ in Visual Studio Code)[https://code.visualstudio.com/docs/cpp/cpp-debug] since we cover here how to debug when using external libraries and CMakelists.txt.


### Resources

### Follow the guide on [Debugging C++ & CMake in VSCode in the Right Way](https://www.youtube.com/watch?v=Qng2RW_bjS8&t=396s)

* Mainly ensure to install `gdb` `CMake` on linux with `sudo apt install gdb Cmake` and also install in VS code `C/C++ Extension Pack` from Extensions menu. Reload window with `Developer:Reload Window` command from Command Pallete (`Ctrl+Shift+P`)



### First setup CMake build process.
Create within your project working directory aka your VS code `workspaceFolder`a `CMakePresets.json` file  which can be obtained for example from here [https://github.com/matheusgomes28/cpp-cmake-vscode-example/blob/main/CMakePresets.json](https://github.com/matheusgomes28/cpp-cmake-vscode-example/blob/main/CMakePresets.json) 

Next in VS code open Command Pallete (`Ctrl+Shift+P`) and type `CMake:Add Configure Preset` -> `Create from Compiler` -> `GCC x.x.x x86...` --> Give name e.g `GCC`

This should add an entry as below within your  `CMakePresets.json` file:

```
{
            "name": "GCC",
            "displayName": "GCC 9.4.0 x86_64-linux-gnu",
            "description": "Using compilers: C = /usr/bin/gcc, CXX = /usr/bin/g++",
            "binaryDir": "${sourceDir}/out/build/${presetName}",
            "cacheVariables": {
                "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",
                "CMAKE_C_COMPILER": "/usr/bin/gcc",
                "CMAKE_CXX_COMPILER": "/usr/bin/g++",
                "CMAKE_BUILD_TYPE": "Debug"
            }
},
```

### Next Create `launch.json` file in `${workspaceFolder}/.vscode` directory either directly or by clicking on `create a launch.json file` within Run and Debug menu and add the following `C/C++: (gdb) Launch` config which will be automatically suggested
* Update the program output name and directory as you specified in your `CMakeLists.txt` file
```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "main Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/examples/out/build/GCC/bin/my_project",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }

    ]
}

```
Run `CMake: Build` from Command Pallete (`Ctrl+Shift+P`) with the main file
Make sure to correctly specify the ` "program"` which can be seen in `Output` of `CMake/Build` tab in bottom panel of VS Code next to `Terminal` 

You are ready to debug! Open the `main.cpp` you want to debug and next open Run and Debug menu from side(Ctrl+Shift+D) and click on `Play` icon or press `F5` to start debugging
