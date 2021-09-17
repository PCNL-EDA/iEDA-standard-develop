#include <string>
#include <cstdlib>

namespace Assignment2 {

#define kDELETE_UNUSED_CONSTRUCTOR(class_name) \
  class_name(const class_name &)  = delete;    \
  class_name(const class_name &&) = delete;    \
  void operator=(const class_name &) = delete

using Status = int;

enum ErrorCode {
  kError_Free,
  kError_Nullptr,
  kError_Mem_Failed,
  kError_Out_Of_Range,
  kError_Invalid_Param,
  kError_Logical_Impossible,
};

void activatingSelfDestructSequence(Status error_code);

void printErrorInfo(Status error_code);

void paincCheck(Status error_type, bool condition);

}  // namespace Assignment2
