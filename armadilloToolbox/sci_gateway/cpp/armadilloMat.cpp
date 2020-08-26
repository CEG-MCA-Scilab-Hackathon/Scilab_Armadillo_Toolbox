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


    static const char fname[] = "armaMat"; //Function name for scilab interface

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

    void throwinputerror()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatch(string str)
    {
        Scierror(77, _("%s: Function doesn't available .\n"), fname);
    }


    int armadilloMat(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
    {
        int row = 0;
        int column = 0;
        int size = 0;
        double *inputArray = NULL;
        wchar_t* in2 = 0;
        SciErr sciErr;
        // Check input argument count
        if(nin<1)
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
        if(scilab_isMatrix2d(env, in[1])!=1){
            Scierror(77, _("%s: Wrong type for input argument #%d: A 2d matrix is expected.\n"), fname, 1);
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

        // Copy input array
        //get size and data from Scilab memory
		// sciErr = getMatrixOfDouble(env, in[1], &row, &column, &inputArray);
        scilab_getDoubleArray(env, in[1], &inputArray);

        vector<vector<double>> inputMat(row, vector<double>(column));
        int k = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                inputMat[i][j] = (double)inputArray[k++];

        // output variable
        
        scilab_getString(env, in[0], &in2);
        
        //conversion wchar to string type
        wstring ws(in2);
        string str(ws.begin(), ws.end());
        
        // switch to respected function call
        vector<vector<double>> out1;
        
        if(str.compare("exp")==0){ out1 = expArma(inputMat); }
        else if(str.compare("exp2")==0){ out1 = exp2Arma(inputMat); }
        else if(str.compare("exp10")==0){ out1 = exp10Arma(inputMat); }
        else if(str.compare("truncExp")==0){ out1 = truncExpArma(inputMat); }
        else if(str.compare("expm1")==0){ out1 = expm1Arma(inputMat); }
        else if(str.compare("log")==0){ out1 = logArma(inputMat); }
        else if(str.compare("log2")==0){ out1 = log2Arma(inputMat); }
        else if(str.compare("log10")==0){ out1 = log10Arma(inputMat); }
        else if(str.compare("truncLog")==0){ out1 = truncLogArma(inputMat); }
        else if(str.compare("log1p")==0){ out1 = log1pArma(inputMat); }
        else if(str.compare("pow")==0){
            if(nin!=3){
            Scierror(77, _("%s: Wrong number of input argument(s): 3 expected.\n"), fname);
            return 1;
            }
            int pow;
            scilab_getInteger32(env,in[2],&pow);
            out1 = powArma(inputMat,pow);
        }
        else if(str.compare("square")==0){ out1 = squareArma(inputMat); }
        else if(str.compare("sqrt")==0){ out1 = sqrtArma(inputMat); }
        else if(str.compare("floor")==0){ out1 = floorArma(inputMat); }
        else if(str.compare("ceil")==0){ out1 = ceilArma(inputMat); }
        else if(str.compare("round")==0){ out1 = roundArma(inputMat); }
        else if(str.compare("trunc")==0){ out1 = truncArma(inputMat); }
        else if(str.compare("erf")==0){ out1 = erfArma(inputMat); }
        else if(str.compare("erfc")==0){ out1 = erfcArma(inputMat); }
        else if(str.compare("lgamma")==0){ out1 = lgammaArma(inputMat); }
        else if(str.compare("sign")==0){ out1 = signArma(inputMat); }
        else{ throwMismatch(str);return 1; }

        row = out1.size(); column = out1[0].size();

        double *output2D = (double *)malloc(sizeof(double) * row * column);

        out[0] = scilab_createDoubleMatrix2d(env, row, column, 0);        

        scilab_getDoubleArray(env, out[0], &output2D);
        int tk = 0;
        for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				output2D[tk++] = out1[i][j];
        
        return 0;
    }
}
