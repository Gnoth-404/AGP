#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"
#include <algorithm>
#include <cmath>
#include <limits>

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using the test values given above as samples, assert that a
     * NullAdjustor's adjust method returns the argument's value
     * unchanged.
     */
    // TODO
    auto nullAdjuster = NullAdjuster::sharedInstance;
    for (auto& value:testValues)
    {
        float out = nullAdjuster->adjust(value);
        assertTrue(out==value,"Null adjuster provides wrong output");

    }
    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    // TODO
    TableBasedAdjuster table;
    table.addBreakpoint(0,0);
    for (auto& value:testValues)
    {
        float out=0;
        out = table.adjust(value);

        assertTrue(out==value,"Null adjuster provides wrong output");

    }

    /*
     * (3) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
     * and (100,90) returns the given expected values.
     *
     * Remember (from your basic C/C++ courses) that floating
     * point calculations do not always yield exact results
     * (rounding errors due to using the binary system).
     * Take this into account when checking the result.
     */
    float expected[] = { -11, -1.1, 0, 0.9, 9 };
    // TODO
    TableBasedAdjuster table2;
    table2.addBreakpoint(-100,-110).addBreakpoint(0,0).addBreakpoint(100,90);

    for (int i=0; i<5;i++)
    {
        float out =0;
        out = table2.adjust(testValues[i]);
        assertTrue(out-expected[i]<0.00001,"Null adjuster provides wrong output");

    }

}

/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a NullAdjustor returns the raw
     * readings of a sensor as readings.
     */
    // TODO
    auto nullAdjuster = NullAdjuster::sharedInstance;

    TestSensor test("test", nullAdjuster);
    for (auto& testValue:testValues)
    {
        test.setRawReading(testValue);
        float out = test.reading();
        assertTrue(out==testValue, "Null adjuster is wrong");
    }

    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    auto linear = std::make_unique<LinearAdjuster>(5,10);
    for (float value : testValues) {
        for (float slope = -10; slope <= 10; slope += 5) {
            for (float intercept = -10; intercept <= 10; intercept += 5) {
                auto linear = std::make_shared<LinearAdjuster>(slope, intercept);
                TestSensor test("test", linear);

                test.setRawReading(value);
                float actualReading = test.reading();
                float expectedReading = slope * value + intercept;

                assertTrue(fabs(actualReading - expectedReading) < 0.0001, "LinearAdjuster provides wrong output");
            }
        }
    }

    // TODO
}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
    /*
     * Create a sensor network with 10 TestSensors named
     * "Thermometer n" (with n being the number of the thermometer)
     * that have their readings set to values 20 + n * 0.05.
     */
    // TODO
    SensorNetwork network;
    auto adjustter = NullAdjuster::sharedInstance;
    for (int i=0;i<10;i++)
    {
        std::string sensorName = "Thermometer " + std::to_string(i);
        auto pSensor = std::make_unique<TestSensor>(sensorName, adjustter);
        pSensor->setRawReading(20+ i*0.05);
        network.add(std::move(pSensor));
    }
    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
    try
    {
        auto pSensor = std::make_unique<TestSensor>("Thermometer 9", adjustter);
        network.add(std::move(pSensor));
    }catch(DuplicateSensorName& e)
    {
       std::cout << e.what() << std::endl;
    }
    // TODO
}

void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
