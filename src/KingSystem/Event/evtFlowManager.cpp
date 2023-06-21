#include "KingSystem/Event/evtFlowManager.h"
#include <basis/seadNew.h>
#include "KingSystem/Event/evtEventFlow.h"
#include "KingSystem/Event/evtFlow.h"

namespace ksys::evt {

FlowManager::FlowManager(sead::Heap* heap) {
    // This is the bulk of what this is doing.
    // However, the way the code emits is that all but the first one are a list of "Do the
    // constructor on this chunk of memory" instead of allocating all at once. Additionally, the 0th
    // byte of the allocated data is how many entries there are, so the constructor actually starts
    // on the 1st byte.
    mFlowType1Heap = new (heap, std::nothrow) EventFlow[0x60];
    mFlowType2Heap = new (heap, std::nothrow) EventMgrStruct3A[0x40];
    mFlowType3Heap = new (heap, std::nothrow) EventMgrStruct3A[0x10];
    mFlowType4Heap = new (heap, std::nothrow) EventMgrStruct3B[0x04];
    mFlowType5Heap = new (heap, std::nothrow) EventMgrStruct3B[0x08];
    mFlowType6Heap = new (heap, std::nothrow) EventMgrStruct3B[0x10];
}

void FlowManager::loadSimple(long param_2, long param_3) {
    load(param_2, param_3, 0, 0, 0);
}

void FlowManager::unload(EventFlow* eventFlow) {
    mCriticalSection->lock();
    eventFlow->unload(1);
    mCriticalSection->unlock();
}

bool FlowManager::loadEventResourceForAllEventFlows(u32 param_2) {
    bool success = true;
    // Iterate over the event type 1 objects
    // Get the current EventFlow*
    // success &= curEventFlow->loadEventResource(param_2 & 1);
    return success;
}
}  // namespace ksys::evt
