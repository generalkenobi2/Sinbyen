#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("tunnel flooded");
    set_map_feature_summary("a flooded section of tunnel");
    add_map_feature_terrain(Terrain_Ocean);
    remove_map_feature_terrain(Terrain_Urban);
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{blue}*}");
    set_map_feature_specify("!");
    set_map_feature_light(0);
    
}