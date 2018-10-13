#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <iterator>


using namespace std;

void First_Word_Count()
{
	ifstream input_file;
	string filename;
	map <string, int> content;

	do
	{
		cin >> filename;
		input_file.open(filename);

		if (input_file.fail())
			cout << "Error, please input with correct file name: ";
	} while (input_file.fail());

	int word_count = 0;
	string delimiter = "\".?,";

	while (!input_file.eof())
	{
		//getline(input_file, content);
		string temp; 
		input_file >> temp;
		for (int i = 0; i < temp.size(); ++i)
		{
			temp[i] = tolower(temp[i]);
			if (!((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] == '\'')))
			{
				temp[i] = '\0';
			}
		}
		
		content.insert(pair<string, int>(temp, 1));
		//cout << temp << endl;
		//content.push_back(temp.substr());
		word_count++;
	}

	for (map<string,int>::iterator it = content.begin(); it != content.end(); it++)
		cout << it->first << "	 =>  " << it->second << endl;
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