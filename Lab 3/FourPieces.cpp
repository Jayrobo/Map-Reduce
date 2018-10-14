#include <iostream>
#include <string>

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
//					Function Declearation					  //
//------------------------------------------------------------//

/*JUST INITIAL THOUGHTS, MORE THAN WELCOME TO CHANGE PARAMETERS & TYPES*/

/*1*/
//inputter should read the input file and feed into the input reader
//should return an array of something to the generic part
/*Initial Thoughts - https://stackoverflow.com/questions/6810656/creating-an-array-of-structs-in-c */
/*OR just return an array of strings*/
/*return array of strings - https://stackoverflow.com/questions/7527356/return-string-array-in-c-function */
string* inputter(string filename);


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