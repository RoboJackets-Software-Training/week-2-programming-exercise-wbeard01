#pragma once

#include <string>

class NumberConverter {
public:
	NumberConverter(int din, int bin, int hin, int dout, int bout, int hout);
	~NumberConverter();
	int hexCharToNumber(char input);
	char numberToHexChar(int input);
	int hexToDecimal(std::string input);
	int binaryToDecimal(std::string input);
	std::string decimalToHex(int input);
	std::string binaryToHex(std::string input);
	std::string decimalToBinary(int input);
	std::string hexToBinary(std::string input);
private:
	int decimal_inputs;
	int binary_inputs;
	int hex_inputs;
	int decimal_outputs;
	int binary_outputs;
	int hex_outputs;
};