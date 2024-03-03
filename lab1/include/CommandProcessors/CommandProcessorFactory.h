#ifndef COMMANDPROCESSORFACTORY_H
#define COMMANDPROCESSORFACTORY_H

#include <map>

class CommandProcessor;
class ParamObject;

class CommandProcessorFactory {
public:
    static CommandProcessor* createCommandProcessor(int opcode);

private:
    static std::map<int, CommandProcessor*> processors;
};

#endif // COMMANDPROCESSORFACTORY_H
