#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits>
 
auto merge(int tot, std::vector<std::vector<int>>& a)
{   std::vector<int> res(tot);
    auto n{(int)a.size()};
    std::vector<int> cur_indexes(n, 0);
    int min{0};
    int min_ind{};
    for (auto i=0;i< tot;++i ) {
        min=std::numeric_limits<int>::max();
        for (int j=0; j<n;++j) {
            if (cur_indexes[j] < a[j].size() && a[j][cur_indexes[j]] < min)  {
                min = a[j][cur_indexes[j]];
                min_ind = j;
            }
        }

        res[i]=a[min_ind][cur_indexes[min_ind]++];
    }

    return res;    
}
 
int main() {
    int n = 0, tot{};
    std::cin >> n;
    std::vector<std::vector<int>> data(n);
    for (auto i=0;i<n;i++) {
        int m{};
        std::cin >> m;
        data[i].resize(m);
        tot+=m;
        for (auto j=0; j < m; ++j) {
            std::cin >> data[i][j]; 
        }       
    }
 
    auto res = merge(tot, data);
    for (auto [i, size] = std::tuple{0, res.size()}; i < size;++i) {
        std::cout << res[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}