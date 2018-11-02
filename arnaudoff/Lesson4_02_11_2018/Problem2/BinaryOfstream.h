#pragma once
#include <fstream>
#include <iostream>

#include <cstring>

using namespace std;

class BinaryOfstream : public ofstream {
	private:
		int charSize_;

	public:
		BinaryOfstream(const char* fname) :
			ofstream(fname, ios::binary) {
			if (!is_open()) {
				cerr << "error: open file for output failed!" << endl;
				abort();
			}
		}

		void SetSize(int size) {
			charSize_ = size;
		}

		friend BinaryOfstream& operator << (BinaryOfstream& out, char* ptr);
};

template <typename T>
BinaryOfstream& operator<<(BinaryOfstream& out, T& data) {
	out.write((char*)&data, sizeof(T));
	return out;
}

BinaryOfstream& operator<<(BinaryOfstream& out, char* ptr) {
	out.write(ptr, out.charSize_);
	return out;
}