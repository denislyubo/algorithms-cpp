// find-two-el-equal-k.cpp : Defines the entry point for the application.
//

#include "find-two-el-equal-k.h"

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <optional>

using namespace std;

template<typename T>
concept SupportFirstSecond = requires(T val) {
	val.first;
	val.second;
};

template <typename T>
//requires SupportFirstSecond<T>
std::ostream& operator<< (std::ostream& out, const std::pair<T, T>& data) {
	out << data.first << ":" << data.second << ";";

	return out;
}

template<typename T>
requires SupportFirstSecond<T>
struct pair_hash {
	size_t operator() (const T& p) const noexcept {
		return ((size_t)p.first << 32) | p.second;
	}
};

template <typename T>
requires SupportFirstSecond<T>
struct Comparator {
	bool operator() (const T& a, const T& b) const noexcept {
		if ((a.first == b.first && a.second == b.second) || (a.first == b.second && a.second == b.first))
			return true;

		return false;
	}
};

template <typename T>
using Res = unordered_set <T, pair_hash<T>, Comparator<T>>;

template <typename T>
requires(std::is_integral_v<T>)
using Set = std::unordered_set<T>;

auto twoSum(const vector<int>& arr, int k) {
	Res<std::pair<int, int>> res;

	auto len = arr.size();

	for (auto i = 0; i < len; ++i) 
		for (auto j = i+1; j < len; ++j) {
			if ((arr[i] + arr[j]) == k) {
				res.insert(make_pair(min(arr[i], arr[j]), max(arr[i], arr[j])));
			}
		}

	return res;
}

auto twoSum1(const vector<int>& arr, int k) {
	Res<std::pair<int, int>> res;
	Set<int> temp;

	auto len = arr.size();

	for (auto i = 0; i < len; ++i) 
	{
		const auto& el = temp.find(k-arr[i]);
		if (el != temp.end()) 
		{
			res.insert(make_pair(*el, arr[i]));
		}
		else
			temp.insert(arr[i]);
	}
		

	return res;
}

template<typename T>
std::optional<T> binary_search(const vector<T>& arr, T k)
{
	std::optional<T> res;

	int i = 0, j = arr.size()-1;
	while (i<j-1)
	{
		auto n = (j + i) / 2;
		if (k < n) {
			j = n;
		}
		else if (k >n)
		{
			i = n;
		}
		else
			return std::optional<T>{arr[n]};
	}

	return std::optional<T>{};
}

auto twoSum2(const vector<int>& arr, int k) {
	Res<std::pair<int, int>> res;

	auto len = arr.size();

	for (auto i = 0; i < len; ++i)
	{
		auto j = k - arr[i];
		auto r = binary_search(arr, j);
		if (r)
			res.insert(make_pair(r.value(), j));		
	}


	return res;
}


int main()
{
	vector<int> input{ -1, 2,6, 7, 8, 12, 14, 15, 16 };

	auto res = twoSum(input, 15);

	cout << "Found results twoSum: " << endl;
	for (const auto& el : res) {
		cout << el << endl;
	}

	auto res1 = twoSum1(input, 15);

	cout << "Found results twoSum1: " << endl;
	for (const auto& el : res1) {
		cout << el << endl;
	}

	auto res2 = twoSum2(input, 15);

	cout << "Found results twoSum2: " << endl;
	for (const auto& el : res1) {
		cout << el << endl;
	}

	return 0;
}
