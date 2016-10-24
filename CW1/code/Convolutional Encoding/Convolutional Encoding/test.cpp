#include <iostream>
#include "encoder.h"
#include "common.h"
#include <vector>

using namespace std;

void generate(string file, encoder* e, vector<string> *results, vector<string> *perm) {
	int c = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int a = 0; a < 4; a++) {
				for (int b = 0; b < 4; b++) {
					for (int c = 0; c < 4; c++) {
						for (int d = 0; d < 4; d++) {
							bool dupe = false;
							string encoded = e->encode(file, a, b, c, d, 2 + i, 2 + j);
							for (int it = 0; it < results->size(); it++) {
								if (encoded.compare(results->at(it))) {
									dupe = true;
								}
							}
							if (dupe == false) {
								results->push_back(e->encode(file, a, b, c, d, 2 + i, 2 + j));
								string permutation = "r0 = " + to_string(a) + " r1 = " + to_string(b) + " r2 = " + to_string(c) + " input = " + to_string(d) + " xor1c = " + to_string(i+2) + " xor2c = " + to_string(j+2);
								perm->push_back((permutation));
							}
							c++;
						}
					}
				}
			}
		}
	}
}

int main() {
	encoder* e = new encoder();
	common* c = new common();
	vector<string> *results = new vector<string>;
	vector<string> *perm = new vector<string>;
	generate(c->readin("binaryFile.txt"), e, results, perm);
	//c->printtofile("coded", e->encode(c->readin("binaryFile.txt")));
	for (int it = 0; it < results->size(); it++) {
		c->printtofile("Results\\" + perm->at(it), results->at(it));
	}
	system("PAUSE");
}