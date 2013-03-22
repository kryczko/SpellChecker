/*This program prompts the user to input a text file that the user
would like to spellcheck. If the words do not match the dictionary,
the words are printed.*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>


using namespace std;

int main()
{
// prompt the user to enter a text file
string filename;
cout << "Please enter the file name you would like to spell check: ";
cin >> filename;

//declare the input file streams
ifstream inputfile, dictionary;

//open the file entered by the user
inputfile.open(filename.c_str());

//if the input file is not readable tell the user 
if (inputfile.fail())
{
cerr << "File " << filename << " could not be opened.\n";
exit(1);
}

cout << "\n\nThe misspelled words in your file are:\n\n";

string word, dictword;
// start of the loop that will compare each word in the user's file
// to each of the dictionary words
while (!inputfile.eof())
	{
		// declare the boolean variable to decide whether or not to
		// print the word and declare the string taking in the user's
		// words
		bool flag = false;
		inputfile >> word;

		//find all the punctuation and replace them with empty strings
		int found1 = word.find(".");
		if (found1 >= 0) { word.replace(found1,1,""); }
 
		int found2 = word.find("!");
		if (found2 >= 0) { word.replace(found2,1,""); }
 
		int found3 = word.find("(");
		if (found3 >= 0) { word.replace(found3,1,""); }
 
		int found4 = word.find(")");
		if (found4 >= 0) { word.replace(found4,1,""); }
 
		int found5 = word.find(";");
		if (found5 >= 0) { word.replace(found5,1,""); }
 
		int found6 = word.find("?");
		if (found6 >= 0) { word.replace(found6,1,""); }
 
		int found7 = word.find(",");
		if (found7 >= 0) { word.replace(found7,1,""); }
 
		int found8 = word.find(":");
		if (found8 >= 0) { word.replace(found8,1,""); }

		int found9 = word.find("-");
		if (found9 >= 0) { word.replace(found9,1,"\n"); }
 
		int found10 = word.find("\"");
		while (found10 >= 0)
		{
			word.replace(found10,1,"");
			found10 = word.find("\"");
		}
		//if the word is a number, set the boolean variable to true,
		// so the number does not get printed
		int find = word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
		if (find >= 0)
		{
			flag = true;
		}
		
		// now open the dictionary file to compare the word to every word
		// in the dictionary file
		dictionary.open("dictionary.txt");

		//if there are errors with the dictionary file tell the user
		if (dictionary.fail())
		{
			cerr << "File " << "dictionary.txt" << " could not be opened.\n";
			exit(1);
		}
		
		//loop to determine whether the word matches a dictionary
		// word or not
		while (!(dictionary.eof()))
		{
			dictionary >> dictword;
			if(stricmp(word.c_str(),dictword.c_str()) == 0)
				{
					flag = true;	
				}
		}
				
			if (flag == false)
			{
				cout << word << endl;
			}
			// close the dictionary file
			dictionary.close();
		
}
	

//close the inputfile and terminate the program

inputfile.close();
cout << "\n";
return 0;
}










