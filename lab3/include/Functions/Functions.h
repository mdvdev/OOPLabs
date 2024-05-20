#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <map>
#include <string>

template<typename T>
class Functions {
protected:
    std::map<std::string, T> functions;
public:
    using ConstIterator = typename std::map<std::string, T>::const_iterator;

    void addFunction(const std::string& name, const T& function) {
        functions[name] = function;
    }

    T getFunction(const std::string& name) const {
        return functions.at(name);
    }

    bool isFunctionExist(const std::string& name) const {
        return functions.find(name) != functions.end();
    }

    ConstIterator begin() const {
        return functions.begin();
    }

    ConstIterator end() const {
        return functions.end();
    }
};

#endif // FUNCTIONS_H
