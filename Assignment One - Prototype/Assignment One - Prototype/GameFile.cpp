#include "GameFile.h"
#include <fstream>

GameFile::GameFile(string name)
{
	fileName = name;
	ReadFile();
}

GameFile::~GameFile()
{
	data.clear();
}

void GameFile::ReadFile()
{
	data.clear();
	ifstream txtFile("Data/" + fileName + ".txt");
	string placeHolder;
	if (txtFile.is_open())
	{
		while (!txtFile.eof())
		{
			getline(txtFile, placeHolder);
			data.push_back(placeHolder);
		}
		txtFile.close();
	}
}

string GameFile::GetName()
{
	return fileName;
}

int GameFile::GetVecSize()
{
	return data.size();
}

string GameFile::GetString(int i)
{
	if (i >= 0 && i < data.size())
	{
		return data[i];
	}
}

void GameFile::RemoveString(int i)
{
	data.erase(data.begin() + i);
}