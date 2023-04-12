// find-two-el-equal-k.cpp : Defines the entry point for the application.
//

#include "find-two-el-equal-k.h"

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
std::ostream& operator<< (std::ostream& out, std::pair<T, T> const& data) {
	out << data.first << ":" << data.second << ";";

	return out;
}

template<typename T>
struct pair_hash {
	size_t operator() (const T& p) const noexcept {
		return ((size_t)p.first << 32) | p.second;
	}
};

template <typename T>
struct Comparator {
	bool operator() (const T& a, const T& b) const noexcept {
		if (a == b || (a.first == b.second && a.second == b.first))
			return true;

		return false;
	}
};

template <typename T>
using Res = unordered_set <T, pair_hash<T>, Comparator<T>>;

auto twoSum(const vector<int>& arr, int k) {
	Res<std::pair<int, int>> res;

	auto len = arr.size();

	for (auto i = 0; i < len; ++i) 
		for (auto j = 0; j < len; ++j) {
			if ((arr[i] + arr[j]) == k) {
				res.insert(make_pair(arr[i], arr[j]));
			}
		}

	return res;
}


int main()
{
	vector<int> input{ -1, 2,6, 7, 12, 14 };

	auto res = twoSum(input, 6);

	cout << "Found results: " << endl;
	for (const auto& el : res) {
		cout << el << endl;
	}
	return 0;
}
