 // Function Name: dot, cdot, norm_dot
 //  dot(A,B): dot product of A and B, treating A and B as vectors
 //  cdot(A,B): as per dot(A,B), but the complex conjugate of A is used
 //  norm_dot(A,B): normalised dot product; equivalent to dot(A,B) / (∥A∥•∥B∥)
 // Calculating the dot, cdot, norm_dot
 inputvec1 = [1, 2, 3];
 inputvec2 = [4, 5, 2];
 result = armaVec("dot",inputvec1,inputvec2)
 result = armaVec("cdot",inputvec1,inputvec2)
 result = armaVec("norm_dot",inputvec1,inputvec2)
  
 // Function Name: eps
 //  Obtain the positive distance of the absolute value of each element of inputvec to the next largest representable floating point number
 // Calculating the eps.
 inputvec1 = [1, 2, 3];
 result = armaVec("eps",inputvec1)

