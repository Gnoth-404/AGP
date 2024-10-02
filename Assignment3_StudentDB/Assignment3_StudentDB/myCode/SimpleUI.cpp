/*
 * SimpleUI.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: tiena
 */
#include <iostream>
#include <fstream>

#include "SimpleUI.h"
#include "StudentDb.h"

#include "BlockCourse.h"
#include "Weeklycourse.h"

#include <Poco/DateTime.h>
#include <Poco/Data/Time.h>


#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"

#include "Poco/Net/DNS.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"



using namespace std;


std::string getDayName(const Poco::DateTime::DaysOfWeek& dayOfWeek) {
    switch (dayOfWeek) {
        case Poco::DateTime::DaysOfWeek::SUNDAY:
            return "Sunday";
        case Poco::DateTime::DaysOfWeek::MONDAY:
            return "Monday";
        case Poco::DateTime::DaysOfWeek::TUESDAY:
            return "Tuesday";
        case Poco::DateTime::DaysOfWeek::WEDNESDAY:
            return "Wednesday";
        case Poco::DateTime::DaysOfWeek::THURSDAY:
            return "Thursday";
        case Poco::DateTime::DaysOfWeek::FRIDAY:
            return "Friday";
        case Poco::DateTime::DaysOfWeek::SATURDAY:
            return "Saturday";
        default:
            return "Invalid day"; // Handle invalid input
    }
}

Poco::DateTime::DaysOfWeek getDayOfWeekFromInt(int dayIndex) {
    switch (dayIndex) {
        case 0:
            return Poco::DateTime::DaysOfWeek::SUNDAY;
        case 1:
            return Poco::DateTime::DaysOfWeek::MONDAY;
        case 2:
            return Poco::DateTime::DaysOfWeek::TUESDAY;
        case 3:
            return Poco::DateTime::DaysOfWeek::WEDNESDAY;
        case 4:
            return Poco::DateTime::DaysOfWeek::THURSDAY;
        case 5:
            return Poco::DateTime::DaysOfWeek::FRIDAY;
        case 6:
            return Poco::DateTime::DaysOfWeek::SATURDAY;
        default:
            return Poco::DateTime::DaysOfWeek::SUNDAY;
    }
}

const Address queryAddress()
{
	cout << "Enter student address: \n";
	string street;
	cout << "Street: ";
    getline(cin >> ws, street);


	unsigned short postalCode;
	cout << "Postal code: ";
	cin >> postalCode;

	string cityName;
	cout << "City name: ";
    getline(cin >> ws, cityName);


	string additionalInfo;
	cout << "Additional Info (enter 0 if no additional info): ";
    getline(cin >> ws, additionalInfo);

	if (additionalInfo == "0") {
	  additionalInfo = "";
	}


	return Address{street, postalCode, cityName, additionalInfo};

}

SimpleUI::SimpleUI(StudentDb &db):db{db}
{
}

void SimpleUI::run()
{
	cout << "###################################### \n";
	cout << "###   Student Management Database  ### \n";
	cout << "###################################### \n";
	cout << endl;
	while(1)
	{
		this->printHelp();
		cout << "Enter your command: " ;
		int command;
		cin >> command;
		switch(command)
		{
		case 1:
			this->addNewCourse();
			break;
		case 2:
			this->listCourses();
			break;
		case 3:
			this->addNewStudent();
			break;
		case 4:
			this->addEnrollment();
			break;
		case 5:
			this->printStudent();
			break;
		case 6:
			this->searchStudent();
			break;
		case 7:
			this->updateStudent();
			break;
		case 8:
			this->readDatabase();
			break;
		case 9:
			this->writeDatabase();
			break;
		case 10:
			this->getStudentFromServer();
			break;
		case 0:
			cout << "Quit Database" << endl;
			return;
		default:
			break;
		}
	}


}



SimpleUI::~SimpleUI()
{
	// TODO Auto-generated destructor stub
}

