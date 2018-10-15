#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

//------------------------------------------------------------//
//						  Global Variables						  //
//------------------------------------------------------------//
int word_count = 0; //for use as counter

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
vector<std::string> inputter(string filename) {

	ifstream input_file;
	input_file.open(filename);
	vector<std::string> chunks ;

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
			chunks.push_back(temp);
		}

		//cout << temp << endl;
		//content.push_back(temp.substr());
		word_count++;
	}
	return chunks;
}

/*2*/
//map must not return void
//map returns a single key-value pair
//map has single input
key_val map(string str) {
	key_val pair;
	return pair;
}

/*3*/
//reduce must not return void
//reduce returns a single key value pair 
//reduce has single input ----> collection of key-value pair which suppose to be together
//*****should not look at more than one kind of key/invocation of the reduce step???*****/

/*NOTE: Collection as input maybe struct array????*/
key_val reduce(key_val collection) {
	key_val reduced_pair;
	return reduced_pair;
}

/*4*/
//outputter takes key-value pair and outputs to the screen
void outputter(key_val collection) {

}

int main() {

	vector<string> words;
	key_val pair;

	words = inputter("Text.txt"); //read in text file and get words into array
	
	//pass single array elements into map, then reduce then group and pass into outputter
	for(int i = 0; i<words.size();i++){
		pair = map(words[i]);

	}
	system("Pause");
	return 0;
}