#include "encoder.h"
#include <iostream>
using namespace std;

encoder::encoder()
{
	
}

string encoder::xorgate(char a, char b){
	return to_string(((int)a + (int)b) % 2);
}

string encoder::xorgate(char a, char b, char c) {
	int ta = (((int)a + (int)b) % 2);
	return to_string((ta + (int)c) % 2);
}

string encoder::encode(string file, int x1, int x2, int x3, int x4, int xorc1, int xorc2) {
	string coded;
	string encode = "000" + file;

	for (int i = 0; i < encode.length()-3; i++) {
		char r3 = encode[(i+x1)];
		char r2 = encode[(i+x2)];
		char r1 = encode[(i+x3)];
		char i1 = encode[(i+x4)];
		if (xorc1 == 2 && xorc2 == 2) {
			coded += xorgate(i1, r1) + xorgate(r2, r3);
		}
		if (xorc1 == 3 && xorc2 == 2) {
			coded += xorgate(i1, r1, r2) + xorgate(r2, r3);
		}
		if (xorc1 == 2 && xorc2 == 3) {
			coded += xorgate(i1, r1) + xorgate(r1, r2, r3);
		}
		if (xorc1 == 3 && xorc2 == 3) {
			coded += xorgate(i1, r1, r2) + xorgate(r1, r2, r3);
		}
	}

	return coded;

}

encoder::~encoder()
{
}
