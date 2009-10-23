#include "ifc2x3/IfcLoop.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcTopologicalRepresentationItem.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcLoop::IfcLoop(Step::Id id, Step::SPFData *args) : IfcTopologicalRepresentationItem(id, args) {
}

IfcLoop::~IfcLoop() {
}

bool IfcLoop::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcLoop(this);
}

const std::string &IfcLoop::type() const {
    return IfcLoop::s_type.getName();
}

const Step::ClassType &IfcLoop::getClassType() {
    return IfcLoop::s_type;
}

const Step::ClassType &IfcLoop::getType() const {
    return IfcLoop::s_type;
}

bool IfcLoop::isOfType(const Step::ClassType &t) const {
    return IfcLoop::s_type == t ? true : IfcTopologicalRepresentationItem::isOfType(t);
}

bool IfcLoop::init() {
    bool status = IfcTopologicalRepresentationItem::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcLoop::copy(const IfcLoop &obj, const CopyOp &copyop) {
    IfcTopologicalRepresentationItem::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcLoop::s_type("IfcLoop");
