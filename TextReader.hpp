#ifndef TEXT_READER
#define TEXT_READER

#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

/***************************************************************
Student Name: Daniel Tran
File Name: TextReader.hpp
Assignment number: Project 1

This header file declares the CreateTextFile method for this
class.
***************************************************************/

class TextReader
{
	public:
		void CreateTextFile(std::string infile, std::string outfile, bool encrypt);
};

#endif