#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
 
std::string stones(int n, int m)
{
    bool R[n+1][m+1];

    R[0][0]=false;
    for (auto i=1;i<=n;++i)
        if (R[i-1][0])
            R[i][0]=false;
        else
            R[i][0]=true;
    
    for (auto j=1;j<=m;++j)
        if (R[0][j-1])
            R[0][j]=false;
        else
            R[0][j]=true;

    for (auto i=1;i<=n;++i)
        for (auto j=1;j<=m;++j)
            if (R[i-1][j] && R[i][j-1] && R[i-1][j-1])
                R[i][j]=false;
            else
                R[i][j]=true;



    return R[n][m]?"Win":"Loose";
}
 
int main() {
    int n, m;
    std::cin >> n >> m;
    
    auto res = stones(n, m);
    std::cout << res << std::endl;

    return 0;
}