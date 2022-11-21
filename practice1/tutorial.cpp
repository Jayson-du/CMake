
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Tutorial.h"
#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double value  = atof(argv[1]);

#ifdef USE_MYMATH
    printf("USE_MYMATH!\n");
    double result = mysqrt(value);
#else
    printf("USE_STDMATH!\n");
    double result = sqrt(value) ;
#endif
    fprintf(stdout, "The square root of %g is %g\n", value, result);

    return 0;
}
