# Mandelbrot-Set
 
UPDATE v0.10 --------------------------------------------------------------------------------------------

Hi everyone!

This project was a fun way to represent the behavior of a famous iterative function on the complex plane.

To view the image output, which is a .ppm file, open it with software that can read these files like Gimp.

Specifically, the equation used by this program is z_n = z_(n-1)^2 + c, where each term is a complex number
in the form a + bi, where a and b are constants. The c value corresponds to a specific starting coordinate
on the complex plane, and the z_(n-1) term is first set to zero. The equation iterates by setting z_(n-1)
equal to z_n when the right side of the equation is simplified. After a set number of iterations, the
z value's magnitude will either exceed a preset value, or it will continue to stay within a range less
than the preset maximum magnitude. The former is not a part of the Mandelbrot Set, and the latter is.
For points not in the set, the number of iterations it takes for them to exceed the maximum magnitude
will correspond to a color spectrum.
