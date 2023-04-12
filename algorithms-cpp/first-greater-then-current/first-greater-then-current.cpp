// first-greater-then-current.cpp : Defines the entry point for the application.
//

#include "first-greater-then-current.h"

#include <vector>


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

int main()
{
	vector<int> input{ -1, -7, 0, -2, 2, 4, 3, 3, 6 };
	
	for (const auto& i : input)
	{
		cout << i << " ";
	}
	cout << endl;

	auto res = fst_grtr_cur(input);

	for (const auto& i : res)
	{
		cout << i << " ";
	}
	cout << endl;	

	return 0;
}
