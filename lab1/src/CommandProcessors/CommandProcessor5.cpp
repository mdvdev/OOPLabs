#include <vector>
#include <algorithm>

#include "CommandProcessor5.h"
#include "Shape.h"
#include "InputHandler.h"

void CommandProcessor5::process(InputHandler& inputHandler, std::istream& inputStream)
{
    std::vector<Shape*> shapes = inputHandler.getShapes();
    std::sort(shapes.begin(), shapes.end(), [](const Shape* a, const Shape* b) -> bool
                                            {
                                                return a->getPerimeter() > b->getPerimeter();
                                            });
    inputHandler.setShapes(shapes);
}
