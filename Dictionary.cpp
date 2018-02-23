#include <map>
#include <vector>
#include <string>
#include <fstream>

using std::map;
using std::string;
using std::vector;

int main()
{
	std::ifstream file("file.txt");
	if (file.is_open())
	{
		string word;
		map<string,int> dict;
		while (!file.eof())
		{
			file >> word;
			word = prepare(word);
			dict[word]++;
		}
		struct stat
		{
			int count;
			string word;
		}
		vector<stat> s;
		for(auto it = dict.begin(), it != dict.end(), it++)
		{
			
		}
		std::sort(s.begin(), s.end(), compare);
	}
	file.close();
}
