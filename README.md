# Qsys [![Build Status](https://travis-ci.org/aarongrisez/Qsys.svg?branch=master)](https://travis-ci.org/aarongrisez/Qsys) <img align='right' src='/QhordLogo.png'>

Qsys is a C++ library used in [Qhord](https://www.qhord.com/) to simulate a quantum particle.


Website: [qhord](http://qhord.com/)

Demo: [Youtube](https://youtu.be/WgCajz7P-M0)

## Getting Started

### Prerequisites
This library uses the linear algebra library [Eigen](http://eigen.tuxfamily.org/), which is already installed in [src/Eigen](src/Eigen). The depdencies for this project use conan to download the required depdenices.
Its documentation can be found [here](http://eigen.tuxfamily.org/dox/GettingStarted.html).

#### Git

this project has some submodule that will need to be cloned

```
git submodule update --init --recursive
```

#### Conan

[conan](https://conan.io/) is a package manager for C/C++ libraries.  
To install, you need Python >=2.7 with pip, which should come by default:
```
pip install conan
```
Then, go to the repository's root directory and do
```
conan install . -s compiler.libcxx=libstdc++11
```

to install the required libraries that Qsys will need to use when building.

#### Scons (cross platform)

Godot will need to be built first before building QSys. it's under ```/godot-cpp```. more information can be found [here](https://github.com/GodotNativeTools/godot-cpp). It's already available as a submodule so there is no need to clone godot-cpp.

```
scons generate_bindings=yes
```

scons is used to compile QSys:

```
scons platform=windows/linux/osx
```

This should create the required shared libraries under: ```bin/{platform}/libQSys.*```.  
**Note:** When running the above script, select your operating system from the list
(ie if you're compiling on Linux, run `scons platform=linux`).

#### CxxTest
We are currently using [CxxTest](https://cxxtest.com/) to unit-test this library.
To generate a test runner for a given test suite, run
```
cxxtestgen --error-printer -o test_runner.cpp [TestSuite].h
```

The runner can then be built via
```
g++ -o runner -I CXXTEST test_runner.cpp
```

## Files
`README.md` - this file  
`LICENSE` - the MIT license for this project  
`math.pdf` - an outline of the mathematics being implemented by this library  
`QsysLibraryInterface.md` - a brief description of what the API will be  
`FunctionSpecification.md` - a specification for how functions will be written in initialization files  
`library` - a folder containing all the code. Within it there are three subfolders:
  * `include` - the header files needed for the tests and source code
  * `src` - the source code for the library
  * `tests` - tests for the source code and header files

# Contributing

Please reach out to us at [http://qhord.com/](http://qhord.com/) or email Aaron at aaron@qhord.com for info about contributing.

## Maintainers

The current maintainers of this repository are:

* **Aaron Grisez** - *Initial work, Front-End* - [Aaron Grisez](https://github.com/aarongrisez)
* **Michael Seaman** - *Just the README* [Michael Seaman](https://github.com/michaelseaman)
* **Sam Kagan** - *Library Coding* [Sam Kagan](https://github.com/HungryJoe)
* **Michael Pollind** - *Library Coding* [Michael Pollind](https://github.com/pollend)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
