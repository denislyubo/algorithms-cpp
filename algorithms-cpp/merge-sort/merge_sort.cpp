#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>

void merge_s(std::vector<int>& a, int b, int e) {
    if (b == e) {
        return;
    }

    auto k = (b+e)/2;
    merge_s(a, b, k);
    merge_s(a, 1+k, e);

    auto len = e-b+1;
    std::vector<int> res(len);

    auto m{b}, n{1+k};
    for (auto i=0; i<len;++i) {
        if (m <= k && n <=e) {
            if (a[m] < a[n])
                res[i] = a[m++];
            else
                res[i] = a[n++];
        } else if (m <= k) {
            res[i] = a[m++];
        } else if (n <= e) {
            res[i] = a[n++];
        }
    }

    std::copy(res.begin(), res.end(), &a[b]);
}
 
void merge_sort(std::vector<int>& a){
    merge_s(a, 0, a.size()-1);
}
 
int main() {
    int n = 0, tot{};
    std::cin >> n;
    std::vector<int> data(n);
    for (auto i=0;i<n;i++) {
        std::cin >> data[i]; 
    }
 
    merge_sort(data);
    for (auto i = 0; i < n;++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}