void SimpleUI::printHelp() const
{
	cout << "0. Quit menu \n";
	cout << "----------------- \n";
	cout << "1. Add new Course \n";
	cout << "2. List courses \n";
	cout << "3. Add new Student \n";
	cout << "4. Add enrollment \n";
	cout << "5. Print student \n";
	cout << "6. Search student \n";
	cout << "7. Update student \n";
	cout << "8. Reading StudentDB text file \n";
	cout << "9. Writing StudentDB to file \n";
	cout << "10. Update student from Cloud \n";
	cout << "----------------- \n";

}

void SimpleUI::listCourses() const
{
	// use dynamic cast here to print all of our course
	auto& courses = db.getCourses();
	cout << "---------------------- \n";
	cout << "---   List Course  --- \n";
	cout << "---------------------- \n";
	if (courses.empty())
	{
		cout << "Empty course list. Please add course" <<endl;
		return;

	}

	for(const auto& course:courses)
	{
		// create pointer to actual object data to check type later
		 const Course* pCourseData = course.second.get();
		 this->listCourse(pCourseData);
		cout <<"------------------------------------" <<endl;

	}

}

void SimpleUI::addNewCourse() const
{
	cout << "---------------------- \n";
	cout << "---   Add Course   --- \n";
	cout << "---------------------- \n";
	unsigned int courseKey;
	cout << "Enter course key: ";
	cin >> courseKey;

	string title;
	cout << "Enter course title: ";
    getline(cin >> ws, title);

	// list current available major
	string major;
	cout << "MSEIT major: \n";
	cout << "  - Embedded \n";
	cout << "  - Power \n";
	cout << "  - Automation \n";
	cout << "  - Telecommunication \n";

	cout << "Enter major(case sensitive): ";
    getline(cin >> ws, major);

	float creditPoints;
	cout << "Enter number of credit points: ";
	cin >> creditPoints;

	bool courseType;
	cout << "0. Block Course \n" ;
	cout << "1. Weekly Course \n";
	cout << "Enter course type: ";

	cin >> courseType;

	if(courseType)
	{
		// handling Weekly Course Input
		int weekDay;
	    cout << "Select Weekly Course day of the week:" << std::endl;
	    cout << "0. Sunday \n" ;
	    cout << "1. Monday \n" ;
	    cout << "2. Tuesday \n" ;
	    cout << "3. Wednesday \n" ;
	    cout << "4. Thursday \n" ;
	    cout << "5. Friday \n" ;
	    cout << "6. Saturday \n" ;
		cout <<"Enter your day: ";

	    cin >> weekDay;

		Poco::DateTime::DaysOfWeek dayOfWeek =getDayOfWeekFromInt(weekDay);
		int hour;
		int minute;
		int second;
		cout <<"Enter class end time in 24h format(8:30am = 8 30 00): ";
		cin >> hour >> minute >> second;
		Poco::Data::Time startTime{hour,minute,second};
		cout <<"Enter class end time in 24h format(1:30pm = 13 30 00): ";
		cin >> hour >> minute >> second;
		Poco::Data::Time endTime{hour,minute,second};
	    std::unique_ptr<Course> weeklyCourse(new WeeklyCourse(courseKey,
	    		title, major, creditPoints, dayOfWeek, startTime, endTime));

		this->db.addCourse(weeklyCourse);
		std::cout << "Weekly Course added successfully" << endl;


	}
	else
	{
		// handling Block Course Input
		char slash_dummy;
		int day;
		int month;
		int year;
		cout <<"Enter class start day(e.g. 06/12/2023): ";
		cin >> day >> slash_dummy >> month >> slash_dummy>> year;
		Poco::Data::Date startDate{year, month, day};

		cout <<"Enter class end day(e.g. 06/12/2024): ";
		cin >> day >> slash_dummy >> month >> slash_dummy>> year;

		Poco::Data::Date endDate{year, month, day};

		int hour;
		int minute;
		int second;
		cout <<"Enter class start time in 24h format(8:30am = 8 30 00): ";
		cin >> hour >> minute >> second;
		Poco::Data::Time startTime{hour,minute,second};

		cout <<"Enter class end time in 24h format(11:30am = 11 30 00): ";
		cin >> hour >> minute >> second;
		Poco::Data::Time endTime{hour,minute,second};
	    std::unique_ptr<Course> blockCourse(new BlockCourse(courseKey,
	    		title, major, creditPoints,
				startDate, endDate, startTime, endTime));

		this->db.addCourse(blockCourse);

		cout << "Block Course added successfully" << endl;

	}

	cout << "-----------------------------" << endl;

}


