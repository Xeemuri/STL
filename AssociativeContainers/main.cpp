#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------------\n"

class MyInt
{
	int value;
public:
	MyInt(int value = 0) : value(value) {}
	bool operator <(const MyInt& other)const
	{
		return this->value < other.value;
	}
	friend std::ostream& operator <<(std::ostream& os, const MyInt& obj)
	{
		return os << obj.value;
	}
};

//#define STL_MAP
//#define STL_SET
#define STL_MAP_2

int main()
{
	setlocale(LC_ALL, "");
#ifdef STL_MAP
	std::multimap<int, std::string> weekdays =
	{
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday"),
		std::pair<int, std::string>(7, "Sunday")
	};

	for (std::map<int, std::string>::iterator it = weekdays.begin(); it != weekdays.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}

	cout << delimiter;

	for (std::pair<int, std::string> i : weekdays)
	{
		cout << i.first << tab << i.second << endl;
	}
#endif // STL_MAP
#ifdef STL_SET
	std::set<int> i_set = { 50,25,75,16,32,58,85 };
	for (std::set<int>::iterator it = i_set.begin(); it != i_set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	MyInt a = 5;
	cout << a << endl;

	std::set<MyInt> my_set = { 50,25,75,16,32,58,85 };
	for (std::set<MyInt>::iterator it = my_set.begin(); it != my_set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP_2
	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("statement", {"утверждение", "заявление", "формулировка"}),
		{"space", {"космос", "пространство", "пробел"}},
		{"promise", {"обещание", "перспектива", "проекция"}},
		{"accept", {"принимать", "допускать", "соглашаться", "признавать"}},
		{"reverse", {"переворачивать", "перевернутый", "обратный", "задний ход"}},
		{"", {"", "", "", ""}},
	};

	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ":\t";
		for (std::list<std::string>::iterator r_it = it->second.begin(); r_it != it->second.end(); ++r_it)
		{
			cout << *r_it << ",";
		}
		cout << endl;
	}
	cout << delimiter << endl;

	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout << i.first << ":\t";
		for (std::string j : i.second)
		{
			cout << j << ",";
		}
		cout << endl;
	}
#endif // STL_MAP_2

}

