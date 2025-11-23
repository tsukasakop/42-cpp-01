#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return str;
	
	std::string result;
	size_t pos = 0;
	size_t lastPos = 0;
	
	while ((pos = str.find(s1, lastPos)) != std::string::npos) {
		result.append(str, lastPos, pos - lastPos);
		result.append(s2);
		lastPos = pos + s1.length();
	}
	result.append(str, lastPos, std::string::npos);
	
	return result;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	// 入力ファイルを開く
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}
	
	// 出力ファイル名を作成
	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		infile.close();
		return 1;
	}
	
	// ファイルの内容を行ごとに読み込み、置換して書き込む
	std::string line;
	while (std::getline(infile, line)) {
		std::string replaced = replaceAll(line, s1, s2);
		outfile << replaced;
		if (!infile.eof())
			outfile << std::endl;
	}
	
	infile.close();
	outfile.close();
	
	std::cout << "File " << outfilename << " created successfully" << std::endl;
	return 0;
}
