#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("cave roof");
    set_map_feature_summary("atop a large cave");
	add_map_feature_terrain(Terrain_Roof);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Rooftop");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(False);
	add_map_feature_exit_boundary(Direction_Down, "roof of the cave");
	set_map_feature_visualize("{{gray}v}");
	set_map_feature_specify("y");
	set_map_feature_light(1);
	set_map_feature_access(([
		0								: Move_Access_Climb,
		Direction_Up                    : Move_Access_Tunnel,
		Direction_Down                  : Move_Access_Fly,
	]));

	add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
			Identity_Nouns               : ({ "moss"}),
		]),
		Abstract_Item_Descriptions       : ({({
			"The moss grows well atop this cave."
		})}),
		Abstract_Item_Attach_Description : ([
			Description_Type             : Description_Type_Simple,
			Description_Content          : ({
				"The top of this cave has small patches of", ({ 'n', 0 }), "scattered about."
			}),
			Description_Order            : Description_Order_Early,
		]),
		Abstract_Item_Elements           : ({
			([
				Element_Type             : Material_Moss,
				Element_Part             : Part_Bulk,
				Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
			]),
			
		}),
	]));
}
