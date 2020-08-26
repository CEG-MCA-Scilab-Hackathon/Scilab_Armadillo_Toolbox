 // Function Name: cummulativeProduct
 // Returns a matrix containing the cumulative product of elements in each column (dim=0), or each row (dim=1)  of input matrix
 // Calculating the cummulativeProduct.
 //dim = 1 
 inputMat = [-1.2, 1, 1.9; -4, 2.6, 5; -2.3, 8, -7];
 result = armaMatFunc("cummulativeProduct",inputMat,1)
 //dim = 0
 result = armaMatFunc("cummulativeProduct",inputMat,0)

