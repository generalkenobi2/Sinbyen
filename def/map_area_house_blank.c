#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("house blank");
    set_map_feature_summary("a house");
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_cross_obscure(1.0);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_visualize("{{brown}h}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("3");
	set_map_feature_light(1);
		
}
