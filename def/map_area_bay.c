#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("bay");
    set_map_feature_summary("the surface of a bay");
    set_map_feature_cross_obscure(0.1);
    add_map_feature_terrain(Terrain_Ocean);
    add_map_feature_terrain(Terrain_Surface);
    set_map_feature_access(Move_Access_Swim_Fly);
    add_map_feature_realm("SINBYEN_OCEAN");
    set_map_feature_exposure(Exposure_Exposed);
    set_map_feature_visualize("{{blue}o}");
    set_map_feature_exploration_significant(True);
    set_map_feature_specify("o");
    set_map_feature_light(1);
    add_map_feature_description(
                "The {{watery}waters} of the bay are crystal clear, allowing you to see to the bottom.  "
                "The sea breeze is refreshing and smells lightly of brine.  "
                "The {{watery}water} is cold and icy to the touch."
    );
}