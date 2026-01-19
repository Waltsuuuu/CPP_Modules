#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
	// ./replace <filename> <str_to_replace> <str_to_replace_with>
	if (argc != 4) {
		std::cout << "Usage: ./replace <filename> <str_to_replace> <str_to_replace_with>\n";
		return (1);
	}

	// 1. Open the <filename> argv[1]
	std::ifstream	inputFile(argv[1]);
	
	// 2. Create and open output file called <filename>.replace
	std::string		fileName = (std::string)argv[1] + ".replace";
	std::ofstream	outputFile(fileName);
	
	// 3. Copy 'inputFile' lines into 'outputFile', 
	// Where every occurance of (argv[2]) is replaced with (argv[3]).
	std::string		toReplace = argv[2];
	std::string		replaceWith = argv[3];
	std::string		line;
	while (getline(inputFile, line)) {
		size_t pos = line.find(toReplace);
		while (pos != std::string::npos) {
			line.erase(pos, toReplace.length());
			line.insert(pos, replaceWith);
			pos += replaceWith.length();
			pos = line.find(line, pos);
		}
		outputFile << line;
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}