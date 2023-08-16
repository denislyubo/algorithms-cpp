#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <optional>
 
std::optional<int> find_min_right(const std::vector<std::pair<int, int>>& intervals, std::vector<bool>& excluded)
{
    std::optional<int> res{std::nullopt};
    auto min = INT32_MAX;
    for (auto i = 0; i < intervals.size(); ++i)
    {
        if (!excluded[i]){
            const auto& val = intervals[i].second;
            if (val <= min)
            {
                min = val;
                res = i;
            }
        }
    }

    return res;
}

void exclude(int j, const std::vector<std::pair<int, int>>& intervals, std::vector<bool>& excluded)
{
    const auto& target = intervals[j].second;
    excluded[j] = true;
    for (auto i = 0; i < intervals.size(); ++i)
    {
        if(!excluded[i]){
            const auto& val = intervals[i].first;
            if (val <= target)
                excluded[i] = true;
        }
    }
}

int booking(const std::vector<std::pair<int, int>>& intervals) 
{
    std::vector<bool> excluded(intervals.size());
    int count{};
    while (true){
        auto v = find_min_right(intervals, excluded);
        if (!v)break;
        exclude(v.value(), intervals, excluded);
        count++;
    }
    return count;
}
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for(auto i=0;i<n;i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    auto res = booking(a);
    std::cout << res << ' '<< std::endl;

    return 0;
}