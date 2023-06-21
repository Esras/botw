#pragma once

#include "KingSystem/Event/evtEvent.h"
#include "heap/seadHeap.h"
#include "prim/seadRuntimeTypeInfo.h"
namespace ksys::evt {

class Context {
    SEAD_RTTI_BASE(Context)

public:
    Context();
    Context(sead::Heap* heap, Event* event);
    ~Context();

    void loadChildrenEvents();
    void calc();
    void x();
    void x_3();

    void updateEventsStatus();

    void setFlags4();
    void setActorBeingDeleted();
    void getActorByPointer();
    void getActorByName();
    void callDemoFromEventFlow();

    void setNoDeleteCurrentActor();
    void getEventName();
    void getEntryPointName();

private:
    bool checkSomething();

    u64 numEventsMaybe;
    u8 pad[456];
    u64 someVar_1D8;
    u64 mUnknown64_0;
    u64 mUnknown64_1;
    u64 someVar_1F0;
};
}  // namespace ksys::evt
