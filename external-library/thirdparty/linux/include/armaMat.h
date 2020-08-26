// Armadillo matrix functions header file

#include <bits/stdc++.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;


//1 Function to return  conv2cxvec2d
vector<vector<complex<double>>> conv2cxvec2d(cx_mat X);

//2 Function to return  conv2vec
vector<double> conv2vec(vec inp);

//3 Function to return  accumulateArma
double accumulateArma(vector<vector<double>> inputMat);

//4 Function to return  absoluteArma
vector<vector<double>> absoluteArma(vector<vector<double>> inputMat);

//5 Function to return  affmultiplyArma
vector<double> affmultiplyArma(vector<vector<double>> inputMat1, vector<double> inputMat2);

//6 Function to return  argArma
vector<vector<double>> argArma(vector<vector<double>> inp);

//7 Function to return  asScalarArma
double asScalarArma(vector<double> inpvec1, vector<double> inpvec2);

//8 Function to return  asScalarArma
double asScalarArma(vector<double> inpvec1, vector<vector<double>> inpmat,vector<double> inpvec2);

//9 Function to return  clampArma
vector<vector<double>> clampArma(vector<vector<double>> inpvec, double min, double max);

//10 Function to return  condArma
double condArma(vector<vector<double>> inpvec);

//11 Function to return  conjArma
vector<vector<complex<double>>> conjArma(vector<vector<complex<double>>> inpvec);

//12 Function to return  crossArma
vector<double> crossArma(vector<double> inpvec1, vector<double> inpvec2);

//13 Function to return  cummulativeSumArma
vector<vector<double>> cummulativeSumArma(vector<vector<double>> inputMat, int dimension=0);

//14 Function to return  cummulativeSumArma
vector<double> cummulativeSumArma(vector<double> inputMat);

//15 Function to return  cummulativeProductArma
vector<vector<double>> cummulativeProductArma(vector<vector<double>> inputMat, int dimension=0);

//16 Function to return  cummulativeProductArma
vector<double> cummulativeProductArma(vector<double> inputMat);

//17 Function to return  determinantArma
double determinantArma(vector<vector<double>> inputMat);

//18 Function to return  diagmatArma
vector<vector<double>> diagmatArma(vector<double> inpvec, int k=0);

//19 Function to return  diagmatArma
vector<vector<double>> diagmatArma(vector<vector<double>> inpmat, int k=0);

//20 Function to return  diagvecArma
vector<double> diagvecArma(vector<vector<double>> inpvec, int k=0);

//21 Function to return  diffArma
vector<double> diffArma(vector<double> inpvec, int k=1);

//22 Function to return  diffArma
vector<vector<double>> diffArma(vector<vector<double>> inpmat, int k=1, int dim=0);

//23 Function to return  dotArma
double dotArma(vector<double> inpvec1, vector<double> inpvec2);

//24 Function to return  cdotArma
double cdotArma(vector<double> inpvec1, vector<double> inpvec2);

//25 Function to return  norm_dotArma
double norm_dotArma(vector<double> inpvec1, vector<double> inpvec2);

//26 Function to return  epsArma
double epsArma(double inp);

//27 Function to return  epsArma
vector<double> epsArma(vector<double> inpvec);

//28 Function to return  epsArma
vector<vector<double>> epsArma(vector<vector<double>> inpmat);

//29 Function to return  expmatArma
vector<vector<double>> expmatArma(vector<vector<double>> inpmat);

//30 Function to return  expmatSymArma
vector<vector<double>> expmatSymArma(vector<vector<double>> inpmat);

//31 Function to return  findArma
vector<uword> findArma(vector<vector<double>> inpmat, int opt, double value, int k=0, int s=0);

//32 Function to return  findFiniteArma
vector<uword> findFiniteArma(vector<vector<double>> inpmat);

//33 Function to return  findNonFiniteArma
vector<uword> findNonFiniteArma(vector<vector<double>> inpmat);

//34 Function to return  findUniqueArma
vector<uword> findUniqueArma(vector<double> inpvec, bool ascending_indices=false);

//35 Function to return  fliplrArma
vector<vector<double>> fliplrArma(vector<vector<double>> inpmat);

