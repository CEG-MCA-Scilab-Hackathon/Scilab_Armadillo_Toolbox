// Gateway to Aramdillo functions Matrix elements
// Todo - Exception Handling
#include "armaMat.h"
#include <string.h>
extern "C"
{
#include "api_scilab.h"
#include "Scierror.h"
#include "BOOL.h"
#include <localization.h>


    static const char fname[] = "armaMatFunc"; //Function name for scilab interface

    void throwinputerrorMat()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchMat(string str)
    {
        Scierror(77, _("%s: %s Function doesn't available .\n"), fname, str);
    }


    int armadilloMatFunc(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
    {
        int row0 = 0, row1 = 0, row2=0;
        int column0 = 0, column1=0, column2=0;
        int size0 = 0, size1=0, size2=0;
        double *inputArray1 = NULL;
        double *inputArray2 = NULL;
        double *k = (double *)malloc(sizeof(double)*1);
        double *q = (double *)malloc(sizeof(double)*1);
        double *option = (double *)malloc(sizeof(double)*1);
        double *n = (double *)malloc(sizeof(double)*1);
        double *p = (double *)malloc(sizeof(double)*1);
        double *dim = (double *)malloc(sizeof(double)*1);
        double *min = (double *)malloc(sizeof(double)*1);
        double *max = (double *)malloc(sizeof(double)*1);
        wchar_t* in2 = 0;
        SciErr sciErr;
        int optrigger = 0;

        // Check input argument count
        if(nin<2)
        {
            Scierror(77, _("%s: Wrong number of input argument(s): 2 expected.\n"), fname);
            return 1;
        }

        // Check argument type

        if(scilab_isMatrix2d(env, in[1]) != 1 || scilab_isDouble(env, in[1]) == 0)
        {
            Scierror(999, _("%s: Wrong type for input argument #%d:  A double vector expected.\n"), fname, 1);
            return 1;
        }

        // Get array dims
        size0 = scilab_getDim2d(env, in[1], &row0, &column0);
        
        // if (isrowcolumnInvalid(row, column))return 1;
        if (row0 <= 0 || column0 <= 0)
        {
            Scierror(77, _("%s: Size(s) row or column size cannot be less than 1: %d or more expected.\n"), fname, 1);
            return 1;
        }
        
        // Copy input array
        scilab_getDoubleArray(env, in[1], &inputArray1);
        
        vector<vector<double>> inputMat(row0, vector<double>(column0));
        int tk = 0;
        for (int i = 0; i < row0; i++)
            for (int j = 0; j < column0; j++)
                inputMat[i][j] = inputArray1[tk++];
        
        scilab_getString(env, in[0], &in2);        
        //conversion wchar to string type
        wstring ws(in2);
        string str(ws.begin(), ws.end());
        
        // Result variables
        vector<vector<double>> out1;
        vector<vector<uword>> uout1;
        vector<vector<complex<double>>> cxmatres;
        vector<double> vectorres;
        double doubleres;
        vector<uword> uvectorres;
        uword uwordres;
        
        // switch to respected function call
        try{
        if(str.compare("accumulate")==0){ //c
            doubleres = accumulateArma(inputMat); 
            optrigger = 3; 
        }
        else if(str.compare("absolute")==0){ //c
            out1 = absoluteArma(inputMat); 
            optrigger = 0; 
        }
        else if(str.compare("affmultiply")==0){ //c
            if(nin==3){  
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 <= 0 || column1 <= 0){throwinputerrorMat();return 1;}  
                if(column0 != (row1 + 1)){throwinputerrorMat();return 1;}    
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                vectorres = affmultiplyArma(inputMat,  inpvec12); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("arg")==0){ //c
            out1 = argArma(inputMat);
            optrigger = 0;
        }
        else if(str.compare("clamp")==0){ //c
            if(nin==4){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                if(scilab_isDouble(env, in[3]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], min);
                scilab_getDouble(env, in[3], max);
                out1 = clampArma(inputMat, (int)*min, (int)*max); 
            }else{throwMismatchMat(str);return 1;} 
            optrigger = 0;
        }
        else if(str.compare("cond")==0){ //c
            try{ 
                doubleres = condArma(inputMat);
            }catch(...){Scierror(133,"The Matrix cannot be decomposed: %d\n", 1);return 1;} 
            optrigger = 3; 
        }
        // else if(str.compare("conj")==0){ cxmatres = conjArma(inputMat); optrigger = 1;}
        else if(str.compare("cummulativeSum")==0){ //c
            if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                int idim = (int)*dim;
                if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
                out1 = cummulativeSumArma(inputMat, idim);
            }else{throwMismatchMat(str);return 1;}  
            optrigger = 0; 
        }
        else if(str.compare("cummulativeProduct")==0){ //c 
            if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                int idim = (int)*dim;
                if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
                out1 = cummulativeProductArma(inputMat, idim);
            }else{throwMismatchMat(str);return 1;}  
            optrigger = 0; 
        }
        else if(str.compare("determinant")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;}
            doubleres = determinantArma(inputMat); 
            optrigger = 3; 
        }
        else if(str.compare("diagmat")==0){ //c
            if(nin==2){
                out1 = diagmatArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], k);
                out1 = diagmatArma(inputMat, (int)*k);
            }else{throwMismatchMat(str);return 1;}            
            optrigger = 0; 
        }
        else if(str.compare("diagvec")==0){ //c
            if(nin==2){
                vectorres = diagvecArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], k);
                vectorres = diagvecArma(inputMat, (int)*k);
            }else{throwMismatchMat(str);return 1;} 
            optrigger = 2;
        }   // as of now
        else if(str.compare("diff")==0){ //c
            if(nin==2){
                out1 = diffArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                double *k = (double *)malloc(sizeof(double)*1);
                scilab_getDouble(env, in[2], k);
                out1 = diffArma(inputMat,  (int)*k);
            }else if(nin==4){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                double *k = (double *)malloc(sizeof(double)*1);
                scilab_getDouble(env, in[2], k);
                if(scilab_isDouble(env, in[3]) == 0){throwinputerrorMat();return 1;}
                double *dim = (double *)malloc(sizeof(double)*1);
                scilab_getDouble(env, in[3], dim);
                out1 = diffArma(inputMat,  (int)*k,  (int)*dim); 
            }else{throwMismatchMat(str);return 1;} 
        	optrigger = 0; 
        }
        else if(str.compare("eps")==0){ //c
            out1 = epsArma(inputMat); 
            optrigger = 0; 
        }
        else if(str.compare("expmat")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;} 
            try
         	{ 
       	        out1 = expmatArma(inputMat); 
          	}catch(...)
         	{Scierror(133,"The Matrix Exponential cannot be found: %d\n", 1);return 1;   }         	 
        	optrigger = 0; 
        }
        else if(str.compare("expmatSym")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;} 
            try
         	{ 
       	        out1 = expmatSymArma(inputMat); 
          	}catch(...){Scierror(133,"The Matrix Exponential cannot be found: %d\n", 1);return 1;   } 
        	optrigger = 0; 
        }
        // else if(str.compare("find")==0){ //ic
        //     if(nin==6){
        // 	    if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
        // 	    scilab_getDouble(env, in[2], option);
        //       	if(scilab_isDouble(env, in[3]) == 0){throwinputerrorMat();return 1;}
        // 	    scilab_getDouble(env, in[3], n);
        //       	if(scilab_isDouble(env, in[4]) == 0){throwinputerrorMat();return 1;}
        // 	    scilab_getDouble(env, in[4], k);
        //       	if(scilab_isDouble(env, in[5]) == 0){throwinputerrorMat();return 1;}
        // 	    scilab_getDouble(env, in[5], p);
		//         uvectorres = findArma(inputMat, (int)*option, (int)*n, (int)*k, (int)*p); 
        //     }else{throwMismatchMat(str);return 1;} 
        // 	optrigger = 4; 
        // }
        // else if(str.compare("findFinite")==0){ //ic
        //     uvectorres = findFiniteArma(inputMat); 
        //     optrigger = 4; 
        // }
        // else if(str.compare("findNonFinite")==0){ //ic
        //     uvectorres = findNonFiniteArma(inputMat); 
        //     optrigger = 4; 
        // }
        else if(str.compare("fliplr")==0){ //c
            out1 = fliplrArma(inputMat); 
            optrigger = 0; 
        }
        else if(str.compare("flipud")==0){ //c
            out1 = flipudArma(inputMat); 
            optrigger = 0; 
        }
        // else if(str.compare("imag")==0){ out1 = imagArma(inputMat); optrigger = 0; } \\ic
        // else if(str.compare("real")==0){ out1 = realArma(inputMat); optrigger = 0; } \\ic
        // else if(str.compare("ind2sub")==0){ //c
        //     if(scilab_isDouble(env, in[2]) == 0 || scilab_isVector(env, in[2]) == 0){
        //          scilab_getDouble(env, in[2], option);        
        //          uvectorres = ind2subArma(inputMat, (int)*option); 
        //          optrigger = 4;  
		//     }else if(scilab_isDouble(env, in[2]) == 0 || scilab_isVector(env, in[2]) != 0){
        //          size1 = scilab_getSize(env, in[2]); 
        //          scilab_getDoubleArray(env, in[2], &inputArray2);
        //          vector<uword> inpindices(size1);
        //          int bk = 0;
        //          for (int i = 0; i < size1; i++)
        //             inpindices[i] = (uword)inputArray2[bk++];
        //          uout1 = ind2subArma(inputMat,  inpindices); 
        //          optrigger = 6;
		//     }else{throwMismatchMat(str);return 1;}	 
        // }
        // else if(str.compare("indexMin")==0){ //c
        //     if(nin==2){
        //         uvectorres = indexMinArma(inputMat); 
        //     }else if(nin==3){
        //         if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
        //         scilab_getDouble(env, in[2], dim);
        //         int idim = (int)*dim;
        //         if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
        //         uvectorres = indexMinArma(inputMat, idim); 
        //     }else{throwMismatchMat(str);return 1;}  
        //     optrigger = 4; 
        // }
        // else if(str.compare("indexMax")==0){ //ic
        //     if(nin==2){
        //         uvectorres = indexMaxArma(inputMat); 
        //     }else if(nin==3){
        //         if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
        //         scilab_getDouble(env, in[2], dim);
        //         int idim = (int)*dim;
        //         if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
        //         uvectorres = indexMaxArma(inputMat, idim); 
        //     }else{throwMismatchMat(str);return 1;} 
        //     optrigger = 4; 
        // }
        else if(str.compare("inplaceTrans")==0){ //c
            try{
                if(nin==2){
                    out1 = inplaceTransArma(inputMat); 
                }else if(nin==3){
                    if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                    scilab_getDouble(env, in[2], k);
                    int x = (int)*k;
                    bool lowmem = x?true:false;
                    out1 = inplaceTransArma(inputMat, lowmem);
                }else{throwMismatchMat(str);return 1;}
            }catch(...){Scierror(133,"Matrix Incompatible: %d\n", 1);return 1;}
            optrigger = 0; 
        }
        // else if(str.compare("inplaceStrans")==0){ out1 = inplaceStransArma(inputMat, lowmem); optrigger = 0; }
        else if(str.compare("joinRows")==0 || str.compare("joinCols")==0 || str.compare("joinHoriz")==0 || str.compare("joinVert")==0){ //c
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1){throwinputerrorMat();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 <= 0 || column1 <= 0){throwinputerrorMat();return 1;}    
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<vector<double>> inputMat1(row1, vector<double>(column1));
                int k = 0;
                for (int i = 0; i < row1; i++)
                    for (int j = 0; j < column1; j++)
                        inputMat1[i][j] = inputArray2[k++];
                if(str.compare("joinRows")==0){
                    if(row0!=row1){throwinputerrorMat();return 1;}
                    out1 = joinRowsArma(inputMat, inputMat1); 
                }else if(str.compare("joinCols")==0){
                    if(column0!=column1){throwinputerrorMat();return 1;}
                    out1 = joinColsArma(inputMat, inputMat1); 
                }else if(str.compare("joinHoriz")==0){
                    if(row0!=row1){throwinputerrorMat();return 1;}
                    out1 = joinHorizArma(inputMat, inputMat1);
                }else if(str.compare("joinVert")==0){
                    if(column0!=column1){throwinputerrorMat();return 1;}
                    out1 = joinVertArma(inputMat, inputMat1);  
                }else{throwMismatchMat(str);return 1;} 
            }else{throwMismatchMat(str);return 1;} 
            optrigger = 0; 
        }
        else if(str.compare("kron")==0){ //c
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1){throwinputerrorMat();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 <= 0 || column1 <= 0){throwinputerrorMat();return 1;}  
                // if(column0 != (row1 + 1)){throwinputerrorMat();return 1;}    
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<vector<double>> inputMat1(row1, vector<double>(column1));
                int k = 0;
                for (int i = 0; i < row1; i++)
                    for (int j = 0; j < column1; j++)
                        inputMat1[i][j] = inputArray2[k++];
                out1 = kronArma(inputMat, inputMat1); 
            }else{throwMismatchMat(str);return 1;} 
            optrigger = 0; 
        }
        else if(str.compare("logDet")==0){ //c
            vectorres = logDetArma(inputMat); 
            optrigger = 2; 
        }
        else if(str.compare("logMat")==0){ //c
            cxmatres = logMatArma(inputMat); 
            optrigger = 1; 
        }
        // else if(str.compare("logmatSympd")==0){ out1 = logmatSympdArma(inputMat); optrigger = 0; } //ic
        else if(str.compare("min")==0){ //c
            if(nin==2){
                vectorres = minArma(inputMat);  
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                int idim = (int)*dim;
                if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
                vectorres = minArma(inputMat, idim); 
            }else{throwMismatchMat(str);return 1;} 
            optrigger = 2; 
        }
        else if(str.compare("max")==0){ //c
            if(nin==2){
                vectorres = maxArma(inputMat);  
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                int idim = (int)*dim;
                if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
                vectorres = maxArma(inputMat, idim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("nonZeros")==0){ //c
            vectorres = nonZerosArma(inputMat); 
            optrigger = 2; 
        }
        else if(str.compare("norm")==0){ //c
            if(nin==2){
                doubleres = normArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], p);
                doubleres = normArma(inputMat, 1 , (int)*p ); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 3; 
        }
        else if(str.compare("normalize")==0){ //c
            if(nin==2){
                out1 = normalizeArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], p);
                out1 = normalizeArma(inputMat, (int)*p); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("prod")==0){ //c
            if(nin==2){
                vectorres = prodArma(inputMat, 1); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                int idim = (int)*dim;
                if(idim != 0 && idim !=1 ){throwinputerrorMat();return 1;}
                vectorres = prodArma(inputMat, 1); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("powMat")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;}
            if(nin==3){
                if(scilab_isDouble(env, in[2]) == 1){
                    if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                    scilab_getDouble(env, in[2], n);
                    cxmatres = powMatArma(inputMat, (double)*n); 
                    optrigger = 1; 
                }
                else if(scilab_isInt32(env, in[2]) == 1){
                    int pow;
                    scilab_getInteger32(env,in[2],&pow);
                    out1 = powMatArma(inputMat, pow); 
                    optrigger = 0; 
                }else{throwMismatchMat(str);return 1;}
            }else{throwMismatchMat(str);return 1;}
        }
        else if(str.compare("rank")==0){ //c
            uwordres = rankArma(inputMat); 
            optrigger = 5; 
        }
        else if(str.compare("rcond")==0){ //c
            doubleres = rcondArma(inputMat); 
            optrigger = 3; 
        }
        else if(str.compare("repElem")==0){ //c
            if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], p);
                int copies_per_row = (int)*n, copies_per_col = (int)*p;
                if(copies_per_row<1 || copies_per_row<1){throwMismatchMat(str);return 1;}
                out1 = repElemArma(inputMat, copies_per_row, copies_per_col);
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("repMat")==0){ //c
            if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], p);
                int copies_per_row = (int)*n, copies_per_col = (int)*p;
                if(copies_per_row<1 || copies_per_row<1){throwMismatchMat(str);return 1;}
                out1 = repMatArma(inputMat, copies_per_row, copies_per_col); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("reshape")==0){ //c
            if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], p);
                int rows = (int)*n, cols = (int)*p;
                if(rows<1 || cols<1){throwMismatchMat(str);return 1;}
                out1 = reshapeArma(inputMat, rows, cols);
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("resize")==0){ //c
            if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], p);
                int rows = (int)*n, cols = (int)*p;
                if(rows<1 || cols<1){throwMismatchMat(str);return 1;}
                out1 = resizeArma(inputMat, rows, cols); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("reverse")==0){ //c
            if(nin==2){
                out1 = reverseArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], dim);
                out1 = reverseArma(inputMat, (int)*dim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("shift")==0){ //c
            if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                out1 = shiftArma(inputMat, (int)*n); 
            }else if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], dim);
                out1 = shiftArma(inputMat, (int)*n, (int)*dim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("shuffleRowOrColumn")==0){ //c
            if(nin==2){
                out1 = shuffleRowOrColumnArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], dim);
                out1 = shuffleRowOrColumnArma(inputMat, (int)*dim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("sort")==0){ //c
            if(nin==2){
                out1 = sortArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                out1 = sortArma(inputMat, (int)*n); 
            }else if(nin==4){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], n);
                if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[3], dim);
                out1 = sortArma(inputMat, (int)*n, (int)*dim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("sqrtMat")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;}
            cxmatres = sqrtMatArma(inputMat); 
            optrigger = 1; 
        }
        // else if(str.compare("sqrtmatSympd")==0){ //ic
        //     if(row0 != column0){throwinputerrorMat();return 1;}
        //     out1 = sqrtmatSympdArma(inputMat); 
        //     optrigger = 0; 
        // }
        else if(str.compare("sum")==0){ //c
            if(nin==2){
                vectorres = sumArma(inputMat);         
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], dim);
                vectorres = sumArma(inputMat, (int)*dim); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 2; 
        }
        // else if(str.compare("sub2ind")==0){ //ic 
        //     if(nin==4){
        //         if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
        //         scilab_getDouble(env, in[2], k);
        //         if(scilab_isDouble(env, in[3]) != 1){throwMismatchMat(str);return 1;}
        //         scilab_getDouble(env, in[3], p);
        //         int row = (int)*k, col = (int)*p;
        //         uwordres = sub2ind(inputMat, row, col);
        //     }else{throwMismatchMat(str);return 1;}
        //     optrigger = 5;
        // }
        else if(str.compare("symmatu")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;}
            if(nin==2){
                out1 = symmatuArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], k);
                int x = (int)*k;
                bool do_conj = x?true:false;
                out1 = symmatuArma(inputMat, do_conj); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("symmatl")==0){ //c
            if(row0 != column0){throwinputerrorMat();return 1;}
            if(nin==2){
                out1 = symmatlArma(inputMat); 
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) != 1){throwMismatchMat(str);return 1;}
                scilab_getDouble(env, in[2], k);
                int x = (int)*k;
                bool do_conj = x?true:false;
                out1 = symmatlArma(inputMat, do_conj); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("trace")==0){ //c
            doubleres = traceArma(inputMat); 
            optrigger = 3;
        }
        else if(str.compare("trans")==0){ //c
            try{
                out1 = transArma(inputMat); 
                optrigger = 0; 
            }catch(...){Scierror(133,"Matrix Incompatible: %d\n", 1);return 1;}
        }
        // else if(str.compare("trans")==0){ cxmatres = transArma(inputMat); optrigger = 1; } //ic
        // else if(str.compare("strans")==0){ out1 = stransArma(inputMat); optrigger = 0;} //ic
        else if(str.compare("trimatu")==0){ //c
            if(nin==2){
                out1 = trimatuArma(inputMat);
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], k);
                out1 = trimatuArma(inputMat, (int)*k); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("trimatl")==0){ //c
            if(nin==2){
                out1 = trimatlArma(inputMat);
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], k);
                out1 = trimatlArma(inputMat, (int)*k); 
            }else{throwMismatchMat(str);return 1;}
            optrigger = 0; 
        }
        // else if(str.compare("trimatuInd")==0){ //ic
        //     if(nin==2){
        //         uvectorres = trimatuIndArma(inputMat); 
        //     }else if(nin==3){
        //         if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
        //         scilab_getDouble(env, in[2], k);
        //         uvectorres = trimatuIndArma(inputMat, (int)*k); 
        //     }else{throwMismatchMat(str);return 1;}
        //     optrigger = 4; 
        // }
        // else if(str.compare("trimatlInd")==0){ //ic
        //     if(nin==2){
        //         uvectorres = trimatlIndArma(inputMat); 
        //     }else if(nin==3){
        //         if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
        //         scilab_getDouble(env, in[2], k);
        //         uvectorres = trimatlIndArma(inputMat, (int)*k); 
        //     }else{throwMismatchMat(str);return 1;}
        //     optrigger = 4;
        // }
        else if(str.compare("unique")==0){ //c
            vectorres = uniqueArma(inputMat); 
            optrigger = 2;
        }
        else if(str.compare("vectorise")==0){ //c -- !dim
            if(nin==2){
                vectorres = vectoriseArma(inputMat);
            }else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwinputerrorMat();return 1;}
                scilab_getDouble(env, in[2], dim);
                vectorres = vectoriseArma(inputMat, (int)*dim);
            }else{throwinputerrorMat();return 1;}
            optrigger = 2; 
        }
        else{ throwMismatchMat(str);return 1; }
        }catch(...){Scierror(133,"An unexception Exception occured: %d\n", 1);return 1;} 

        // Return respective output variable to scilab env
        // ['out1','cxmatres', 'vectorres', 'doubleres', 'uvectorres', 'uwordres']
        // ['vector<vector<double>>', 'vector<vector<complex<double>>>', 'vector<double>', 'double', 'vector<uword>', 'uword']
        if(optrigger==0){
            //matrix return type
            int row = out1.size(), column = out1[0].size();
            double *output2D = (double *)malloc(sizeof(double) * row * column);
            out[0] = scilab_createDoubleMatrix2d(env, row, column, 0);
            scilab_getDoubleArray(env, out[0], &output2D);
            int tk = 0;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    output2D[tk++] = (double)out1[i][j];
        }else if(optrigger==1){
            // output of this type will not be returned in this group
            // cxmatres
            int row = cxmatres.size(), column = cxmatres[0].size();
            double *m = (double *)malloc(sizeof(double) * row * column);
            double *n = (double *)malloc(sizeof(double) * row * column);
            out[0] = scilab_createDoubleMatrix2d(env,row,column, 1);
            scilab_getDoubleComplexArray(env, out[0], &m,&n);
            for (int i = 0; i < row; i++){
                for (int j = 0; j < column; j++){ 
                    m[i + cxmatres.size() * j] = cxmatres[i][j].real();
                    n[i + cxmatres.size() * j] = cxmatres[i][j].imag();
                }
            }
        }else if(optrigger==2){
            int outputlength = vectorres.size();
            double *outputArray = (double *)malloc(sizeof(double) * outputlength);
            //assiging output variable
            out[0] = scilab_createDoubleMatrix2d(env, 1, outputlength, 0);
            scilab_getDoubleArray(env, out[0], &outputArray);
            //returning values to scilab as array
            for(int i = 0; i<outputlength; i++)
                outputArray[i] = vectorres[i];
        }else if(optrigger==3){
            out[0] = scilab_createDouble(env, doubleres);
        }else if(optrigger==4){
            int outputlength = uvectorres.size();
            double *outputArray = (double *)malloc(sizeof(double) * outputlength);
            //assiging output variable
            out[0] = scilab_createDoubleMatrix2d(env, 1, outputlength, 0);
            scilab_getDoubleArray(env, out[0], &outputArray);
            //returning values to scilab as array
            for(int i = 0; i<outputlength; i++)
                outputArray[i] = (double)vectorres[i];
        }else if(optrigger==5){
            out[0] = scilab_createDouble(env, (double)uwordres);
        }else if(optrigger==6){
            //matrix return type
            int row = uout1.size(), column = uout1[0].size();
            double *output2D = (double *)malloc(sizeof(double) * row * column);
            out[0] = scilab_createDoubleMatrix2d(env, row, column, 0);
            scilab_getDoubleArray(env, out[0], &output2D);
            int tk = 0;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    output2D[tk++] = (double)uout1[i][j];
        }else{
            Scierror(77, _("%s: Output variable mismatch.\n"), fname);
            return 1;
        }
        return 0;
    }
}

// As of now 52 functions
// complex matrix input have to be implement ("trans","stranse") // else if
// to be done input->complex matrix and output uword array