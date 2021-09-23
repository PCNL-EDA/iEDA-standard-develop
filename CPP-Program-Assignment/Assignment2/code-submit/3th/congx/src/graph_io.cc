#include "graph_io.h"

namespace pather {

void GraphIO::read(const std::string& file,
                   std::vector<std::vector<char>>& map) const {
  std::ifstream ifs(file);
  if (!ifs) {
    std::cout << "Fail to open the file!" << std::endl;
    exit(0);
  }
  std::string line;
  while (std::getline(ifs, line)) {
    std::istringstream iss(line);
    std::istream_iterator<char> is_iter(iss);
    std::istream_iterator<char> is_eof;
    map.push_back(std::vector<char>(is_iter, is_eof));
  }
  ifs.close();
}

void GraphIO::write(const std::vector<std::vector<char>>& map) const {
  for (auto rows : map) {
    for (auto cell : rows) {
      if (cell == kTrack) {
        std::cout << "\033[44m";
      } else if (cell == kBarrier) {
        std::cout << "\033[41m";
      }
      std::cout << "  "
                << "\033[0m";
    }
    std::cout << "\n";
  }
}

}  // namespace pather
