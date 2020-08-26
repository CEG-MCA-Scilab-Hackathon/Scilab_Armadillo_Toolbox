rm *.o *.so *.lib test

g++ -fPIC -c armaMat.cpp 
g++ -shared -o libarmaMat.so armaMat.o -O2 -larmadillo
g++ -L$(pwd) -Wl,-rpath=$(pwd) -o test main.cpp -larmaMat -g -O2 -larmadillo


cp armaMat.h thirdparty/linux/include/
cp libarmaMat.so thirdparty/linux/lib/x64/

cp armaMat.h thirdparty/Mac/include/
cp libarmaMat.so thirdparty/Mac/lib/x64/
