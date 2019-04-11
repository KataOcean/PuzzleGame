#pragma once

#include <string>

using namespace std;

class FileReader {
private:
	string *Data;
	int FileSize;
public:
	FileReader(const char *path);
	~FileReader();

	string GetData();
};