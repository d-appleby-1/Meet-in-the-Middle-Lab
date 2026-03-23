#include <iostream>
#include <fstream>
#include <string>

#include "src/meet.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  string filename;
  cout << "Enter CSV filename: ";
  cin >> filename;
  std::ifstream in(filename);
  if (!in.is_open()) {
    std::cerr << "Error: Could not open file.\n";
  }
  int capacity = 10;
  int size = 0;
  int* data = new int[capacity];
  string line;
  if (getline(in, line)) {
    string number = "";
    for (char c : line) {
      if (c == ',') {
        if (!number.empty()) {
          append(data, size, capacity, stoi(number));
          number = "";
        }
      } else {
        number += c;
      }
    }
    if (!number.empty()) {
      append(data, size, capacity, stoi(number));
    }
  }
  in.close();
  if (size == 0) {
    cout << "No data found.\n";
    delete[] data;
    return 0;
  }
  double median;
  if (size % 2 == 1) {
    median = data[size / 2];
  } else {
    median = (data[size / 2 - 1] + data[size / 2]) / 2.0;
  }
  cout << "Median: " << median << endl;
  delete[] data;
}