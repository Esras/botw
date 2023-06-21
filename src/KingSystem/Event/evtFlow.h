#pragma once

#include "basis/seadTypes.h"
#include "prim/seadSafeString.h"
namespace ksys::evt {

class EventMgrStruct3A {
    void assignToActor(long param_2);

private:
    u64 m0;
    u64 m1;
    u64 m2;
};

class EventMgrStruct3B {
public:
    EventMgrStruct3B() = default;
    EventMgrStruct3B(u32, u32, sead::SafeString* a_string);

private:
    sead::FixedSafeString<64> mSafeString;
    u32 m32_0x58;
    u8 padding_0x5C[260];
    u32 m32_0x160;
    u32 m32_0x164;
    u32 m32_0x168;
    u64 m32_0x170;
    u32 m32_0x178;
    u32 m32_0x17C;
    u32 m32_0x180;
    u32 m32_0x184;
    u32 m32_0x188;
};
}  // namespace ksys::evt
