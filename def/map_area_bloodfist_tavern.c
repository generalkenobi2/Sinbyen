#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("tavern");
    set_map_feature_summary("The Raging Gnoll Tavern");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Tavern");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{red}B}");
	set_map_feature_specify("B");
}