//36 Function to return  flipudArma
vector<vector<double>> flipudArma(vector<vector<double>> inpmat);

//37 Function to return  imagArma
vector<vector<double>> imagArma(vector<vector<complex<double>>> inpmat);

//38 Function to return  realArma
vector<vector<double>> realArma(vector<vector<complex<double>>> inpmat);

//39 Function to return  ind2subArma
vector<uword> ind2subArma(vector<vector<double>> inpmat, int index);

//40 Function to return  ind2subArma
vector<vector<uword>> ind2subArma(vector<vector<double>> inpmat, vector<uword> inpindices);

//41 Function to return  indexMinArma
uword indexMinArma(vector<double> inpvec);

//42 Function to return  indexMinArma
vector<uword> indexMinArma(vector<vector<double>> inpmat, int dim=0);

//43 Function to return  indexMaxArma
uword indexMaxArma(vector<double> inpvec);

//44 Function to return  indexMaxArma
vector<uword> indexMaxArma(vector<vector<double>> inpmat, int dim=0);

//45 Function to return  inplaceTransArma
vector<vector<double>> inplaceTransArma(vector<vector<double>> inpmat, bool lowmem=false);

//46 Function to return  inplaceStransArma
vector<vector<double>> inplaceStransArma(vector<vector<double>> inpmat, bool lowmem=false);

//47 Function to return  intersectArma
vector<double> intersectArma(vector<double> inp1, vector<double> inp2);

//48 Function to return  joinRowsArma
vector<vector<double>> joinRowsArma(vector<vector<double>> inp1, vector<vector<double>> inp2);

//49 Function to return  joinColsArma
vector<vector<double>> joinColsArma(vector<vector<double>> inp1, vector<vector<double>> inp2);

//50 Function to return  joinHorizArma
vector<vector<double>> joinHorizArma(vector<vector<double>> inp1, vector<vector<double>> inp2);

//51 Function to return  joinVertArma
vector<vector<double>> joinVertArma(vector<vector<double>> inp1, vector<vector<double>> inp2);

//52 Function to return  kronArma
vector<vector<double>> kronArma(vector<vector<double>> inp1, vector<vector<double>> inp2);

//53 Function to return  logDetArma
vector<double> logDetArma(vector<vector<double>> inpmat);

//54 Function to return  logMatArma
vector<vector<complex<double>>> logMatArma(vector<vector<double>> inpmat);

//55 Function to return  logmatSympdArma
vector<vector<double>> logmatSympdArma(vector<vector<double>> inpmat);

//56 Function to return  minArma
double minArma(vector<double> inpvec);

//57 Function to return  minArma
vector<double> minArma(vector<vector<double>> inpmat, int dim=0);

//58 Function to return  maxArma
double maxArma(vector<double> inpvec);

//59 Function to return  maxArma
vector<double> maxArma(vector<vector<double>> inpmat, int dim=0);

//60 Function to return  nonZerosArma
vector<double> nonZerosArma(vector<vector<double>> inpmat);

//61 Function to return  normArma
double normArma(vector<double> inpvec, int q = 1, int opt = 0);

//62 Function to return  normArma
double normArma(vector<vector<double>> inpmat, int q = 1, int opt = 0);

//63 Function to return  normalizeArma
vector<double> normalizeArma(vector<double> inpvec, int p=0);

//64 Function to return  normalizeArma
vector<vector<double>> normalizeArma(vector<vector<double>> inpmat, int p=0);

//65 Function to return  prodArma
vector<double> prodArma(vector<vector<double>> inpmat, int dim=0);

//66 Function to return  powMatArma
vector<vector<double>> powMatArma(vector<vector<double>> inpmat, int n);

//67 Function to return  powMatArma
vector<vector<complex<double>>> powMatArma(vector<vector<double>> inpmat, double n);

//68 Function to return  rankArma
uword rankArma(vector<vector<double>> inpmat);

//69 Function to return  rcondArma
double rcondArma(vector<vector<double>> inpmat);

//70 Function to return  repElemArma
vector<vector<double>> repElemArma(vector<vector<double>> inpmat, int copies_per_row, int copies_per_col);

