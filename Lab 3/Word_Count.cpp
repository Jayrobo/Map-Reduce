#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void First_Word_Count()
{
	ifstream input_file;
	string filename, content;

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
		getline(input_file, content);
		word_count++;
	}

	cout << content;

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