// Copyright (C) 2019 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Author: Rupak Rokade
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in


function [y] = armaMat(inp1, inp2, opt)
    //   armaVec function applies mathematical functions to to dense matrix(vector processing)
    //
    //   Syntax
    //   y = armaDenseMat(fname, inputMat, opt)
    //   
    //   Parameters
    //   y : ouput
    //   fname: Function Name 
    //   inputMat : input Dense Matrix
    //   opt : additional arguements
    //
    //   Description
    //   This function accepts a Dense Matrix of values of double type and returns the output of respective function executed.
    //   Available functions are asScalar, 
    //
    // Examples
    // // Function Name: chol
    // // Returns the cholesky decomposition of input matrix
    // // Calculating the chol.
    // 
    // inputMat= [2,1,0;1,2,1;0,1,2];
    // result = armaDenseMat("chol",inputMat)
    //
    // Examples
    // // Function Name: eig_sym
    // // Returns the Eigen decomposition of dense symmetric/hermitian input matrix 
    // // Calculating the eigen avlue
    // 
    // inputMat= [2,1,0;1,2,1;0,1,2];
    // result = armaDenseMat("eig_sym",inputMat)
    //
    // Examples
    // // Function Name: eig_gen
    // // Returns the Eigen decomposition of dense general (non-symmetric/non-hermitian) square input matrix 
    // // Calculating the eigen avlue
    // 
    // inputMat= [2,1,0;1,2,1;0,1,2];
    // result = armaDenseMat("eig_gen",inputMat)
    // result = armaDenseMat("eig_gen",inputMat,"balance")
    //
    // Examples
    // // Function Name: hess
    // // Returns the Upper Hessenberg decomposition of square input matrix 
    // // Calculating the hess avlue
    // 
    // inputMat= [3, 1, 1;1,2,2;1,2,2];
    // result = armaDenseMat("hess",inputMat)
    //
    // Examples
    // // Function Name: svd
    // // Returns ingular value decomposition of dense input matrix 
    // // Calculating the svd
    // 
    // inputMat= [2,1,0;1,2,1;0,1,2];
    // result = armaDenseMat("svd",inputMat)
    //
// Authors
// Ajay.S, Kalai Chelvan.M, Pooja K, Prabhakar P, Dr.K.Indra Gandhi
endfunction
