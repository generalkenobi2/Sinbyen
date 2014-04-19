#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("building blank");
    set_map_feature_summary("a building");
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_realm("SINBYEN_CITY");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	add_map_feature_exit_boundary(Direction_Up, "ceiling");
	set_map_feature_visualize("{{brown}b}");
	set_map_feature_specify("2");
	set_map_feature_light(2);
}
