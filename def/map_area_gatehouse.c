#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("gatehouse");
    set_map_feature_summary("a gatehouse");
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_exposure(Exposure_Enclosed);
	set_map_feature_access(Move_Access_Tunnel);
	add_map_feature_realm("SINBYEN_CITY");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{dark gray}G}");
	set_map_feature_specify("G");
	set_map_feature_light(2);

	add_map_feature_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the inside of one of the city gatehouses."
		}),
		Description_Order            : Description_Order_Very_Early,
	]));
	
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "torches", "sconces" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The {{fiery}flaming} {{brown}pine torches} are placed on either side of the room to provide"
				" light for the mechanical parts of the gate system."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"On either side of the room {{fiery}flaming}", ({ 'n', 0 }), "are housed in"
					" {{dark gray}iron sconces}"
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
				Identity_Nouns               : ({ "gears", "parts", "mechanical parts", "counterweights", "chains", "weights"}),
			]),
			Abstract_Item_Descriptions       : ({({
				"The gear system looks rather complex, though robust.  The gears appear to operate",
				"sets of thick",

						Description(([
							Description_Type                        : Description_Type_Element_Name,
							Description_Index                       : Element(([
								Element_Type                        : Material_Steel,
								Element_Color                       : "polished",
							])),
						])),
				"chains, which in turn allow the gate's {{gray}portcullis} to move up and down through",
				"the use of {{black}large counterweights}.",
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"The room houses a system of", ({ 'n', 0 }), ", {{black}large counterweights}, and thick {{white}chains}.",
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Steel,
					Element_Part             : Part_Bulk,
					Element_Color			 : "black",
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
					"A ladder leads upward."
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
		set_map_feature_access_override(([
				Direction_Up                             : Move_Access_Climb,
        ]));
}
