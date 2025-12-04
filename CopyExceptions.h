#ifndef EXCEPTIONS_H

 #define EXCEPTIONS_H
 
#include <stdexcept>

 #include <string>
 
class FlavorNotFoundException : public std::runtime_error {

 public:

     explicit FlavorNotFoundException(const std::string& name)

         : std::runtime_error("Flavor not found: " + name) {}

 };
 
class OutOfStockException : public std::runtime_error {

 public:

     explicit OutOfStockException(const std::string& name)

         : std::runtime_error("Not enough scoops available for: " + name) {}

 };
 
#endif // EXCEPTIONS_H

