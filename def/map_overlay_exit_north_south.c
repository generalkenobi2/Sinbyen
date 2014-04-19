#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("exit north south");
        set_map_feature_access_override(([
                Direction_North                          : Move_Access_Walk,
				Direction_South                          : Move_Access_Walk,
        ]));
               
}
