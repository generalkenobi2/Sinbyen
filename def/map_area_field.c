#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("field");
    set_map_feature_summary("an area of open field");
	add_map_feature_terrain(Terrain_Grasslands);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Field");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{green}\"}");
	set_map_feature_specify("\"");
	set_map_feature_light(1);
	
		add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
			Identity_Nouns               : ({ "rye", "grass" }),
		]),
		Abstract_Item_Descriptions       : ({({
			({ 't', 0 }), "{{dark green}grass} is tall and healthy. It appears to be well cared for, as they are evenly cut and is free of bare spots."
		})}),
		Abstract_Item_Attach_Description : ([
			Description_Type             : Description_Type_Simple,
			Description_Content          : ({
				"The area is covered in {{dark green}dark green}", ({ 'n', 0 }), "{{dark green}grass} and a variety of {{white-purple sequence}small flowers}."
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
