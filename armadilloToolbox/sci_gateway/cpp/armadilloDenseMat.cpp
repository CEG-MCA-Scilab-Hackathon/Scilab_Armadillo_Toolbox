#include "armaMat.h"
#include <string.h>
extern "C"
{
#include "api_scilab.h"
#include "Scierror.h"
#include "BOOL.h"
#include <localization.h>


    static const char fname[] = "armaDenseMat"; //Function name for scilab interface

    void throwinputerrorDense()
    {
        Scierror(77, _("%s: Input Arguments are not matching .\n"), fname);
    }

    void throwMismatchDense(string str)
    {
        Scierror(77, _("%s: %s Function doesn't available .\n"), fname, str);
    }


    int armadilloDenseMat(scilabEnv env, int nin, scilabVar *in, int nopt, scilabOpt *opt, int nout, scilabVar *out)
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
        wchar_t* in1 = 0;
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
        vector<complex<double>> cxvector;
        vector<double> vectorres;
        double doubleres;

        vector<uword> uvectorres;
        uword uwordres;
	try{
        if(str.compare("chol")==0){
            try{  
            if(nin==2){ 
            out1 = cholArma(inputMat);
            }
            else if(nin==3) {
             scilab_getString(env, in[2], &in1);        
        //conversion wchar to string type
             wstring ws(in1);
             string str2(ws.begin(), ws.end());
            out1 = cholArma(inputMat,str2); 
            }else{throwMismatchDense(str);return 1;}  
            optrigger = 0;
            }catch(...){
              Scierror(133,"Matrix Cant be decomposed %d\n", 1);return 1;
            }
      
        }else if(str.compare("eig_sym")==0){
            try{  
            vectorres = eig_symArma(inputMat); 
            optrigger = 1;
            }catch(...){
              Scierror(133,"Matrix Cant be decomposed %d\n", 1);return 1;
            }
      
        }else if(str.compare("eig_gen")==0){
            try{
            if(nin==2){    
            cxvector = eig_genArma(inputMat);
            }
            else if(nin==3){
             scilab_getString(env, in[2], &in1);        
        //conversion wchar to string type
             wstring ws(in1);
             string str2(ws.begin(), ws.end());
            cxvector = eig_genArma(inputMat,str2); 
            }else{throwMismatchDense(str);return 1;}   
            optrigger = 2;
            }catch(...){
              Scierror(133,"Matrix Cant be decomposed %d\n", 1);return 1;
            }
      
        }else if(str.compare("hess")==0){
            try{  
            out1 = hessArma(inputMat); 
            optrigger = 0;
            }catch(...){
              Scierror(133,"Matrix Cant be decomposed %d\n", 1);return 1;
            }
      
        }else if(str.compare("svd")==0){
            try{  
            vectorres = svdArma(inputMat); 
            optrigger = 1;
            }catch(...){
              Scierror(133,"Matrix Cant be decomposed %d\n", 1);return 1;
            }
        }        
        else{ throwMismatchDense(str);return 1; }
        }catch(...){Scierror(133,"An unexception Exception occured: %d\n", 1);return 1;} 

        // Return respective output variable to scilab env
        // ['out1','cxmatres', 'vectorres', 'doubleres', 'uvectorres', 'uwordres']
        // ['vector<vector<double>>', 'vector<vector<complex<double>>>', 'vector<double>', 'double', 'vector<uword>', 'uword']
        try{   
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
            int outputlength = vectorres.size();
            double *outputArray = (double *)malloc(sizeof(double) * outputlength);
            //assiging output variable
            out[0] = scilab_createDoubleMatrix2d(env, 1, outputlength, 0);
            scilab_getDoubleArray(env, out[0], &outputArray);
            //returning values to scilab as array
            for(int i = 0; i<outputlength; i++)
                outputArray[i] = vectorres[i];
        }else if(optrigger==2){
	    int row = cxvector.size();
            double *m = (double *)malloc(sizeof(double) * row);
            double *n = (double *)malloc(sizeof(double) * row);
            out[0] = scilab_createDoubleMatrix2d(env,1,row, 1);
            scilab_getDoubleComplexArray(env, out[0], &m,&n);
            for (int i = 0; i < row; i++){
                    m[i] = cxvector[i].real();
                    n[i] = cxvector[i].imag();
                
            }
        }
        }catch(...){Scierror(133,"An unexception Exception occured in opt: %d\n", 1);return 1;}
        return 0;
 }
}
