#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include <prim/seadTypedBitFlag.h>
#include "KingSystem/Utils/Byaml/Byaml.h"

namespace ksys::evt {

class OrderParam;
// TODO
class Event {
public:
    Event();
    virtual ~Event();

    enum class Flag : u64 {
        _80000000000 = 0x80000000000,
    };

    bool hasFlag(Flag flag) const { return mFlags.isOn(flag); }

    void getEventName();
    void makeEventFlow(sead::Heap* heap, al::ByamlIter& event_flow, bool param_3);
    void makeEventFlowByName(sead::Heap* heap, const sead::SafeString& event_flow_name,
                             const sead::SafeString& entry_point, bool param_5);

private:
    u8 TEMP_0[0x238];
    sead::SafeString* mEventName;
    u8 TEMP_1[0x98];  // For size.
    sead::TypedBitFlag<Flag> mFlags;
};
// sizeof() = 0x620

}  // namespace ksys::evt
