#include <Sinbyen.h>
#include <room.h>


inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("earth");
	set_map_feature_summary("the earth");
	add_map_feature_terrain(Terrain_Solid);
	set_map_feature_access(Move_Access_Tunnel);
	set_map_feature_exposure(Exposure_None);
	set_map_feature_suppress_all_adjacency(True);
	set_map_feature_visualize("{{brown}@}");
	set_map_feature_specify("e");
	set_map_feature_exploration_significant(False);
	set_map_feature_light(0);

}