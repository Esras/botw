#include "KingSystem/Resource/resEvent.h"
#include "KingSystem/Resource/resEntryFactory.h"
#include "KingSystem/Resource/resSystem.h"

namespace ksys::res {

void Event::registerFactory(sead::Heap* heap) {
    auto* rm = sead::ResourceMgr::instance();
    if (!rm)
        return;

    if (rm->getDefaultFactory() != rm->findFactory("bevent"))
        return;

    res::registerEntryFactory(new (heap) EntryFactory<Event>(1.0, sizeof(Event)), "bevent");
}

}  // namespace ksys::res
