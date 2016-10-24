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
			//file.close;
			return file_contents;
		}		
	}
	catch(std::exception &ex){
		throw std::runtime_error("Could not open file");
	}
}

void common::printtofile(string file, string content) {
	try {
		ofstream out(file + ".txt");
		out << content;
		//out.close;
	}
	catch (std::exception &ex) {
		throw std::runtime_error("Could not open file");
	}
}
