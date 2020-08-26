 // Function Name: repMat
 //  Generate a matrix by replicating matrix A in a block-like fashion
 //  The generated matrix has the following size:
 //  n_rows  =  num_copies_per_row  *   A.n_rows
 //  n_cols  =  num_copies_per_col  *   A.n_cols
 //  3rd parameter = num_copies_per_row
 //  4th parameter = num_copies_per_col
 // Calculating the repmat
 inputMat = [ 1, 2, 3; 4, 5, 6; 7, 8, 9;]
 result = armaMatFunc("repMat",inputMat,2,2)

