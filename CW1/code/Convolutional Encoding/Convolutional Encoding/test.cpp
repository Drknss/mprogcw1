#include <iostream>
#include<limits>
#include "encoder.h"
#include "common.h"
#include <vector>

using namespace std;

void generate(string file, encoder* e, vector<string> *results, vector<string> *perm) {
	int count = 0; //testing
	//loops through first Xor gate configurations, 2 or 3 inputs
	for (int i = 0; i < 2; i++) {
		//loops through 2nd Xor gate configurations, 2 or 3 inputs
		for (int j = 0; j < 2; j++) {
			//loops through bit positions for input and registers
			for (int a = 0; a < 4; a++) {
				for (int b = 0; b < 4; b++) {
					for (int c = 0; c < 4; c++) {
						for (int d = 0; d < 4; d++) {
							bool dupe = false;
							//encodes file with current configuration
							string encoded = e->encode(file, a, b, c, d, 2+i, 2+j);
							//for every currently in the vector find out if it already exists
							for (int it = 0; it < results->size(); it++) {
								if (!encoded.compare(results->at(it))) {
									dupe = true;									
									//cout << "dupe?" << endl;
									break;
								}

							}
							//if the encryption isn't a dupe add it and its permutation format to the vectors.
							if (dupe == false) {
								results->push_back(e->encode(file, a, b, c, d, i+2, j+2));
								string permutation = "r0 = " + to_string(a) + " r1 = " + to_string(b) + " r2 = " + to_string(c) + " input = " + to_string(d) + " xor1c = " + to_string(i+2) + " xor2c = " + to_string(j+2);
								perm->push_back((permutation));
							}
							count++; //testing
						}
					}
				}
			}
		}
	}
	cout << count; //testing
}

int main() {
	encoder* e = new encoder();
	common* c = new common();
	vector<string> *results = new vector<string>;
	vector<string> *perm = new vector<string>;
	int x = 0;
	string filename1;
	string filename2;
	string command = "del /Q ";
	string path = "Results\\*.txt";
	int r1;
	int r2;
	int r3;
	int i1;
	int xor1c;
	int xor2c;
	cout << "Menu" << endl;
	cout << "Please enter the apropriate number for the function you wish to exicute;" << endl;
	cout << "1; Generate Unique Encryptions" << endl;
	cout << "2; Generate Encryption Based Off your Input" << endl;
	cout << "3; Delete All the Encoded files" << endl;
	cout << "4; Exit" << endl;
	while (x != -5) {
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		switch (x)
		{
		case 1:
			cout << "Generating Unique Encrytions, based off of bainaryFile.txt" << endl;
			generate(c->readin("binaryFile.txt"), e, results, perm);
			for (int it = 0; it < results->size(); it++) {
				c->printtofile("Results\\" + perm->at(it), results->at(it));
			}
			cout << "Generation Completed" << endl;
			cout << "Please enter the apropriate number for the function you wish to exicute;" << endl;
			cout << "1; Generate Unique Encryptions" << endl;
			cout << "2; Generate Encryption Based Off your Input" << endl;
			cout << "3; Delete All the Encoded files" << endl;
			cout << "4; Exit" << endl;
			break;
		case 2:
			cout << "You are now in the individual configuration setting";
			cout << "Please enter the name of the file that contains the source data" << endl;
			cin >> filename1;
			cout << "Please enter the name of the file that you wish to print data to" << endl;
			cin >> filename2;
			cout << "Please enter the number of paramaters for the first Xor gate, it can handle 2 or 3" << endl;
			cin >> xor1c;
			cout << "Please enter the number of paramaters for the second Xor gate, it can handle 2 or 3" << endl;
			cin >> xor2c;
			cout << "Please enter the integer position of the first bit, between 0 and 3" << endl;
			cin >> r1;
			cout << "Please enter the integer position of the second bit, between 0 and 3" << endl;
			cin >> r2;
			cout << "Please enter the integer position of the third bit, between 0 and 3" << endl;
			cin >> r3;
			cout << "Please enter the integer position of the fourth bit, between 0 and 3" << endl;
			cin >> i1;
			c->printtofile(filename2, e->encode(c->readin(filename1), r1, r2, r3, i1, xor1c, xor2c));
			cout << "Encoding completed" << endl;
			cout << "Please enter the apropriate number for the function you wish to exicute;" << endl;
			cout << "1; Generate Unique Encryptions" << endl;
			cout << "2; Generate Encryption Based Off your Input" << endl;
			cout << "3; Delete All the Encoded files" << endl;
			cout << "4; Exit" << endl;
			break;
		case 3:
			cout << "Deleting all .txt Files" << endl;
			system(command.append(path).c_str());
			break;
		case 4:
			cout << "Now exiting from program" << endl;
			cout << "Bye Bye";
			x = -5;
			break;
		default:
			cin.clear();
			cout << "Please enter a valid option" << endl;
		}
	}
	delete results;
	delete perm;
}