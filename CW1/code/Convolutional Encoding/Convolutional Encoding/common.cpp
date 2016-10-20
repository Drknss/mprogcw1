#include "common.h"

common::common()
{
}


common::~common()
{
}

int common::xorgate(int a, int b) {
	if (a == 0 && b == 1 || a == 1 && b == 0) {
		return 1;
	}
	return 0;
}

void common::readin(string file_location) {
	string line;
	ifstream file (file_location);
	if (file.is_open()) {
		while (getline(file, line)) {
			line += line;
		}
		file.close;
	}
	else(
		cout << "Error opening file" << endl;
	)
}

void common::printfile() {}
