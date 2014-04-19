#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("bloodfist boulevard");
    set_map_feature_summary("on Bloodfist Boulevard");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_exposure(Exposure_Exposed);
	set_map_feature_visualize("{{tan}-}");
	add_map_feature_realm("Sinbyen_Street");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("1");
}