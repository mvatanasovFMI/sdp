#ifndef BINARIOFSTREAM
#define BINARIOFSTREAM
#endif // !BINARIOFSTREAM
#include <iostream>
#include <fstream>
using namespace std;


class BinaryOfstream: public ofstream {
private:
	int m_charSize;
public:
	BinaryOfstream(const char* fname) :
		ofstream(fname, ios::binary)
	{
		if (!this->is_open()) {
			cerr << "error: open file for output failed!" << endl;
			abort();
		}
	}
	void SetSize(int size)
	{
		m_charSize = size;
	}
	friend BinaryOfstream& operator << (BinaryOfstream&, char*);
};

template <typename DataType>
BinaryOfstream& operator << (BinaryOfstream& out, DataType& data)
{
	out.write((char*)&data, sizeof(DataType));
	return out;
}

BinaryOfstream& operator << (BinaryOfstream& out, char* ptr)
{
	out.write(ptr, strlen(ptr) + 1);
	return out;
}
