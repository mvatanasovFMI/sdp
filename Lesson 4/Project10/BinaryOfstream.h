#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
class BinaryOfstream : public ofstream {
public:
	BinaryOfstream(const char * filePathInput) :
		ofstream(filePathInput)
	{
		if (!this->is_open())
		{
			cerr << "error: open file for output failed!" << endl;
			abort();
		}
	}
	friend BinaryOfstream & operator << (BinaryOfstream & out, char* fileData);
};

BinaryOfstream & operator << (BinaryOfstream & out, char * fileData)
{
	out.write((char *)fileData, strlen(fileData));
	return out;
}
