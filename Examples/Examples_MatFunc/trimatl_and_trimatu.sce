 // Function Name: trimatl and trimatu
 //  Create a new matrix by copying either the upper or lower triangular part from square matrix A, and setting the remaining elements to zero
 //  trimatu() copies the upper triangular part
 //  trimatl() copies the lower triangular part
 //  Additional parameter super/sub diagonal level
 // Returns the unique array of input matrix
 // Calculating the trimatl and trimatu
 inputMat = [ 1, 2, 8; 5, 5, 6; 9, 8, 9;]
 result = armaMatFunc("trimatl",inputMat)
 result = armaMatFunc("trimatl",inputMat,1)
 result = armaMatFunc("trimatu",inputMat)
 result = armaMatFunc("trimatu",inputMat,1)

