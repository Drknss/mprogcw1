#include "common.h"

common::common()
{
}

common::~common()
{
}

string common::readin(string file_location) {
	try {
		ifstream file(file_location);
		if (file.is_open()) {
			string file_contents{ istreambuf_iterator<char>(file), istreambuf_iterator<char>() };
			file.close();
			return file_contents;
		}
	}
	catch (std::exception &ex) {
		throw std::runtime_error("Could not open file");
	}
}

vector<string> common::readinlbl(string filename) {
	vector<string> lines;
	string line;
	try {
		ifstream file(filename);
		if (file.is_open()) {
			while (getline(file, line)) {
				lines.push_back(line);
			}
			file.close();
			return lines;
		}
	}
	catch (std::exception &ex) {
		throw std::runtime_error("Could not open file");
	}
}

void common::printtofile(string file, string content) {
	string fname = file + ".txt";
	ofstream out(fname);
	out << content;
	out.close();
}

void common::printtofilelbl(string file, vector<string> content) {
	string fname = file + ".txt";
	ofstream out(fname);
	if (out.is_open()) {
		for each (string s in content) {
			out << s << endl;
		}
	}
}