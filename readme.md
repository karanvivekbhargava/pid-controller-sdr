# PID Controller (ENPM808X)
[![Build Status](https://travis-ci.org/karanvivekbhargava/pid-controller-sdr.svg?branch=master)](https://travis-ci.org/karanvivekbhargava/pid-controller-sdr)
[![Coverage Status](https://coveralls.io/repos/github/karanvivekbhargava/pid-controller-sdr/badge.svg?branch=master)](https://coveralls.io/github/karanvivekbhargava/pid-controller-sdr?branch=master)
---
## Discussion Keypoints

We discussed on whether the UML diagram for the class was good enough to convey my thoughts to the team.
<p align="center">
<a target="_blank"><img src="https://github.com/karanvivekbhargava/pid-controller-sdr/blob/master/Class_Diagram.jpg" 
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>

We also discussed a bit on how the compute method works based on the activity diagram. Anyone working with robotics systems understands how to make a PID controller however this gives a clear idea on how to proceed.

<p align="center">
<a target="_blank"><img src="https://raw.githubusercontent.com/karanvivekbhargava/pid-controller-sdr/master/Activity%20Diagram.jpg" 
alt="NMPC" width="480" height="640" border="10" />
</a>
</p>

We discussed a few tests and how to improve upon the current implementation by adding more tests.

1. Step or Convergence Test (Implemented)
<p align="center">
<a target="_blank"><img src="https://797ib1mbyf481ftl3rimdn3x-wpengine.netdna-ssl.com/wp-content/uploads/2016/07/Step-Testv2-800x480.jpg" 
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>
This test was to check the convergence of the controller to the target velocity in a fixed time. It can be viewed as checking the settling time of the system.

2. Bump Test (Implemented)
<p align="center">
<a target="_blank"><img src="https://797ib1mbyf481ftl3rimdn3x-wpengine.netdna-ssl.com/wp-content/uploads/2016/07/Bump-Test-v2-800x480.png" 
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>
This test uses two steps in succession in opposite direction. It checks whether the response is settling at the final target velocity in the given time.

3. Doublet Test (Possible Improvement)
<p align="center">
<a target="_blank"><img src="https://797ib1mbyf481ftl3rimdn3x-wpengine.netdna-ssl.com/wp-content/uploads/2016/07/Doublet-Test-v2-800x480.png" 
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>

Similarly, the Doublet Test is two (2) Bump Tests performed in rapid succession and in opposite directions. The second bump is implemented as soon as the process shows a clear response to the first bump.  Note that the second bump returns the SP to its original value.


4. PRBS Test (Possible Improvement)
<p align="center">
<a target="_blank"><img src="https://797ib1mbyf481ftl3rimdn3x-wpengine.netdna-ssl.com/wp-content/uploads/2016/07/PRBS-Test-v2-800x480.png" 
alt="NMPC" width="480" height="360" border="10" />
</a>
</p>

Finally, a Pseudo-Random Binary Sequence (PRBS) Test is a sequence of SP pulses – or Bump Tests – that are uniform in amplitude, alternating in direction, and of random duration.  While more changes to the SP are involved, the PRBS Test allows each change to be of lesser magnitude.

The other possible improvement is to use more C++ 11 features in the code.

---
## Overview

Simple starter C++ project with:

- cmake
- googletest

## Standard install via command-line
```
git clone --recursive https://github.com/karanvivekbhargava/pid-controller-sdr
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/karanvivekbhargava/pid-controller-sdr
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
