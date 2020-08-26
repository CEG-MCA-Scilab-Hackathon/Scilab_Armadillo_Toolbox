 // Function Name: diagmat
 // Returns a matrix with the k-th diagonal containing a copy of the k-th diagonal of X; all other elements are set to zero. 
 // Calculating the diagmat.
 inputMat = [-1.2, 1, 1.9; -4, 2.6, 5; -2.3, 8, -7];
 //k=2
 result = armaMatFunc("diagmat",inputMat,2)
 //k can also be optional,by default k=0
 result = armaMatFunc("diagmat",inputMat)

