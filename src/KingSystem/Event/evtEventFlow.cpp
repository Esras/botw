#include "KingSystem/Event/evtEventFlow.h"
#include "KingSystem/Event/evtManager.h"

namespace ksys::evt {

EventFlowBase::EventFlowBase(void*) {
    if ((mFlags.getDirect() & 0x1000100) == 0x1000000) {
        Manager::instance()->incrementAliveEventFlowCount();
        // setFlag4();
    }
}

u32 EventFlowBase::getBaseProcLinkId() {
    // return mBaseProcLink->getProc();
}

bool EventFlowBase::calc() {
    // set global to this
    // call to otherVTable + 28
    // Set global to nullptr
    mCalcCounter++;
    return true;
}

void EventFlowBase::setFlag4(EventFlowBase* flow) {
    mFlags.set(Flag::Flag4);
}
}  // namespace ksys::evt
