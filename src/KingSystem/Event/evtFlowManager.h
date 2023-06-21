#pragma once

#include "KingSystem/Event/evtEventFlow.h"
#include "KingSystem/Event/evtFlow.h"
#include "heap/seadHeap.h"
#include "thread/seadCriticalSection.h"

namespace ksys::evt {

class FlowManager {
public:
    FlowManager(sead::Heap* heap);
    virtual ~FlowManager();

    void* calc(void* param_2);

    void x_0();

    void load(long, long, u32, u64, long);
    void loadSimple(long param_2, long param_3);
    bool loadEventResourceForAllEventFlows(u32 param_2);

    void unload(EventFlow* eventFlow);

private:
    u32 mFreeFlowType1Count = 0;
    EventFlow* mFlowType1Heap = nullptr;
    u32 mFreeFlowType2Count = 0;
    EventMgrStruct3A* mFlowType2Heap = nullptr;
    u32 mFreeFlowType3Count = 0;
    EventMgrStruct3A* mFlowType3Heap = nullptr;
    u32 mFreeFlowType4Count = 0;
    EventMgrStruct3B* mFlowType4Heap = nullptr;
    u32 mFreeFlowType5Count = 0;
    EventMgrStruct3B* mFlowType5Heap = nullptr;
    u32 mFreeFlowType6Count = 0;
    EventMgrStruct3B* mFlowType6Heap = nullptr;
    sead::CriticalSection* mCriticalSection;
};

}  // namespace ksys::evt
