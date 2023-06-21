#include "KingSystem/Event/evtBaseProcLink.h"

namespace ksys::evt {

// BaseProcLink::BaseProcLink() {
//     mMetadata.reset();
//}

BaseProcLinkForEvent::BaseProcLinkForEvent(Event* event, act::Actor* actor) {
    // init();
}

void BaseProcLinkForEvent::assign(Event* event) {
    mBaseProcLink.getProc(nullptr, nullptr);
    // init();
}

act::BaseProc* BaseProcLinkForEvent::acquireActor() {
    return mBaseProcLink.getProc(nullptr, nullptr);
}

void BaseProcLinkForEvent::reset() {
    // Other stuff
    mMetadata.reset();
    mBaseProcLink.reset();
}
}  // namespace ksys::evt