void SimpleUI::addNewStudent() const
{
	cout << "--------------------------- \n";
	cout << "---   Add new Student   --- \n";
	cout << "--------------------------- \n";

	string firstName;
	cout << "Enter first name: \n";
    getline(cin >> ws, firstName);


	string lastName;
	cout << "Enter last name: \n";
    getline(cin >> ws, lastName);


	char slash_dummy;
	int day;
	int month;
	int year;
	cout <<"Enter birthday(e.g. 06/12/2001): ";

	cin >> day >> slash_dummy >> month >> slash_dummy>> year;

	Poco::Data::Date birthDay{year, month, day};


	Address newAddress = queryAddress();
	Student student{firstName,lastName,
		newAddress,birthDay};

	this->db.addStudent(student);

}



void SimpleUI::printStudent() const
{
	auto& students = db.getStudents();
	cout << "------------------------ \n";
	cout << "---   Print Student  --- \n";
	cout << "------------------------ \n";
	if (students.empty())
	{
		cout << "Empty student list. Please add student to the database" <<endl;
		return;
	}
	for(const auto& student:students)
	{
		cout << "----------------------------------------" << endl;

		cout << "Matriculation number: "
				<< student.second.getMatrikelNumber() << endl;

		cout << "Full name: " << student.second.getFirstName() <<
				" "<< student.second.getLastName()<<endl;

		const Poco::Data::Date& birthday=student.second.getDateOfBirth();
		cout << "Date of Birth: " << birthday.day()<<"/"
								<<birthday.month()<<"/"
								<<birthday.year()<<endl;

		const Address& address= student.second.getAddress();

		cout << "Student address: " << address.getStreet()<<", "
				<<address.getPostalCode()<<" " <<address.getCityName() << "; "
				<< address.getAdditionalInfo() << endl;

		auto enrollments= student.second.getEnrollments();
		if (enrollments.empty())
		{
			cout << "No enrolled course from this student" << endl;
		}
		else
		{
			cout << "$$$ Enrolled course $$$" << endl;
			for(auto enrollment:enrollments)
			{
				const Course* enrollCourse =enrollment.getCourse();
				this->listCourse(enrollCourse);
				cout << "Enrolled semester: " <<
						enrollment.getSemester() << endl;
				cout << "Grade: " << enrollment.getGrade() << endl;

			}
		}
		cout << "----------------------------------------" << endl;

	}

}
void SimpleUI::addEnrollment() const
{
	cout << "--------------------------- \n";
	cout << "---   Add Enrollment    --- \n";
	cout << "--------------------------- \n";
	unsigned int matrikelNumber;
	cout << "Enter student matriculation number: ";
	cin >> matrikelNumber;

	unsigned int courseKey;
	cout <<"Enter Course Id: ";
	cin >> courseKey;


	std::string semester;
	cout << "Enter semester: \n";
    getline(cin >> ws, semester);
    if (this->db.validCourse(courseKey)&& this->db.validStudent(matrikelNumber))
    {
    	if(this->db.addEnrollment(matrikelNumber, courseKey, semester))
    	{
    		return;
    	}
    	else
    	{
    		cout << "!!! Student enrolled this course already!!!" <<endl;
    	}
    }
    else
    {
    	cout << "Invalid courseID or matriculation number" <<endl;
    	cout << "Please try again";
    	return;
    }
}
void SimpleUI::searchStudent() const
{
	cout << "--------------------------- \n";
	cout << "---   Search Student    --- \n";
	cout << "--------------------------- \n";
	string studentName;
	cout << "Search name: \n";
    getline(cin >> ws, studentName);
    const auto& searchStudents = this->db.findStudentByName(studentName);
    if (searchStudents.empty())
    {
    	cout << "No matching student found" << endl;
    }
    else
    {
    	cout << "Search Result: " << endl;
    	for (const auto& student:searchStudents)
    	{
        	cout << " - Matriculation: " << student.getMatrikelNumber()  << ". ";
        	cout << student.getFirstName()<< " " << student.getLastName() << endl;


    	}
    }
}





