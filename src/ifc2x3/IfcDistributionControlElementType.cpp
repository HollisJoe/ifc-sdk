#include "ifc2x3/IfcDistributionControlElementType.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcDistributionElementType.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcDistributionControlElementType::IfcDistributionControlElementType(Step::Id id, Step::SPFData *args) : IfcDistributionElementType(id, args) {
}

IfcDistributionControlElementType::~IfcDistributionControlElementType() {
}

bool IfcDistributionControlElementType::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcDistributionControlElementType(this);
}

const std::string &IfcDistributionControlElementType::type() const {
    return IfcDistributionControlElementType::s_type.getName();
}

const Step::ClassType &IfcDistributionControlElementType::getClassType() {
    return IfcDistributionControlElementType::s_type;
}

const Step::ClassType &IfcDistributionControlElementType::getType() const {
    return IfcDistributionControlElementType::s_type;
}

bool IfcDistributionControlElementType::isOfType(const Step::ClassType &t) const {
    return IfcDistributionControlElementType::s_type == t ? true : IfcDistributionElementType::isOfType(t);
}

bool IfcDistributionControlElementType::init() {
    bool status = IfcDistributionElementType::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcDistributionControlElementType::copy(const IfcDistributionControlElementType &obj, const CopyOp &copyop) {
    IfcDistributionElementType::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcDistributionControlElementType::s_type("IfcDistributionControlElementType");
