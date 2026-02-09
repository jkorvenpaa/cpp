#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	
	if (argc != 4){
		std::cerr << "Arguments expected:\n" << argv[0] <<
		" <filename> <StringToReplace> <NewString>\n";
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() || s2.empty()){
		std::cerr << "empty string as an argument\n";
		return 1;
	}
	std::string replace = filename + ".replace";
	std::ifstream infile(filename);
	if (!infile){
		std::cerr << "Opening file failed\n";
		return 1;
	}
	std::ofstream outfile(replace);
	if (!outfile){
		infile.close();
		std::cerr << "Creating file failed\n";
		return 1;
	}
	while (1){
		std::string line;
		if (!std::getline(infile, line))
			break;
		while (1){
			size_t pos = line.find(s1);
			if (pos == std::string::npos)
				break;
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length(), line.length());
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}