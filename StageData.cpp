#include "StageData.h"
#include <fstream>
#include <iostream>

StageData::StageData(char fileName[1024]) {
	ifstream inputFile(fileName, ifstream::binary);
	inputFile.seekg(0, ifstream::end);

	int fileSize = static_cast<int>(inputFile.tellg());
	inputFile.seekg(0, ifstream::beg);

	char *data = new char[fileSize];
	inputFile.read(data, fileSize);

	std::cout.write(data, fileSize);
}