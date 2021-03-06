/* PigLatin.cpp : Defines the entry point for the console application.
Author: Malik Hicks
Program Description:  This program serves the purpose to tranlate an English word into one that is Pig-Latin
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

const int MAX = 51;													// Declares a constant interger of 51 to allocate character space

int translatetoPigLatin(char engPhrase[MAX], char pigPhrase[MAX]);
bool isVowel(char ch);
bool isConjunction(char engPhrase[MAX]);


int main()
{
	cout << "\t\t*****************************************************" << endl;				// Outputs the instructions to the user
	cout << "\t\t*        Greetings User and welcome to the          *" << endl;
	cout << "\t\t*     English Language to Pig-Latin Converter       *" << endl;
	cout << "\t\t*  --------------------*****------------------------*" << endl;
	cout << "\t\t*  Please type in your desired word or engPhrase and   *" << endl;
	cout << "\t\t*               enjoy the difference                *" << endl;
	cout << "\t\t*****************************************************" << endl << endl;

	bool isValid = true;
	do
	{
		char again;
		char engPhrase[MAX] = "";
		char pigPhrase[MAX] = "";

		cout << "============================================================================================\n";
		cout << "Insert word/engPhrase: ";
		cin.getline(engPhrase, MAX);
		cout << "*" << endl;

		cout << "Your word is " << engPhrase << "." << endl;
		cout << "*" << endl;

		if (translatetoPigLatin(engPhrase, pigPhrase) == 0)
		{
			cout << "Your text translates to: " << pigPhrase << endl;
			cout << "*\nWould you like to try another word? Press Y for 'yes', otherwise press another key for 'no': ";	 //Prompts the user to enter "y" or "Y" if they wish to try again
			cin >> again;
			cout << "============================================================================================\n";

			if (again == 'y' || again == 'Y')
			{
				isValid = true;
			}
			else
			{																								//Outputs a message should the use say no to repeating the message
				cout << endl;
				cout << "\t\t*****************************************************" << endl;
				cout << "\t\t*         Thank you so much for using our           *" << endl;
				cout << "\t\t*          English to Pig-Latin Converter           *" << endl;
				cout << "\t\t*  --------------------*****------------------------*" << endl;
				cout << "\t\t*           Please have an amazing day!             *" << endl;
				cout << "\t\t*             Enjoy it to the fullest               *" << endl;
				cout << "\t\t*****************************************************" << endl << endl;
				isValid = false;
			}
		}
		else
		{
			cout << "UH OH! It seems your input was wrong. Press ENTER to try again." << endl;
			isValid = true;
		}

		cin.ignore(MAX, '\n');
	} while (isValid == true);
	return 0;
}


int translatetoPigLatin(char engPhrase[MAX], char pigPhrase[MAX])		// Begins the translation of the english word to pigLatin
{

	if (engPhrase[0] == '\0')
	{
		return -1;
	}

	else if (engPhrase[0] == '1' || engPhrase[0] == '2' || engPhrase[0] == '3' || engPhrase[0] == '4' ||
		engPhrase[0] == '5' || engPhrase[0] == '6' || engPhrase[0] == '7' || engPhrase[0] == '8' || engPhrase[0] == '0')
	{
		return -1;
	}

	else if (engPhrase[2] == '\0')				//Verifies if the word is only two characters by checking for a null space
	{
		strcpy(pigPhrase, engPhrase);
	}

	else if (isConjunction(engPhrase) == true)
	{
		strcat(pigPhrase, engPhrase);
	}

	else if (isVowel(engPhrase[0]))					// Returns back to the isVowel function to check if the first character is a vowel
	{
		strcat(pigPhrase, engPhrase);
		strcat(pigPhrase, "ay");
	}

	else
	{
		int i = 1;
		int end = strlen(engPhrase) - 1;
		for (; i <= end; i++)
		{
			pigPhrase[i - 1] = engPhrase[i];
		}
		pigPhrase[strlen(engPhrase) - 1] = engPhrase[0];
		strcat(pigPhrase, "ay");
	}

	return 0;
}

bool isVowel(char ch)								/* Checks through several cases that represent vowels and returns true if the initial character is a vowel
													and returns true, otherwise it returns false
													*/
{
	switch (ch)
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
	default:
		return false;
	}
}

bool isConjunction(char engPhrase[MAX])

{

	bool conjunction;

	engPhrase[MAX] = tolower(engPhrase[MAX]);



	if (engPhrase == "the" || engPhrase == "a" || engPhrase == "an" || engPhrase == "but" || engPhrase == "and" ||
		engPhrase == "for" || engPhrase == "so" || engPhrase == "nor" || engPhrase == "yet" || engPhrase == "or" ||
		engPhrase == "The" || engPhrase == "A" || engPhrase == "An" || engPhrase == "But" || engPhrase == "And" ||
		engPhrase == "For" || engPhrase == "So" || engPhrase == "Nor" || engPhrase == "Yet" || engPhrase == "Or")
	{
		conjunction = true;
	}

	else

	{
		conjunction = false;
	}

	return conjunction;

}
