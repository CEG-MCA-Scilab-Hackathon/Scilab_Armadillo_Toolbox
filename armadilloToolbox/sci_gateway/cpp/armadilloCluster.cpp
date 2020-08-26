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


    static const char fname[] = "armaClust"; //Function name for scilab interface

    void throwinputerrorc()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchc(string str)
    {
        Scierror(77, _("%s: Function doesn't available .\n"), fname);
    }


    int armadilloCluster(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
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

        // Result variables
        vector<double> vectorres;//0
        vector<vector<double>> out1;//1

        if(str.compare("normcdf")==0 || str.compare("lognormpdf")==0){ 
            scilab_getDoubleArray(env, in[1], &inputArray);
            size = scilab_getDim2d(env, in[1], &row, &column);
            vector<double> inpvec1(inputArray, inputArray+column);
            if(str.compare("normcdf")==0){
                vectorres = armaNormcdf(inpvec1);
            }else{
                vectorres = armalogNormpdf(inpvec1);
            }
            optrigger = 0;
        }
        else if(str.compare("cor")==0 || str.compare("cov")==0){ 
            scilab_getDoubleArray(env, in[1], &inputArray);
            size1 = scilab_getDim2d(env, in[1], &row1, &column1);
            if(row1<=0 || column1<=0){throwinputerrorc();return 1;}
            vector<vector<double>> inputMat1(row1, vector<double>(column1));
            int k = 0;
            for (int i = 0; i < row1; i++)
                for (int j = 0; j < column1; j++)
                    inputMat1[i][j] = (double)inputArray[k++];
            scilab_getDoubleArray(env, in[2], &inputArray2);
            size2 = scilab_getDim2d(env, in[2], &row2, &column2);
            if(row2<=0 || column2<=0){throwinputerrorc();return 1;}
            vector<vector<double>> inputMat2(row2, vector<double>(column2));
            k = 0;
            for (int i = 0; i < row2; i++)
                for (int j = 0; j < column2; j++)
                    inputMat2[i][j] = (double)inputArray[k++];
            if(row1!=row2 || column1!=column2){throwinputerrorc();return 1;}
            if(str.compare("cor")==0){
                out1 = armaCor(inputMat1, inputMat2);
            }else{
                out1 = armaCov(inputMat1, inputMat2);
            }
            optrigger = 1;
        }
        else if(str.compare("princomp")==0){
            scilab_getDoubleArray(env, in[1], &inputArray);
            size1 = scilab_getDim2d(env, in[1], &row1, &column1);
            vector<vector<double>> inputMat1(row1, vector<double>(column1));
            int k = 0;
            for (int i = 0; i < row1; i++)
                for (int j = 0; j < column1; j++)
                    inputMat1[i][j] = (double)inputArray[k++];
            out1 = armaPrincomp(inputMat1);
            optrigger = 1;
        }
        else{ throwMismatchc(str);return 1; }


        if(optrigger==1){
            int rowx = out1.size(), columnx = out1[0].size();
            double *output2D = (double *)malloc(sizeof(double) * rowx * columnx);
            out[0] = scilab_createDoubleMatrix2d(env, rowx, columnx, 0);
            scilab_getDoubleArray(env, out[0], &output2D);
            int tk = 0;
            for (int i = 0; i < rowx; i++)
                for (int j = 0; j < columnx; j++)
                    output2D[tk++] = (double)out1[i][j];
        }else if(optrigger==0){
            int outputlength = vectorres.size();
            double *outputArray = (double *)malloc(sizeof(double) * outputlength);
            out[0] = scilab_createDoubleMatrix2d(env, 1, outputlength, 0);
            scilab_getDoubleArray(env, out[0], &outputArray);
            for(int i = 0; i<outputlength; i++)
                outputArray[i] = vectorres[i];
        }else{ throwMismatchc(str);return 1; }
        return 0;
    }
}
