#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("building");
    set_map_feature_summary("a building");
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_realm("SINBYEN_CITY");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	add_map_feature_exit_boundary(Direction_Up, "ceiling");
	set_map_feature_visualize("{{brown}b}");
	set_map_feature_specify("b");
	set_map_feature_light(2);
	
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "counter", "stools" }),
			]),
			Abstract_Item_Descriptions       : ({
				({({ 't', 0 }), "is set with various items and is clearly where most of the",
				"business here is done. Two {{brown}stools} are tucked beneath the front of it.", }),
			}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"There is a large", ({ 'n', 0 }), "and two {{brown}stools} nearby.",
				}),
				Description_Order            : Description_Order_Middle,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pine,
					Element_Part             : Part_Bulk,
				])
			}),
		]));
}
