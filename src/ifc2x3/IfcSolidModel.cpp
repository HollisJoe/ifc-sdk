#include "ifc2x3/IfcSolidModel.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcGeometricRepresentationItem.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcSolidModel::IfcSolidModel(Step::Id id, Step::SPFData *args) : IfcGeometricRepresentationItem(id, args) {
}

IfcSolidModel::~IfcSolidModel() {
}

bool IfcSolidModel::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcSolidModel(this);
}

const std::string &IfcSolidModel::type() const {
    return IfcSolidModel::s_type.getName();
}

const Step::ClassType &IfcSolidModel::getClassType() {
    return IfcSolidModel::s_type;
}

const Step::ClassType &IfcSolidModel::getType() const {
    return IfcSolidModel::s_type;
}

bool IfcSolidModel::isOfType(const Step::ClassType &t) const {
    return IfcSolidModel::s_type == t ? true : IfcGeometricRepresentationItem::isOfType(t);
}

bool IfcSolidModel::init() {
    bool status = IfcGeometricRepresentationItem::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcSolidModel::copy(const IfcSolidModel &obj, const CopyOp &copyop) {
    IfcGeometricRepresentationItem::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcSolidModel::s_type("IfcSolidModel");
