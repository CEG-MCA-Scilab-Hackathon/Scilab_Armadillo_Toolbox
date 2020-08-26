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


function [y] = armaClust(inp1, inp2, opt)
    //   armaClust function applies clustering techninques.
    //
    //   Syntax
    //   y = armaClust(inp1, inp2, opt)
    //   
    //   Parameters
    //   y : ouput variable
    //   inp1: Function Name
    //   inp2: input array / 2d array
    //   opt : optional additional arguements
    //
    //   Description
    //   This function contains the clustering functions for 1darray/2darray
    //
    //
    // Examples 
    // // Calculating the normcdf and lognormpdf
    // y = [1,2,3,4,5,6,7,8]
    // res = armaClust("normcdf",y)
    // res = armaClust("lognormpdf",y)
    // 
    // Examples 
    // // Calculating the corelation and covariance , input dimension must be same
    // y1 = [1,2,3; 4,5,6; 7,8,9]
    // y2 = [1,9,3; 3,5,6; 7,8,5]
    // res = armaClust("cor",y1,y2)
    // res = armaClust("cov",y1,y2)
    //
    // Examples 
    // // Calculating the principal component analysis
    // y1 = [1,2,3; 4,5,6; 7,8,9]
    // res = armaClust("princomp",y1)
    //
// Authors
// Ajay.S, Kalai Chelvan.M, Pooja K, Prabhakar P, Dr.K.Indra Gandhi
endfunction
