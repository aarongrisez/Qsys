This file specifies the notation to be used for functions of *t*
in the Hamiltonian section of an initialization file, as well as
anywhere else where the library needs to read such functions from a file.

# Specification

For variable *t*, constants *a,b,c,d,e*,
and expressions of arbitrary length *u,v,w*,  
*c + a - b* := `c+a-b`  
*a\*b* = `ab`  
*a/b* = `a/b`
*a(b + c(d - e))* = `a(b+c(d-e))`  
*a<sup>t</sup>* = `a^t`  
*a<sup>u</sup>* = `a^(u)`  

*u + v - w* = `u+v-(w)`  
*u \* v* = `u(v)`  
*u / v* = `(u)/(v)`  
sin *u* = `sin(u)`  
cos *u* = `cos(u)`

*t<sup>a</sup>* = `t^a`  
*t<sup>u</sup>* = `t^(u)`  
*v<sup>u</sup>* = `(v)^(u)`  
*e<sup>u<sup>a</sup> + t <sup>b</sup></sup>* = `e^((u)^a+t^b)`  

### Some general rules
* The independent variable of all functions shall be written `t`.
* There shall be no whitespace within a function.
* There shall be parentheses around any expression longer than
a single constant or variable for terms of all operations other than `+`.
* No constant shall be exponentiated by another constant.
