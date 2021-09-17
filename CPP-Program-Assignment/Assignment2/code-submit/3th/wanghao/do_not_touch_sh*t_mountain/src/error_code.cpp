#include "error_code.h"
#include <map>
#include <iostream>

using std::cerr;
using std::endl;
using std::map;
using std::string;

namespace Assignment2 {

/**
 * @brief exit the program
 * @param[in] error_code
 * @warning
 * exit() doesn't execute destructor for each object what has been constructed,
 * it would cause unexpected close for resources, like files, which might cause problems.
 * see https://stackoverflow.com/questions/30250934/how-to-end-c-code
 *
 * Also, exit() is not thread-safe, so that exitProgram() can never be called concurrently from two threads.
 * see https://stackoverflow.com/questions/57161596/how-to-use-exit-safely-from-any-thread
 *
 * @note
 * I know these codes are terrible. but this project is too small, it might never meet those problems above.
 * So I decide to keep these codes (they are actually coming from my implementations for Assignment1)
 * Just be careful.
 */
void activatingSelfDestructSequence(Status error_code) {
  if (error_code == kError_Free) {
    exit(EXIT_SUCCESS);
  } else {
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief print description of errorcode
 * @param[in] error_code
 */
void printErrorInfo(Status error_code) {
  static map<int, string> info_map = {{kError_Free, "No error occurs."},
                                      {kError_Nullptr, "NULL pointer returned."},
                                      {kError_Mem_Failed, "Fail to create memory."},
                                      {kError_Out_Of_Range, "Failed to check range."},
                                      {kError_Invalid_Param, "Invalid parameter."},
                                      {kError_Logical_Impossible, "Logical Impossible."}};

  cerr << (info_map.find(error_code) == info_map.end() ? "Unknown error" : info_map[error_code]) << endl;
}

/**
 * @brief if the condition is not satisfied, print error info and exit the program
 * @param[in] error_type
 * @param[in] condition
 */
void paincCheck(Status error_type, bool condition) {
  if (!condition) {
    printErrorInfo(error_type);
    activatingSelfDestructSequence(error_type);
  }
}

}  // namespace Assignment2