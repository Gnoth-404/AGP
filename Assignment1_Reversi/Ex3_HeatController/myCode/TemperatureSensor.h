/*
 * TemperatureSensor.h
 *
 *  Created on: Nov 15, 2023
 *      Author: tiena
 */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_
/**
 * @class TemperatureSensor
 * @brief Represents a temperature sensor.
 *
 * This class models a temperature sensor and
 * provides methods for initializing the sensor,
 * reading temperature data, and accessing the current temperature.
 */
class TemperatureSensor
{
private:
	int sensorPin; ///< The pin number of the sensor.
	float datasheetTemp; ///< The properties of the sensor
public:
	TemperatureSensor();
	/**
	 * @brief Construct a new Temperature Sensor object
	 * 
	 * @param pin The pin number of the sensor.
	 * @param temp The properties of the sensor.
	 */
	TemperatureSensor(int& pin, float& temp);

	/**
	 * @brief Get the current temperature
	 * 
	 * @return float The current temperature in degrees Celsius.
	 */
	float getTemperture() const;

	/**
	 * @brief Convert the temperature from degrees Fahrenheit to degrees Celsius
	 * 
	 * @param temp The temperature in degrees Fahrenheit.
	 * @return float The temperature in degrees Celsius.
	 */
	float convertToCelsius(float temp) const;

	/**
	 * @brief Convert the temperature from degrees Celsius to degrees Fahrenheit
	 * 
	 * @param temp The temperature in degrees Celsius.
	 * @return float The temperature in degrees Fahrenheit.
	 */
	float convertToFahrenheit(float temp) const;
	/**
	 * @brief Destroy the Temperature Sensor object
	 * 
	 */
	virtual ~TemperatureSensor();
};

#endif /* TEMPERATURESENSOR_H_ */
