#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("road");
    set_map_feature_summary("a dirt road");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Road");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{brown}*}");
	set_map_feature_specify("r");
	add_map_feature_description(({
		"a wide {{brown}dirt} road",
	}));
	add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "road" }),
		]),
		Abstract_Item_Descriptions       : ({
				"The {{brown}dirt} road has seen much use."
		}),
		Abstract_Item_Elements           : ({
			([
				Element_Type             : Material_Earth,
				Element_Part             : Part_Bulk,
				Element_Flags            : Element_Flag_Suppress_Part_Description,
			])
		}),
	]));
}
