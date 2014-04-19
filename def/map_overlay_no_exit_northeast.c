#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("no exit northeast");
        set_map_feature_access_override(([
				Direction_Northeast                             : Move_Access_Tunnel,
        ]));
               
}
