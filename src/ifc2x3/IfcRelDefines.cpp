#include "ifc2x3/IfcRelDefines.h"


#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcObject.h"
#include "ifc2x3/IfcRelationship.h"
#include "ifc2x3/Visitor.h"
#include <Step/BaseExpressDataSet.h>
#include <Step/BaseObject.h>
#include <Step/ClassType.h>
#include <Step/Referenced.h>
#include <Step/SPFFunctions.h>
#include <Step/logger.h>
#include <string>

using namespace ifc2x3;

Inverted_IfcRelDefines_RelatedObjects_type::Inverted_IfcRelDefines_RelatedObjects_type() {
}

void Inverted_IfcRelDefines_RelatedObjects_type::setOwner(IfcRelDefines *owner) {
    mOwner = owner;
}

void Inverted_IfcRelDefines_RelatedObjects_type::insert(const Step::RefPtr< IfcObject > &value) throw(std::out_of_range) {
    IfcObject *inverse = const_cast< IfcObject * > (value.get());
    Set_IfcObject_1_n::insert(value);
    inverse->m_isDefinedBy.insert(mOwner);
}

Inverted_IfcRelDefines_RelatedObjects_type::size_type Inverted_IfcRelDefines_RelatedObjects_type::erase(const Step::RefPtr< IfcObject > &value) {
    IfcObject *inverse = const_cast< IfcObject * > (value.get());
    inverse->m_isDefinedBy.erase(mOwner);
    return Set_IfcObject_1_n::erase(value);
}

void Inverted_IfcRelDefines_RelatedObjects_type::clear() {
    while (size()) {
        erase(*begin());
    }
}

IfcRelDefines::IfcRelDefines(Step::Id id, Step::SPFData *args) : IfcRelationship(id, args) {
    m_relatedObjects.setOwner(this);
}

IfcRelDefines::~IfcRelDefines() {
}

bool IfcRelDefines::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcRelDefines(this);
}

const std::string &IfcRelDefines::type() const {
    return IfcRelDefines::s_type.getName();
}

const Step::ClassType &IfcRelDefines::getClassType() {
    return IfcRelDefines::s_type;
}

const Step::ClassType &IfcRelDefines::getType() const {
    return IfcRelDefines::s_type;
}

bool IfcRelDefines::isOfType(const Step::ClassType &t) const {
    return IfcRelDefines::s_type == t ? true : IfcRelationship::isOfType(t);
}

Set_IfcObject_1_n &IfcRelDefines::getRelatedObjects() {
    if (Step::BaseObject::inited()) {
        return m_relatedObjects;
    }
    else {
        m_relatedObjects.setUnset(true);
        return m_relatedObjects;
    }
}

const Set_IfcObject_1_n &IfcRelDefines::getRelatedObjects() const {
    IfcRelDefines * deConstObject = const_cast< IfcRelDefines * > (this);
    return deConstObject->getRelatedObjects();
}

void IfcRelDefines::unsetRelatedObjects() {
    m_relatedObjects.clear();
    m_relatedObjects.setUnset(true);
}

bool IfcRelDefines::testRelatedObjects() const {
    return !Step::isUnset(getRelatedObjects());
}

bool IfcRelDefines::init() {
    bool status = IfcRelationship::init();
    std::string arg;
    if (!status) {
        return false;
    }
    arg = m_args->getNext();
    if (arg == "$" || arg == "*") {
        m_relatedObjects.setUnset(true);
    }
    else {
        m_relatedObjects.setUnset(false);
        while (true) {
            std::string str1;
            Step::getSubParameter(arg, str1);
            if (str1 != "") {
                Step::RefPtr< IfcObject > attr2;
                attr2 = static_cast< IfcObject * > (m_expressDataSet->get(Step::getIdParam(str1)));
                m_relatedObjects.insert(attr2);
            }
            else {
                break;
            }
        }
    }
    return true;
}

void IfcRelDefines::copy(const IfcRelDefines &obj, const CopyOp &copyop) {
    Step::Set< Step::RefPtr< IfcObject >, 1 >::const_iterator it_m_relatedObjects;
    IfcRelationship::copy(obj, copyop);
    for (it_m_relatedObjects = obj.m_relatedObjects.begin(); it_m_relatedObjects != obj.m_relatedObjects.end(); ++it_m_relatedObjects) {
        Step::RefPtr< IfcObject > copyTarget = (IfcObject *) (copyop((*it_m_relatedObjects).get()));
        m_relatedObjects.insert(copyTarget.get());
    }
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcRelDefines::s_type("IfcRelDefines");
