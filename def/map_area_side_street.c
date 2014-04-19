#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("side street");
    set_map_feature_summary("a quiet side street");
	add_map_feature_terrain(Terrain_Road);
	set_map_feature_cross_obscure(0.1);
	set_map_feature_exposure(Exposure_Cover);
	set_map_feature_visualize("{{white}-}");
	add_map_feature_realm("SINBYEN_CITY");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("-");
	set_map_feature_light(1);
	
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "torches", "sconces" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The {{fiery}flaming} {{brown}pine torches} are positioned strategically to provide light"
				"for the entire street.  They are mounted against the wall with {{dark gray}iron sconces}."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"On either side of the street {{fiery}flaming}", ({ 'n', 0 }), "are housed in"
					" {{dark gray}iron sconces}"
				}),
				Description_Order            : Description_Order_Middle,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pine,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Suppress_Part_Description,
				]),
				
				([
					Element_Type             : Material_Iron,
					Element_Part             : Part_Coat,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				]),
			}),
		]));
		
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "street", "stones", "blocks" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"This street seems to see less traffic than the main streets, though it was"
				" constructed with no less care.  Each brick is staggered at half width to the "
				"next, resulting in a pleasing, stair-like pattern."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"This is a more sheltered side", ({ 'n', 0 }), ".  The wind is less noticeable "
					"here.  Small patches of {{green}moss} grow along some of the buildings in the shadier"
					" spots.  The noise from the main streets is still faintly audible."
					
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Granite,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				])
			}),
		]));
}