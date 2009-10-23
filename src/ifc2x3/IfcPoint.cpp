#include "ifc2x3/IfcPoint.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcGeometricRepresentationItem.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcPoint::IfcPoint(Step::Id id, Step::SPFData *args) : IfcGeometricRepresentationItem(id, args) {
}

IfcPoint::~IfcPoint() {
}

bool IfcPoint::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcPoint(this);
}

const std::string &IfcPoint::type() const {
    return IfcPoint::s_type.getName();
}

const Step::ClassType &IfcPoint::getClassType() {
    return IfcPoint::s_type;
}

const Step::ClassType &IfcPoint::getType() const {
    return IfcPoint::s_type;
}

bool IfcPoint::isOfType(const Step::ClassType &t) const {
    return IfcPoint::s_type == t ? true : IfcGeometricRepresentationItem::isOfType(t);
}

bool IfcPoint::init() {
    bool status = IfcGeometricRepresentationItem::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcPoint::copy(const IfcPoint &obj, const CopyOp &copyop) {
    IfcGeometricRepresentationItem::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcPoint::s_type("IfcPoint");
