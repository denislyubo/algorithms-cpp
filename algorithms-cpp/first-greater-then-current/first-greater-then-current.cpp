// first-greater-then-current.cpp : Defines the entry point for the application.
//

#include "first-greater-then-current.h"

#include <vector>
#include <stack>


using namespace std;


vector<int> fst_grtr_cur(const vector<int>&a)
{
	const auto len = a.size();
	vector<int> res(len, 0);
	

	for (auto i = 0; i < len; ++i)
	{
		for (auto j = i; j < len; ++j)
		{
			if (a[j] > a[i])
			{
				res[i] = j - i;
				break;
			}
		}
	}

	return res;
}

vector<int> fst_grtr_cur_1(const vector<int>& a)
{
	const auto len = a.size();
	vector<int> res(len, 0);
	stack<pair<int, int>> index_temp;


	for (auto i = static_cast<int>(len)-1; i >=0; --i)
	{
		if (i == len - 1) 
		{
			index_temp.emplace(make_pair(i, a[i]));
			continue;
		}


		while (index_temp.size())
		{
			if (a[i] >= index_temp.top().second)
				index_temp.pop();
			else
				break;
		}

		if (index_temp.size())
		{
			res[i] = index_temp.top().first - i;
		}
		else
			res[i] = 0;

		index_temp.emplace(make_pair(i, a[i]));		
	}

	return res;
}

int main()
{
	vector<int> input{ -1, -7, 0, -2, 2, 4, 3, 3, 6 };
	
	for (const auto& i : input)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "Naive O(n^2) approach: " << endl;
	auto res = fst_grtr_cur(input);

	for (const auto& i : res)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "Stack based O(n) approach: " << endl;
	auto res1 = fst_grtr_cur_1(input);

	for (const auto& i : res1)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
