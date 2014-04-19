#include <room.h>
#include <Sinbyen.h>
#include <Gardagh.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("zone exit");
        add_map_feature_exit(Direction_South, Gardagh_Room("m_20_32_0"));
        set_map_feature_access_override(([
            Direction_South                          : Move_Access_Walk,
        ]));
}
