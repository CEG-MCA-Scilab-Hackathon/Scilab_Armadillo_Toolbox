// Testing Time using trace -- Matrix Armadillo convolution 1d
// y1 = [1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3,1,2.3,4,5.2,6, 3,2.1,5,4.1,1, 2.8,1,3,4.2,2, 3,2.6,1,2,3, 5,4,3.4,2,3];
// y2 = [ 2, 0, 1];



y1 =rand(1,20000,"uniform");
y2 = rand(1, 10, "uniform");
tic();
res = armaImage("conv1d",y1,y2,0);
t1 = toc();
t1