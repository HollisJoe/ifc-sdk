#include "ifc2x3/IfcConstructionEquipmentResource.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcConstructionResource.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcConstructionEquipmentResource::IfcConstructionEquipmentResource(Step::Id id, Step::SPFData *args) : IfcConstructionResource(id, args) {
}

IfcConstructionEquipmentResource::~IfcConstructionEquipmentResource() {
}

bool IfcConstructionEquipmentResource::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcConstructionEquipmentResource(this);
}

const std::string &IfcConstructionEquipmentResource::type() const {
    return IfcConstructionEquipmentResource::s_type.getName();
}

const Step::ClassType &IfcConstructionEquipmentResource::getClassType() {
    return IfcConstructionEquipmentResource::s_type;
}

const Step::ClassType &IfcConstructionEquipmentResource::getType() const {
    return IfcConstructionEquipmentResource::s_type;
}

bool IfcConstructionEquipmentResource::isOfType(const Step::ClassType &t) const {
    return IfcConstructionEquipmentResource::s_type == t ? true : IfcConstructionResource::isOfType(t);
}

bool IfcConstructionEquipmentResource::init() {
    bool status = IfcConstructionResource::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcConstructionEquipmentResource::copy(const IfcConstructionEquipmentResource &obj, const CopyOp &copyop) {
    IfcConstructionResource::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcConstructionEquipmentResource::s_type("IfcConstructionEquipmentResource");
