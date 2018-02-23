#include <iostream>
#include <string>

using std::string;

struct Vector2
{
	string str;
	Vector2(const string& name)
	{
		str = name;
		std::cout << "Vector2 " << name;
	}
	~Vector2()
	{
		std::cout << "Destruct Vector2 " << str;
	}
};

int main()
{
	string word;
	std::cin >> word;
	word = word + "\n";
	Vector2 a("Hello world\n");
	Vector2 b("Bye world\n");
	Vector2 c(word);
	std::cout << "WTF world\n";
}
