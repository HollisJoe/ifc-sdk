#include "ifc2x3/IfcCsgSolid.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcCsgSelect.h"
#include "ifc2x3/IfcSolidModel.h"
#include "ifc2x3/Visitor.h"
#include <Step/BaseExpressDataSet.h>
#include <Step/BaseObject.h>
#include <Step/ClassType.h>
#include <Step/logger.h>
#include <stdlib.h>
#include <string>

using namespace ifc2x3;

IfcCsgSolid::IfcCsgSolid(Step::Id id, Step::SPFData *args) : IfcSolidModel(id, args) {
    m_treeRootExpression = NULL;
}

IfcCsgSolid::~IfcCsgSolid() {
}

bool IfcCsgSolid::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcCsgSolid(this);
}

const std::string &IfcCsgSolid::type() const {
    return IfcCsgSolid::s_type.getName();
}

const Step::ClassType &IfcCsgSolid::getClassType() {
    return IfcCsgSolid::s_type;
}

const Step::ClassType &IfcCsgSolid::getType() const {
    return IfcCsgSolid::s_type;
}

bool IfcCsgSolid::isOfType(const Step::ClassType &t) const {
    return IfcCsgSolid::s_type == t ? true : IfcSolidModel::isOfType(t);
}

IfcCsgSelect *IfcCsgSolid::getTreeRootExpression() {
    if (Step::BaseObject::inited()) {
        return m_treeRootExpression.get();
    }
    else {
        return NULL;
    }
}

const IfcCsgSelect *IfcCsgSolid::getTreeRootExpression() const {
    IfcCsgSolid * deConstObject = const_cast< IfcCsgSolid * > (this);
    return deConstObject->getTreeRootExpression();
}

void IfcCsgSolid::setTreeRootExpression(const Step::RefPtr< IfcCsgSelect > &value) {
    m_treeRootExpression = value;
}

void IfcCsgSolid::unsetTreeRootExpression() {
    m_treeRootExpression = Step::getUnset(getTreeRootExpression());
}

bool IfcCsgSolid::testTreeRootExpression() const {
    return !Step::isUnset(getTreeRootExpression());
}

bool IfcCsgSolid::init() {
    bool status = IfcSolidModel::init();
    std::string arg;
    if (!status) {
        return false;
    }
    arg = m_args->getNext();
    if (arg == "$" || arg == "*") {
        m_treeRootExpression = NULL;
    }
    else {
        m_treeRootExpression = new IfcCsgSelect;
        if (arg[0] == '#') {
            m_treeRootExpression->set(m_expressDataSet->get(atoi(arg.c_str() + 1)));
        }
        else if (arg[arg.length() - 1] == ')') {
            std::string type1;
            unsigned int i1;
            i1 = arg.find('(');
            if (i1 != std::string::npos) {
                type1 = arg.substr(0, i1);
                arg = arg.substr(i1 + 1, arg.length() - i1 - 2);
            }
        }
    }
    return true;
}

void IfcCsgSolid::copy(const IfcCsgSolid &obj, const CopyOp &copyop) {
    IfcSolidModel::copy(obj, copyop);
    m_treeRootExpression = new IfcCsgSelect;
    m_treeRootExpression->copy(*(obj.m_treeRootExpression.get()), copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcCsgSolid::s_type("IfcCsgSolid");
