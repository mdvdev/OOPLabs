#ifndef SHAPECONTROLLERFACTORY_H
#define SHAPECONTROLLERFACTORY_H

#include <map>
#include <memory>

#include "include/Controllers/ShapeController.h"

class ShapeControllerFactory {
public:
    static ShapeController& createShapeController(ShapeType type);

private:
    static std::map<ShapeType, std::unique_ptr<ShapeController>> controllers;
};

#endif // SHAPECONTROLLERFACTORY_H
