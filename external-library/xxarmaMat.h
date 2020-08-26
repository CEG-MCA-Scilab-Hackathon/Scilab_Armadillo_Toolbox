// Armadillo matrix functions header file

#include <bits/stdc++.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

// Function for random matrix generation
vector<vector<double>> randMat01(double row, double col);

// Function for accumulating array values
double accumulate(vector<vector<double>> inputMat);

// Function to return cummulative sum of given array, either row-wise or column-wise
vector<vector<double>> cummulativeSum(vector<vector<double>> inputMat, int dimension);

// Funtion to return the determinant of a square sized matrix
double determinant(vector<vector<double>> inputMat);

// Function to return shuffled array - 0 for column shuffle and 1 for row shuffle
vector<vector<double>> shuffleRowOrColumn(vector<vector<double>> inputMat, int dimension);

//Function to return cholesky decomposition of Symetric Matrix
vector<vector<double>> cholesky(vector<vector<double>> inputMat);

//Function to return Eigen Value of  Symetric Matrix
vector<double> sym_eigen(vector<vector<double>> inputMat);

//Function to return Eigen Value of Non Symetric Matrix
vector<complex<double>> gen_eigen(vector<vector<double>> inputMat);

//Function to return Hessenberg decomposition of Square Matrix
vector<vector<double>> hesse(vector<vector<double>> inputMat);

//..Function to return mean of the input vector
double meanVector(vector<double> inputVector);

//..Function to return median of the input vector
double medianVector(vector<double> inputVector);

//..Function to return variance of the input vector
double varianceVector(vector<double> inputVector);

//..Function to return standard deviation of the input vector
double stddevVector(vector<double> inputVector);

//..Function to return range of the input vector
double rangeVector(vector<double> inputVector);

//..Function to return clustering centroids using kmeans of input vector matrix
vector<vector<double>> kmeans(vector<vector<double>> inputData, int centroids, int iterations);

//..Function to return matrix for solving sparse system of linear equations
vector<vector<double>> spsolve(vector<vector<double>> inputDataA, vector<vector<double>> inputDataB);

//..Function to return array for solving singular value decomposition
vector<double> svd(vector<vector<double>> inputData);

//..Function to return matrix - principal component analysis
vector<vector<double>> princomp(vector<vector<double>> inputData);

//..Function to return vector array - probability density function
vector<double> log_normpdf(vector<double> inputData);

//..Function to return vector array - cumulative distribution function
vector<double> normcdf(vector<double> inputData);