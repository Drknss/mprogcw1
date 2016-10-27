#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class common
{
public:
	common();
	~common();
	string readin(string file_location);
	vector<string> readinlbl(string filename);
	void printtofile(string file, string content);
	void printtofilelbl(string file, vector<string> content);
};