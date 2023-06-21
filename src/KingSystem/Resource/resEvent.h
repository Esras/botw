#pragma once

#include "KingSystem/Resource/resEntryFactory.h"
#include "KingSystem/Resource/resResource.h"
#include "resource/seadResource.h"

namespace ksys::res {

class Event : public Resource {
    SEAD_RTTI_OVERRIDE(Event, Resource)
public:
    Event() = default;
    ~Event() override = default;

    static void registerFactory(sead::Heap* heap);

    void doCreate_(u8* buffer, u32 bufferSize, sead::Heap* heap) override;

    /*
    loadCommon_DemoAndModel
    initTimeline
    loadEventPack
    initFlowchart
    loadEventResources
    finishLoad
    areCameraAndModelAndXlinkReady
    processResourceLoad
    load
    */

    void* mUnknown1 = nullptr;
    void* mUnknown2 = nullptr;
};

}  // namespace ksys::res
