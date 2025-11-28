#ifdef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FlavorNotFoundException : public runtime_error{
    public:
    explicit FlavorNotFoundException(const string& name)
    runtime_error("Flavor not Founbd: " + name) {}
};

class OutOfStockException : public runtime_error {
    public: 
    explicit OutOfStockException(const string& name)
    : runtime_error("Not enough scoops available for: " + name){}
};

#endif
