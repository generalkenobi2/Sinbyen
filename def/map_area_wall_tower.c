#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("wall tower");
    set_map_feature_summary("inside a watchtower");
	add_map_feature_terrain(Terrain_Roof);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_access(Move_Access_Walk);
	add_map_feature_realm("Sinbyen_Rooftop");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}T}");
	set_map_feature_specify("T");
    set_map_feature_light(1);
	set_map_feature_access_override(([
		Direction_Down                            : Move_Access_Climb,
    ]));
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "railing", "rails"}),
			]),
			Abstract_Item_Descriptions       : ({({
				"The rails overlook the city."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					({ 'n', 0 }), ({ "run", 0 }), "out of the stone and surrounds the platform.",
				}),
				Description_Order            : Description_Order_Very_Slightly_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pine,
					Element_Part             : Part_Bulk,
				]),
				
			}),
		]));
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "ladder" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The ladder isn't much more than large pegs protruding from the wall."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"A ladder leads downward."
				}),
				Description_Order            : Description_Order_Very_Slightly_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pine,
					Element_Part             : Part_Bulk,
				]),
				
			}),
		]));
}
