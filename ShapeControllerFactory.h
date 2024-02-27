#ifndef SHAPECONTROLLERFACTORY_H
#define SHAPECONTROLLERFACTORY_H

#include <map>

#include "ShapeController.h"

class ShapeControllerFactory {
public:
    static ShapeController& createShapeController(ShapeType type);

private:
    static std::map<ShapeType, ShapeController*> controllers;
};

#endif // SHAPECONTROLLERFACTORY_H
