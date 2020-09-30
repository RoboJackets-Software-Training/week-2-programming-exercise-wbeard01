#include <string>
#include <iostream>
#include <vector>
#include "NumberConverter.cpp"

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
	std::string line;
	std::cin >> line;
	std::vector initial_values = readInVector(line);
	char output_type;
	std::cin >> output_type;
	std::string input;
	std::cin >> input;

	std::string out;
	NumberConverter nc(initial_values[0], initial_values[1], initial_values[2], initial_values[3], initial_values[4], initial_values[5]);
	if (input.find("x") != std::string::npos) {
		std::cout << "input: " << input.substr(2) << std::endl;
		if (output_type == 'b') {
			out = nc.hexToBinary(input.substr(2));
		} else if (output_type == 'd') {
			out = std::to_string(nc.hexToDecimal(input.substr(2)));
		} else {
			out = input;
		}
	} else if (input.find("b") != std::string::npos) {
		std::cout << "input: " << input.substr(1) << std::endl;
		if (output_type == 'd') {
			out = std::to_string(nc.binaryToDecimal(input.substr(1)));
		} else if (output_type == 'x') {
			out = nc.binaryToHex(input.substr(1));
		} else {
			out = input;
		}
	} else {
		std::cout << "input: " << input << std::endl;
		if (output_type == 'h') {
			out = nc.decimalToHex(std::stoi(input));
		} else if (output_type == 'b') {
			out = nc.decimalToBinary(std::stoi(input));
		} else {
			out = input;
		}
	}
	std::cout << "output type: " << output_type << std::endl;
	std::cout << "result: " << out << std::endl;
}