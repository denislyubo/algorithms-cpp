#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
 
int combinations(int n, int k)
{
    int res{1},res1{1};

    for (auto i=n-k+1; i<=n; ++i) 
    {
        res*=i;
    }
        for (auto i=1; i<=k; ++i) 
    {
        res1*=i;
    }

    return res/res1;
}
 
int main() {
    int n, k;
    std::cin >> n >> k;
    
    auto res = combinations(n, k);
    std::cout << res << std::endl;

    return 0;
}