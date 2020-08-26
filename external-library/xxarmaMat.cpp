// Armadillo function call and definition source for scilab gateway
#include "armaMat.h"

// Function for random matrix generation
vector<vector<double>> randMat01(double row, double col)
{
	// Generate random matrix using "randu"
	mat armadilloRandom = randu<mat>(row, col);

	vector<vector<double>> randomMatrix(row);

	for (int i = 0; i < row; i++)
		randomMatrix[i] = conv_to<vector<double>>::from(armadilloRandom.row(i));

	return randomMatrix;
}

// Function for accumulating array values
double accumulate(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	// Returning the accumulated value using armadillo "accu" function
	return accu(armadilloMat);
}

// Function to return cummulative sum of given array, either row-wise or column-wise
vector<vector<double>> cummulativeSum(vector<vector<double>> inputMat, int dimension)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	// Cummulative sum of input array by calling "cumsum"
	mat output = cumsum(armadilloMat, dimension);

	vector<vector<double>> returnOutput(row);

	for (int i = 0; i < row; i++)
		returnOutput[i] = conv_to<vector<double>>::from(output.row(i));
	
	// Return resulting array
	return returnOutput;
}

// Funtion to return the determinant of a square sized matrix
double determinant(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	// Return the determinant of the given square matrix
	return det(armadilloMat);
}


// Function to return shuffled array - 1 for column shuffle and 0 for row shuffle
vector<vector<double>> shuffleRowOrColumn(vector<vector<double>> inputMat, int dimension)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	// Cummulative sum of input array by calling "cumsum"
	mat output = shuffle(armadilloMat, dimension);

	vector<vector<double>> returnOutput(row);

	for (int i = 0; i < row; i++)
		returnOutput[i] = conv_to<vector<double>>::from(output.row(i));
	
	// Return resulting array
	return returnOutput;
}

vector<vector<double>> cholesky(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
	 mat output = chol(armadilloMat);
        
	vector<vector<double>> returnOutput(row);

	for (int i = 0; i < row; i++)
		returnOutput[i] = conv_to<vector<double>>::from(output.row(i));
	
	return returnOutput;
}

vector<double> sym_eigen(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
        
        vec output = eig_sym(armadilloMat);
        
          
	vector<double> returnOutput(col);
         for (int i = 0; i < col; i++)
		returnOutput[i] = output[i];
	

	return returnOutput;
}

vector<complex<double>> gen_eigen(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
        cx_vec output = eig_gen(armadilloMat);
          
	vector<complex<double>> returnOutput(col);
         for (int i = 0; i < col; i++)
		returnOutput[i] = output[i];

	return returnOutput;
}

vector<vector<double>> hesse(vector<vector<double>> inputMat)
{
	int row = inputMat.size(), col = inputMat[0].size();

	mat armadilloMat(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			armadilloMat(i, j) = inputMat[i][j];
	
        mat output = hess(armadilloMat);
        
	vector<vector<double>> returnOutput(row);

	for (int i = 0; i < row; i++)
		returnOutput[i] = conv_to<vector<double>>::from(output.row(i));
	
	return returnOutput;
}


//..Function to return mean of the input vector
double meanVector(vector<double> inputVector)
{
	vec armadilloVec(inputVector);
	//Armadillo mean function for vector
	return mean(armadilloVec);
}


//..Function to return median of the input vector
double medianVector(vector<double> inputVector)
{
	vec armadilloVec(inputVector);
	//Armadillo median function for vector
	return median(armadilloVec);
}


//..Function to return variance of the input vector
double varianceVector(vector<double> inputVector)
{
	vec armadilloVec(inputVector);
	//Armadillo variance function for vector
	return var(armadilloVec);
}


//..Function to return standard deviation of the input vector
double stddevVector(vector<double> inputVector)
{
	vec armadilloVec(inputVector);
	//Armadillo standard deviation function for vector
	return stddev(armadilloVec);
}


//..Function to return range of the input vector
double rangeVector(vector<double> inputVector)
{
	vec armadilloVec(inputVector);
	//Armadillo range function for vector
	return range(armadilloVec);
}

//..Function to return clustering centroids using kmeans of input vector matrix
vector<vector<double>> kmeans(vector<vector<double>> inputData, int centroids, int iterations)
{
	//converting input vector to mat type
	int row = inputData.size(), col = inputData[0].size();

	mat data(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data(i, j) = inputData[i][j];

	mat means;
	
	//calling armadillo kmeans function 
	bool status = kmeans(means, data, centroids, random_subset, iterations, false);
	
	if(status == false)
	{
		vector<vector<double>> resultVector(1);
		vector<double> outv(1);
		outv.push_back(0.0);
		resultVector.push_back(outv);
		return resultVector;
	}

	//converting output mat to vector
	int outputrows = means.n_rows;

	vector<vector<double>> resultVector(outputrows);

	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<double>>::from(means.row(i));

	return resultVector;
}


//..Function to return matrix for solving sparse system of linear equations
vector<vector<double>> spsolve(vector<vector<double>> inputDataA, vector<vector<double>> inputDataB)
{
	// handling two input matrices
	int rowA = inputDataA.size(), colA = inputDataA[0].size();
	sp_mat dataA(rowA, colA);
	for (int i = 0; i < rowA; i++)
		for (int j = 0; j < colA; j++)
			dataA(i, j) = inputDataA[i][j];
	dataA = dataA.t();
	int rowB = inputDataB.size(), colB = inputDataB[0].size();
	mat dataB(rowB, colB);
	for (int i = 0; i < rowB; i++)
		for (int j = 0; j < colB; j++)
			dataB(i, j) = inputDataB[i][j];
	//check two matrices has same rows
	if(rowA!=rowB)
	{
		vector<vector<double>> resultVector(1);
		vector<double> outv(1);
		outv.push_back(0.0);
		resultVector.push_back(outv);
		return resultVector;
	}

	mat X;
	//armadillo function call sparse system linear equation solver
	spsolve(X, dataA, dataB, "lapack");

	int outputrows = X.n_rows;

	vector<vector<double>> resultVector(outputrows);

	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<double>>::from(X.row(i));

	return resultVector;
}

//..Function to return array for solving singular value decomposition
vector<double> svd(vector<vector<double>> inputData)
{
	int row = inputData.size(), col = inputData[0].size();
	mat data(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data(i, j) = inputData[i][j];	

	vec S;
	//calling armadillo svd solver
	svd(S,data);

	return conv_to<vector<double>>::from(S);

}

//..Function to return matrix - principal component analysis
vector<vector<double>> princomp(vector<vector<double>> inputData)
{
	int row = inputData.size(), col = inputData[0].size();
	mat data(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data(i, j) = inputData[i][j];

	mat X;

	//calling armadillo function to princomp
	princomp(X,data);

	int outputrows = X.n_rows;

	vector<vector<double>> resultVector(outputrows);

	for (int i = 0; i < outputrows; i++)
		resultVector[i] = conv_to<vector<double>>::from(X.row(i));

	return resultVector;

}

//..Function to return vector array - probability density function
vector<double> log_normpdf(vector<double> inputData)
{
	vec armadilloVec(inputData);
	vec result = log_normpdf(armadilloVec);
	return conv_to<vector<double>>::from(result);
}

//..Function to return vector array - cumulative distribution function
vector<double> normcdf(vector<double> inputData)
{
	vec armadilloVec(inputData);
	vec result = normcdf(armadilloVec);
	return conv_to<vector<double>>::from(result);
}