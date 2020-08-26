 // Calculating the corelation and covariance , input dimension must be same
 y1 = [1,2,3; 4,5,6; 7,8,9]
 y2 = [1,9,3; 3,5,6; 7,8,5]
 res = armaClust("cor",y1,y2)
 res = armaClust("cov",y1,y2)