void SimpleUI::listCourse(const Course* course) const
{
	cout << "----------------------------------------" << endl;

	cout << "Course key: " << course->getCourseKey() <<endl;
	cout << "Course title: " << course->getTitle() << endl;
	cout << "Major: " << course->getMajor() <<endl;
	cout << "Number of credit points: "
			<< course->getCreditPoints() <<endl;

	if (auto weeklyCourse=dynamic_cast<const WeeklyCourse*>(course))
	{
		cout << "Type of Course: Weekly" <<endl;

		const Poco::Data::Time& startTime=weeklyCourse->getStartTime();
		const Poco::Data::Time& endTime=weeklyCourse->getEndTime();

		cout << "Time: " << getDayName(weeklyCourse->getDayOfWeek())
				<<", "<< startTime.hour()
				<<"h"<<startTime.minute()<<" - "<<
				endTime.hour()<<"h"<<endTime.minute()<< endl;
	}
	if(auto blockCourse=dynamic_cast<const BlockCourse*>(course))
	{
		cout << "Type of Course: Block" <<endl;

		const Poco::Data::Date& startDate=blockCourse->getStartDate();
		const Poco::Data::Date& endDate=blockCourse->getEndDate();

		cout << "Start date: " << startDate.day()<<"/"
								<<startDate.month()<<"/"
								<<startDate.year()<<endl;
		cout << "End date: " << endDate.day()<<"/"
								<<endDate.month()<<"/"
								<<endDate.year()<<endl;


		const Poco::Data::Time& startTime=blockCourse->getStartTime();
		const Poco::Data::Time& endTime=blockCourse->getEndTime();

		cout << "Time: " << startTime.hour()
				<<"h"<<startTime.minute()<<" - "<<
				endTime.hour()<<"h"<<endTime.minute()<< endl ;

	}
	cout << "----------------------------------------" << endl;

}



void SimpleUI::updateStudent() const
{
	cout << "--------------------------- \n";
	cout << "---  Edit Student Data  --- \n";
	cout << "--------------------------- \n";
	unsigned int matriculationNumber;
	cout << "Enter edit student matriculation number: ";
	cin >> matriculationNumber;

	if(this->db.validStudent(matriculationNumber))
	{
		cout << "Choose edit field: " << endl;
		cout << "1. First name" << endl;
		cout << "2. Last name" << endl;
		cout << "3. Address" << endl;
		cout << "4. Date of Birth" << endl;
		cout << "5. Enrollment" << endl;
		cout << "0. Return to menu" << endl;
		auto& student= this->db.getStudentByID(matriculationNumber);
		int command2;
		cin >> command2;

		std::string firstname, lastname;
		Address newAddress{"0",0,"0","0"};
		int date, month, year;
		char slash_dummy;
		Poco::Data::Date newBirthDay;
		float grade;
		unsigned int courseKey;
		switch(command2)
		{
		case 1:
			cout << "Enter new first name: " << endl;
		    getline(cin >> ws, firstname);
		    student.setFirstName(firstname);
		    break;
		case 2:
			cout << "Enter new last name: " << endl;
		    getline(cin >> ws, lastname);
		    student.setLastName(lastname);
			break;
		case 3:
			cout << "Enter new address: " << endl;
			newAddress = queryAddress();
			student.setAddress(newAddress);
			break;
		case 4:
			cout << "Enter new birthday (e.g. 06/12/2001): " << endl;
			cin >> date >> slash_dummy >> month >> slash_dummy>> year;
			newBirthDay.assign(year, month,date);
			student.setDateOfBirth(newBirthDay);
			break;
		case 5:
			cout << "Enter the course key: " << endl;
			cin >> courseKey;
			cout << "Enter new grade of the course: " << endl;
			cin >>grade;
			if(student.setNewGrade(courseKey, grade)==0)
			{
				cout << "Invalid course key. Please try again" << endl;
			}
			break;

		default:
			cout << "Invalid option. Please try again" << endl;
			break;
		}
	}
	else
	{
		cout << "Invalid matriculation number. Please try again" << endl;
		return;
	}


}

