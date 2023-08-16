#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
 
int permutations(int n)
{
    int res{1};

    for (auto i=1; i<=n; ++i) 
    {
        res*=i;
    }

    return res;
}
 
int main() {
    int n = 0;
    std::cin >> n;
    
    auto res = permutations(n);
    std::cout << res << std::endl;

    return 0;
}