/**

 *
 * @author tiena
 * @date Nov 15, 2023
 */

#ifndef HEATCONTROLLER_H_
#define HEATCONTROLLER_H_

/**
 * @class HeatController
 *
 * @brief A class for controlling heating operations.
 *
 * The HeatController class provides methods to turn the heating system on
 * and off.
 */
class HeatController
{
public:
    /**
     * @brief Default constructor for the HeatController class.
     *
     * This constructor initializes a HeatController object.
     */
    HeatController();

    /**
     * @brief Destructor for the HeatController class.
     *
     */
    virtual ~HeatController();

    /**
     * @brief Turn on the heating system.
     *
     * This method is used to activate the heating system, allowing it to
     * generate heat.
     */
    void turnOnHeating();

    /**
     * @brief Turn off the heating system.
     *
     * This method is used to deactivate the heating system, stopping it
     * from generating heat.
     */
    void turnOffHeating();
};

#endif /* HEATCONTROLLER_H_ */
