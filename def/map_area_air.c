#include <Sinbyen.h>
#include <room.h>
#include <altitude.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("air");
	set_map_feature_summary("the air");
	add_map_feature_description(({
		"This is the open air above the city of Sinbyen.",
	}));
	add_map_feature_description(([
		Description_Type        : Description_Type_Viewer_Condition,
		Description_Index       : ([
	    Condition_Type_Code     : Condition_Type_Smell,
		]),
		Description_Content : ({
			"The",
			Description(Description_Type_Ambient_Medium_Colored_Name),
			"is icy and carries the faint scent of smoke from the fires below.",
		}),
	]));
	add_map_feature_realm("Sinbyen_Outside");
	add_map_feature_realm("Sinbyen_Air");
	add_map_feature_terrain(Terrain_Air);
	set_map_feature_exposure(Exposure_Exposed);
	set_map_feature_altitude(2);
	set_map_feature_adjacency("%w is open air.");
	set_map_feature_visualize("{{blue}^}");
	set_map_feature_specify("^");
	set_map_feature_exploration_significant(False);
}