// Calculating the convolution 1d. 4th paramter 0 for full, 1 for same
y1 = [1,2,3,4,5,6,7,8];
y2 = [1,2]
res = armaImage("conv1d",y1,y2,0)
res = armaImage("conv1d",y1,y2,1)