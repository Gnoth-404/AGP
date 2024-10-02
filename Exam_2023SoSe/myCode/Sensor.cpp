#include "Sensor.h"
#include "Adjuster.h"

Sensor::~Sensor() {
}

std::string Sensor::getName() const {
    return name;
}

Sensor::Sensor(const std::string &name, std::shared_ptr<Adjuster> adjuster) :name{name},adjuster{adjuster}
    {
}

float Sensor::reading() const {
    // TODO, dummy implementation
    float result =0;
    result = this->adjuster->adjust(this->rawReading());
    return result;
}