//71 Function to return  repMatArma
vector<vector<double>> repMatArma(vector<vector<double>> inpmat, int copies_per_row, int copies_per_col);

//72 Function to return  reshapeArma
vector<vector<double>> reshapeArma(vector<vector<double>> inpmat, int rows, int cols);

//73 Function to return  resizeArma
vector<vector<double>> resizeArma(vector<vector<double>> inpmat, int rows, int cols);

//74 Function to return  reverseArma
vector<double> reverseArma(vector<double> inpvec);

//75 Function to return  reverseArma
vector<vector<double>> reverseArma(vector<vector<double>> inpmat, int dim=0);

//76 Function to return  shiftArma
vector<double> shiftArma(vector<double> inpvec, int n);

//77 Function to return  shiftArma
vector<vector<double>> shiftArma(vector<vector<double>> inpmat,int n, int dim=0);

//78 Function to return  shuffleArma
vector<double> shuffleArma(vector<double> inpvec);

//79 Function to return  shuffleRowOrColumnArma
vector<vector<double>> shuffleRowOrColumnArma(vector<vector<double>> inputMat, int dimension=0);

//80 Function to return  sortArma
vector<double> sortArma(vector<double> inpvec, int n=0);

//81 Function to return  sortArma
vector<vector<double>> sortArma(vector<vector<double>> inpmat,int n=0, int dim=0);

//82 Function to return  sortIndexArma
vector<uword> sortIndexArma(vector<double> inpvec, int n=0);

//83 Function to return  stableSortIndexArma
vector<uword> stableSortIndexArma(vector<double> inpvec, int n=0);

//84 Function to return  sqrtMatArma
vector<vector<complex<double>>> sqrtMatArma(vector<vector<double>> inpmat);

//85 Function to return  sqrtmatSympdArma
vector<vector<double>> sqrtmatSympdArma(vector<vector<double>> inpmat);

//86 Function to return  sumArma
double sumArma(vector<double> inpvec);

//87 Function to return  sumArma
vector<double> sumArma(vector<vector<double>> inputMat, int dim=0);

//88 Function to return  sub2ind
uword sub2ind(vector<vector<double>> inputMat, int row, int col);

//89 Function to return  symmatuArma
vector<vector<double>> symmatuArma(vector<vector<double>> inpmat, bool do_conj=true);

//90 Function to return  symmatlArma
vector<vector<double>> symmatlArma(vector<vector<double>> inpmat, bool do_conj=true);

//91 Function to return  traceArma
double traceArma(vector<vector<double>> inpmat);

//92 Function to return  transArma
vector<vector<double>> transArma(vector<vector<double>> inputMat);

//93 Function to return  transArma
vector<vector<complex<double>>> transArma(vector<vector<complex<double>>> inputMat);

//94 Function to return  stransArma
vector<vector<double>> stransArma(vector<vector<double>> inputMat);

//95 Function to return  trapzArma
vector<vector<double>> trapzArma(vector<double> x, vector<double> y, int dim=0);

//96 Function to return  trapzArma
vector<vector<double>> trapzArma(vector<double> x, int dim=0);

//97 Function to return  trimatuArma
vector<vector<double>> trimatuArma(vector<vector<double>> inpmat, int k=0);

//98 Function to return  trimatlArma
vector<vector<double>> trimatlArma(vector<vector<double>> inpmat, int k=0);

//99 Function to return  trimatuIndArma
vector<uword> trimatuIndArma(vector<vector<double>> inpmat, int k=0);

//100 Function to return  trimatlIndArma
vector<uword> trimatlIndArma(vector<vector<double>> inpmat, int k=0);

//101 Function to return  uniqueArma
vector<double> uniqueArma(vector<double> inpvec);

//102 Function to return  uniqueArma
vector<double> uniqueArma(vector<vector<double>> inpmat);

//103 Function to return  vectoriseArma
vector<double> vectoriseArma(vector<vector<double>> inpmat, int dim=0);

//104 Function to return  expArma
vector<vector<double>> expArma(vector<vector<double>> inpmat);

//105 Function to return  exp2Arma
vector<vector<double>> exp2Arma(vector<vector<double>> inpmat);

