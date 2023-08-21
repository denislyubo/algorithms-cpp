#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

auto max(auto a, auto b) {
    return a>b?a:b;
}
auto min(auto a, auto b) {
    return a<b?a:b;
}
 
template<typename T> 
T max_prod(std::vector<T>& a) {
    auto m1=max(a[0],max(a[1], a[2])), m3=min(a[0],min(a[1], a[2]));
    auto m2 = a[0]+a[1]+a[2]-m1-m3;

    for (auto [i, n]=std::tuple(3, a.size());i<n;++i) {
        if (a[i]>m1) {
            m3=m2;
            m2=m1;
            m1=a[i];
        } else if(a[i]>m2) {
            m3=m2;
            m2=a[i];
        }else if (a[i]>m3) {
            m3=a[i];
        }
    }

    return m1*m2*m3;
}
template<typename T> 
T max_prod_sort(std::vector<T>& a) {
    std::sort(a.begin(),a.end(),[](auto i, auto j)->bool{return (i< j);});
    auto m1 = *a.rbegin();
    auto m2 = *(a.rbegin()+1);
    auto m3 = *(a.rbegin()+2);
    auto m1_ = *a.begin();
    auto m2_ = *(a.begin()+1);
    auto v1 = m1*m2*m3;
    auto v2= m1_*m2_*m1;
    
    return max(v1, v2);
}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int64_t> a(n);
    for(auto i=0;i<n;i++) {
        std::cin >> a[i];
    }

    auto res = max_prod_sort(a);
    std::cout << res << ' '<< std::endl;

    return 0;
}