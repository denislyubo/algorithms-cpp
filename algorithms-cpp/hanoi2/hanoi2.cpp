#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>


 void HanoiTowers(int n,int fromPeg,int toPeg, int unusedPeg1, int unusedPeg2, std::vector<std::pair<int,int>>& res) {
    if (n == 0)
        return;
    if (n == 1){
        res.push_back(std::make_pair(fromPeg, toPeg));
        return;
    }

    HanoiTowers(n-2,fromPeg,unusedPeg1, unusedPeg2, toPeg,  res);
    res.push_back(std::make_pair(fromPeg, unusedPeg2));
    res.push_back(std::make_pair(fromPeg, toPeg));
    res.push_back(std::make_pair(unusedPeg2, toPeg));
    HanoiTowers(n-2,unusedPeg1,toPeg, fromPeg, unusedPeg2,  res);
 }

std::vector<std::pair<int,int>> hanoi(int n)
{
    std::vector<std::pair<int,int>> res;
    HanoiTowers(n,1, 4, 2, 3, res);
    return res;
}
 
int main() {
    int n, m;
    std::cin >> n;
    
    auto res = hanoi(n);

    std::cout << res.size() << std::endl;
    //for(const auto& i : res){
    //    std::cout << i.first << " " << i.second << std::endl;
    //}

    return 0;
}