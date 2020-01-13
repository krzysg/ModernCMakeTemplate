# ModernCMakeTemplate

## What this project is about?
This is a simple example of using modern CMake basing on great Daniel Pfeifer’s presentation ([video](https://www.youtube.com/watch?v=bsXLMQ6WgIk) and [slides](https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf)).

Since many examples of modern CMake I have found are too naive my main goal was to create
- header only library with tests (LibA) 
- simple regular static .h/.cpp library with tests (LibB)
- project that is using this libraries added as a subproject (this project)
- project that is using LibA/LibB after installation and is searching them via find_package() CMake function (externalClientProject)

Below you can find all needed use cases and information how to build them.
To learn how it works go through `CMakeList.txt` files, they are kept as easy as possible (altogether with other library and test files).
With minimum effort it should be easy to copy/paste it and modify to use in any project.


## Use cases
To play with shown use cases please clone the whole project first via:
```
git clone https://github.com/krzysg/ModernCMakeTemplate.git
cd ModernCMakeTemplate
```
or if you are using SSH keys:
```
git clone git@github.com:krzysg/ModernCMakeTemplate.git
cd ModernCMakeTemplate
```

**NOTICE**: Each use case commands are meant to run from project root directory.

### I want to create header only library
Focus only on `LibA` directory. This is full example of header only library that can be installed and tested.
 
To build this library with a tests enabled run:
```
# Go to the directory with LibA
cd LibA

# create build directory and enter it
mkdir build
cd build

# run cmake with tests enabled
cmake -DLIBA_TESTS=ON ..

# build library
make

# test library
ctest
```

### I want to create regular static (or shared) library
Focus only on `LibB` directory. This is full example of header only library that can be installed and tested.
 
To build this library with a tests enabled run:
```
# Go to the directory with LibB
cd LibB

# create build directory and enter it
mkdir build
cd build

# run cmake with tests enabled
cmake -DLIBB_TESTS=ON ..

# build library
make

# test library
ctest
```

### I want to use LibA and LibB as a subproject
The whole ModernCMakeTemplate project is a example of that case. Main cpp file `src/main.cpp` is using LibA and LibB.
To build project run:
```
# create build directory and enter it
mkdir build
cd build

# run cmake with tests enabled
cmake ..

# build library
make

# run executable
./main
```

### I want to use LibA and/or LibB in a external project
First we need to build and install libraries:
```
# create build directory, run cmake and install libs in `/tmp/myNewLibs` directory
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/tmp/myNewLibs ..
make install
cd ..
```

We could also install the libraries one by one running:
```
cd LibA
mkdir build
cd build
cmake -D CMAKE_INSTALL_PREFIX=/tmp/myNewLibs ..
make install
cd ../..
```

and repeating this step for LibB. But since we have master CMakeLists.txt we can use it.

Now, we have libraries installed and we would like to use it in external project. Such a example is in 'externalClientProject' directory.
To build it run (remember in setting up env variable since we have intalled LibA and LibB in non standard directory):
```
cd externalClientProject

CMAKE_PREFIX_PATH=/tmp/myNewLibs:$CMAKE_PREFIX_PATH

mkdir build
cd build
cmake ..
make

./main

```
