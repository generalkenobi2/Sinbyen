#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("wall occupied");
	set_map_feature_summary("inside a watch tower");
	add_map_feature_terrain(Terrain_Building);
	add_map_feature_realm("Sinbyen_Wall");
	set_map_feature_exposure(Exposure_None);
	set_map_feature_access(Move_Access_Walk);
	set_map_feature_suppress_all_adjacency(True);
	set_map_feature_visualize("{{dark gray}T}");
	set_map_feature_specify("T");
	set_map_feature_exploration_significant(True);
}