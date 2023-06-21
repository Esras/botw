#pragma once

#include <evfl/Flowchart.h>
#include "basis/seadTypes.h"
#include "heap/seadHeap.h"
#include "prim/seadRuntimeTypeInfo.h"

namespace ksys::evt {

class Flowchart {
    SEAD_RTTI_BASE(Flowchart)
public:
    Flowchart();
    virtual ~Flowchart();

    virtual void m4_null();
    virtual u32 getFrameCount() const;
    virtual u32 getEventFlowType() const;
    virtual void m7();
    virtual void m8_null();
    virtual void printStatus();
    virtual void m10();
    virtual void init();
    virtual void calc();
    virtual void start();
    virtual void isFinished();
    virtual void init2();
    virtual void m16_null();
    virtual void m17_null();

private:
    sead::Heap* heap;
    u8 padding_0x10[1552];
    evfl::FlowchartContext* mFlowchartContext;
    u8 padding_0x628[136];
    u32 mUnknown32_0x6b0;
    u32 mFrameCount;
};
}  // namespace ksys::evt
