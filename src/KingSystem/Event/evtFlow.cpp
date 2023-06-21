#include "KingSystem/Event/evtFlow.h"

namespace ksys::evt {

EventMgrStruct3B::EventMgrStruct3B(u32 param_2, u32 param_3, sead::SafeString* a_string) {
    mSafeString = *a_string;
    m32_0x160 = 0;
    m32_0x164 = param_2;
    m32_0x168 = param_3;
}
}  // namespace ksys::evt
