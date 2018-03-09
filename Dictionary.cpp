#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <assert.h>
#include <iostream>
////////////////////////////////////////////////////////////////////////////
using std::map;
using std::string;
using std::vector;
using std::ios_base;
////////////////////////////////////////////////////////////////////////////
typedef struct Statistics
{
	int count_w;
	string word;
} stat;
////////////////////////////////////////////////////////////////////////////
string prepare(const string& s)
{
	string result = s;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	/*
	А если слово оканчивается троеточием?
	вероятно вместо if нужен while
	*/
	if (ispunct(result.back()))//if current character is punctuation or space character(case space is not implemented)
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
	return lhs.count_w != rhs.count_w ? lhs.count_w > rhs.count_w : compare_words(lhs.word, rhs.word);//in descending order of number, in accending order of alphabet
}
////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<stat> s;
	std::ifstream fin("input.txt");
	if (fin.is_open())
	{
        string word;
		map<string,int> dict;//string - our word, int - number of repetitions
		while (!fin.eof())
		{
			fin >> word;
 			word = prepare(word);
			dict[word]++;
		}
		stat buf;//buffer structure for copying
		/*
		вам не нравится range-based for ?
		for (const auto& pair : dict)
		{
		  buf.word = pair.word;
		  ...
		}
		*/
		for(auto it = dict.begin(); it != dict.end(); it++)
		{
			buf.word = it->first;
			buf.count_w = it->second;
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
		for (auto it = s.begin(); it != s.end(); it++)
			fout << it->word << " " << it->count_w << "\n";
	}
	else
	{
		printf("Output file cannot be open\n");
		assert(0);
	}
	fout.close();
}
