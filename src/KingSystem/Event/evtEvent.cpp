#include "KingSystem/Event/evtEvent.h"
#include "KingSystem/Event/evtInfoData.h"
#include "KingSystem/Event/evtManager.h"
#include "KingSystem/Event/evtOrderParam.h"
#include "KingSystem/Utils/Byaml/Byaml.h"

namespace ksys::evt {

Event::Event() {}

void Event::makeEventFlowByName(sead::Heap* heap, const sead::SafeString& event_flow_name,
                                const sead::SafeString& entry_point, bool param_5) {
    al::ByamlIter yamlIter;
    al::ByamlIter* yamlIter_copy = &yamlIter;
    bool resultMaybe;

    resultMaybe = InfoData::instance()->getEntry(&yamlIter, event_flow_name, entry_point);
    if (!resultMaybe) {
        yamlIter_copy = nullptr;
    }
    makeEventFlow(heap, *yamlIter_copy, param_5);
}
}  // namespace ksys::evt
