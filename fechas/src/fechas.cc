#include <iostream>
#include <vector>
#include <fstream>
#include "fecha.h"

int main(int argc, char* argv[]) {
	//Usage(argc, argv);

	size_t last = 0;
	size_t next = 0;
	int limit = std::atoi(argv[2]);
	std::string raw_date_string = argv[1];
	std::vector<std::string> raw_date;
	raw_date.reserve(3);
	
	while ((next = raw_date_string.find("/", last)) != std::string::npos) {   
		raw_date.emplace_back(raw_date_string.substr(last, next - last));
		last = next + 1;
	}
	raw_date.emplace_back(raw_date_string.substr(last));

	Date date = Date(std::stoi(raw_date[0]), std::stoi(raw_date[1]), std::stoi(raw_date[2]));

	std::ofstream file(argv[3]);
	file << date << '\n';

	for (int i = 0; i < limit; i++) {
		date.NextDate();
		file << date << '\n';
	}

	file.close();

	return 0;
}