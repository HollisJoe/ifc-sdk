#include "ifc2x3/IfcCondition.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcGroup.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcCondition::IfcCondition(Step::Id id, Step::SPFData *args) : IfcGroup(id, args) {
}

IfcCondition::~IfcCondition() {
}

bool IfcCondition::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcCondition(this);
}

const std::string &IfcCondition::type() const {
    return IfcCondition::s_type.getName();
}

const Step::ClassType &IfcCondition::getClassType() {
    return IfcCondition::s_type;
}

const Step::ClassType &IfcCondition::getType() const {
    return IfcCondition::s_type;
}

bool IfcCondition::isOfType(const Step::ClassType &t) const {
    return IfcCondition::s_type == t ? true : IfcGroup::isOfType(t);
}

bool IfcCondition::init() {
    bool status = IfcGroup::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcCondition::copy(const IfcCondition &obj, const CopyOp &copyop) {
    IfcGroup::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcCondition::s_type("IfcCondition");
