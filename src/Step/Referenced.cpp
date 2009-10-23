#include "Step/Referenced.h"
#include "Step/logger.h"

#include <set>

using namespace Step;



ClassType_root_implementations(STEP_DLL_DEF,Referenced);

typedef std::set<Observer*> ObserverSet;

Referenced::Referenced() :
    _refCount(0), _observers(0)
{
#ifdef STEP_THREAD_SAFE
    _refMutex = new OpenThreads::Mutex;
#endif
}

Referenced::Referenced(const Referenced &) :
    _refCount(0), _observers(0)
{
#ifdef STEP_THREAD_SAFE
    _refMutex = new OpenThreads::Mutex;
#endif
}

Referenced::~Referenced()
{
    if (_refCount > 0)
    {
        LOG_WARNING("Warning: deleting still referenced object " << this
                << " of type '" << getType().getName() << "'" << std::endl
                << "         the final reference count was " << _refCount
                << ", memory corruption possible.");
    }
    if (_observers)
    {
        ObserverSet* os = static_cast<ObserverSet*> (_observers);
        for (ObserverSet::iterator itr = os->begin(); itr != os->end(); ++itr)
        {
            (*itr)->objectDeleted(this);
        }
        delete os;
        _observers = 0;
    }

#ifdef STEP_THREAD_SAFE
    OpenThreads::Mutex* tmpMutexPtr = _refMutex;
    _refMutex = 0;
    delete tmpMutexPtr;
#endif
}

void Referenced::unref_nodelete() const
{
#ifdef STEP_THREAD_SAFE
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_refMutex);
#endif
    --_refCount;
}

void Referenced::addObserver(Observer* observer)
{
#ifdef STEP_THREAD_SAFE
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex);
#endif
    if (!_observers)
        _observers = new ObserverSet;
    if (_observers)
        static_cast<ObserverSet*> (_observers)->insert(observer);
}

void Referenced::removeObserver(Observer* observer)
{
#ifdef STEP_THREAD_SAFE
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex);
#endif
    if (_observers)
        static_cast<ObserverSet*> (_observers)->erase(observer);
}