void SimpleUI::writeDatabase() const
{
	cout << "--------------------------- \n";
	cout << "---   Write to Backup   --- \n";
	cout << "--------------------------- \n";
	cout << "Please enter backup name: ";
	string fileName;
	cin >> fileName;
	ofstream myfile;
	myfile.open(fileName);

	this->db.write(myfile);

	myfile.close();

}

void SimpleUI::readDatabase() const
{
	cout << "--------------------------- \n";
	cout << "---  Write to StudentDB --- \n";
	cout << "--------------------------- \n";
	cout << "Please enter backup filename: ";
	string backupFile;
	cin >> backupFile;
	ifstream backUpStream;
	backUpStream.open(backupFile);

	this->db.read(backUpStream);

	backUpStream.close();
}

void SimpleUI::getStudentFromServer() const
{

	int numberOfInput;
	cout << "Enter number of generating student from cloud: ";
	cin >> numberOfInput;
	if (numberOfInput ==0)
	{
		cout << "Invalid input!!! Please try again" << endl;
		return;
	}

	try
	{

        // Resolve host name to IP address
    	Poco::Net::HostEntry host =
    			Poco::Net::DNS::hostByName("www.hhs.users.h-da.cloud");

    	Poco::Net::IPAddress hostAddress(host.addresses()[0]);

    	Poco::UInt16 portNumber = 4242;

        Poco::Net::SocketAddress address(hostAddress, portNumber);

        // Connect to the server
        Poco::Net::StreamSocket socket;

        socket.connect(address, 20000); // 10-second timeout

        // Create a buffered stream
        Poco::Net::SocketStream stream(socket);

        string responseData;

        stream << "generate" << endl;
        stream.flush();
        // Read the first line from the stream
        getline(stream, responseData);

        while (true) {
            if (responseData.find("100 Generating")!= string::npos)
            {
            	//get next line(json generating line)
                getline(stream, responseData);

            }
            if (responseData.find("cell")!= string::npos) {
            	Poco::JSON::Parser parser;
                Poco::Dynamic::Var result = parser.parse(responseData);
                if (!result.isEmpty()) {
                    Poco::JSON::Object::Ptr object =
                    		result.extract<Poco::JSON::Object::Ptr>();


                    // Dynamic struct from Poco to enhance readability

                    Poco::DynamicStruct dynamicStruct = *object;

                    string street =
                    		dynamicStruct["location"]["street"];
                    string cityName =
                    		dynamicStruct["location"]["city"];
                    string additionalInfo =
                    		dynamicStruct["location"]["state"];
                    unsigned short postalCode =
                    		dynamicStruct["location"]["postCode"];


                    Address studentAddress{street, postalCode,
                    						cityName, additionalInfo};

        			int year= dynamicStruct["dateOfBirth"]["year"];
        			// Since month from database is 1-12
					int month= dynamicStruct["dateOfBirth"]["month"] +1;

					int date= dynamicStruct["dateOfBirth"]["date"];

                    Poco::Data::Date birthDay{year, month, date};

                    string firstName =dynamicStruct["name"]["firstName"];
                    string lastName =dynamicStruct["name"]["lastName"];
                    Student newStudent{firstName,lastName ,
                    						studentAddress, birthDay};


                    this->db.addStudent(newStudent);

                }
                numberOfInput--;

                // Get next line after the json line
            	getline(stream, responseData);

                if (responseData.find("200 Data generated.")!= string::npos)
                {
                    if (numberOfInput==0)
                    {
                        cout<<"Added student successfully. "
                        		"Sending quit command." << endl;

                        // Now send the "quit" command to the server
                        stream << "quit" << endl; // Send quit command
                        stream.flush();
                        getline(stream, responseData);
                    	cout << responseData << endl;

                		cout << "----------------------------------"
                						"------" << endl;

                        return;
                    }
                    else
                    {
                        stream << "generate" << endl;
                        stream.flush(); // Flush the stream
                        // Read final line from the stream

                        getline(stream, responseData);
                    }
                }


            }

        }
	} catch(Poco::Exception& ex)
	{
		cerr  << "Exception: " << ex.displayText() << endl;
        return;
    }

}
