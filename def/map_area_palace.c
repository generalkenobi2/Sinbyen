#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("palace");
    set_map_feature_summary("the royal palace");
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_exposure(Exposure_None);
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_realm("Sinbyen_Palace");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{purple}p}");
	set_map_feature_specify("p");
}
