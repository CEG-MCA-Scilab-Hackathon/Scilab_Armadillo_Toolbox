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


    static const char fname[] = "armaVec"; //Function name for scilab interface

    // bool isNoofInputError(int nin,int cond)
    // {
    //     if(nin<1 || nin>cond)
    //     {
    //         Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, cond);
    //         return true;
    //     }
    //     return false;
    // }
    // bool is2dMatrix(int res)
    // {
    //     if(res!=1){
    //         Scierror(77, _("%s: Wrong type for input argument #%d: A 2d matrix is expected.\n"), fname, 1);
    //         return true;
    //     }
    //     return false;
    // }
    // bool isrowcolumnInvalid(int row, int col){
    //     if (row == 0 || col == 0)
    //     {
    //         Scierror(77, _("%s: Size(s) row or column size cannot be less than 1: %d or more expected.\n"), fname, 1);
    //         return true;
    //     }
    //     return false;
    // }

    void throwinputerrorvec()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchvec(string str)
    {
        Scierror(77, _("%s: %s Function doesn't available .\n"), fname, str);
    }


    int armadilloVecFunc(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
    {
        int row = 0, row1 = 0, row2=0;
        int column = 0, column1=0, column2=0;
        int size = 0, size1=0, size2=0;
        double *inputArray = NULL;
        double *inputArray2 = NULL;
        double *inputArrayMat = NULL;
        double *k = (double *)malloc(sizeof(double)*1);
        double *q = (double *)malloc(sizeof(double)*1);
        double *option = (double *)malloc(sizeof(double)*1);
        double *n = (double *)malloc(sizeof(double)*1);
        double *p = (double *)malloc(sizeof(double)*1);
        wchar_t* in2 = 0;
        SciErr sciErr;
        int optrigger = 0;

        // Check input argument count
        if(nin<2)
        {
            Scierror(77, _("%s: Wrong number of input argument(s): 2 expected.\n"), fname);
            return 1;
        }

        // if (scilab_isString(env, in[0]) == 0)
        // {
        //     Scierror(77, _("%s: Wrong type for input argument: A String expected.\n"), fname);
        //     return 1;
        // }

        // Check argument type
        // if (is2dMatrix(scilab_isMatrix2d(env, in[1])))return 1;
        if(scilab_isMatrix2d(env, in[1]) != 1 || scilab_isDouble(env, in[1]) == 0)
        {
            Scierror(999, _("%s: Wrong type for input argument #%d:  A double vector expected.\n"), fname, 1);
            return 1;
        }

        // Get array dimensions
        size = scilab_getDim2d(env, in[1], &row, &column);

        // if (isrowcolumnInvalid(row, column))return 1;
        if (row == 0 || column == 0)
        {
            Scierror(77, _("%s: Size(s) row or column size cannot be less than 1: %d or more expected.\n"), fname, 1);
            return 1;
        }
        if(row > 1){    
            Scierror(77, _("%s: Input should be vector/Array of double\n"), fname);
            return 1;
        }
        
        // Copy input array
        scilab_getDoubleArray(env, in[1], &inputArray);
        vector<double> inpvec1(inputArray, inputArray+column);
        
        scilab_getString(env, in[0], &in2);        
        //conversion wchar to string type
        wstring ws(in2);
        string str(ws.begin(), ws.end());
        
        // Result variables
        vector<vector<double>> out1;
        vector<double> vectorres;
        double doubleres;
        vector<uword> uvectorres;
        uword uwordres;
        
        // switch to respected function call
        if(str.compare("asScalar")==0){ 
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                doubleres = asScalarArma( inpvec1,  inpvec12);
            }else if(nin==4){
                if(scilab_isMatrix2d(env, in[2])!=1){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 <= 0 || column1 <= 0 ){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArrayMat);
                vector<vector<double>> inputMat(row1, vector<double>(column1));
                int k = 0;
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < column; j++)
                        inputMat[i][j] = (double)inputArrayMat[k++];

                if(scilab_isMatrix2d(env, in[3]) != 1 || scilab_isDouble(env, in[3]) == 0){throwinputerrorvec();return 1;}
                size2 = scilab_getDim2d(env, in[3], &row2, &column2);
                if (row2 == 0 || column2 == 0 || row2>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                doubleres = asScalarArma( inpvec1,  inputMat, inpvec12);
            }else{throwMismatchvec(str);return 1;}
            optrigger = 3;
        }
        else if(str.compare("cross")==0){ 
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                vectorres = crossArma( inpvec1,  inpvec12); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("cummulativeSum")==0){ vectorres = cummulativeSumArma( inpvec1); optrigger = 2; }
        else if(str.compare("cummulativeProduct")==0){ vectorres = cummulativeProductArma( inpvec1); optrigger = 2; }
        else if(str.compare("diagmat")==0){ 
            if(nin==2){
                out1 = diagmatArma( inpvec1); 
            }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], k);
                out1 = diagmatArma( inpvec1,  (int)*k); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("diff")==0){ 
            if(nin==2){
                vectorres = diffArma( inpvec1); 
            }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], k);
                vectorres = diffArma( inpvec1,  (int)*k);  
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("dot")==0){ 
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                doubleres = dotArma( inpvec1,  inpvec12); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 3; 
        }
        else if(str.compare("cdot")==0){ 
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                doubleres = cdotArma( inpvec1,  inpvec12); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 3; 
        }
        else if(str.compare("norm_dot")==0){
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                doubleres = norm_dotArma( inpvec1,  inpvec12);
            }else{throwMismatchvec(str);return 1;}
            optrigger = 3; 
        }// till verified
        else if(str.compare("eps")==0){ vectorres = epsArma( inpvec1); optrigger = 2; }
        else if(str.compare("findUnique")==0){
            if(nin==2){ uvectorres = findUniqueArma( inpvec1); }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], k);
                int x = (int)*k;
                bool ascending_indices = x?true:false;
                uvectorres = findUniqueArma( inpvec1, ascending_indices); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 4; 
        }
        else if(str.compare("indexMin")==0){ uwordres = indexMinArma( inpvec1); optrigger = 5; }
        else if(str.compare("indexMax")==0){ uwordres = indexMaxArma( inpvec1); optrigger = 5; }
        else if(str.compare("intersect")==0){ 
            if(nin==3){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                vectorres = intersectArma( inpvec1,  inpvec12); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("min")==0){ doubleres = minArma( inpvec1); optrigger = 3; }
        else if(str.compare("max")==0){ doubleres = maxArma( inpvec1); optrigger = 3; }
        else if(str.compare("norm")==0){ 
            if(nin==2){ doubleres = normArma( inpvec1); }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], p);
                doubleres = normArma( inpvec1,  (int)*p ); 
            }
            else if(nin==4){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], p);
                if(scilab_isDouble(env, in[3]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[3], n);
                doubleres = normArma( inpvec1, (int)*p, (int)*n ); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 3; 
        }
        else if(str.compare("normalize")==0){ 
            if(nin==2){ vectorres = normalizeArma( inpvec1);  }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], p);
                vectorres = normalizeArma( inpvec1,  (int)*p); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("reverse")==0){ vectorres = reverseArma( inpvec1); optrigger = 2; }
        else if(str.compare("shift")==0){
            if(nin==3){ 
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], n);
                vectorres = shiftArma( inpvec1,  (int)*n); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("shuffle")==0){ vectorres = shuffleArma( inpvec1); optrigger = 2; }
        else if(str.compare("sort")==0){
            if(nin==2){ vectorres = sortArma( inpvec1);   }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], n);
                vectorres = sortArma( inpvec1,  (int)*n); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 2; 
        }
        else if(str.compare("sortIndex")==0){
            if(nin==2){ uvectorres = sortIndexArma( inpvec1); }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], n);
                uvectorres = sortIndexArma( inpvec1,  (int)*n); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 4; 
        }
        else if(str.compare("stableSortIndex")==0){
            if(nin==2){ uvectorres = stableSortIndexArma( inpvec1);  }
            else if(nin==3){
                if(scilab_isDouble(env, in[2]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[2], n);
                uvectorres = stableSortIndexArma( inpvec1,  (int)*n); 
            }else{throwMismatchvec(str);return 1;}
            optrigger = 4; 
        }
        else if(str.compare("sum")==0){ doubleres = sumArma( inpvec1); optrigger = 3; }
        else if(str.compare("trapz")==0){ 
            if(nin==2){ out1 = trapzArma( inpvec1);  }
            else if(nin==3){ 
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);
                out1 = trapzArma( inpvec1, inpvec12);
            }
            else if(nin==4){
                if(scilab_isMatrix2d(env, in[2]) != 1 || scilab_isDouble(env, in[2]) == 0){throwinputerrorvec();return 1;}
                size1 = scilab_getDim2d(env, in[2], &row1, &column1);
                if (row1 == 0 || column1 == 0 || row1>1){throwinputerrorvec();return 1;}
                scilab_getDoubleArray(env, in[2], &inputArray2);
                vector<double> inpvec12(inputArray2, inputArray2+column1);

                if(scilab_isDouble(env, in[3]) == 0){throwMismatchvec(str);return 1;}
                scilab_getDouble(env, in[3], n);
                out1 = trapzArma( inpvec1,  inpvec12, (int)*n);
            }else{throwMismatchvec(str);return 1;}
            optrigger = 0; 
        }
        else if(str.compare("unique")==0){ vectorres = uniqueArma( inpvec1); optrigger = 2; }
        else{ throwMismatchvec(str);return 1; }

        // Return respective output variable to scilab env
        // ['out1','cxmatres', 'vectorres', 'doubleres', 'uvectorres', 'uwordres']
        // ['vector<vector<double>>', 'vector<vector<complex<double>>>', 'vector<double>', 'double', 'vector<uword>', 'uword']
        if(optrigger==0){
            //matrix return type
            row = out1.size(); column = out1[0].size();
            double *output2D = (double *)malloc(sizeof(double) * row * column);
            out[0] = scilab_createDoubleMatrix2d(env, row, column, 0);
            scilab_getDoubleArray(env, out[0], &output2D);
            int tk = 0;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    output2D[tk++] = out1[i][j];
        }else if(optrigger==1){
            // output of this type will not be returned in this group
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
                outputArray[i] = (double) uvectorres[i];
        }else if(optrigger==5){
            out[0] = scilab_createDouble(env, (double)uwordres);
        }else{
            Scierror(77, _("%s: Output variable mismatch.\n"), fname);
            return 1;
        }
        return 0;
    }
}

// handle with care trapz
// IDK sortindex,stablesortindex