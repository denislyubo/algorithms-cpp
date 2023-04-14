// robot-dynamic-programming.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
#include <format>

using namespace std;

int helper(int n, int m, vector<vector<int>>& arr);

int paths(int n, int m)
{
	vector<vector<int>> arr;
	arr.resize(n);
	for (int i=0; i < n;++i)
		arr[i].resize(m);
	
	return helper(n, m, arr);
}

int helper(int n, int m, vector<vector<int>>& arr) 
{
	if (n < 1 || m < 1)
		return 0;

	if (n == 1 && m == 1)
		return 1;

	if (arr[n-1][m-1] != 0)
		return arr[n-1][m-1];

	arr[n-1][m-1] = paths(n - 1, m) + paths(n, m - 1);

	return arr[n-1][m-1];
}

int main()
{
	auto res = paths(4, 3);

	cout << std::format("Result is: {}", res);

	return 0;
}
