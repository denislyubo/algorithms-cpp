#include <iostream>
#include <vector>
 
std::vector<int> polynom_sum(const std::vector<int>& a, const std::vector<int>& b) {
    auto n = a.size(), m = b.size();
    std::vector<int> res(n>m?n:m);
    for(auto i=0, j=0, k=0;i<n || j<m;) {
        if (i < n)
            res[k]+=a[i++];
        if (j < m)
            res[k]+=b[j++];

        k++;
    }

    return res;

}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n+1);
    for(auto i=n;i>=0;--i) {
        std::cin >> a[i];
    }

    int m = 0;
    std::cin >> m;
    std::vector<int> b(m+1);
    for(auto i=m;i>=0;--i) {
        std::cin >> b[i];
    }

    auto res = polynom_sum(a, b);
    std::cout << res.size()-1 << ' '<< std::endl;
    for (int i=res.size()-1; i>=0;i--){
        std::cout << res[i] << ' ';
    }
    return 0;
}