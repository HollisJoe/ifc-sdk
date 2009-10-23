#include "ifc2x3/IfcFlowTerminalType.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcDistributionFlowElementType.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcFlowTerminalType::IfcFlowTerminalType(Step::Id id, Step::SPFData *args) : IfcDistributionFlowElementType(id, args) {
}

IfcFlowTerminalType::~IfcFlowTerminalType() {
}

bool IfcFlowTerminalType::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcFlowTerminalType(this);
}

const std::string &IfcFlowTerminalType::type() const {
    return IfcFlowTerminalType::s_type.getName();
}

const Step::ClassType &IfcFlowTerminalType::getClassType() {
    return IfcFlowTerminalType::s_type;
}

const Step::ClassType &IfcFlowTerminalType::getType() const {
    return IfcFlowTerminalType::s_type;
}

bool IfcFlowTerminalType::isOfType(const Step::ClassType &t) const {
    return IfcFlowTerminalType::s_type == t ? true : IfcDistributionFlowElementType::isOfType(t);
}

bool IfcFlowTerminalType::init() {
    bool status = IfcDistributionFlowElementType::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcFlowTerminalType::copy(const IfcFlowTerminalType &obj, const CopyOp &copyop) {
    IfcDistributionFlowElementType::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcFlowTerminalType::s_type("IfcFlowTerminalType");
