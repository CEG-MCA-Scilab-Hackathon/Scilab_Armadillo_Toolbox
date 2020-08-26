 // Function Name: diff
 //  Return a matrix containing the differences between consecutive elements in each column (dim=0), or each row (dim=1) of the input matrix. 
 // Calculating the diff.
 inputMat = [-1.2, 1, 1.9; -4, 2.6, 5; -2.3, 8, -7];
 // k indicates that the differences are calculated recursively k times 
 //k=2
 result = armaMatFunc("diff",inputMat,2)
 //k can also be optional,by default k=0
 result = armaMatFunc("diff",inputMat)
 
