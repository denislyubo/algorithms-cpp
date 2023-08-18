#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
 
 void HanoiTowers(int n,int fromPeg,int toPeg, std::vector<std::pair<int,int>>& res) {
    if (n == 1){
        res.push_back(std::make_pair(fromPeg, toPeg));
        return;
    }

    auto unusedPeg = 6 - fromPeg - toPeg;
    HanoiTowers(n-1,fromPeg,unusedPeg, res);
    res.push_back(std::make_pair(fromPeg, toPeg));
    HanoiTowers(n-1,unusedPeg,toPeg, res);
 }

std::vector<std::pair<int,int>> hanoi(int n)
{
    std::vector<std::pair<int,int>> res;
    HanoiTowers(n,1, 3, res);
    return res;
}
 
int main() {
    int n, m;
    std::cin >> n;
    
    auto res = hanoi(n);

    std::cout << res.size() << std::endl;
    for(const auto& i : res){
        std::cout << i.first << " " << i.second << std::endl;
    }

    return 0;
}