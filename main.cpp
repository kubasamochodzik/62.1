#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

int main() {

  std::ifstream input("liczby1.txt");
  std::ofstream output("wynik.txt");
  std::istream_iterator < unsigned > start(input), end;
  std::vector < unsigned > buffer_oct(start, end);
  input.close();
  std::vector < unsigned > buffer_dec;
  for (std::vector < unsigned > ::iterator it = buffer_oct.begin(); it != buffer_oct.end(); ++it) {
    std::stringstream ss;
    unsigned n;
    ss << * it;
    ss >> std::oct >> n;
    buffer_dec.push_back(n);
  }
  std::vector < unsigned > ::iterator result_min = std::min_element(buffer_dec.begin(), buffer_dec.end());
  std::vector < unsigned > ::iterator result_max = std::max_element(buffer_dec.begin(), buffer_dec.end());
  output << "62.1\n\tMin: " << std::oct << buffer_dec.at(std::distance(buffer_dec.begin(), result_min)) 
  <<"\n\tMax: " << buffer_dec.at(std::distance(buffer_dec.begin(), result_max)) << std::endl;
  output.close();

}
