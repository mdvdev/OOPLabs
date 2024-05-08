#ifndef COMMAND_H
#define COMMAND_H

template<typename T>
class Command {
public:
    virtual ~Command() = default;
    virtual T execute() = 0;
};

#endif // COMMAND_H
