# Qsys [![Build Status](https://travis-ci.org/aarongrisez/Qsys.svg?branch=master)](https://travis-ci.org/aarongrisez/Qsys) <img align='right' src='/QhordLogo.png'>

Qsys is a C++ library used in [Qhord](https://www.qhord.com/) to simulate a quantum particle.


Website: [qhord](http://qhord.com/)

Demo: [Youtube](https://youtu.be/WgCajz7P-M0)

## Getting Started

### Prerequisites
This library uses the linear algebra library [Eigen](http://eigen.tuxfamily.org/), which is already installed in [src/Eigen](src/Eigen).
For now, the whole library download is also included in [src/eigen3.3.5-raw](src/eigen3.3.5-raw).
Its documentation can be found [here](http://eigen.tuxfamily.org/dox/GettingStarted.html).

### Files
`README.md` - this file  
`LICENSE` - the MIT license for this project  
`math.pdf` - an outline of the mathematics being implemented by this library  
`QsysLibraryInterface.md` - a brief description of what the API will be  
The `src` folder contains all source code, which at the moment is just the following:
* `Eigen` - the library we're using for linear algebra (discussed in the  [Prerequisites](Prerequisites) section above)
* `eigen3.3.5-raw` - raw copy of the Eigen library as downloaded from [here](http://bitbucket.org/eigen/eigen/get/3.3.5.zip).
* `test.cpp` - a test file, which now generates a random matrix, exponentiates it to get a propagator,
and applies that propagator to a state-vector in a loop

### Building
To build from source, open the [src](src) folder. From there, you have 2 options:
* Using `make` if you have it installed, or
* Running `g++ -I Eigen/ tests.cpp -o test` from the terminal.

### Running
From the [src](src) folder:  
`./test`

# Contributing

Please reach out to us at [http://qhord.com/](http://qhord.com/) or email Aaron at aaron@qhord.com for info about contributing.

## Authors

* **Aaron Grisez** - *Initial work, Front-End* - [Aaron Grisez](https://github.com/aarongrisez)
* **Michael Seaman** - *Just the README* [Michael Seaman](https://github.com/michaelseaman)
* **Sam Kagan** - *Library Coding* [Sam Kagan](https://github.com/HungryJoe)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
