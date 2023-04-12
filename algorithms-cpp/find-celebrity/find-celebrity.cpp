// find-celebrity.cpp : Defines the entry point for the application.
//

#include "find-celebrity.h"

#include <vector>
#include <format>

using namespace std;

class Person
{
	int ownId;
	vector<bool> knowVect;
public:
	Person(int id, const vector<bool>& knowVector) :knowVect(knowVector), ownId(id) {}
	bool Knows(const Person& rhs) const
	{
		return knowVect[rhs.ownId];
	}

	int GetId() const {
		return ownId;
	}

	bool operator==(const Person& rhs) const noexcept {
		return ownId == rhs.ownId;
	}
};

template<>
struct std::formatter<Person>
{
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	auto format(const Person& value, std::format_context& ctx) const {
		auto id = value.GetId();
		if (id == -1)
			return  std::format_to(ctx.out(), "No celebrity");
		else 
			return std::format_to(ctx.out(), "Person({})", value.GetId());
	}
};

Person findCelebrity(const vector<Person>& persons)
{
	auto len = persons.size();
	auto l = 0, r = int(len) - 1;

	while (l != r)
	{
		if (persons[l].Knows(persons[r]))
			l++;
		else
			r--;
	}

	for (auto i = 0; i < len; ++i)
	{
		if (persons[i] != persons[l] && (!persons[i].Knows(persons[l]) || persons[l].Knows(persons[i])))
			return Person(-1, vector<bool>{});
	}

	return persons[l];
}

int main()
{
	/*vector<vector<bool>> mtx{
		{false, true, false},
		{false, false, false},
		{false, true, false},
	};*/

	vector<vector<bool>> mtx{
	{false, true, false},
	{false, false, false},
	{false, false, true},
	};

	vector<Person> persons;

	for (auto i = 0; i < mtx.size(); ++i)
	{
		persons.emplace_back(Person(i, mtx[i]));
	}

	auto celebrity = findCelebrity(persons);

	cout << format("Celebrity person: {}", celebrity);

	return 0;
}
