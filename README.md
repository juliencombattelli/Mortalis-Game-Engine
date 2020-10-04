# Makuyop's Game Engine

This is an open source C++ Game Engine project based on SFML library.

The goal of this project is both create a 2D RPG game and a reusable game engine for any 2D game.

To compile this project, you could use any compiler as long as they provide full C++17 support (like GCC 7). You also need the SFML 2.5 library.

# cpp_starter_project

![CMake Build Matrix](https://github.com/juliencombattelli/cpp_starter_project/workflows/CMake%20Build%20Matrix/badge.svg)

## Getting Started

### Use the Github template
First, click the green `Use this template` button near the top of this page.
This will take you to Github's [Generate Repository](https://github.com/juliencombattelli/cpp_starter_project/generate) page. 
Fill in a repository name and short description, and click `Create repository from template`. 
This will allow you to create a new repository in your Github account, 
prepopulated with the contents of this project. 
Now you can clone the project locally and get to work!

    $ git clone https://github.com/<user>/<your_new_repo>.git

### Remove files you're not going to use
This template comes with an example library called `Math` and an executable called `intro`.
You can remove them with `git rm` and adjust the CMakeLists.txt:

    $ git rm -r include/* src/* test/test.cpp

## Dependencies

Note about install commands: 
- for Windows, you can use [choco](https://chocolatey.org/install).
- for MacOS, you can use [brew](https://brew.sh/).
- for Linux, prefer use your distribution package manager (like apt on Ubuntu).
- In case of an error in CMake, make sure that the dependencies are on the PATH.

### Necessary Dependencies

You will need to install the following software.

1. A C++ compiler that supports C++17.
2. [Conan](https://docs.conan.io/en/latest/installation.html)
3. [CMake 3.17+](https://cmake.org/install/)
	- You can also install it as a [pip package](https://pypi.org/project/cmake/).

### Optional Dependencies

You may need the following software if you enable the corresponding CMake flags.

  * [Doxygen](http://doxygen.nl/)
  * [Cppcheck](http://cppcheck.sourceforge.net/)
  * [Clang tools](https://releases.llvm.org/download.html)

## Build Instructions

### Specify the compiler using environment variables

By default (if you don't set environment variables `CC` and `CXX`), the system default compiler will be used.

Conan and CMake use the environment variables CC and CXX to decide which compiler to use.
So to avoid conflicts only specify the compilers using these variables.

CMake will detect which compiler was used to build each of the Conan targets. 
If you build all of your Conan targets with one compiler, 
and then build your CMake targets with a different compiler, the project may fail to build.

### Configure your build

To configure the project and generate the build system, you can use `cmake` with a bunch of command line options.
There are also some interactive alternatives.

#### **Configure via cmake**:
with the CMake binary:  

    cmake -S . -B ./build
    
The project provides many options you can pass to CMake. 
If you want to use them, it is recommended to use one of the following alternatives.
But if you really want to use the `cmake` command, you can use the -LH switch to list the options available and their help message.

#### **Configure via ccmake**:
with the CMake curses dialog command line tool:  

    ccmake -S . -B ./build

This command will start a curses-based command line interface 
where you will find all the CMake options available with their default value and their help message. 
Once `ccmake` has finished setting up, press 'c' to configure the project, press 'g' to generate, and 'q' to quit.

#### **Configure via cmake-gui**:

1) Open cmake-gui from the project directory:
```
cmake-gui .
```
2) Set the build directory:

![build_dir](https://user-images.githubusercontent.com/16418197/82524586-fa48e380-9af4-11ea-8514-4e18a063d8eb.jpg)

3) Configure the generator:

In cmake-gui, from the upper menu select `Tools/Configure`.

**Warning**: if you have set `CC` and `CXX` always choose the `use default native compilers` option. This picks `CC` and `CXX`. Don't change the compiler at this stage!

<details>
<summary>Windows - MinGW Makefiles</summary>

Choose MinGW Makefiles as the generator:

<img src="https://user-images.githubusercontent.com/16418197/82769479-616ade80-9dfa-11ea-899e-3a8c31d43032.png" alt="mingw">

</details>

<details>
<summary>Windows - Visual Studio generator and compiler</summary>

You should have already set `C` and `CXX` to `cl.exe`.

Choose "Visual Studio 16 2019" as the generator:

<img src="https://user-images.githubusercontent.com/16418197/82524696-32502680-9af5-11ea-9697-a42000e900a6.jpg" alt="default_vs">

</details>

<details>

<summary>Windows - Visual Studio generator and Clang Compiler</summary>

You should have already set `C` and `CXX` to `clang.exe` and `clang++.exe`.

Choose "Visual Studio 16 2019" as the generator. To tell Visual studio to use `clang-cl.exe`:
- If you use the LLVM that is shipped with Visual Studio: write `ClangCl` under "optional toolset to use". 

<img src="https://user-images.githubusercontent.com/16418197/82781142-ae60ac00-9e1e-11ea-8c77-222b005a8f7e.png" alt="visual_studio">

- If you use an external LLVM: write [`LLVM_v142`](https://github.com/zufuliu/llvm-utils#llvm-for-visual-studio-2017-and-2019)
 under "optional toolset to use".

<img src="https://user-images.githubusercontent.com/16418197/82769558-b3136900-9dfa-11ea-9f73-02ab8f9b0ca4.png" alt="visual_studio">

</details>
<br/>

4) Choose the Cmake options and then generate:

![generate](https://user-images.githubusercontent.com/16418197/82781591-c97feb80-9e1f-11ea-86c8-f2748b96f516.png)



### Build
Once you have selected all the options you would like to use, you can build the project (all targets):

    cmake --build ./build

### Run tests
If the test binaries have been registered in CMake with `add_test` command, you can start them with:

    ctest
    
### Install your software
You can run the install target to a specific directory:

    cmake --install ./build --prefix ./instdir --strip


## Troubleshooting

### Update Conan
Many problems that users have can be resolved by updating Conan, so if you are 
having any trouble with this project, you should start by doing that.

To update conan: 

    $ pip install --user --upgrade conan 

You may need to use `pip3` instead of `pip` in this command, depending on your 
platform.

### Clear Conan cache
If you continue to have trouble with your Conan dependencies, you can try 
clearing your Conan cache:

    $ conan remove -f '*'
    
The next time you run `cmake` or `cmake --build`, your Conan dependencies will
be rebuilt. If you aren't using your system's default compiler, don't forget to 
set the CC, CXX, CMAKE_C_COMPILER, and CMAKE_CXX_COMPILER variables, as 
described in the 'Build using an alternate compiler' section above.

### Identifying misconfiguration of Conan dependencies

If you have a dependency 'A' that requires a specific version of another 
dependency 'B', and your project is trying to use the wrong version of 
dependency 'B', Conan will produce warnings about this configuration error 
when you run CMake. These warnings can easily get lost between a couple 
hundred or thousand lines of output, depending on the size of your project. 

If your project has a Conan configuration error, you can use `conan info` to 
find it. `conan info` displays information about the dependency graph of your 
project, with colorized output in some terminals.

    $ cd build
    $ conan info .

In my terminal, the first couple lines of `conan info`'s output show all of the
project's configuration warnings in a bright yellow font. 

For example, the package `spdlog/1.5.0` depends on the package `fmt/6.1.2`.
If you were to modify the file `cmake/Conan.cmake` so that it requires an 
earlier version of `fmt`, such as `fmt/6.0.0`, and then run:

    $ conan remove -f '*'       # clear Conan cache
    $ rm -rf build              # clear previous CMake build
    $ mkdir build && cd build
    $ cmake ..                  # rebuild Conan dependencies
    $ conan info .

...the first line of output would be a warning that `spdlog` needs a more recent
version of `fmt`.

## Testing
See [GTest tutorial](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)

## Fuzz testing

See [libFuzzer Tutorial](https://github.com/google/fuzzing/blob/master/tutorial/libFuzzerTutorial.md)

