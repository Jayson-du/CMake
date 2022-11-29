#include <iostream>

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif
    __declspec(dllexport) void hello();
#ifdef __cplusplus
}
#endif
