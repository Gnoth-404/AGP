#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

int main() {
    try {
        // Create an IO service
        io_service io_service;

        // Create a resolver to resolve the domain name
        ip::tcp::resolver resolver(io_service);

        // Resolve the domain name and port
        ip::tcp::resolver::query query("www.hhs.users.h-da.cloud", "4242");
        ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        // Create an iostream for the connection to the server
        ip::tcp::iostream stream(*endpoint_iterator);



        // Send "generate" command to the server
        stream << "generate" << std::endl;

        // Read and print the response
        std::string line;
        while (std::getline(stream, line)) {
            std::cout << "received" << line << std::endl;

            // Assuming 200 is the response code indicating successful operation
            if (line.find("200") != std::string::npos) {
                break;
            }
        }

        // Send "quit" command to the server
        stream << "quit" << std::endl;

        // Read and print the closing response
        while (std::getline(stream, line)) {
            std::cout << "print " << line << std::endl;
        }
    } catch (const boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
