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
		cout << "ステージデータ読み込みエラー:" << path << endl;
		exit(1);
	}

	// ファイルサイズ読み込み
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