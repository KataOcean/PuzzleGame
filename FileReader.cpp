#include <fstream>
#include <iostream>
#include "FileReader.h"
#include <iterator>

using namespace std;

FileReader::FileReader(const char* path) {
	this->Data = NULL;
	this->FileSize = 0;

	ifstream stream;

	stream.open(path, ios::in || ios::binary);
	if (stream.fail()) {
		cout << "�X�e�[�W�f�[�^�ǂݍ��݃G���[:" << path << endl;
		exit(1);
	}

	// �t�@�C���T�C�Y�ǂݍ���
	istreambuf_iterator<char> it(stream);
	istreambuf_iterator<char> last;

	Data = new string(it, last);
}

FileReader::~FileReader() {
	delete Data;
}

string FileReader::GetData() {
	return *Data;
}