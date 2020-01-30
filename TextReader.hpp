#ifndef TEXT_READER
#define TEXT_READER

#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

class TextReader
{
	public:
		void CreateTextFile(std::string infile, std::string outfile, bool encrypt);
};

#endif