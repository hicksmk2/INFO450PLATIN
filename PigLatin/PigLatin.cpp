// PigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
using namespace std;

const int MAX = 500;										// Sets a global variable for line length

int translatetoPigLatin(char ph[MAX], char engPhrase[MAX]);
bool isVowel(char ch);

int main()
{
	char answer = 'y';
	char ph[MAX];
	char engPhrase[MAX];								//Declares a character array of 500 characters

	cout << "\t\t*****************************************************" << endl;
	cout << "\t\t*        Greetings User and welcome to the          *" << endl;
	cout << "\t\t*     English Language to Pig-Latin Converter       *" << endl;
	cout << "\t\t*  --------------------*****------------------------*" << endl;
	cout << "\t\t*  Please type in your desired word or phrase and   *" << endl;
	cout << "\t\t*               enjoy the difference                *" << endl;
	cout << "\t\t*****************************************************" << endl << endl;

	do
	{
		cout << "Insert sentence: ";
		cin.getline(engPhrase, MAX);
		cout << endl;


		cout << "You entered the following sentence: " << engPhrase << endl;		// Display the phrase entered by the user
		cout << endl;

		translatetoPigLatin(ph, engPhrase);
		cout << "Your text translates to: " << ph;
		cout << endl;

		cout << "\nWould you like to try another word? Press Y for 'yes', otherwise press another key for 'no': ";	 // Asks the user if they wish to try another phrase
		cin >> answer;
		cout << "============================================================================================\n";
		cin.ignore(MAX, '\n');

	} while (answer == 'y' || answer == 'Y');

	return 0;
}

bool isVowel(char ch)
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

int translatetoPigLatin(char ph[MAX], char engPhrase[MAX])
{
	

	if (engPhrase[0] == '\0' || engPhrase[0] == '1' || engPhrase[0] == '2' || engPhrase[0] == '3' || engPhrase[0] == '4' ||
		engPhrase[0] == '5' || engPhrase[0] == '6' || engPhrase[0] == '7' || engPhrase[0] == '8' || engPhrase[0] == '0')
	{
		return -1;
	}
	else if (isVowel(engPhrase[0]))
		{
			strcat(ph, engPhrase);
			strcat(ph, "ay");
		}

		else
		{
			int i = 1;
			int end = strlen(ph) - 1;
			for (; i <= end; i++)
			{
				ph[i - 1] = engPhrase[i];
			}
			ph[strlen(engPhrase) - 1] = engPhrase[0];
			strcat(engPhrase, "ay");
		}
	return 0;
	}
