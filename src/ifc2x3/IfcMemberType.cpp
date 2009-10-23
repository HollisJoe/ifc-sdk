#include "ifc2x3/IfcMemberType.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcBuildingElementType.h"
#include "ifc2x3/Visitor.h"
#include <Step/BaseObject.h>
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

IfcMemberType::IfcMemberType(Step::Id id, Step::SPFData *args) : IfcBuildingElementType(id, args) {
    m_predefinedType = IfcMemberTypeEnum_UNSET;
}

IfcMemberType::~IfcMemberType() {
}

bool IfcMemberType::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcMemberType(this);
}

const std::string &IfcMemberType::type() const {
    return IfcMemberType::s_type.getName();
}

const Step::ClassType &IfcMemberType::getClassType() {
    return IfcMemberType::s_type;
}

const Step::ClassType &IfcMemberType::getType() const {
    return IfcMemberType::s_type;
}

bool IfcMemberType::isOfType(const Step::ClassType &t) const {
    return IfcMemberType::s_type == t ? true : IfcBuildingElementType::isOfType(t);
}

IfcMemberTypeEnum IfcMemberType::getPredefinedType() {
    if (Step::BaseObject::inited()) {
        return m_predefinedType;
    }
    else {
        return IfcMemberTypeEnum_UNSET;
    }
}

const IfcMemberTypeEnum IfcMemberType::getPredefinedType() const {
    IfcMemberType * deConstObject = const_cast< IfcMemberType * > (this);
    return deConstObject->getPredefinedType();
}

void IfcMemberType::setPredefinedType(IfcMemberTypeEnum value) {
    m_predefinedType = value;
}

void IfcMemberType::unsetPredefinedType() {
    m_predefinedType = IfcMemberTypeEnum_UNSET;
}

bool IfcMemberType::testPredefinedType() const {
    return getPredefinedType() != IfcMemberTypeEnum_UNSET;
}

bool IfcMemberType::init() {
    bool status = IfcBuildingElementType::init();
    std::string arg;
    if (!status) {
        return false;
    }
    arg = m_args->getNext();
    if (arg == "$" || arg == "*") {
        m_predefinedType = IfcMemberTypeEnum_UNSET;
    }
    else {
        if (arg == ".BRACE.") {
            m_predefinedType = IfcMemberTypeEnum_BRACE;
        }
        else if (arg == ".CHORD.") {
            m_predefinedType = IfcMemberTypeEnum_CHORD;
        }
        else if (arg == ".COLLAR.") {
            m_predefinedType = IfcMemberTypeEnum_COLLAR;
        }
        else if (arg == ".MEMBER.") {
            m_predefinedType = IfcMemberTypeEnum_MEMBER;
        }
        else if (arg == ".MULLION.") {
            m_predefinedType = IfcMemberTypeEnum_MULLION;
        }
        else if (arg == ".PLATE.") {
            m_predefinedType = IfcMemberTypeEnum_PLATE;
        }
        else if (arg == ".POST.") {
            m_predefinedType = IfcMemberTypeEnum_POST;
        }
        else if (arg == ".PURLIN.") {
            m_predefinedType = IfcMemberTypeEnum_PURLIN;
        }
        else if (arg == ".RAFTER.") {
            m_predefinedType = IfcMemberTypeEnum_RAFTER;
        }
        else if (arg == ".STRINGER.") {
            m_predefinedType = IfcMemberTypeEnum_STRINGER;
        }
        else if (arg == ".STRUT.") {
            m_predefinedType = IfcMemberTypeEnum_STRUT;
        }
        else if (arg == ".STUD.") {
            m_predefinedType = IfcMemberTypeEnum_STUD;
        }
        else if (arg == ".USERDEFINED.") {
            m_predefinedType = IfcMemberTypeEnum_USERDEFINED;
        }
        else if (arg == ".NOTDEFINED.") {
            m_predefinedType = IfcMemberTypeEnum_NOTDEFINED;
        }
    }
    return true;
}

void IfcMemberType::copy(const IfcMemberType &obj, const CopyOp &copyop) {
    IfcBuildingElementType::copy(obj, copyop);
    setPredefinedType(obj.m_predefinedType);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcMemberType::s_type("IfcMemberType");
