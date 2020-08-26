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


    static const char fname[] = "armaImage"; //Function name for scilab interface

    void throwinputerrori()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchi(string str)
    {
        Scierror(77, _("%s: Function doesn't available .\n"), fname);
    }


    int armadilloImage(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
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
        if(nin!=4)
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



        if(scilab_isDouble(env, in[3]) == 0){throwinputerrori();return 1;}
                scilab_getDouble(env, in[3], k);
        int shape = (int)*k;
        if(shape<0 || shape>1)shape=0;

        if(str.compare("conv1d")==0){ 
            size1 = scilab_getDim2d(env, in[1], &row1, &column1);
            scilab_getDoubleArray(env, in[1], &inputArray);
            vector<double> inpvec1(inputArray, inputArray+column1);

            size2 = scilab_getDim2d(env, in[2], &row2, &column2);
            scilab_getDoubleArray(env, in[2], &inputArray2);
            vector<double> inpvec2(inputArray2, inputArray2+column2);
            
            vectorres = armaconv1d(inpvec1, inpvec2, shape);
            optrigger = 0;
        }
        else if(str.compare("conv2d")==0){ 
            scilab_getDoubleArray(env, in[1], &inputArray);
            size1 = scilab_getDim2d(env, in[1], &row1, &column1);
            if(row1<=0 || column1<=0){throwinputerrori();return 1;}
            vector<vector<double>> inputMat1(row1, vector<double>(column1));
            int tik = 0;
            for (int i = 0; i < row1; i++)
                for (int j = 0; j < column1; j++)
                    inputMat1[i][j] = (double)inputArray[tik++];

            scilab_getDoubleArray(env, in[2], &inputArray2);
            size2 = scilab_getDim2d(env, in[2], &row2, &column2);
            if(row2<=0 || column2<=0){throwinputerrori();return 1;}
            vector<vector<double>> inputMat2(row2, vector<double>(column2));
            tik = 0;
            for (int i = 0; i < row2; i++)
                for (int j = 0; j < column2; j++)
                    inputMat2[i][j] = (double)inputArray[tik++];
            out1 = armaconv2d(inputMat1, inputMat2, shape);
            optrigger = 1;
        }
        else{ throwMismatchi(str);return 1; }

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
        }else{
            throwMismatchi("error");return 1;
        }
        return 0;
    }
}
