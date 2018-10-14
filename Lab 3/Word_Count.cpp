#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <set>


using namespace std;

//reference material http://www.techiedelight.com/sort-map-values-cpp/
struct comp
{
	template<typename T>
	bool operator()(const T& left, const T& right) const
	{
		if (left.second != right.second)
			return left.second > right.second;
	
		return left.first > right.first;
	}
};

void First_Word_Count()
{
	ifstream input_file;
	string filename;
	multimap <string, int> content;

	do
	{
		cin >> filename;
		input_file.open(filename);

		if (input_file.fail())
			cout << "Error, please input with correct file name: ";
	} while (input_file.fail());

	int word_count = 0;
	
	while (!input_file.eof())
	{
		//getline(input_file, content);
		string temp; 
		input_file >> temp;

		for (int i = 0; i < temp.size(); ++i)
		{
			temp[i] = tolower(temp[i]); //convert everything into lower cases

			if (!((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] == '\'') || (temp[i] == '-')))
			{
				if (i == 0)
				{
					temp = temp.substr(1, temp.size());
					temp[i] = tolower(temp[i]); //since the first character has been replaced, need to make sure it's also lower cased
				}
				else
				{
					temp[i] = ':';
				}
			}
		}

		size_t found = temp.find_first_of(":");
		if (found != string::npos)
		{
			temp = temp.substr(0, found); //to make sure the word doesn't include other symbols 
		}
		
		if (temp != "\0" && temp != "-") //remove stand along character
		{
				content.insert(pair<string, int>(temp, 1));
		}
			
		//cout << temp << endl;
		//content.push_back(temp.substr());
		word_count++;
	}

	map<string, int> reduced_content;
	string current_content = "a";
	int similar_count = 1; //since its registered in map, it means the least count it will have is 1
	for (map<string, int>::iterator it = content.begin(); it != content.end(); it++)
	{
		if (it->first != current_content)
		{
			if (current_content == "a") //because the first "a" will be passing into the eqaul statement while it only has 1 "a"
				reduced_content.insert(pair<string, int>(current_content, similar_count - 1));
			else
				reduced_content.insert(pair<string, int>(current_content, similar_count));

			current_content = it->first; //update for the next comparison
			similar_count = 1; //reset the count because a new key has arrived

			//cout << current_content << endl;
		}
		else if (it->first == current_content)
		{
			similar_count++; //adding one for similar count
			//cout << current_content << endl;
		}
	}
	
	set<pair<string, int>, comp> set(reduced_content.begin(), reduced_content.end());
	
	//for (map<string,int>::iterator it = content.begin(); it != content.end(); it++)
	//	cout << left << setw(30) << it->first << it->second << endl;
	//for (map<string,int>::iterator it = reduced_content.begin(); it != reduced_content.end(); it++)
	//	cout << left << setw(30) << it->first << it->second << endl;

	for (auto const &pair: set) //tried to manually produce the auto type but idk how
		cout << left << setw(30) << pair.first << pair.second << endl;
	//cout << content << " " << word_count <<endl;


	input_file.close();
}


int main()
{
	cout << "Please input the input file name:";
	First_Word_Count();

	cout << "done";

	system("pause");
	return 0;
}