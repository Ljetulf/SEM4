#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algoritm>
#include <ctype.h>
#include <assert.h>
////////////////////////////////////////////////////////////////////////////
using std::map;
using std::string;
using std::vector;
////////////////////////////////////////////////////////////////////////////
typedef struct Statistics
{
	int count;
	string word;
} stat;
////////////////////////////////////////////////////////////////////////////
string prepare(const string& s)
{
	string result;
	std::transform(s.begin(), s.end(), result.begin(), ::tolower);
	if ispunct(s.back())//if current character is punctuation or space character(case space is not implemented)
		result.pop_back();
	return result;
}
////////////////////////////////////////////////////////////////////////////
bool compare_words(const string& lhs, const string& rhs)
{
	return lhs.size()==rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
}
////////////////////////////////////////////////////////////////////////////
bool compare(const stat& lhs, const stat& rhs)
{
	return lhs.count == rhs.count ? lhs.count > rhs.count : compare_words(lhs.word, rhs.word);//in descending order of number, in accending order of alphabet
}
////////////////////////////////////////////////////////////////////////////
int main()
{
	std::ifstream fin("input.txt");
	if (fin.is_open())
	{
		string word;
		map<string,int> dict;//string - our word, int - number of repetitions
		while (!file.eof())
		{
			file >> word;
			word = prepare(word);
			dict[word]++;
		}
		stat buf;//buffer structure for copying
		vector<stat> s;
		for(auto it = dict.begin(), it != dict.end(), it++)
		{
			buf.word = it->first;
			buf.count = it->second;
			s.push_back(buf);
		}
		std::sort(s.begin(), s.end(), compare);
	}
	else
	{
		printf("Input file cannot be open\n");
		assert(0);
	}
	fin.close();
	std::ofstream fout("output.txt", ios_base::out | ios_base::trunc);//open file only for writing and delete all data in it 
	if (fout.is_open())
	{
		for (auto it = s.begin(), it != s.end(), it++)
			fout << it->word << " " << it->count;
	}
	else
	{
		printf("Output file cannot be open\n");
		assert(0);
	}
	fout.close();
}
