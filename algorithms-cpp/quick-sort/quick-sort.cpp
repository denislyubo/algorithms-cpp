#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>
#include <optional>
 
void swap(int& a, int& b) {
    if (a == b)
        return;
    int c = a;
    a = b;
    b = c;
}

std::optional<int> lomuto(std::vector<int>& a, int b, int e) {
    if (e-b <= 0)
    return std::nullopt;

    int k{b+1};
    for (auto [i, n]=std::tuple(b+1, a.size()); i<=e;++i) {
        if (a[i] < a[b])
            swap(a[i], a[k++]);
    }

    swap(a[b], a[k-1]);

    return k-1;   
}

void quick_aux(std::vector<int>& a, int b, int e) {

    auto k= lomuto(a, b, e).value_or(-1);
    if(k<0)
        return;
    

    quick_aux(a, b, k);
    quick_aux(a, k+1, e);
}

void quick(std::vector<int>& a)
{   
    auto n{a.size()};

    quick_aux(a, 0, n-1);    
}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> data(n);
    for (auto i=0; i < n; ++i) {
        std::cin >> data[i]; 
    }       
    
    std::random_shuffle(data.begin(), data.end());

    quick(data);
    for (auto i = 0; i < n;++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}