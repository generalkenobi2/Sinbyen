#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("rooftop");
    set_map_feature_summary("a grassy rooftop");
	add_map_feature_terrain(Terrain_Roof);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Rooftop");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(False);
	add_map_feature_exit_boundary(Direction_Down, "ceiling");
	set_map_feature_visualize("{{dark green}v}");
	set_map_feature_specify("v");
	set_map_feature_light(1);
	set_map_feature_access(([
		0								: Move_Access_Climb,
		Direction_Up                    : Move_Access_Tunnel,
		Direction_Down                  : Move_Access_Fly,
	]));
	
	add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
			Identity_Nouns               : ({ "grass", "cottongrass", "rooftop" }),
		]),
		Abstract_Item_Descriptions       : ({({
			"It appears that people in this region use sod as part of the rooving insulation."
			"wild rye", ({ 'n', 0 }), ", cottongrass and some species of flower grow well in"
			"the cold climate."
		})}),
		Abstract_Item_Attach_Description : ([
			Description_Type             : Description_Type_Simple,
			Description_Content          : ({
				"The rooftop is covered by a thick layer of insulating {{dark black}sod} and plantlife. "
				"Lush {{dark green}rye}", ({ 'n', 0 }), "and flowers are buffeted by the wind "
				"as it rushes across the rooftops.  Unlike the grass on the fields below, "
				"these have been allowed to grow freely and differ greatly in height and colour."
			}),
			Description_Order            : Description_Order_Early,
		]),
		Abstract_Item_Elements           : ({
			([
				Element_Type             : Material_Grass,
				Element_Part             : Part_Bulk,
				Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
			]),
			
		}),
	]));

}
