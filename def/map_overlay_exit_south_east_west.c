#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("exit south east west");
        set_map_feature_access_override(([
                Direction_South                          : Move_Access_Walk,
				Direction_East                           : Move_Access_Walk,
				Direction_West                           : Move_Access_Walk,
        ]));
               
}
