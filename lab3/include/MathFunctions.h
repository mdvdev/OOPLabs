#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <map>
#include <string>
#include <functional>
#include <memory>

class MathFunctions {
private:
    // simple case: functions with only 1 parameter
    std::map<std::string, std::function<double(double)>> functions;
    static std::shared_ptr<MathFunctions> instance;
protected:
    MathFunctions();
public:
    using ConstIterator = std::map<std::string, std::function<double(double)>>::const_iterator;

    static const MathFunctions& getInstance() {
        if (!instance) {
            class Proxy : public MathFunctions { };
            instance = std::make_shared<Proxy>();
        }
        return *instance;
    }

    void addFunction(const std::string& name,
                     const std::function<double(double)>& function)
    {
        functions[name] = function;
    }

    std::function<double(double)> getFunction(const std::string& name) {
        return functions.find(name) != functions.end() ? functions[name] : nullptr;
    }

    ConstIterator begin() const {
        return functions.begin();
    }

    ConstIterator end() const {
        return functions.end();
    }
private:
    static double ctg(double n);
    static double inverse(double n);
};

#endif // MATHFUNCTIONS_H
