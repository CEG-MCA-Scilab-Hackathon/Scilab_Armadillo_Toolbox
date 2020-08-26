#include "armaMat.h"

void printer(vector<vector<double>> pvec)
{
    for (const auto& v : pvec)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout<<endl;
    }
}

void printer(vector<double> pvec)
{
    for(auto i : pvec)
        cout<< i << " ";
    cout<<endl;
}

mat conv2mat(vector<vector<double>> inpvecmat)
{
    int row = inpvecmat.size(), col = inpvecmat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inpvecmat[i][j];
    return armadilloMat;
}

cx_mat conv2cxmat(vector<vector<complex<double>>> inpvecmat)
{
    int row = inpvecmat.size(), col = inpvecmat[0].size();
	cx_mat armadilloMat(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inpvecmat[i][j];
    return armadilloMat;
}

mat conv2matcol(vector<double> inpvecmat)
{
    int row = inpvecmat.size(), col = 1;

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inpvecmat[i];
    return armadilloMat;
}

vector<vector<double>> conv2vec2d(mat X)
{
    int outputrows = X.n_rows;
	vector<vector<double>> resultVector(outputrows);
	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<double>>::from(X.row(i));
	return resultVector;
}

vector<vector<uword>> conv2vec2dumat(umat X)
{
    int outputrows = X.n_rows;
	vector<vector<uword>> resultVector(outputrows);
	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<uword>>::from(X.row(i));
	return resultVector;
}

vector<vector<complex<double>>> conv2cxvec2d(cx_mat X)
{
    int outputrows = X.n_rows;
	vector<vector<complex<double>>> resultVector(outputrows);
	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<complex<double>>>::from(X.row(i));
	return resultVector;
}

vector<double> conv2vec(vec inp){
    return conv_to<vector<double>>::from(inp);
}

vec conv2vec(vector<double> inp){
    vec X(inp);return X;
}

////1
double accumulateArma(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	// Returning the accumulated value using armadillo "accu" function
	return accu(armadilloMat);
}

////2
vector<vector<double>> absoluteArma(vector<vector<double>> inputMat)
{
	mat armadilloMat = conv2mat(inputMat);
	// Returning the abs value using armadillo "abs" function
	mat X = abs(armadilloMat);
    return conv2vec2d(X);
}

////3
vector<double> affmultiplyArma(vector<vector<double>> inputMat1, vector<double> inputMat2)
{
    mat armadilloMat = conv2mat(inputMat1);
    mat armadilloMat2 = conv2matcol(inputMat2);
    // Returning armadillo "affmul" function
	vec X = affmul(armadilloMat, armadilloMat2);
    return conv_to<vector<double>>::from(X);
}

////4
////opt for lt gt eq --- val for comparison
bool allArma(vector<double> inp, int opt, double val)
{
    vec inpvec(inp);
    if(opt==0)
        return all(inpvec);
    else if(opt==1)
        return all(inpvec < val);
    else if(opt==2)
        return all(inpvec > val);
    return all(inpvec);
}
bool allArma(vector<vector<double>> inp, int opt, double val)
{
    mat inpmat = conv2mat(inp);
    if(opt==0)
        return all(vectorise(inpmat));
    else if(opt==1)
        return all(vectorise(inpmat) < val);
    else if(opt==2)
        return all(vectorise(inpmat) > val);
    return all(vectorise(inpmat));
}

////5 
////opt for lt gt eq --- val for comparison
bool anyArma(vector<double> inp, int opt, double val)
{
    vec inpvec(inp);
    if(opt==0)
        return any(inpvec);
    else if(opt==1)
        return any(inpvec < val);
    else if(opt==2)
        return any(inpvec > val);
    return any(inpvec);
}
bool anyArma(vector<vector<double>> inp, int opt, double val)
{
    mat inpmat = conv2mat(inp);
    if(opt==0)
        return any(vectorise(inpmat));
    else if(opt==1)
        return any(vectorise(inpmat) < val);
    else if(opt==2)
        return any(vectorise(inpmat) > val);
    return any(vectorise(inpmat));
}

////6
////opt for method rel or abs and total value for comparison
bool approxEqualArma(vector<vector<double>> inp1,vector<vector<double>> inp2, int opt, double total)
{
    mat armadilloMat1 = conv2mat(inp1);
    mat armadilloMat2 = conv2mat(inp2);
    if(opt==1)
        return approx_equal(armadilloMat1, armadilloMat2, "absdiff", total);
    else
        return approx_equal(armadilloMat1, armadilloMat2, "reldiff", total);
}
bool approxEqualArma(vector<vector<double>> inp1,vector<vector<double>> inp2, double absTotal, double relTotal)
{
    mat armadilloMat1 = conv2mat(inp1);
    mat armadilloMat2 = conv2mat(inp2);
    return approx_equal(armadilloMat1, armadilloMat2, "both", absTotal, relTotal);
}

////7
vector<vector<double>> argArma(vector<vector<double>> inp)
{
    mat armadilloMat = conv2mat(inp);
    mat res = arg(armadilloMat);
    return conv2vec2d(res);
}

////8
double asScalarArma(vector<double> inpvec1, vector<double> inpvec2)
{
    rowvec r(inpvec1);
    colvec q(inpvec2);
    return as_scalar(r*q);
}
double asScalarArma(vector<double> inpvec1, vector<vector<double>> inpmat,vector<double> inpvec2)
{
    rowvec r(inpvec1);
    colvec q(inpvec2);
    mat X = conv2mat(inpmat);
    return as_scalar(r*X*q);
}

////9
vector<vector<double>> clampArma(vector<vector<double>> inpvec, double min, double max){
    return conv2vec2d(clamp(conv2mat(inpvec), min, max));
}

////10
double condArma(vector<vector<double>> inpvec){
    return cond(conv2mat(inpvec));
}

////11
vector<vector<complex<double>>> conjArma(vector<vector<complex<double>>> inpvec){
    cx_mat inpmat = conv2cxmat(inpvec);
    return conv2cxvec2d(conj(inpmat));
}

////12 conv_to ignored

////13
vector<double> crossArma(vector<double> inpvec1, vector<double> inpvec2){
    return conv2vec(cross(conv2vec(inpvec1),conv2vec(inpvec2)));
}

////14
vector<vector<double>> cummulativeSumArma(vector<vector<double>> inputMat, int dimension){
	// Cummulative sum of input array by calling "cumsum"
    return conv2vec2d(cumsum(conv2mat(inputMat), dimension));
}
vector<double> cummulativeSumArma(vector<double> inputMat){
	// Cummulative sum of input array by calling "cumsum"
    return conv2vec(cumsum(conv2vec(inputMat)));
}

////15
vector<vector<double>> cummulativeProductArma(vector<vector<double>> inputMat, int dimension){
	// Cummulative sum of input array by calling "cumsum"
    return conv2vec2d(cumprod(conv2mat(inputMat), dimension));
}
vector<double> cummulativeProductArma(vector<double> inputMat){
	// Cummulative sum of input array by calling "cumsum"
    return conv2vec(cumprod(conv2vec(inputMat)));
}

////16
double determinantArma(vector<vector<double>> inputMat){
	// Return the determinant of the given square matrix
	return det(conv2mat(inputMat));
}

////17
////k is optional
vector<vector<double>> diagmatArma(vector<double> inpvec, int k)
{
    return conv2vec2d(diagmat(conv2vec(inpvec),k));
}
vector<vector<double>> diagmatArma(vector<vector<double>> inpmat, int k)
{
    return conv2vec2d(diagmat(conv2mat(inpmat),k));
}

////18
vector<double> diagvecArma(vector<vector<double>> inpvec, int k){
 return conv2vec(diagvec(conv2mat(inpvec),k));
}

////19
vector<double> diffArma(vector<double> inpvec, int k){return conv2vec(diff(conv2vec(inpvec),k));}
vector<vector<double>> diffArma(vector<vector<double>> inpmat, int k, int dim){
    return conv2vec2d(diff(conv2mat(inpmat), k, dim));
}

////20
double dotArma(vector<double> inpvec1, vector<double> inpvec2){
    return dot(conv2vec(inpvec1), conv2vec(inpvec1));
}
////21
double cdotArma(vector<double> inpvec1, vector<double> inpvec2){
    return cdot(conv2vec(inpvec1), conv2vec(inpvec1));
}
////22
double norm_dotArma(vector<double> inpvec1, vector<double> inpvec2){
    return norm_dot(conv2vec(inpvec1), conv2vec(inpvec1));
}

////23
double epsArma(double inp){return eps(inp);}
vector<double> epsArma(vector<double> inpvec){return conv2vec(eps(conv2vec(inpvec)));}
vector<vector<double>> epsArma(vector<vector<double>> inpmat){return conv2vec2d(eps(conv2mat(inpmat)));}

////24
vector<vector<double>> expmatArma(vector<vector<double>> inpmat){
    mat output;
    bool res = expmat(output, conv2mat(inpmat));
    return conv2vec2d(output);
}
////25
vector<vector<double>> expmatSymArma(vector<vector<double>> inpmat){
    mat output;
    bool res = expmat_sym(output, conv2mat(inpmat));
    return conv2vec2d(output);
}

////26
//// opt for lessthan 1,greathan 2
//// k for returning k most indices optional
//// s for specifying first = 0 , last = 1 optional
vector<uword> findArma(vector<vector<double>> inpmat, int opt, double value, int k, int s){
    mat A = conv2mat(inpmat);
    uvec res;
    if(opt==1){
        if(s==0)
            res = find(A<value, k);
        else
            res = find(A<value, k, "last");
    }
    else if(opt==2){
        if(s==0)
            res = find(A>value, k);
        else
            res = find(A>value, k, "last");
    }
    else
        res = find(A<value);
    return conv_to<vector<uword>>::from(res);
}

////27
vector<uword> findFiniteArma(vector<vector<double>> inpmat){
    uvec res = find_finite(conv2mat(inpmat));
    return conv_to<vector<uword>>::from(res);
}

////28
vector<uword> findNonFiniteArma(vector<vector<double>> inpmat){
    uvec res = find_nonfinite(conv2mat(inpmat));
    return conv_to<vector<uword>>::from(res);
}

////29
////result in ascesding order set ascending_indices to true //optional arg
vector<uword> findUniqueArma(vector<double> inpvec, bool ascending_indices){
    colvec inp(inpvec);
    uvec res = find_unique(inp, ascending_indices);
    return conv_to<vector<uword>>::from(res);
}

////30
vector<vector<double>> fliplrArma(vector<vector<double>> inpmat){
    return conv2vec2d(fliplr(conv2mat(inpmat)));
}
////31
vector<vector<double>> flipudArma(vector<vector<double>> inpmat){
    return conv2vec2d(flipud(conv2mat(inpmat)));
}
////32
vector<vector<double>> imagArma(vector<vector<complex<double>>> inpmat){
    return conv2vec2d(imag(conv2cxmat(inpmat)));
}
////33
vector<vector<double>> realArma(vector<vector<complex<double>>> inpmat){
    return conv2vec2d(real(conv2cxmat(inpmat)));
}

////34
vector<uword> ind2subArma(vector<vector<double>> inpmat, int index){
    uvec res;
    mat X = conv2mat(inpmat);
    res = ind2sub( size(X), index);
    return conv_to<vector<uword>>::from(res);
}
////35
vector<vector<uword>> ind2subArma(vector<vector<double>> inpmat, vector<uword> inpindices){
    umat res;
    mat X = conv2mat(inpmat);
    uvec indices(inpindices);
    res = ind2sub( size(X), indices);
    return conv2vec2dumat(res);
}

////36
//// matrix dim ---> returns colvec if 0, rowvec if 1 ///optional default is 0
uword indexMinArma(vector<double> inpvec){
    return index_min(conv2vec(inpvec));
}
vector<uword> indexMinArma(vector<vector<double>> inpmat, int dim){
    if(dim==0){
        urowvec res = index_min(conv2mat(inpmat));
        return conv_to<vector<uword>>::from(res);
    }else{
        uvec res = index_min(conv2mat(inpmat),1);
        return conv_to<vector<uword>>::from(res);
    }
}
////37
uword indexMaxArma(vector<double> inpvec){
    return index_max(conv2vec(inpvec));
}
vector<uword> indexMaxArma(vector<vector<double>> inpmat, int dim){
    if(dim==0){
        urowvec res = index_max(conv2mat(inpmat));
        return conv_to<vector<uword>>::from(res);
    }else{
        uvec res = index_max(conv2mat(inpmat),1);
        return conv_to<vector<uword>>::from(res);
    }
}



////38
vector<vector<double>> inplaceTransArma(vector<vector<double>> inpmat, bool lowmem){
    mat x = conv2mat(inpmat);
    if(!lowmem)
        inplace_trans(x);
    else
        inplace_trans(x,"lowmem");
    return conv2vec2d(x);
}
vector<vector<double>> inplaceStransArma(vector<vector<double>> inpmat, bool lowmem){
    mat x = conv2mat(inpmat);
    if(!lowmem)
        inplace_strans(x);
    else
        inplace_strans(x,"lowmem");
    return conv2vec2d(x);
}

////39
vector<double> intersectArma(vector<double> inp1, vector<double> inp2){
    vec r1(inp1),r2(inp2);
    vec res = intersect(r1,r2);
    return conv_to<vector<double>>::from(res);
}

////40
vector<vector<double>> joinRowsArma(vector<vector<double>> inp1, vector<vector<double>> inp2){
    return conv2vec2d(join_rows(conv2mat(inp1), conv2mat(inp2)));
}
////41
vector<vector<double>> joinColsArma(vector<vector<double>> inp1, vector<vector<double>> inp2){
    return conv2vec2d(join_cols(conv2mat(inp1), conv2mat(inp2)));
}
////42
vector<vector<double>> joinHorizArma(vector<vector<double>> inp1, vector<vector<double>> inp2){
    return conv2vec2d(join_horiz(conv2mat(inp1), conv2mat(inp2)));
}
////43
vector<vector<double>> joinVertArma(vector<vector<double>> inp1, vector<vector<double>> inp2){
    return conv2vec2d(join_vert(conv2mat(inp1), conv2mat(inp2)));
}

////44 ignored join slices

////45
vector<vector<double>> kronArma(vector<vector<double>> inp1, vector<vector<double>> inp2){
    return conv2vec2d(kron(conv2mat(inp1), conv2mat(inp2)));
}

////46
vector<double> logDetArma(vector<vector<double>> inpmat){
    vector<double> res;
    double val, sign;
    log_det(val, sign, conv2mat(inpmat));   
    res.push_back(val);res.push_back(sign);
    return res;
}
complex<double> logDetComplexArma(vector<vector<double>> inpmat)
{
    return log_det(conv2mat(inpmat));
}

////47
vector<vector<complex<double>>> logMatArma(vector<vector<double>> inpmat){
    mat A = conv2mat(inpmat);
    cx_mat B;
    bool res = logmat(B, A);
    return conv2cxvec2d(B);
}

////48
vector<vector<double>> logmatSympdArma(vector<vector<double>> inpmat){
    mat A = conv2mat(inpmat), B;
    bool res = logmat_sympd(B, A);
    return conv2vec2d(B);
}

////49
double minArma(vector<double> inpvec){
    return min(conv2vec(inpvec));
}
vector<double> minArma(vector<vector<double>> inpmat, int dim){
    if(dim==0){
        rowvec res = min(conv2mat(inpmat));
        return conv_to<vector<double>>::from(res);
    }else{
        colvec res = min(conv2mat(inpmat),1);
        return conv_to<vector<double>>::from(res);
    }
}

////50
double maxArma(vector<double> inpvec){
    return max(conv2vec(inpvec));
}
vector<double> maxArma(vector<vector<double>> inpmat, int dim){
    if(dim==0){
        rowvec res = max(conv2mat(inpmat));
        return conv_to<vector<double>>::from(res);
    }else{
        colvec res = max(conv2mat(inpmat),1);
        return conv_to<vector<double>>::from(res);
    }
}

////51
vector<double> nonZerosArma(vector<vector<double>> inpmat){
    return conv2vec(nonzeros(conv2mat(inpmat)));
}

////52
////"-inf" 0 is the minimum norm, "inf" 1 is the maximum norm, while "fro" 2 is the Frobenius norm
double normArma(vector<double> inpvec, int q, int opt){
    vec x = conv2vec(inpvec);
    if(opt>0 && opt<3){
        if(opt==1)
            return norm(x, "-inf");
        else if(opt==2)
            return norm(x, "inf");
        else
            return norm(x, "fro");
    }
    else if(q>1){
        return norm(x, q);
    }
    else{
        return norm(x);
    }

}
double normArma(vector<vector<double>> inpmat, int q, int opt){
    mat x = conv2mat(inpmat);
    if(opt>0 && opt<3){
        if(opt==1)
            return norm(x, "-inf");
        else if(opt==2)
            return norm(x, "inf");
        else
            return norm(x, "fro");
    }
    else if(q>1){
        return norm(x, q);
    }
    else{
        return norm(x);
    }
}

////53
vector<double> normalizeArma(vector<double> inpvec, int p){
    vec res;
    if(p==0){
        res = normalise(conv2vec(inpvec));
    }
    else{
        res = normalise(conv2vec(inpvec), p);
    }
    return conv2vec(res);
}
vector<vector<double>> normalizeArma(vector<vector<double>> inpmat, int p){
    mat res;
    if(p==0){
        res = normalise(conv2mat(inpmat));
    }
    else{
        res = normalise(conv2mat(inpmat), p);
    }
    return conv2vec2d(res);
}

////54
//// dim is optional
/////// function under unfinished
// vector<double> prodArma(vector<double> inpvec){
//     // colvec inp = conv2vec(inpvec);
//     vec res = prod(conv2vec(inpvec));
//     return conv_to<vector<double>>::from(res);
// }
vector<double> prodArma(vector<vector<double>> inpmat, int dim){
    if(dim==1){
        colvec res = prod(conv2mat(inpmat), dim);
        return conv_to<vector<double>>::from(res);
    }else{
        colvec res = prod(conv2mat(inpmat));
        return conv_to<vector<double>>::from(res);
    }   
}

////55
vector<vector<double>> powMatArma(vector<vector<double>> inpmat, int n){
    if(n>0)
        return conv2vec2d(powmat(conv2mat(inpmat), n));
    return conv2vec2d(powmat(conv2mat(inpmat), 0));
}
vector<vector<complex<double>>> powMatArma(vector<vector<double>> inpmat, double n){
    cx_mat B;
    if(n>0)
        powmat(B, conv2mat(inpmat), n);
    powmat(B, conv2mat(inpmat), 0);
    return conv2cxvec2d(B);
}

////56
////overload not done
uword rankArma(vector<vector<double>> inpmat){
    return arma::rank(conv2mat(inpmat));
}

////57
double rcondArma(vector<vector<double>> inpmat){
    return arma::rcond(conv2mat(inpmat));
}

////58
vector<vector<double>> repElemArma(vector<vector<double>> inpmat, int copies_per_row, int copies_per_col){
    if(copies_per_col<0)
        copies_per_col = 0;
    if(copies_per_row<0)
        copies_per_row = 0;
    mat B = repelem(conv2mat(inpmat), copies_per_row, copies_per_col);
    return conv2vec2d(B);
}

////59
vector<vector<double>> repMatArma(vector<vector<double>> inpmat, int copies_per_row, int copies_per_col){
    if(copies_per_col<1)
        copies_per_col = 1;
    if(copies_per_row<1)
        copies_per_row = 1;
    mat B = repmat(conv2mat(inpmat), copies_per_row, copies_per_col);
    return conv2vec2d(B);
}

////60
vector<vector<double>> reshapeArma(vector<vector<double>> inpmat, int rows, int cols){
    if(rows<1)
        rows = 1;
    if(cols<1)
        cols = 1;
    mat B = reshape(conv2mat(inpmat), rows, cols);
    return conv2vec2d(B);
}

////61
vector<vector<double>> resizeArma(vector<vector<double>> inpmat, int rows, int cols){
    if(rows<1)
        rows = 1;
    if(cols<1)
        cols = 1;
    mat B = resize(conv2mat(inpmat), rows, cols);
    return conv2vec2d(B);
}

////62
vector<double> reverseArma(vector<double> inpvec){
    return conv2vec(reverse(conv2vec(inpvec)));
}
vector<vector<double>> reverseArma(vector<vector<double>> inpmat, int dim){
    mat B ;
    if(dim==0)
        B = reverse(conv2mat(inpmat));
    else if(dim==1)
        B = arma::reverse(conv2mat(inpmat),1);
    else
        B = reverse(conv2mat(inpmat));
    return conv2vec2d(B);
}

////63
vector<complex<double>> rootsArma(vector<double> inpvec){
    cx_vec res = roots(conv2vec(inpvec));
    return conv_to<vector<complex<double>>>::from(res);
}

////64
vector<double> shiftArma(vector<double> inpvec, int n){
    return conv2vec(shift(conv2vec(inpvec), n));
}
vector<vector<double>> shiftArma(vector<vector<double>> inpmat,int n, int dim){
    mat B ;
    if(dim==1)
        B = arma::shift(conv2mat(inpmat), n, 1);
    else
        B = shift(conv2mat(inpmat), n);
    return conv2vec2d(B);
}

////65
// Function to return shuffled array - 1 for column shuffle and 0 for row shuffle
vector<double> shuffleArma(vector<double> inpvec){
    return conv2vec(shuffle(conv2vec(inpvec)));
}
vector<vector<double>> shuffleRowOrColumnArma(vector<vector<double>> inputMat, int dimension){
	// shuffle
	mat output = shuffle(conv2mat(inputMat), dimension);
    return conv2vec2d(output);
}

////66 size ignored

////67
////The sort_direction argument is optional; sort_direction is either "ascend" -->0 or "descend" --> 1; by default "ascend" is used
vector<double> sortArma(vector<double> inpvec, int n){
    if(n==1)
        return conv2vec(arma::sort(conv2vec(inpvec), "descend"));
    return conv2vec(arma::sort(conv2vec(inpvec)));
}
vector<vector<double>> sortArma(vector<vector<double>> inpmat,int n, int dim){
    mat B ;
    if(dim==1){
        if(n==1)
            B = arma::sort(conv2mat(inpmat), "descend", 1);
        else
            B = arma::sort(conv2mat(inpmat),"ascend", 1);
    }
    else{
        if(n==1)
            B = arma::sort(conv2mat(inpmat), "descend");
        else
            B = arma::sort(conv2mat(inpmat));
    }
    return conv2vec2d(B);
}

////68
////The sort_direction argument is optional; sort_direction is either "ascend" -0 or "descend" -1; by default "ascend" is used
vector<uword> sortIndexArma(vector<double> inpvec, int n){
    uvec res = sort_index(conv2vec(inpvec));
    return conv_to<vector<uword>>::from(res);
}

////69
////The sort_direction argument is optional; sort_direction is either "ascend" -0 or "descend" -1; by default "ascend" is used
vector<uword> stableSortIndexArma(vector<double> inpvec, int n){
    uvec res = stable_sort_index(conv2vec(inpvec));
    return conv_to<vector<uword>>::from(res);
}

////70
vector<vector<complex<double>>> sqrtMatArma(vector<vector<double>> inpmat){
    cx_mat B;
    bool result = sqrtmat(B,conv2mat(inpmat));
    return conv2cxvec2d(B);
}

////71
vector<vector<double>> sqrtmatSympdArma(vector<vector<double>> inpmat){
    mat B;
    bool result = sqrtmat_sympd(B,conv2mat(inpmat));
    return conv2vec2d(B);
}

////72
double sumArma(vector<double> inpvec){
    return arma::sum(conv2vec(inpvec));
}
vector<double> sumArma(vector<vector<double>> inputMat, int dim){
    if(dim==1){
        colvec res = sum(conv2mat(inputMat), 1);
        return conv_to<vector<double>>::from(res);
    }
    else{
        rowvec res = sum(conv2mat(inputMat));
        return conv_to<vector<double>>::from(res);
    }
}

////73
////overload not done
uword sub2ind(vector<vector<double>> inputMat, int row, int col){
    mat A = conv2mat(inputMat);
    return arma::sub2ind(size(A), row, col);
}

////74
vector<vector<double>> symmatuArma(vector<vector<double>> inpmat, bool do_conj){
    return conv2vec2d(symmatu(conv2mat(inpmat),do_conj));
}

////75
vector<vector<double>> symmatlArma(vector<vector<double>> inpmat, bool do_conj){
    return conv2vec2d(symmatl(conv2mat(inpmat),do_conj));
}

////76
double traceArma(vector<vector<double>> inpmat){
    return arma::trace(conv2mat(inpmat));
}

////77
vector<vector<double>> transArma(vector<vector<double>> inputMat){
    mat A = conv2mat(inputMat);
    return conv2vec2d(trans(A));
}
vector<vector<complex<double>>> transArma(vector<vector<complex<double>>> inputMat){
    cx_mat A = conv2cxmat(inputMat);
    return conv2cxvec2d(trans(A));
}

////78
vector<vector<double>> stransArma(vector<vector<double>> inputMat){
    mat A = conv2mat(inputMat);
    return conv2vec2d(strans(A));
}

////79
////X must be a vector; its length must equal either the number of rows in Y (when dim=0), or the number of columns in Y (when dim=1)
vector<vector<double>> trapzArma(vector<double> x, vector<double> y, int dim){
    if(dim==1)
        return conv2vec2d( arma::trapz( conv2vec(x), conv2vec(y), 1));
    return conv2vec2d( arma::trapz( conv2vec(x), conv2vec(y)));
}
vector<vector<double>> trapzArma(vector<double> x, int dim){
    if(dim==1)
        return conv2vec2d( arma::trapz( conv2vec(x), 1));
    return conv2vec2d( arma::trapz( conv2vec(x)));
}

////80
// The argument k specifies the diagonal which inclusively delineates the boundary of the triangular part
// for k > 0, the k-th super-diagonal is used (above main diagonal, towards top-right corner)
// for k < 0, the k-th sub-diagonal is used (below main diagonal, towards bottom-left corner)
// default k = 0 , inpmat must be square matrix
vector<vector<double>> trimatuArma(vector<vector<double>> inpmat, int k){
    mat x = arma::trimatu(conv2mat(inpmat),k);
    return conv2vec2d(x);
}

////81
vector<vector<double>> trimatlArma(vector<vector<double>> inpmat, int k){
    mat x = arma::trimatl(conv2mat(inpmat),k);
    return conv2vec2d(x);
}

////82
vector<uword> trimatuIndArma(vector<vector<double>> inpmat, int k){
    mat A = conv2mat(inpmat);
    uvec res = arma::trimatu_ind(size(A),k);
    return conv_to<vector<uword>>::from(res);
}

////83
vector<uword> trimatlIndArma(vector<vector<double>> inpmat, int k){
    mat A = conv2mat(inpmat);
    uvec res = arma::trimatl_ind(size(A),k);
    return conv_to<vector<uword>>::from(res);
}

////84
vector<double> uniqueArma(vector<double> inpvec){
    vec res = unique(conv2vec(inpvec));
    return conv_to<vector<double>>::from(res);
}
vector<double> uniqueArma(vector<vector<double>> inpmat){
    colvec res = unique(conv2mat(inpmat));
    return conv_to<vector<double>>::from(res);
}

////85
vector<double> vectoriseArma(vector<vector<double>> inpmat, int dim){
    if(dim==1)
        return conv2vec(arma::vectorise(conv2mat(inpmat),1));
    return conv2vec(arma::vectorise(conv2mat(inpmat)));
}


////miscellaneous element-wise functions:
//// extra functions

////86
vector<vector<double>> expArma(vector<vector<double>> inpmat){return conv2vec2d(exp(conv2mat(inpmat)));}
////87
vector<vector<double>> exp2Arma(vector<vector<double>> inpmat){return conv2vec2d(exp2(conv2mat(inpmat)));}
////88
vector<vector<double>> exp10Arma(vector<vector<double>> inpmat){return conv2vec2d(exp10(conv2mat(inpmat)));}
////89
vector<vector<double>> truncExpArma(vector<vector<double>> inpmat){return conv2vec2d(trunc_exp(conv2mat(inpmat)));}
////90
vector<vector<double>> expm1Arma(vector<vector<double>> inpmat){return conv2vec2d(expm1(conv2mat(inpmat)));}
////91
vector<vector<double>> logArma(vector<vector<double>> inpmat){return conv2vec2d(log(conv2mat(inpmat)));}
////92
vector<vector<double>> log2Arma(vector<vector<double>> inpmat){return conv2vec2d(log2(conv2mat(inpmat)));}
////93
vector<vector<double>> log10Arma(vector<vector<double>> inpmat){return conv2vec2d(log10(conv2mat(inpmat)));}
////94
vector<vector<double>> truncLogArma(vector<vector<double>> inpmat){return conv2vec2d(trunc_log(conv2mat(inpmat)));}
////95
vector<vector<double>> log1pArma(vector<vector<double>> inpmat){return conv2vec2d(log1p(conv2mat(inpmat)));}
////96
vector<vector<double>> powArma(vector<vector<double>> inpmat, int n){return conv2vec2d(pow(conv2mat(inpmat),n));}
////97
vector<vector<double>> squareArma(vector<vector<double>> inpmat){return conv2vec2d(square(conv2mat(inpmat)));}
////98
vector<vector<double>> sqrtArma(vector<vector<double>> inpmat){return conv2vec2d(sqrt(conv2mat(inpmat)));}
////99
vector<vector<double>> floorArma(vector<vector<double>> inpmat){return conv2vec2d(floor(conv2mat(inpmat)));}
////100
vector<vector<double>> ceilArma(vector<vector<double>> inpmat){return conv2vec2d(ceil(conv2mat(inpmat)));}
////101
vector<vector<double>> roundArma(vector<vector<double>> inpmat){return conv2vec2d(round(conv2mat(inpmat)));}
////102
vector<vector<double>> truncArma(vector<vector<double>> inpmat){return conv2vec2d(trunc(conv2mat(inpmat)));}
////103
vector<vector<double>> erfArma(vector<vector<double>> inpmat){return conv2vec2d(erf(conv2mat(inpmat)));}
////104
vector<vector<double>> erfcArma(vector<vector<double>> inpmat){return conv2vec2d(erfc(conv2mat(inpmat)));}
////105
vector<vector<double>> lgammaArma(vector<vector<double>> inpmat){return conv2vec2d(lgamma(conv2mat(inpmat)));}
////106
vector<vector<double>> signArma(vector<vector<double>> inpmat){return conv2vec2d(sign(conv2mat(inpmat)));}



// Statistics
//..Function to return mean of the input vector
double armaMean(vector<double> inputVector){ return mean(conv2vec(inputVector)); }
vector<double> armaMean(vector<vector<double>> inputVector, int dim){
	mat armaMat = conv2mat(inputVector); 
    if(dim!=1)dim=0;
    vec vc = dim?mean(armaMat,1):mean(armaMat);
    return conv2vec(vc);
}


//..Function to return median of the input vector
double armaMedian(vector<double> inputVector){ return median(conv2vec(inputVector)); }
vector<double> armaMedian(vector<vector<double>> inputVector, int dim){
	mat armaMat = conv2mat(inputVector); 
    if(dim!=1)dim=0;
    vec vc = dim?median(armaMat,1):median(armaMat);
    return conv2vec(vc);
}

//..Function to return variance of the input vector
double armaVariance(vector<double> inputVector){ return var(conv2vec(inputVector)); }
vector<double> armaVariance(vector<vector<double>> inputVector, int dim){
	mat armaMat = conv2mat(inputVector); 
    if(dim!=1)dim=0;
    vec vc = dim?var(armaMat):var(armaMat,0,1);
    return conv2vec(vc);
}

//..Function to return standard deviation of the input vector
double armaStddev(vector<double> inputVector){ return stddev(conv2vec(inputVector)); }
vector<double> armaStddev(vector<vector<double>> inputVector, int dim){
	mat armaMat = conv2mat(inputVector); 
    if(dim!=1)dim=0;
    vec vc = dim?stddev(armaMat):stddev(armaMat,0,1);
    return conv2vec(vc);
}

//..Function to return range of the input vector
double armaRange(vector<double> inputVector){ return range(conv2vec(inputVector)); }
vector<double> armaRange(vector<vector<double>> inputVector, int dim){
	mat armaMat = conv2mat(inputVector); 
    if(dim!=1)dim=0;
    vec vc = dim?stddev(armaMat):stddev(armaMat,1);
    return conv2vec(vc);
}

// clustering

//..Function to return matrix - principal component analysis
vector<vector<double>> armaPrincomp(vector<vector<double>> inputData){
	mat X;
	princomp(X,conv2mat(inputData));
	return conv2vec2d(X);
}

//..Function to return vector array - probability density function
vector<double> armalogNormpdf(vector<double> inputData){ return conv2vec(log_normpdf(conv2vec(inputData))); }

//..Function to return vector array - cumulative distribution function
vector<double> armaNormcdf(vector<double> inputData){ return conv2vec(normcdf(conv2vec(inputData))); }

//.. Function to return correlation, covariance
vector<vector<double>> armaCor(vector<vector<double>> inputData1, vector<vector<double>> inputData2, int ntype){
    if(ntype!=1)ntype=0;
	if(!ntype)
        return conv2vec2d( cor(conv2mat(inputData1),conv2mat(inputData2)));
    else
        return conv2vec2d( cor(conv2mat(inputData1), conv2mat(inputData2),1));
}

//.. Function to return covariance
vector<vector<double>> armaCov(vector<vector<double>> inputData1, vector<vector<double>> inputData2, int ntype){
    if(ntype!=1)ntype=0;
	if(!ntype)
        return conv2vec2d( cov(conv2mat(inputData1),conv2mat(inputData2)));
    else
        return conv2vec2d( cov(conv2mat(inputData1), conv2mat(inputData2),1));
}


// signal and Image Processing

// convolution 1d
vector<double> armaconv1d(vector<double> inputVector1, vector<double> inputVector2, int shape){
    if(shape!=1)shape=0;
    if(shape)
        return conv2vec( conv(conv2vec(inputVector1),conv2vec(inputVector2),"same"));
    else
        return conv2vec( conv(conv2vec(inputVector1),conv2vec(inputVector2)));
}
// convolution 2d
vector<vector<double>> armaconv2d(vector<vector<double>> inputVector1, vector<vector<double>> inputVector2, int shape){
    if(shape!=1)shape=0;
    if(shape)
        return conv2vec2d( conv2(conv2mat(inputVector1),conv2mat(inputVector2),"same"));
    else
        return conv2vec2d( conv2(conv2mat(inputVector1),conv2mat(inputVector2)));
}





vector<vector<double>> cholArma(vector<vector<double>> inputMat, string layout=""){
	mat armadilloMat = conv2mat(inputMat);
	mat R;
	if(layout == "lower")
		R= chol(armadilloMat, "lower");
	else if(layout == "upper")
		R= chol(armadilloMat, "upper");
	else 
		R= chol(armadilloMat);
	return conv2vec2d(R);
}
vector<vector<double>> cholArma(vector<vector<double>> inputMat){
	mat armadilloMat = conv2mat(inputMat);
	mat R;
	R=chol(armadilloMat);
	return conv2vec2d(R);
}

//2. eig_sym - eigen decomposition of dense symmetric/hermitian matrix
vector<double> eig_symArma(vector<vector<double>> inputMat){
	mat armadilloMat = conv2mat(inputMat);
	vec eigVal;
	mat eigVec;
	eig_sym(eigVal, eigVec, armadilloMat);
	return conv2vec(eigVal);
}

/*vector<double> eig_symArma(vector<vector<complex<double>>> inputMat){
	cx_mat armadilloMat =  conv2cxmat(inputMat);
	vec eigVal;
	cx_mat eigVec;
	eig_sym(eigVal, eigVec, armadilloMat);
	return conv2vec(eigVal);
}
*/

//3. eig_gen - eigen decomposition of dense general square matrix
vector<complex<double>> eig_genArma(vector<vector<double>> inputMat, string bal=""){
	mat armadilloMat = conv2mat(inputMat);
	cx_vec eigVal;
	if(bal == "balance")
		eig_gen(eigVal, armadilloMat, "balance");
	else
		eig_gen(eigVal, armadilloMat);
	return conv_to<vector<complex<double>>>::from(eigVal);
}

vector<complex<double>> eig_genArma(vector<vector<double>> inputMat){
	mat armadilloMat = conv2mat(inputMat);
	cx_vec eigVal;
		eig_gen(eigVal, armadilloMat);
	return conv_to<vector<complex<double>>>::from(eigVal);
}
//4. eig_pairArma - eigen decomposition for pair of general dense square matrices
vector<complex<double>> eig_pairArma(vector<vector<double>> inputMat1, vector<vector<double>> inputMat2){
	mat armadilloMat1 = conv2mat(inputMat1);
	mat armadilloMat2 = conv2mat(inputMat2);
	cx_vec eigVal;
	eig_pair(eigVal, armadilloMat1, armadilloMat2);
	return conv_to<vector<complex<double>>>::from(eigVal);
}

//5. hessArma - upper Hessenberg decomposition
vector<vector<double>> hessArma(vector<vector<double>> inputMat){
	mat armadilloMat = conv2mat(inputMat);
	mat U;
	mat H;
	hess(U, H, armadilloMat);
	return conv2vec2d(H);
}

//17. svd - singular value decomposition
vector<double> svdArma(vector<vector<double>> inputMat){
	mat armadilloMat = conv2mat(inputMat);
	vec s;
	svd(s, armadilloMat);
	return conv2vec(s);
}
