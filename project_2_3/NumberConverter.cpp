#include <string>
#include "NumberConverter.h"

NumberConverter::NumberConverter(int din, int bin, int hin, int dout, int bout, int hout) {
  decimal_inputs = din;
  binary_inputs = bin;
  hex_inputs = hin;
  decimal_outputs = dout;
  binary_outputs = bout;
  hex_outputs = hout;

}

NumberConverter::~NumberConverter() {
  std::cout << "decimal_inputs: " << decimal_inputs << std::endl;
  std::cout << "binary_inputs: " << binary_inputs << std::endl;
  std::cout << "hex_inputs: " << hex_inputs << std::endl;
  std::cout << "decimal_outputs: " << decimal_outputs << std::endl;
  std::cout << "binary_outputs: " << binary_outputs << std::endl;
  std::cout << "hex_outputs: " << hex_outputs << std::endl;
}

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

int NumberConverter::binaryToDecimal(std::string input) {
  int ans = 0;
  int mult = 1;
  for (int i = input.length() - 1; i >= 0; i--) {
    if (input[i] == '1') {
      ans += mult;
    }
    mult *= 2;
  }
  return ans;
}

int NumberConverter::hexToDecimal(std::string input) {
  hex_inputs++;
  decimal_outputs++;
  int ans = 0;
  int mult = 1;
  for (int i = input.length() - 1; i >= 0; i--) {
    ans += hexCharToNumber(input[i]) * mult;
    mult *= 16;
  }
  return ans;
}

std::string NumberConverter::decimalToBinary(int input) {
  decimal_inputs++;
  binary_outputs++;
  int largestPower = 1;
  while (2 * largestPower <= input) {
    largestPower *= 2;
  }
  std::string ans = "";
  while (largestPower >= 1) {
    if (input / largestPower >= 1) {
      ans += "1";
      input -= largestPower;
    } else {
      ans += "0";
    }
    largestPower /= 2;
  }
  while (ans.length() % 4 != 0) {
    ans = "0" + ans;
  }
  return ans;
}

std::string NumberConverter::hexToBinary(std::string input) {
  decimal_outputs--;
  decimal_inputs--;
  return decimalToBinary(hexToDecimal(input));
}

std::string NumberConverter::decimalToHex(int input) {
  decimal_inputs++;
  hex_outputs++;
  int largestPower = 1;
  while (16 * largestPower <= input) {
    largestPower *= 16;
  }
  std::string ans = "";
  while (largestPower >= 1) {
    if (input / largestPower >= 1) {
      ans += numberToHexChar(input / largestPower);
      input -= (input / largestPower) * largestPower;
    } else {
      ans += "0";
    }
    largestPower /= 16;
  }
  return ans;
}

std::string NumberConverter::binaryToHex(std::string input) {
  decimal_outputs--;
  decimal_inputs--;
  return decimalToHex(binaryToDecimal(input));
}