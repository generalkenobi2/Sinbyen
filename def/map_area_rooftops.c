#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("rooftop");
    set_map_feature_summary("an empty rooftop");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Rooftop");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}v}");
	set_map_feature_specify("v");
}
