#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>
 
void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void selection_sort(std::vector<int>& a)
{   auto n{a.size()};
    auto min{0};
    auto ind{0};
    for (auto i = 0; i < n; i++)  {
        min = std::numeric_limits<int>::max();
        for (auto j=i; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                ind = j; 
            }
        }
        swap(a[i], a[ind]);
    }
}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> data(n);
    for (auto i=0; i < n; ++i) {
        std::cin >> data[i]; 
    }       
    
    selection_sort(data);
    for (auto i = 0; i < n;++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}