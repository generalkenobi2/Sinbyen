#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("map_area_base");

void configure() {
	::configure();
	set_map_feature_name("a side street");
    set_map_feature_summary("a side street");
	
		
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_cross_obscure(0.1);
	set_map_feature_exposure(Exposure_Cover);
	set_map_feature_visualize("{{yellow}*}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("*");
}