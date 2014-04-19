#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("wall top");
    set_map_feature_summary("the top of the city wall");
	add_map_feature_terrain(Terrain_Roof);
	set_map_feature_access(Move_Access_Walk);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Rooftop");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}_}");
	set_map_feature_specify("_");
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "walk"}),
			]),
			Abstract_Item_Descriptions       : ({({
				"The walk looks sturdy enough."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					({ 'v', 0 }), ({ 'n', 0 }), ({ "run", 0 }), "out and around the city, giving a great vantage point against invaders.",
				}),
				Description_Order            : Description_Order_Very_Slightly_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Granite,
					Element_Part             : Part_Bulk,
				]),
				
			}),
		]));
}
