#pragma once

#import "KingSystem/ActorSystem/actActor.h"
#import "KingSystem/ActorSystem/actBaseProcLink.h"
#import "KingSystem/Event/evtEvent.h"
#import "KingSystem/Event/evtMetadata.h"
#include "prim/seadRuntimeTypeInfo.h"

namespace ksys::evt {

class BaseProcLinkForEvent : public act::BaseProcLink {
    SEAD_RTTI_BASE(BaseProcLinkForEvent)
    //???
public:
    BaseProcLinkForEvent() = default;
    BaseProcLinkForEvent(Event* event, act::Actor* actor);
    // BaseProdLinkForEvent(with call arg)
    virtual ~BaseProcLinkForEvent();

    void init(void*);
    void assign(Event* event);
    act::BaseProc* acquireActor();
    void reset();

private:
    BaseProcLink mBaseProcLink;
    Metadata mMetadata;
};

}  // namespace ksys::evt
