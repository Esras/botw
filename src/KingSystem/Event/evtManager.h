#pragma once

#include <heap/seadDisposer.h>
#include "KingSystem/Event/evtContext.h"
#include "KingSystem/Event/evtEvent.h"
#include "KingSystem/Event/evtEventFlow.h"
#include "KingSystem/Utils/Thread/ActorMessageTransceiver.h"
#include "basis/seadRawPrint.h"
#include "container/seadObjList.h"
#include "math/seadVector.h"
#include "prim/seadRuntimeTypeInfo.h"
#include "prim/seadSafeString.h"
#include "thread/seadAtomic.h"
#include "thread/seadCriticalSection.h"

namespace ksys::act {
class Actor;
}

namespace ksys::evt {

class Event;
class Metadata;

class Manager {
    SEAD_RTTI_BASE(Manager)
    SEAD_SINGLETON_DISPOSER(Manager)

    class IHandler : public MessageTransceiverRxOnly::IHandler,
                     public MessageTransceiverTxOnly::IHandler {};
    KSYS_CHECK_SIZE_NX150(IHandler, 0x10);

    Manager();
    virtual ~Manager() = default;

public:
    void init(sead::Heap* heap);

    Event* getActiveEvent() const;
    sead::SafeString* getActiveEventName(void* param_2, void* param_3) const;
    bool isActiveEventNameEqualTo() const;
    bool hasActiveEvent() const;
    bool hasEvent() const;
    bool isEventStartableAir(void* param_2);

    void stubbed();

    sead::Heap* getEventHeap() const { return mEventHeap; }

    void incrementAliveEventFlowCount();
    void decrementAliveEventFlowCount();

    bool checkActiveContextEventName(long*, long*);

    Event* getBaseProcLinkFromActiveEvent();  // Might not be Event*, might be subtype
    void setNoDeleteCurrentActor();
    void checkEventCancel();

    bool areAllEventFlowsReady();
    bool finishedLoadingResidentData();

    void clearAllPendingEvents();

    bool callEvent(const Metadata& metadata, act::Actor* actor = nullptr, void* x = nullptr);
    bool callEvent_0(void* param_2);

    bool actorDebugStuff(void*, u32);

private:
    ksys::act::Actor* mCurrentActor;
    Event* mActiveEvent;
    u8 pad_1[0x32];
    sead::CriticalSection mCriticalSection1;
    sead::ListNode pendingEventList;
    u32 pendingEventListSize;
    void* field_e8;  // evt::BaseProcLinkForEvent** field_E8;
    u64 field_F0;
    Event* mHeadPointer;
    Event* mTailPointer;
    sead::FixedObjList<Event, 140> mEventList;
    u8 gap_100[118316];
    u8 gap_1CF34[468];
    u64 field_1D100;
    // PlayerLink *playerLink;
    u64 debug;
    char field_1D118;
    u64 mPatroller;
    bool gap_1D128;
    char autosave;
    bool notNewSaveBeforeStageGen;
    char isDoingSystemReset;
    u8 gap_1D12C[4];
    sead::CriticalSection field_1D130;
    sead::Atomic<u32> mAliveEventFlowCount = 0;
    int field_1D174;
    u64 field_1D178;
    sead::Heap* mEventHeap;
    void* vtable_1D188;
    int field_1D190;
    float field_1D194;
    float field_1D198;
    u8 gap1D19C[4];
    int field_1D1A0;
    int field_1D1A4;
    int field_1D1A8;
    float field_1D1AC;
    int field_1D1B0;
    int field_1D1B4;

    evt::Context* eventContexts[32];
    evt::Context* activeEventContext;
    evt::Context* activeAsyncEventContext;
    // ukingEventMgr* ukingEventMgr;
    // EventMgrStruct1* struct1;
    // evt::ActionContext* actionCtxs;
    // EventFlowMgr* eventFlowMgr;
    // EventMgrStruct4* structs4;
    int field_1D2F0;
    // EventMgrFlags flags;
    int setTo999BeforeStageGen;

    int field_1D2FC;
    // sead::BufferedSafeString field_1D300;
    u32 field_1D314;
    u32 field_1D318;
    u8 gap_1D31C[92];
    void* sysActors;  // EventSysActors* sysActors;
    sead::FixedSafeString<40> field_1D380;
    u32 field_1D3D8;
    u8 gap_1D3DC[4];
    EventFlow* sceneChangeEventFlows[2];
    sead::Vector3f mSomePosition;
    u8 gap1D3FC;
    sead::FixedSafeString<20> eventFlowName[2];

    bool doCallEvent(const Metadata& metadata, int flags);
};  // namespace ksys::evt
// static_assert(sizeof(Manager) == 0xd438);

}  // namespace ksys::evt
