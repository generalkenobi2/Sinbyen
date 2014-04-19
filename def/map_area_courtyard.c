#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("courtyard");
	set_map_feature_summary("a spacious courtyard");
	
	add_map_feature_terrain(Terrain_Urban);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("SINBYEN_CITY");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}:}");
	set_map_feature_specify(":");
	set_map_feature_light(1);	
	
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "braziers", "fires" }),
				Identity_Adjectives          : ({ "large {{fiery}flaming}" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The {{fiery}flaming} braziers are are fastened securely atop pedestals around the courtyard."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"The courtyard is decorated with", ({ 'n', 0 }), "."
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Iron,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				])
			}),
		]));
		
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "slabs", "stones" }),
				Identity_Adjectives          : ({ "intricately engraved," }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The {{gray}slabs} were obviously made with much skill, both these, and the engravings",
				"upon them, reflect much time and effort spent.",
				"The slabs seem to depict scenes of battle and epic daring. Most of them "
				"feature two heavily armored anthropoids, one wielding a sword, "
				"and the other a grand battleaxe."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"This is a large courtyard that spans the area between the shops.",
					"It is paved with large,",({ 'n', 0 }), "."
				}),
				Description_Order            : Description_Order_Very_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Concrete,
					Element_Part             : Part_Bulk,

				])
			}),
		]));
}
