# Game engine

A game engine consists of 3 smaller engines:

* [Math Engine](#math-engine)
* [Rendering Engine](#rendering-engine)
* [Physics Engine](#physics-engine)

## Math engine

The most fundamental part. It encapsules the math complexity.

* Vector operations
  * Addition & subtraction: Allows a character to move
  * Dot Product: Determines how much a vector influences another
  * Cross Product: Allows for the creation of a third vector
* Matrix operations
  * Transformation: Allows a character to rotate
  * Transpose
  * Inverse
  * Identity

> You may want to include Quaternion and Dual-Quaternion operations in the math engine. Quaternions rotate game entities but uses less space and are faster than matrices. Dual-Quaternions offer the beauty of translation and rotation in a single math entity.

## Rendering engine

In charge of painting the pixels on the screen. There are 2 options:
* Rasterization:
* Raytracing: Most compuationally expensive


## Physics Engine

There are 3 methods:
* Euler Method
* Verlet Method
* Runge-Kutta Method


## References

* https://www.haroldserrano.com/blog/how-do-i-build-a-game-engine
* http://www.gabrielgambetta.com/computer-graphics-from-scratch
* https://youtu.be/ARn_yhgk7aE
