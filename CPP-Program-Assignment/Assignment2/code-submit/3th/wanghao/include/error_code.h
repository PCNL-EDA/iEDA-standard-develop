#include <string>
#include <cstdlib>

namespace Assignment2 {

using Status = int;

enum ErrorCode {
  kError_Free          = 0,
  kError_Nullptr       = 1,
  kError_Mem_Failed    = 2,
  kError_Out_Of_Range  = 3,
  kError_Invalid_Param = 4,
};

void exitProgram(Status error_code);

void printErrorInfo(Status error_code);

void paincCheck(Status error_type, bool condition);

}  // namespace Assignment2
