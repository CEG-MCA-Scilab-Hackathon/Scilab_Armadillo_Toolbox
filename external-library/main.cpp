#include "armaMat.h"
// Testing the source armadillo functions
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
int main()
{
    double ar[1];
    //cout<<"Inside main: "<< ar[0];
    vector<vector<double>> demo = {{1, 1, 1},
                                   {4, -2, 5},
                                   {2, 8, 7}};
    vector<vector<double>> ans = squareArma(demo);
	printer(ans);
    return 0;
}
