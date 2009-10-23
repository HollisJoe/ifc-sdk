#include "ifc2x3/IfcFlowSegmentType.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcDistributionFlowElementType.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcFlowSegmentType::IfcFlowSegmentType(Step::Id id, Step::SPFData *args) : IfcDistributionFlowElementType(id, args) {
}

IfcFlowSegmentType::~IfcFlowSegmentType() {
}

bool IfcFlowSegmentType::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcFlowSegmentType(this);
}

const std::string &IfcFlowSegmentType::type() const {
    return IfcFlowSegmentType::s_type.getName();
}

const Step::ClassType &IfcFlowSegmentType::getClassType() {
    return IfcFlowSegmentType::s_type;
}

const Step::ClassType &IfcFlowSegmentType::getType() const {
    return IfcFlowSegmentType::s_type;
}

bool IfcFlowSegmentType::isOfType(const Step::ClassType &t) const {
    return IfcFlowSegmentType::s_type == t ? true : IfcDistributionFlowElementType::isOfType(t);
}

bool IfcFlowSegmentType::init() {
    bool status = IfcDistributionFlowElementType::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcFlowSegmentType::copy(const IfcFlowSegmentType &obj, const CopyOp &copyop) {
    IfcDistributionFlowElementType::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcFlowSegmentType::s_type("IfcFlowSegmentType");
