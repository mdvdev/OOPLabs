#ifndef COMMANDPROCESSORFACTORY_H
#define COMMANDPROCESSORFACTORY_H

#include <map>

class CommandProcessor;
class ParamObject;

class CommandProcessorFactory {
public:
    CommandProcessorFactory();

    CommandProcessor* createCommandProcessor(int opcode);

private:
    std::map<int, CommandProcessor*> processors;
};

#endif // COMMANDPROCESSORFACTORY_H
