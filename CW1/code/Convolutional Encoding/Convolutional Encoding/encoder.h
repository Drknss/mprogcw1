#pragma once
#include "common.h"

class encoder
{
public:
	encoder();
	string xorgate(char a, char b);
	string xorgate(char a, char b, char c);
	string encode(string file, int x1, int x2, int x3, int x4, int xorc1, int xorc2);
	~encoder();
	//void func(int in, int r1, int r2, int r3);	
private:

};

