/**
 * @file Address.h
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

/**
 * @class Address
 * @brief Represents an address with street, postal code,
 * city name, and additional information.
 */
class Address {
private:
	//! Street name.
    std::string street;
    //! Postal code.
    unsigned short postalCode;
    //! City name.
    std::string cityName;
    //! Additional information (e.g., apartment number).
    std::string additionalInfo;

public:
    /**
     * @brief Constructor for Address.

     */
    Address(const std::string& street, unsigned short postalCode,
            const std::string& cityName,const std::string& additionalInfo = "");

    /**
     * @brief Get the additional information.
     * @return The additional information.
     */
    const std::string& getAdditionalInfo() const;

    /**
     * @brief Get the city name.
     * @return The city name.
     */
    const std::string& getCityName() const;

    /**
     * @brief Get the postal code.
     * @return The postal code.
     */
    unsigned short getPostalCode() const;

    /**
     * @brief Get the street name.
     * @return The street name.
     */
    const std::string& getStreet() const;

    /**
     * @brief Write the Address object to an output stream.
     * @param out The output stream.
     */
    void write(std::ostream& out);

    /**
     * @brief Read an Address object from an input stream.
     * @param in The input stream.
     * @return The Address object created from input stream.
     */
    Address read(std::istream& in);

    /**
     * @brief Destructor for Address.
     */
    virtual ~Address();
};

#endif /* ADDRESS_H_ */
