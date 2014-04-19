#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("no exit east");
        set_map_feature_access_override(([
				Direction_East                             : Move_Access_Tunnel,
        ]));
               
}
