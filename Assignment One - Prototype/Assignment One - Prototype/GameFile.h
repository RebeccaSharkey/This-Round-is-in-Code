#pragma once
#include <vector>
#include <string>
using namespace std;

class GameFile
{
private:
	string fileName;
	vector<string> data;
public:
	GameFile(string name);
	~GameFile();
	void ReadFile();
	string GetName();
	int GetVecSize();
	string GetString(int i);
	void RemoveString(int i);
};

