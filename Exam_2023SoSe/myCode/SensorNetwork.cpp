#include "SensorNetwork.h"
#include "DuplicateSensorName.h"
#include <algorithm>
SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor) {

    std::string newSensorName = sensor->getName(); // unique ptr here
    for(auto& existingSensor:this->sensors)
    {
        if (existingSensor ->getName()==newSensorName)
        {
            throw DuplicateSensorName(newSensorName);
        }


    }
    this->sensors.push_back(std::move(sensor));

    return *this;
}
