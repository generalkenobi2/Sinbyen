#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("rocky beach");
    set_map_feature_summary("a rocky shoreline");
	add_map_feature_terrain(Terrain_Beach);
	set_map_feature_exposure(Exposure_Exposed);
	add_map_feature_realm("Sinbyen_Beach");
	add_map_feature_adjacency_exclusion("up");
	set_map_feature_exploration_significant(True);
	set_map_feature_visualize("{{gray}~}");
	set_map_feature_specify("~");
	set_map_feature_light(1);
	
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "{{black}shore}", "shells", "beach", "shoreline", "shore"}),
				Identity_Adjectives          : ({ "{{black}rocky}" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"The beach is covered in driftwood and sharp rocks.  The shells "
				"were likely washed up with the tide."
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
				"Waves crash against the", ({ 'n', 0 }), ", producing a chilling mist, "
				"before receding back into the bay.  Shells lie scattered up and down "
				"the beach.  Piles of driftwood and leaves litter the shore"
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pumice,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
				])
			}),
		]));
}
