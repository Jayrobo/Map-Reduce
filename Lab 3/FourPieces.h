#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;


// this file would contain 
//		1. input reader
//		2. mapper
//		3. reducer
//		4. outputter 

//------------------------------------------------------------//
//						  Data Type							  //
//------------------------------------------------------------//
struct key_val
{
	string key;
	int value;
};

vector<key_val> content;
//------------------------------------------------------------//
//					Function Declearation					  //
//------------------------------------------------------------//

/*JUST INITIAL THOUGHTS, MORE THAN WELCOME TO CHANGE PARAMETERS & TYPES*/

/*1*/
//inputter should read the input file and feed into the input reader
//should return an array of something to the generic part
/*Initial Thoughts - https://stackoverflow.com/questions/6810656/creating-an-array-of-structs-in-c */
/*OR just return an array of strings*/
/*return array of strings - https://stackoverflow.com/questions/7527356/return-string-array-in-c-function */
vector<key_val> inputter(string filename);


/*2*/
//map must not return void
//map returns a single key-value pair
//map has single input
key_val map(string str);

/*3*/
//reduce must not return void
//reduce returns a single key value pair 
//reduce has single input ----> collection of key-value pair which suppose to be together
//*****should not look at more than one kind of key/invocation of the reduce step???*****/

/*NOTE: Collection as input maybe struct array????*/
key_val reduce(key_val collection);

/*4*/
//outputter takes key-value pair and outputs to the screen
void outputter(key_val collection);

//---------------------------------------------------------------------------//
//							  Implementation								 //
//---------------------------------------------------------------------------//
vector<key_val> inputter(string filename)
{
	int word_count = 0;

	ifstream input_file;
	input_file.open(filename);

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

			//** https://stackoverflow.com/questions/8067338/vector-of-structs-initialization  **//
			//Push back new key_val struct created with default constructor.
			content.push_back(key_val());

			content[word_count].key = temp;
			content[word_count].value = 0;
			word_count = word_count + 1;
		}
	}
	return content;
	input_file.close();
}