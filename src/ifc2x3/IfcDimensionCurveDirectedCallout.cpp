#include "ifc2x3/IfcDimensionCurveDirectedCallout.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcDraughtingCallout.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcDimensionCurveDirectedCallout::IfcDimensionCurveDirectedCallout(Step::Id id, Step::SPFData *args) : IfcDraughtingCallout(id, args) {
}

IfcDimensionCurveDirectedCallout::~IfcDimensionCurveDirectedCallout() {
}

bool IfcDimensionCurveDirectedCallout::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcDimensionCurveDirectedCallout(this);
}

const std::string &IfcDimensionCurveDirectedCallout::type() const {
    return IfcDimensionCurveDirectedCallout::s_type.getName();
}

const Step::ClassType &IfcDimensionCurveDirectedCallout::getClassType() {
    return IfcDimensionCurveDirectedCallout::s_type;
}

const Step::ClassType &IfcDimensionCurveDirectedCallout::getType() const {
    return IfcDimensionCurveDirectedCallout::s_type;
}

bool IfcDimensionCurveDirectedCallout::isOfType(const Step::ClassType &t) const {
    return IfcDimensionCurveDirectedCallout::s_type == t ? true : IfcDraughtingCallout::isOfType(t);
}

bool IfcDimensionCurveDirectedCallout::init() {
    bool status = IfcDraughtingCallout::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcDimensionCurveDirectedCallout::copy(const IfcDimensionCurveDirectedCallout &obj, const CopyOp &copyop) {
    IfcDraughtingCallout::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcDimensionCurveDirectedCallout::s_type("IfcDimensionCurveDirectedCallout");
