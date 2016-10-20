#pragma once
#include <string>
#include <fstream>

using namespace std;

class common
{
public:
	common();
	~common();
	int xorgate(int a, int b);
	void readin(string file_location);
	void printfile();
};

