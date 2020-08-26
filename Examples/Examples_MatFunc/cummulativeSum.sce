 // Function Name: cummulativeSum
 //  Returns a matrix containing the cumulative sum of elements in each column (dim=0), or each row (dim=1)  of input matrix
 // Calculating the cummulativeSum.
 //dim = 1 
 inputMat = [-1.2, 1, 1.9; -4, 2.6, 5; -2.3, 8, -7];
 result = armaMatFunc("cummulativeSum",inputMat,1)
 //dim = 0
 result = armaMatFunc("cummulativeSum",inputMat,0)


