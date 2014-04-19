#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("portcullis");
    set_map_feature_summary("a large city gate");
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_exposure(Exposure_Exposed);
	set_map_feature_access(Move_Access_Walk);
	add_map_feature_realm("SINBYEN_CITY");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}#}");
	set_map_feature_specify("#");
	set_map_feature_light(1);

	add_map_feature_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"This is one Sinbyen's gates, all traffic to and from the city must pass through here.",
		}),
		Description_Order            : Description_Order_Very_Early,
	]));
	
	add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "portcullis", "gate", }),
			]),
			Abstract_Item_Descriptions       : ({
			({	"the",({ 'n', 0 }), "is massive.  The incredible bulk of the portcullis", 
				"is secured by thick",
					Description(([
						Description_Type                        : Description_Type_Element_Name,
						Description_Index                       : Element(([
						Element_Type                        : Material_Steel,
						Element_Color                       : "polished",
						])),
					])),
				"chains.  Each {{white}chain} appears to lead to a large counterweight secured within the gate.",
			}),	
			}),
			
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
				({ 'a', 0 }), "is sheathed within the gate structure atop the gate above.",
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Steel,
					Element_Part             : Part_Bulk,
					Element_Color			 : "gray",
				])
			}),
		]));
	
}
