// Testing time
inputMat = [1,2.3,4,5.2,6; 3,2.1,5,4.1,1; 2.8,1,3,4.2,2; 3,2.6,1,2,3; 5,4,3.4,2,3;]
t1 = getdate();
result = armaDenseMat("svd",inputMat);
t2 = getdate();
res1 = etime(t2,t1);
t3 = getdate();
result = svd(inputMat);
t4 = getdate();
res2 = etime(t4,t3);
res1
res2
