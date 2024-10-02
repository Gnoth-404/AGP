#include "DuplicateSensorName.h"

DuplicateSensorName::DuplicateSensorName(std::string sensorName):
    std::invalid_argument("Duplicate sensor" + sensorName){
}
