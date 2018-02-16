#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;

bool compare(const string& lhs, const string& rhs)
{
	return lhs.size()==rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
}

int main()
{
	int num, i;
	std::cout << "Number of strings: ";
	std::cin >> num;
	vector<string> a(num);
	for (i = 0; i < num; i++)
	{
		std::cin >> a[i];
	}
	sort(a.begin(), a.end(), compare);
	std::cout << "Your strings: \n";
	for (i = 0; i < num; i++)
	{
		std::cout << a[i] << "\n";
	}
}
