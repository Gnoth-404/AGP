#include <iostream>
#include <fstream> // for file operations
#include <sstream> // for string operations
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/DNS.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/NumberFormatter.h"
#include <string.h>
#include <Poco/DateTime.h>
#include <Poco/StringTokenizer.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>
using namespace std;
#include <stdexcept>
int main() {


	std::string str ="100001;Stein;Josephine;11.12.1972;28 random;64521;Darmstadt;";
	float number = 10;
	cout << number << endl;
	Poco::NumberFormatter formatter;
	cout << formatter.format(number, 5) << endl;
	bool x=true;
	cout << x << endl;
	cout << formatter.format(x, Poco::NumberFormatter::FMT_YES_NO) << endl;
	std::string yesNO= formatter.format(x, Poco::NumberFormatter::FMT_YES_NO);
	Poco::NumberParser numberParser;
	cout << numberParser.parseBool(yesNO) << endl;
	auto time = Poco::DateTime(2024,2,19); // Datetime is year month day
	int weekDay = time.dayOfWeek();
	cout << "Week day" << weekDay << endl;
	Poco::DateTimeFormatter dateTime;
	cout << dateTime.format(time, Poco::DateTimeFormat::SORTABLE_FORMAT ,0) << endl;



	Poco::DateTime::Months month= Poco::DateTime::FEBRUARY;
	cout << month << endl;
	cout << Poco::DateTimeFormat::MONTH_NAMES[month-1] << endl;


	//cout << dateTime.format(dayOfweek,"%b,%B",0);
    return 0;
}



//class Sensor {
//public:
//    Sensor(int id) : id_(id) {}
//    void printId() const {
//        std::cout << "Sensor ID: " << id_ << std::endl;
//    }
//private:
//    int id_;
//};
//
//class MyClass {
//public:
//    void add(std::unique_ptr<Sensor>&& sensor) {
//        sensors.push_back(std::move(sensor));
//    }
//    void printAllSensorIds() const {
//        for (const auto& ptr : sensors) {
//            ptr->printId();
//        }
//    }
//private:
//    std::vector<std::unique_ptr<Sensor>> sensors;
//};
//
//int main() {
//    // Create a Sensor object
//    auto pSensor = std::make_unique<Sensor>(1);
//
//    // Create MyClass instance
//    MyClass network;
//
//    // Add the Sensor object to MyClass using a unique_ptr
//    network.add(pSensor);
//
////    // Print the Sensor ID using pSensor
////    std::cout << "Sensor ID using pSensor: ";
////    pSensor->printId();
//
//    // Print all Sensor IDs stored in MyClass
//    std::cout << "Sensor IDs stored in MyClass:" << std::endl;
//    network.printAllSensorIds();
//
//    return 0;
//}
