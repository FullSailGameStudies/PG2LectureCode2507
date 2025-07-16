#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //MODES of overriding:
    //  FULL override: do NOT call the base method
    //  EXTENSION override: call the base method at some point
    // DO NOT duplicate the base method

    std::string carInfo = Car::vehicleInformation();
    std::string flyingCarInfo = "\n\tMax Altitude: " + std::to_string(maxAlt_);
    return carInfo + flyingCarInfo;
}

