#include "ShapeControllerFactory.h"
#include "CircleController.h"
#include "RectangleController.h"
#include "TriangleController.h"
#include "PolygonController.h"

std::map<ShapeType, ShapeController*> ShapeControllerFactory::controllers = {
    { ShapeType::Circle, new CircleController },
    { ShapeType::Rectangle, new RectangleController },
    { ShapeType::Triangle, new TriangleController },
    { ShapeType::Polygon, new PolygonController}
};

ShapeController& ShapeControllerFactory::createShapeController(ShapeType type)
{
    return *(controllers[type]);
}
