 // Function Name: rcond
 //  Return the 1-norm estimate of the reciprocal of the condition number of square matrix A
 //  Values close to 1 suggest that A is well-conditioned
 //  Values close to 0 suggest that A is badly conditioned
 // Calculating the rcond
 inputMat = [ 1, 2, 3; 4, 5, 6; 7, 8, 1;]
 result = armaMatFunc("rcond",inputMat)

