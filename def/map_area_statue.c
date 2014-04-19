#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("statue");
    set_map_feature_summary("The city square near a statue");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Statue");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{white}S}");
	set_map_feature_specify("S");
}
