#include "mysqrt.h"

double mysqrt(double value)
{
#ifdef LIN
    cout << "In mysqrt, define Linux" << endl;
#elif defined WIN
    cout << "In mysqrt, define Windows" << endl;
#endif

    return sqrt(value);
}
