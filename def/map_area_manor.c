#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("manor");
    set_map_feature_summary("a seaside manor");
	
		
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_cross_obscure(1.0);
	set_map_feature_exposure(Exposure_None);
	set_map_feature_visualize("{{purple}m}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("m");
}