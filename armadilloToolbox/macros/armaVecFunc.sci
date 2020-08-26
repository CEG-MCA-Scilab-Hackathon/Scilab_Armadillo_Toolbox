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
    //   armaVec function applies mathematical functions to to double array (vector processing)
    //
    //   Syntax
    //   y = armaVec(fname, inputvec, opt)
    //   
    //   Parameters
    //   y : ouput
    //   inputvec : Function Name
    //   opt : additional arguements
    //
    //   Description
    //   This function accepts a Array of values of double type and returns the output of respective function executed.
    //   Available functions are asScalar, 
    //
    // Examples
    // // Function Name: asScalar
    // // Returns the pure scalar value of input array/matrix/array
    // // Calculating the asScalar.
    // inputrowvec = [1, 2, 3];
    // inputcolvec = [4, 5, 2];
    // inputMat = [ 1, 2, 3; 4, 5, 6; 7, 8, 10;]
    // result = armaVec("asScalar",inputrowvec,inputcolvec)
    // result = armaVec("asScalar",inputrowvec,inputMat,inputcolvec)
    //
    // Examples
    // // Function Name: cross
    // // Calculate the cross product between A and B, under the assumption that A and B are 3 dimensional vectors
    // // Calculating the cross.
    // inputvec1 = [1, 2, 3];
    // inputvec2 = [4, 5, 2];
    // result = armaVec("cross",inputvec1,inputvec2)
    //
    // Examples
    // // Function Name: cummulativeSum
    // // Calculate the cummulativeSum for given array
    // // Calculating the cummulativeSum.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("cummulativeSum",inputvec1)
    //
    // Examples
    // // Function Name: cummulativeProduct
    // // Calculate the cummulativeProduct for given array
    // // Calculating the cummulativeProduct.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("cummulativeProduct",inputvec1)
    //
    // Examples
    // // Function Name: diagmat
    // // Returns a matrix with the k-th diagonal containing a copy of the k-th diagonal of X; all other elements are set to zero. 
    // // Calculating the diagmat.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("diagmat",inputvec1,2)
    // result = armaVec("diagmat",inputvec1)
    //
    // Examples
    // // Function Name: diff
    // // Return differences between consecutive elements
    // // Calculating the diff.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("diff",inputvec1)
    //
    // Examples
    // // Function Name: dot, cdot, norm_dot
    // //  dot(A,B): dot product of A and B, treating A and B as vectors
    // //  cdot(A,B): as per dot(A,B), but the complex conjugate of A is used
    // //  norm_dot(A,B): normalised dot product; equivalent to dot(A,B) / (∥A∥•∥B∥)
    // // Calculating the dot, cdot, norm_dot
    // inputvec1 = [1, 2, 3];
    // inputvec2 = [4, 5, 2];
    // result = armaVec("dot",inputvec1,inputvec2)
    // result = armaVec("cdot",inputvec1,inputvec2)
    // result = armaVec("norm_dot",inputvec1,inputvec2)
    //  
    // // Function Name: eps
    // //  Obtain the positive distance of the absolute value of each element of inputvec to the next largest representable floating point number
    // // Calculating the eps.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("eps",inputvec1)
    //
    // Examples
    // // Function Name: findUnique
    // //  Obtain the positive distance of the absolute value of each element of inputvec to the next largest representable floating point number
    // //  3rd parameter : 0/1 for ascending/descending
    // // Calculating the findUnique.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("findUnique",inputvec1)
    // result = armaVec("findUnique",inputvec1,1)
    //
    // Examples
    // // Function Name: indexMin/indexMax
    // // Return index of min/max value
    // // Calculating the indexMin/indexMax.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("indexMin",inputvec1)
    // result = armaVec("indexMax",inputvec1)
    //
    // Examples
    // // Function Name: intersect
    // // Return the unique elements common to both A and B, sorted in ascending order
    // // Calculating the intersect.
    // inputvec1 = [1, 2, 3];
    // inputvec2 = [4, 5, 2];
    // result = armaVec("intersect",inputvec1,inputvec2)
    //
    // Examples
    // // Function Name: min/max
    // // Return min/max value
    // // Calculating the min/max
    // inputvec1 = [1, 2, 3];
    // result = armaVec("min",inputvec1)
    // result = armaVec("max",inputvec1)
    //
    // Examples
    // // Function Name: norm
    // //  Compute the p-norm
    // //  3rd parameter : "-inf"=1, "inf"=2, "fro"=default
    // //  "-inf" is the minimum norm, "inf" is the maximum norm, while "fro" is the Frobenius norm
    // // Calculating the norm
    // inputvec1 = [1, 2, 3];
    // result = armaVec("norm",inputvec1)
    //
    // Examples
    // // Function Name: normalize
    // // Return its normalised version (ie. having unit p-norm)
    // //  3rd parameter : p-norm value
    // // Calculating the normalize.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("normalize",inputvec1)
    // result = armaVec("normalize",inputvec1,1)
    //
    // Examples
    // // Function Name: reverse
    // // Return the reversed array
    // // Calculating the reverse.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("reverse",inputvec1)
    //
    // Examples
    // // Function Name: shift
    // // Return the shifted array in circular manner
    // // Calculating the shift.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("shift",inputvec1,1)
    //
    // Examples
    // // Function Name: shuffle
    // // Return the shuffled array
    // // Calculating the shuffle.
    // inputvec1 = [1, 2, 3];
    // result = armaVec("shuffle",inputvec1)
    //
    // Examples
    // // Function Name: sort
    // // Return the sorted array
    // //  3rd parameter : 0/1 for ascend/descend
    // // Calculating the sort.
    // inputvec1 = [5, 4, 3];
    // result = armaVec("sort",inputvec1)
    //
    // Examples
    // // Function Name: sortIndex
    // // Return a vector which describes the sorted order of the elements of inputvec1 (ie. it contains the indices of the elements of inputvec1)
    // //  3rd parameter : 0/1 for ascend/descend
    // // Calculating the sortIndex.
    // inputvec1 = [5, 4, 3];
    // result = armaVec("sortIndex",inputvec1)
    // result = armaVec("sortIndex",inputvec1,1)
    //
    // Examples
    // // Function Name: stableSortIndex
    // // Return a vector which describes the sorted order of the elements of inputvec1 (ie. it contains the indices of the elements of inputvec1)
    // //  stable_sort_index() variant preserves the relative order of elements with equivalent values
    // //  3rd parameter : 0/1 for ascend/descend
    // // Calculating the stableSortIndex.
    // inputvec1 = [5, 4, 3];
    // result = armaVec("stableSortIndex",inputvec1)
    // result = armaVec("stableSortIndex",inputvec1,1)
    //
    // Examples
    // // Function Name: sum
    // // Return the sum of of all elements in array
    // // Calculating the sum.
    // inputvec1 = [5, 4, 3];
    // result = armaVec("sum",inputvec1)
    //  
    // // Function Name: trapz
    // //  Compute the trapezoidal integral of Y with respect to spacing in X, in each column (dim=0) or each row (dim=1) of Y
    // // Calculating the trapz.
    // inputvec1 = [5, 4, 3];
    // inputvec1 = [1, 2, 3];
    // result = armaVec("trapz",inputvec1,inputvec2) 
    // result = armaVec("trapz",inputvec1,inputvec2,1)  
    //
    // Examples
    // // Function Name: unique
    // // Return the unique elements of input Array, sorted in ascending order
    // // Calculating the unique.
    // inputvec1 = [5, 4, 3, 4, 3, 2, 7, 0];
    // result = armaVec("unique",inputvec1)
    //
// Authors
// Ajay.S, Kalai Chelvan.M, Pooja K, Prabhakar P, Dr.K.Indra Gandhi
endfunction
