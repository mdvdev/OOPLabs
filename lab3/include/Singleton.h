#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template<typename T>
class Singleton {
private:
    static std::shared_ptr<T> instance;
protected:
    virtual ~Singleton() = default;
    Singleton() = default;
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static const T& getInstance() {
        if (!instance) {
            class Proxy : public T { };
            instance = std::make_shared<Proxy>();
        }
        return *instance;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance;

#endif // SINGLETON_H
