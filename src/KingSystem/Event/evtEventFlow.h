#pragma once

#include <prim/seadTypedBitFlag.h>
#include "KingSystem/Event/evtBaseProcLink.h"
#include "basis/seadTypes.h"
#include "prim/seadRuntimeTypeInfo.h"

namespace ksys::evt {

class EventFlowBase {
    SEAD_RTTI_BASE(EventFlowBase)
public:
    EventFlowBase();
    EventFlowBase(void*);
    virtual ~EventFlowBase();

    enum class Flag : u64 { Flag1 = 0x1, Flag2 = 0x2, Flag3 = 0x3, Flag4 = 0x4 };

    virtual void m4_null();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8_null();
    virtual void printStatus();
    virtual void m10();

    u32 getBaseProcLinkId();
    bool byte3FlagIsSet();
    void initNoPauseActors();
    void isEventTypeNotMovieWithNoPath();
    void initEventAndReport(bool);
    bool calc();
    void acquireEventFlow();
    void x_3();
    void x_1();
    void x_2();

    void setupActors();
    void initActors();
    void init();

    void x_0();
    void start();
    void play();
    void setFlag4(EventFlowBase* flow);
    void x_6();
    void x_8();
    void x_5();

    void isPlaying();

    void x_7();
    void x_4();

    void exitEventMaybe();
    void x();

private:
    u8 padding_0[176];
    u32 mCalcCounter;
    u8 padding_1[64];
    void* otherVTable;
    u8 padding_2[16];
    act::BaseProcLink* mBaseProcLink;
    u8 padding_3[234];
    sead::TypedBitFlag<Flag> mFlags;
};

class EventFlow : public EventFlowBase {
    SEAD_RTTI_OVERRIDE(EventFlow, EventFlowBase)
public:
    EventFlow();
    ~EventFlow();

    void init();
    void initAndAllocResource();
    void x_1();
    void x();
    void x_0();
    void setState4();
    void setState3();
    void unload(long param_2);
    bool loadEventResource(void*);  // Passthrough to EventResource::load with param_2

private:
};
// static_assert(sizeof(EventFlow) == 0x148);

}  // namespace ksys::evt
