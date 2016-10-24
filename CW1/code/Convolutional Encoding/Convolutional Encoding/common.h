#pragma once
#include <string>
#include <fstream>

using namespace std;

class common
{
public:
	common();
	~common();
	string readin(string file_location);
	void printtofile(string file, string content);
};

