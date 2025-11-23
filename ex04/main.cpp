#include <iostream>
#include <fstream>
#include <string>

static std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return str;
	
	std::string result;
	size_t pos;
	size_t lastPos = 0;
	
	while ((pos = str.find(s1, lastPos)) != std::string::npos) {
		result.append(str, lastPos, pos - lastPos);
		result.append(s2);
		lastPos = pos + s1.length();
	}
	result.append(str, lastPos, str.size() - lastPos);
	
	return result;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}
	
	const std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		return 1;
	}
	
	std::string line;
	while (std::getline(infile, line)) {
		const std::string replaced = replaceAll(line, s1, s2);
		outfile << replaced << std::endl;
		if (outfile.fail()) {
			std::cerr << "Error: Write failed for " << outfilename << std::endl;
			return 1;
		}
	}
	
	if (infile.fail() && !infile.eof()) {
		std::cerr << "Error: Read failed for " << filename << std::endl;
		return 1;
	}
	
	std::cout << "File " << outfilename << " created successfully" << std::endl;
	return 0;
}
