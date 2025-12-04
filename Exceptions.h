#ifdef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FlavorNotFoundException : public runtime_error{
    public:
    explicit FlavorNotFoundException(const string& name)
    runtime_error("Flavor not Found: " + name) {}
};

class OutOfStockException : public runtime_error {
    public: 
    explicit OutOfStockException(const string& namee)
    : runtime_error("Not enough scoops available for: " + name){}
};

#endif