//106 Function to return  exp10Arma
vector<vector<double>> exp10Arma(vector<vector<double>> inpmat);

//107 Function to return  truncExpArma
vector<vector<double>> truncExpArma(vector<vector<double>> inpmat);

//108 Function to return  expm1Arma
vector<vector<double>> expm1Arma(vector<vector<double>> inpmat);

//109 Function to return  logArma
vector<vector<double>> logArma(vector<vector<double>> inpmat);

//110 Function to return  log2Arma
vector<vector<double>> log2Arma(vector<vector<double>> inpmat);

//111 Function to return  log10Arma
vector<vector<double>> log10Arma(vector<vector<double>> inpmat);

//112 Function to return  truncLogArma
vector<vector<double>> truncLogArma(vector<vector<double>> inpmat);

//113 Function to return  log1pArma
vector<vector<double>> log1pArma(vector<vector<double>> inpmat);

//114 Function to return  powArma
vector<vector<double>> powArma(vector<vector<double>> inpmat, int n);

//115 Function to return  squareArma
vector<vector<double>> squareArma(vector<vector<double>> inpmat);

//116 Function to return  sqrtArma
vector<vector<double>> sqrtArma(vector<vector<double>> inpmat);

//117 Function to return  floorArma
vector<vector<double>> floorArma(vector<vector<double>> inpmat);

//118 Function to return  ceilArma
vector<vector<double>> ceilArma(vector<vector<double>> inpmat);

//119 Function to return  roundArma
vector<vector<double>> roundArma(vector<vector<double>> inpmat);

//120 Function to return  truncArma
vector<vector<double>> truncArma(vector<vector<double>> inpmat);

//121 Function to return  erfArma
vector<vector<double>> erfArma(vector<vector<double>> inpmat);

//122 Function to return  erfcArma
vector<vector<double>> erfcArma(vector<vector<double>> inpmat);

//123 Function to return  lgammaArma
vector<vector<double>> lgammaArma(vector<vector<double>> inpmat);

//124 Function to return  signArma
vector<vector<double>> signArma(vector<vector<double>> inpmat);


// statistics
double armaMean(vector<double> inputVector);
vector<double> armaMean(vector<vector<double>> inputVector, int dim=0);

double armaMedian(vector<double> inputVector);
vector<double> armaMedian(vector<vector<double>> inputVector, int dim=0);

double armaVariance(vector<double> inputVector);
vector<double> armaVariance(vector<vector<double>> inputVector, int dim=0);

double armaStddev(vector<double> inputVector);
vector<double> armaStddev(vector<vector<double>> inputVector, int dim=0);

double armaRange(vector<double> inputVector);
vector<double> armaRange(vector<vector<double>> inputVector, int dim=0);

// clustering

vector<vector<double>> armaPrincomp(vector<vector<double>> inputData);

vector<double> armalogNormpdf(vector<double> inputData);

vector<double> armaNormcdf(vector<double> inputData);

vector<vector<double>> armaCor(vector<vector<double>> inputData1, vector<vector<double>> inputData2, int ntype=0);

vector<vector<double>> armaCov(vector<vector<double>> inputData1, vector<vector<double>> inputData2, int ntype=0);

// signal and Image Processing

vector<double> armaconv1d(vector<double> inputVector1, vector<double> inputVector2, int shape=0);

vector<vector<double>> armaconv2d(vector<vector<double>> inputVector1, vector<vector<double>> inputVector2, int shape=0);


// pk code

vector<vector<double>> cholArma(vector<vector<double>> inputMat);

vector<vector<double>> cholArma(vector<vector<double>> inputMat,string gx);

vector<double> eig_symArma(vector<vector<double>> inputMat);

vector<complex<double>> eig_genArma(vector<vector<double>> inputMat);

vector<complex<double>> eig_genArma(vector<vector<double>> inputMat,string gx);

vector<complex<double>> eig_pairArma(vector<vector<double>> inputMat1, vector<vector<double>> inputMat2);

vector<vector<double>> hessArma(vector<vector<double>> inputMat);

vector<double> svdArma(vector<vector<double>> inputMat);