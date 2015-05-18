#include "UserInput.h"

/***
 * I'D USE REGEX, BUT C++'S LIBRARIES DOESN'T FULLY SUPPORT REGEX D:<
 ***/
using namespace std;

UserInput::UserInput() {
	// TODO Auto-generated constructor stub
//http://www.cplusplus.com/reference/string/string/find_first_of/
}

UserInput::~UserInput() {
	// TODO Auto-generated destructor stub
}

/*
 * @param input A string parameter for the input prompt.
 *
 * @return Takes in a string parameter as the input prompt. Returns an integer converted from string.
*/

int UserInput::readInt(string input)
{
	/***
	 * about atoi():
	 * <input> 		|| <return result>
	 * 123 			|| 123 (int)
	 * 00123 		|| 123 (int, leading zeros removed)
	 * -12			|| -12 (int)
	 * -012			|| -12 (int, leading zeros removed)
	 ***/
	int number;
	string text;

	/***
	//version 1: the most basic readInt without error checking.
	cout << input;
	getline(cin, text);
	number = atoi(text.c_str());

	***/

	//version 2: strict error checking, but probably inefficient
	/*****
	while(true)
	{
		try
		{
			cout << input;
			getline(cin, text);

			//error checking
			for(int i=0; i<text.length(); i++)
			{
				if(i==0 && text.length() == 1 && isdigit(text.at(0)) == 0)
				{
					//if input length is 1 and the input is not a digit.
					throw -1;
				}
				else if(i==0 && text.length() > 1)
				{
					//if input is longer than 1 character, at the first position
					if( text.compare(0,1,"-") == 0 || text.compare(0,1,"+") == 0)
					{
						//check to see if the number is positive or negative.
						//if the first character is not a + or -

						//if(isdigit(text.at(1)) == false)
						//{
						//	throw -2;
						//}
					}
					else if(isdigit(text.at(0)) == 0)
					{
						throw -3;
					}

				}
				else
				{
					if(isdigit(text.at(i)) == 0)
						throw -4;
				}
			}

			//successful input
			number = atoi(text.c_str());
			break;
		}
		catch(int x)
		{
			cout << "Input is not a number! error number " << x << endl;
		}
	}

	***/

	//version 3: another way to do it.
	while(true)
	{
		try
		{
			cout << input;
			getline(cin, text);

			stringstream convert(text);
			if(!(convert >> number))
				throw -1;
			break;
		}
		catch(int)
		{
			cout << "Input is not an int!" << endl;
		}
	}

	return number;
}

string UserInput::readString(string input)
{
	string text;
	cout << input;
	getline(cin, text, '\n'); //takes in all input until enter
	return text;
}

char UserInput::readChar(string input)
{
	string text;
	while(true)
	{
		cout << input;
		getline(cin, text, '\n');
		if(text.length() >= 2)
		{
			cout << "Input is not a character!" << endl;
		}
		else
		{
			break;
		}
	}
	//cout << "text.at(0) " << text.at(0) << endl;
	char userInput = text.at(0);
	//char returnThis = 'a';
	return userInput;
}

double UserInput::readDouble(string input)
{
	double number;
	//char text[128];
	string text= "";
	while(true)
	{

		try
		{
			cout << input;
			//fgets(text, 128, stdin);
			getline(cin, text);
			//cin >> text;
			//number = atof(text);
			stringstream convert(text);
			if(!(convert >> number))
				throw -1.1;
			break;
		}
		catch(double)
		{
			cout << "Input is not a double!" << endl;
		}
	}
	return number;
}

float UserInput::readFloat(string input)
{
	float number;

	string text= "";
	while(true)
	{

		try
		{
			cout << input;

			getline(cin, text);

			stringstream convert(text);
			if(!(convert >> number))
				throw -1.1;
			break;
		}
		catch(double)
		{
			cout << "Input is not a float!" << endl;
		}
	}
	return number;
}
