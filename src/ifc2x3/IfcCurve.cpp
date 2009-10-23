#include "ifc2x3/IfcCurve.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcGeometricRepresentationItem.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcCurve::IfcCurve(Step::Id id, Step::SPFData *args) : IfcGeometricRepresentationItem(id, args) {
}

IfcCurve::~IfcCurve() {
}

bool IfcCurve::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcCurve(this);
}

const std::string &IfcCurve::type() const {
    return IfcCurve::s_type.getName();
}

const Step::ClassType &IfcCurve::getClassType() {
    return IfcCurve::s_type;
}

const Step::ClassType &IfcCurve::getType() const {
    return IfcCurve::s_type;
}

bool IfcCurve::isOfType(const Step::ClassType &t) const {
    return IfcCurve::s_type == t ? true : IfcGeometricRepresentationItem::isOfType(t);
}

bool IfcCurve::init() {
    bool status = IfcGeometricRepresentationItem::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcCurve::copy(const IfcCurve &obj, const CopyOp &copyop) {
    IfcGeometricRepresentationItem::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcCurve::s_type("IfcCurve");
