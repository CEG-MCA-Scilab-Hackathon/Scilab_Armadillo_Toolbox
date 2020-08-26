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


    static const char fname[] = "armaStat"; //Function name for scilab interface

    void throwinputerrors()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchs(string str)
    {
        Scierror(77, _("%s: Function doesn't available .\n"), fname);
    }


    int armadilloStatistics(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
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
        int inptype = 0;

        // Check input argument count
        if(nin<2)
        {
            Scierror(77, _("%s: Wrong number of input argument(s): 2 expected.\n"), fname);
            return 1;
        }

        scilab_getString(env, in[0], &in2);
        
        //conversion wchar to string type
        wstring ws(in2);
        string str(ws.begin(), ws.end());

        // Get array dimensions
        size = scilab_getDim2d(env, in[1], &row, &column);
        if(row<=0){ throwMismatchs(str);return 1; }
        // Result variables
        vector<double> vectorres;
        double doubleres;

        if(column>0) //then it is matrix
        {
            scilab_getDoubleArray(env, in[1], &inputArray);
            vector<vector<double>> inputMat(row, vector<double>(column));
            int k = 0;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    inputMat[i][j] = (double)inputArray[k++];
            if(str.compare("mean")==0){ vectorres = armaMean(inputMat); }
            else if(str.compare("median")==0){ vectorres = armaMedian(inputMat); }
            else if(str.compare("variance")==0){ vectorres = armaVariance(inputMat); }
            else if(str.compare("stddev")==0){ vectorres = armaStddev(inputMat); }
            else if(str.compare("range")==0){ vectorres = armaRange(inputMat); }
            else{ throwMismatchs(str);return 1; }
            optrigger = 1;
        } // else it is vector
        else if(column<=0){
            scilab_getDoubleArray(env, in[1], &inputArray);
            vector<double> inpvec1(inputArray, inputArray+column);
            if(str.compare("mean")==0){ doubleres = armaMean(inpvec1); }
            else if(str.compare("median")==0){ doubleres = armaMedian(inpvec1); }
            else if(str.compare("variance")==0){ doubleres = armaVariance(inpvec1); }
            else if(str.compare("stddev")==0){ doubleres = armaStddev(inpvec1); }
            else if(str.compare("range")==0){ doubleres = armaRange(inpvec1); }
            else{ throwMismatchs(str);return 1; }
            optrigger = 2;
        }else{ throwMismatchs(str);return 1; }

        if(optrigger==2){
            out[0] = scilab_createDouble(env, doubleres);
        }else if(optrigger==1){
            int outputlength = vectorres.size();
            double *outputArray = (double *)malloc(sizeof(double) * outputlength);
            out[0] = scilab_createDoubleMatrix2d(env, 1, outputlength, 0);
            scilab_getDoubleArray(env, out[0], &outputArray);
            for(int i = 0; i<outputlength; i++)
                outputArray[i] = vectorres[i];
        }else{ throwMismatchs(str);return 1; }

        return 0;
    }
}
