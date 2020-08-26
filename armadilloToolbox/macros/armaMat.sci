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
    //   armaMat function applies mathematical functions to each element in Matrix
    //
    //   Syntax
    //   y = armaMat(inp1, inp2, opt)
    //   
    //   Parameters
    //   y : ouput 2dmatrix
    //   inp1: Function Name
    //   inp2: 2dMatrix
    //   opt : optional additional arguements
    //
    //   Description
    //   This function accepts a 2dMatrix/2dArray and returns the processed Matrix specified in function name (inp1). Available functions exp, exp2, exp10, truncExp, expm1, log, log2, log10, truncLog, log1p, pow, square, sqrt, floor, ceil, round, trunc, erf, erfc, lgamma and sign.
    //
    //
    // Examples 
    // // Calculating the exp.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // expres = armaMat("exp",y)
    // 
    // Examples 
    // // Calculating the exp2.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // exp2res = armaMat("exp2",y)
    // 
    // Examples 
    // // Calculating the exp10.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // exp10res = armaMat("exp10",y)
    // 
    // Examples 
    // // Calculating the truncExp.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // truncExpres = armaMat("truncExp",y)
    // 
    // Examples 
    // // Calculating the expm1.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // expm1res = armaMat("expm1",y)
    // 
    // Examples 
    // // Calculating the log.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // logres = armaMat("log",y)
    // 
    // Examples 
    // // Calculating the log2.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // log2res = armaMat("log2",y)
    // 
    // Examples 
    // // Calculating the log10.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // log10res = armaMat("log10",y)
    // 
    // Examples 
    // // Calculating the truncLog.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // truncLogres = armaMat("truncLog",y)
    // 
    // Examples 
    // // Calculating the log1p.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // log1pres = armaMat("log1p",y)
    // 
    // Examples 
    // // Calculating the pow.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // power = int32(3)
    // powres = armaMat("pow",y,power)
    // 
    // Examples 
    // // Calculating the square.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // squareres = armaMat("square",y)
    // 
    // Examples 
    // // Calculating the sqrt.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // sqrtres = armaMat("sqrt",y)
    // 
    // Examples 
    // // Calculating the floor.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // floorres = armaMat("floor",y)
    // 
    // Examples 
    // // Calculating the ceil.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // ceilres = armaMat("ceil",y)
    // 
    // Examples 
    // // Calculating the round.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // roundres = armaMat("round",y)
    // 
    // Examples 
    // // Calculating the trunc.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // truncres = armaMat("trunc",y)
    // 
    // Examples 
    // // Calculating the erf.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // erfres = armaMat("erf",y)
    // 
    // Examples 
    // // Calculating the erfc.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // erfcres = armaMat("erfc",y)
    // 
    // Examples 
    // // Calculating the lgamma.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // lgammares = armaMat("lgamma",y)
    // 
    // Examples 
    // // Calculating the sign.
    // y = [1.2, 1, 1.9; 4, 2.6, 5; 2.3, 8, 7];
    // signres = armaMat("sign",y)
    // 
// Authors
// Ajay.S, Kalai Chelvan.M, Pooja K, Prabhakar P, Dr.K.Indra Gandhi
endfunction
