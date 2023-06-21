#pragma once

#include "KingSystem/Event/evtEventFlow.h"
#include "prim/seadRuntimeTypeInfo.h"
namespace ksys::evt {
class FlowTimeline : EventFlowBase {
    SEAD_RTTI_OVERRIDE(FlowTimeline, EventFlowBase)
public:
    FlowTimeline(/* Looks like maybe a pointer to an Event? */);

private:
};
}  // namespace ksys::evt
