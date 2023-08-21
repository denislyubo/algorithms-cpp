#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>

void swap(int& a, int& b) {
    auto c = a;
    a = b;
    b = c;

}

void lomuto(std::vector<int>& a) {
    int k{1};
    for (auto [i, n]=std::tuple(1, a.size()); i<n;++i) {
        if (a[i] < a[0])
            swap(a[i], a[k++]);
    }

    swap(a[0], a[k-1]);   
} 

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> data(n);
    for (auto i=0;i<n;i++) {
        std::cin >> data[i]; 
    }
 
    lomuto(data);
    for (auto i = 0; i < n;++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}