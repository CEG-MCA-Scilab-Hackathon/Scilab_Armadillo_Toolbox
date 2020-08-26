 // Function Name: eig_gen
 // Returns the Eigen decomposition of dense general (non-symmetric/non-hermitian) square input matrix 
 // Calculating the eigen avlue
 
 inputMat= [2,1,0;1,2,1;0,1,2];
 result = armaDenseMat("eig_gen",inputMat)
 result = armaDenseMat("eig_gen",inputMat,"balance")

