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


function [y] = armaImage(inp1, inp2, opt)
    //   armaStat function applies image and signal processing techniques
    //
    //   Syntax
    //   y = armaImage(inp1, inp2, opt)
    //   
    //   Parameters
    //   y : ouput variable
    //   inp1: Function Name
    //   inp2: input array / 2d array
    //   opt : optional additional arguements
    //   Description
    //   This function contains the statistical function for 1darray/2darray
    //
    //
    // Examples 
    // // Calculating the convolution 1d. 4th paramter 0 for full, 1 for same
    // y1 = [1,2,3,4,5,6,7,8];
    // y2 = [1,2]
    // res = armaImage("conv1d",y1,y2,0)
    // res = armaImage("conv1d",y1,y2,1)
    // 
    // Examples 
    // // Calculating the convolution 2d. (beta version works fine) 4th paramter 0 for full, 1 for same
    // // y1 = define matrix
    // // y2 = define matrix
    // // res = armaImage("conv2d",y1,y2,0)
    // // res = armaImage("conv2d",y1,y2,1)
    // 
// Authors
// Ajay.S, Kalai Chelvan.M, Pooja K, Prabhakar P, Dr.K.Indra Gandhi
endfunction
