/*
Sam Schneider
Introductory Programmng
April 16, 2026
P12-2
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int wordCount(string fileName);			//Counts number of words in file
int charCount(string fileName);			//Counts number of characters in file
void pressEnterToContinue();			//Asks user to press enter to continue


int main() {
	string dataFile;					//File to use for analysis

	//Prompts user input
	cout << "Input File: ";
	getline(cin, dataFile);

	//Displays results
	cout << "Words: " << wordCount(dataFile) << endl;
	cout << "Characters: " << charCount(dataFile) << endl;

	//Prompts user to press enter
	pressEnterToContinue();

	//Ends program
	return 0;
}


/*
wordCount: Counts words in given text file
@param fileName - Name of text file to count words in
@return numwords - Number of words in text file (returns -1 in case of error)
*/
int wordCount(string fileName) {
	ifstream inFile;
	int numWords = 0;
	string word;
	inFile.open(fileName);

	if (inFile.fail()) {
		cout << "Error - Unable to read file\n";
		return -1;
	}

	while (inFile >> word) {

		for (int i = 0; i < word.length(); i++) {

			if (word[i] == '-' && i+1 < word.length()){

				if (word[i] == '-' && i < word.length() && word[i + 1] >= 'A' && word[i + 1] <= 'Z') {
					numWords++;
				}

				else if (word[i] == '-' && i < word.length() && word[i + 1] >= 'a' && word[i + 1] <= 'z') {
					numWords++;
				}

			}

		}

		for (int i = 0; i < word.length(); i++) {

			if (word[i] >= 'A' && word[i] <= 'Z') {
					numWords++;
					break;
			}

			else if (word[i] >= 'a' && word[i] <= 'z') {
					numWords++;
					break;
			}

			

		}

	}

	inFile.close();
	return numWords;

}

/*
pressEnterToContinue: Prompts user to press enter in order to continue program
*/
void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

/*
charCount: Counts characters in given text file
@param fileName - Name of text file to count characters in
@return numChars - Number of characters in text file exclusing spaces (returns -1 in case of error)
*/
int charCount(string fileName) {
	ifstream inFile;
	int numChars = 0;
	string word;
	inFile.open(fileName);

	char wordChar;

	

	if (inFile.fail()) {
		cout << "Error - Unable to read file\n";
		return -1;
	}

	while (inFile >> word) {

		for (int i = 0; i < word.length(); i++) {
			wordChar = word[i];
			
			if (wordChar >= 'A' && wordChar <= 'Z') {
				numChars++;
			}

			else if (wordChar >= 'a' && wordChar <= 'z') {
				numChars++;
			}

		}

	}

	inFile.close();
	return numChars;

}

