#include "ifc2x3/IfcRelConnects.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcRelationship.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcRelConnects::IfcRelConnects(Step::Id id, Step::SPFData *args) : IfcRelationship(id, args) {
}

IfcRelConnects::~IfcRelConnects() {
}

bool IfcRelConnects::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcRelConnects(this);
}

const std::string &IfcRelConnects::type() const {
    return IfcRelConnects::s_type.getName();
}

const Step::ClassType &IfcRelConnects::getClassType() {
    return IfcRelConnects::s_type;
}

const Step::ClassType &IfcRelConnects::getType() const {
    return IfcRelConnects::s_type;
}

bool IfcRelConnects::isOfType(const Step::ClassType &t) const {
    return IfcRelConnects::s_type == t ? true : IfcRelationship::isOfType(t);
}

bool IfcRelConnects::init() {
    bool status = IfcRelationship::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcRelConnects::copy(const IfcRelConnects &obj, const CopyOp &copyop) {
    IfcRelationship::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcRelConnects::s_type("IfcRelConnects");
