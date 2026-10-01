#include <stdio.h>

#include "expresso/Expresso.h"
#include "expresso/Exposure.h"
#include "expresso/ExposureCategory.h"
#include "expresso/ExposureLevel.h"

int main(void) {

    Exposure testExposure = createWithIdentity("CMakeExampleTest");

    reset();

    setCategory(EXPOSURE_TEST);
    setLevel(LEVEL1);

    l1(&testExposure, EXPOSURE_TEST, "Expresso CMake package test passed.\n");

    return 0;
}