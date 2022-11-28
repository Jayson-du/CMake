#include <cmath>
#include <iostream>
#include "platform.h"

using namespace std;

#ifdef LIN
    #define EXPORT __attribute__((visibility("default")))
#elif defined WIN
    #define EXPORT __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT double mysqrt(double value);
#ifdef __cplusplus
}
#endif