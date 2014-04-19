#include <Sinbyen.h>
#include <room.h>
#include <condition.h>

inherit "/std/def/map_feature";

void configure() {
    ::configure();
    set_broker(project_control());
    set_map_feature_type(Map_Feature_Type_Area);
    add_map_feature_terrain(Terrain_Urban);
    set_map_feature_realms(({
        "Sinbyen",
    }));
}
