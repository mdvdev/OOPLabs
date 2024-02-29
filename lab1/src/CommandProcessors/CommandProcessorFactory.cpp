#include <stdexcept>

#include "CommandProcessorFactory.h"
#include "CommandProcessor1.h"
#include "CommandProcessor2.h"
#include "CommandProcessor3.h"
#include "CommandProcessor4.h"
#include "CommandProcessor5.h"
#include "CommandProcessor6.h"
#include "CommandProcessor7.h"
#include "SyntaxError.h"

CommandProcessorFactory::CommandProcessorFactory()
{
    processors[1] = new CommandProcessor1();
    processors[2] = new CommandProcessor2();
    processors[3] = new CommandProcessor3();
    processors[4] = new CommandProcessor4();
    processors[5] = new CommandProcessor5();
    processors[6] = new CommandProcessor6();
    processors[7] = new CommandProcessor7();
}

CommandProcessor* CommandProcessorFactory::createCommandProcessor(int opcode)
{
    try {
        return processors.at(opcode);
    } catch (const std::out_of_range& e) {
        throw SyntaxError("Error: Incorrect operation code");
    }
}
