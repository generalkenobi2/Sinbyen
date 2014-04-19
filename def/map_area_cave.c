#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("cave");
    set_map_feature_summary("a dark cave");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_terrain(Terrain_Cave);
	set_map_feature_cross_obscure(1.0);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_visualize("{{gray}C}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("C");
	set_map_feature_light(0);
	
	add_map_feature_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"This is a large cave. The only source of light seems to be what little",
			" that trickles in from outside."
		}),
		Description_Order            : Description_Order_Very_Early,
	]));
	
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "Tracks", "footprints", "tracks" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The footprints seem to belong to a clawed anthropoid. They crisscross",
				" the cave and go in all directions",
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					({ 'n', 0 }), "lead in from outside.",
				}),
				Description_Order            : Description_Order_Significantly_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Earth,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				])
			}),
		]));
		
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "firepit", "fire", "pit" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The firepit is smouldering.  It appears to have been used several hours",
				"prior.",
				})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					({ 'a', 0 }), "smoulders near the entrance of the cave.  An",
							Description(([
								Description_Type                        : Description_Type_Element_Name,
								Description_Index                       : Element(([
								Element_Type                 	        : Material_Iron,
								])),
							])),
					"cooking pot sits above the now dormant {{gray-streaked black}fire}.",
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Ash,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				])
			}),
		]));
		add_map_feature_contents(({
			Sinbyen_Misc("stone_bed"),
		}));
		
}