#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("tunnel");
    set_map_feature_summary("an ancient tunnel");
	add_map_feature_terrain(Terrain_Underground);
	add_map_feature_realm("Sinbyen_Tunnel");
	set_map_feature_exposure(Exposure_Enclosed);
	add_map_feature_adjacency_exclusion("up");
	add_map_feature_adjacency_exclusion("down");	
    add_map_feature_adjacency_exclusion("northup");
    add_map_feature_adjacency_exclusion("northeastup");
    add_map_feature_adjacency_exclusion("northwestup");
    add_map_feature_adjacency_exclusion("eastup");
    add_map_feature_adjacency_exclusion("southup");
    add_map_feature_adjacency_exclusion("southeastup");
    add_map_feature_adjacency_exclusion("southwestup");
    add_map_feature_adjacency_exclusion("westup");
    add_map_feature_adjacency_exclusion("northdown");
    add_map_feature_adjacency_exclusion("northeastdown");
    add_map_feature_adjacency_exclusion("northwestdown");
    add_map_feature_adjacency_exclusion("eastdown");
    add_map_feature_adjacency_exclusion("southdown");
    add_map_feature_adjacency_exclusion("southeastdown");
    add_map_feature_adjacency_exclusion("southwestdown");
    add_map_feature_adjacency_exclusion("westdown");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{chiaroscuro},}");
	set_map_feature_specify("x");
	set_map_feature_light(0);
}
