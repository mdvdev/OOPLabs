#include "ShapeControllerFactory.h"
#include "CircleController.h"
#include "RectangleController.h"
#include "TriangleController.h"
#include "PolygonController.h"

std::map<ShapeType, std::unique_ptr<ShapeController>> ShapeControllerFactory::controllers = {
    { ShapeType::Circle, std::unique_ptr<ShapeController>(new CircleController) },
    { ShapeType::Rectangle, std::unique_ptr<ShapeController>(new RectangleController) },
    { ShapeType::Triangle, std::unique_ptr<ShapeController>(new TriangleController) },
    { ShapeType::Polygon, std::unique_ptr<ShapeController>(new PolygonController) }
};

ShapeController& ShapeControllerFactory::createShapeController(ShapeType type)
{
    return *(controllers[type]);
}
