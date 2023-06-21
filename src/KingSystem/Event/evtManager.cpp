#include "KingSystem/Event/evtManager.h"
#include "KingSystem/ActorSystem/actActor.h"
#include "KingSystem/Event/evtEvent.h"
#include "KingSystem/Event/evtInfoData.h"
#include "KingSystem/Utils/HeapUtil.h"
#include "prim/seadSafeString.h"

namespace ksys::evt {

SEAD_SINGLETON_DISPOSER_IMPL(Manager)

Manager::Manager() {}

void Manager::init(sead::Heap* heap) {
    ksys::util::getDebugHeap();
}

bool Manager::doCallEvent(const Metadata& metadata, int flags) {}

Event* Manager::getActiveEvent() const {
    if (mActiveEvent) {
        // Do stuff
    }
}

sead::SafeString* Manager::getActiveEventName(void* param_2, void* param_3) const {
    sead::SafeString temp;

    // temp = Something in the eventQueue? Potentially the event Name
    if (temp != nullptr) {
        if (param_2 != nullptr) {
            mActiveEvent->getEventName();
        }
        if (param_3 != nullptr) {
        }
    }
}

bool Manager::hasActiveEvent() const {
    return false;
}

bool Manager::hasEvent() const {
    return false;
}

bool Manager::isEventStartableAir(void* param_2) {
    sead::SafeString temp;
    auto infoDataInstance = ksys::evt::InfoData::instance();

    // infoDataInstance->getEntry();
}

void Manager::incrementAliveEventFlowCount() {
    mAliveEventFlowCount++;
}

void Manager::decrementAliveEventFlowCount() {
    mAliveEventFlowCount--;
}

bool Manager::checkActiveContextEventName(long*, long*) {}

void Manager::setNoDeleteCurrentActor() {
    // mCurrentActor->setNoDelete();
}

void Manager::checkEventCancel() {}

bool Manager::areAllEventFlowsReady() {
    // Looks like this does some stuff with the SingletonDisposer Buffer.
}

bool Manager::finishedLoadingResidentData() {
    // bool actors_finished_loading = mEventSystemActors->finishedLoading();
    // calc(???)
    bool event_flows_ready = areAllEventFlowsReady();
    // return actors_finished_loading & event_flows_ready;
    return event_flows_ready;
}

void Manager::stubbed() {}

bool Manager::callEvent(const Metadata& metadata, act::Actor* actor, void* x) {
    int flags = 0x1ff;
    doCallEvent(metadata, flags);
    return 0;
}

void Manager::clearAllPendingEvents() {
    auto iter = mEventList.begin();
    mCriticalSection1.lock();
    for (auto& i : mEventList) {
    }

    mCriticalSection1.unlock();
}

bool Manager::callEvent_0(void* param_2) {
    Metadata new_metadata;
    u32 flags;  // Probably not just a u32.
    // A whole bunch of checks:
    //    - Check that param_2 isn't null
    //    - Call the function 0x20 into param_2 with some arg
    //    - Call the function 0x28 into param_2? This might return the BaseProcLinkForEvent*
    //    - Check that ^ isn't null.
    //    - Grab the actor
    //    - Check that ^ isn't null
    //    - Check that the Actor's state isn't Delete
    //    - Check that the mStateFlags is... true? Or at least the last bit?
    flags = 0x1ff;
    doCallEvent(new_metadata, flags);
    // doCallEvent(new_metadata, flags)
    // Do something with the event queue?
    // Call FUN_7100dbe010 with the base_proc_link_for_event
}

}  // namespace ksys::evt
