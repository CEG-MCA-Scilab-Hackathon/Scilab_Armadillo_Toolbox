 // Function Name: reshape
 //  Generate a vector/matrix/cube with given size specifications, whose elements are taken from the given object in a column-wise manner; the elements in the generated object are placed column-wise (ie. the first column is filled up before filling the second column)
 //  The layout of the elements in the generated object will be different to the layout in the given object
 //  If the total number of elements in the given object is less than the specified size, the remaining elements in the generated object are set to zero
 //  If the total number of elements in the given object is greater than the specified size, only a subset of elements is taken from the given object
 //  3rd parameter = row
 //  4th parameter = column
 // Calculating the reshape
 inputMat = [ 1, 2, 3; 4, 5, 6; 7, 8, 9;]
 result = armaMatFunc("reshape",inputMat,2,2)

