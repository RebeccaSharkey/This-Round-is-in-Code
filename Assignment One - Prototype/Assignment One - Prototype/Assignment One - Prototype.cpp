#include "GameFile.h"
#include <iostream>
#include <random>
using namespace std;

string Substitute(string& input)
{
	string placeHolder;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			input[i] = toupper(input[i]);
			placeHolder += to_string(int(input[i]) - 64) + " ";
		}
		else
		{
			placeHolder += "   ";
		}
	}
	return placeHolder;
}

int RandomNumber(int size)
{
	random_device rand;
	default_random_engine randEngine(rand());
	uniform_int_distribution<int> distribution(0, size - 1);
	return distribution(randEngine);
}

int main()
{
	vector<GameFile> gameFiles;
	gameFiles.push_back(GameFile("Hobbit Characters"));
	gameFiles.push_back(GameFile("Premier League Teams"));
	gameFiles.push_back(GameFile("South American Countries"));

	cout << "Welcome to 'This Round is in Code' from the TV series 'Richard Osman's House of Games'! \n\nYou will be given a random category, from that category you will be presented with a \nword written in alpha-numeric code (i.e. 1=A, 2=B, 3=C, etc.) \n\nYou have to unscramble the codes to get a point. For each category \nthere will be 5 questions.\n\nGood Luck!\n\n";

	system("PAUSE");
	system("CLS");

	bool playing = true;
	while (playing)
	{
		int category = RandomNumber(gameFiles.size());
		cout << "This round will be on: " << gameFiles[category].GetName() << endl;

		int question = 1;
		int score = 0;
		system("PAUSE");


		while (question <= 5)
		{
			system("CLS");
			int randQuestion = RandomNumber(gameFiles[category].GetVecSize());

			string sWord = gameFiles[category].GetString(randQuestion);
			string cWord = Substitute(sWord);
			cout << "Question " << question << ": " << cWord << endl;

			string userInput;
			getline(cin, userInput);

			if (Substitute(userInput) == cWord)
			{
				cout << "Correct! 1 point! \n";
				score++;
			}
			else
			{
				cout << "Incorrect the answer was: " << gameFiles[category].GetString(randQuestion) << "\n";
			}

			gameFiles[category].RemoveString(randQuestion);
			question++;
			system("PAUSE");
		}

		gameFiles[category].~GameFile();
		gameFiles.erase(gameFiles.begin() + category);
		system("CLS");

		if (!gameFiles.empty())
		{
			cout << "Round over you scored " << score << "/5 \n\n" << "Do you wish to play again?\n 1. Yes\n 2. No\n";

			string input;
			getline(cin, input);
			system("CLS");

			if (input != "1")
			{
				playing = false;
				cout << "Thank you for playing!\n\n";
			}
		}
		else
		{
			playing = false;
			cout << "Round over you scored " << score << "/5 \n\n" << "You have played all categories available at this time, game will now end.\n\n";
		}
	}
}
