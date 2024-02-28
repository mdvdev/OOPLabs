#ifndef SHAPECONTROLLERFACTORY_H
#define SHAPECONTROLLERFACTORY_H

#include <map>

#include "ShapeController.h"

// remove
class ShapeControllerFactory {
public:
    static ShapeController& createShapeController(ShapeType type);

private:
    static std::map<ShapeType, ShapeController*> controllers;
};

#endif // SHAPECONTROLLERFACTORY_H
