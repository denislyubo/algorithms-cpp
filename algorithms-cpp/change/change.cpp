#include <iostream>
#include <array>
#include <cmath>
#include <numeric>
#include <algorithm>

int main()
{
    int sum = 0;
    std::cin >> sum;
    std::array<int, 5> nominal {50, 20, 10, 5, 1}; 
    std::array<int, 5> res;

    int temp1=sum%50;
    int temp2=temp1%20;
    int temp3=temp2%10;

    res[0] = (sum / 50);
    res[1] = temp1/20;
    res[2] = temp2/10;
    res[3] = temp3/5;
    res[4] = temp3%5;


    auto num = std::accumulate(res.begin(),res.end(), 0);
    std::cout << num << std::endl;

    int j{};
    std::for_each(res.cbegin(), res.cend(), [&j, &nominal](const auto& val){
        for(auto i=0;i<val;i++) 
        {
            std::cout << nominal[j] << " ";
        }
        j++;
   });

    std::cout << std::flush;    
}