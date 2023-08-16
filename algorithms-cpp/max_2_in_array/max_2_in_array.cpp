#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
 
int max_prod(std::vector<uint64_t>& a) {
    std::sort(a.begin(),a.end(),[](auto i, auto j)->bool{return (i< j);});
    return a[a.size()-1]*a[a.size()-2];
}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<uint64_t> a(n);
    for(auto i=0;i<n;i++) {
        std::cin >> a[i];
    }

    auto res = max_prod(a);
    std::cout << res << ' '<< std::endl;

    return 0;
}