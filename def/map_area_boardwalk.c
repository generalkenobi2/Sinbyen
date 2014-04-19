#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("boardwalk");
    set_map_feature_summary("a sturdy boardwalk");		
	add_map_feature_terrain(Terrain_Building);
	set_map_feature_cross_obscure(0.1);
	set_map_feature_exposure(Exposure_Cover);
	set_map_feature_visualize("{{brown}/}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify("/");
	set_map_feature_light(1);
	
		add_map_feature_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "boardwalk" }),
			]),
			Abstract_Item_Descriptions       : ({({
				"All of the {{brown}wood} above and below the {{brown}walk} seems to be made of large pieces",
				" of treated {{brown}oak wood}.  It was clearly built to last",
			})}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
					"This is a", ({ 'n', 0 }), ".  Despite protests from the wind and waves",
					",it stands completely still on it's thick supports."
					"This boardwalk serves as not only as a convenient fishing spot, but also sees"
					" regular traffic from passenger and fishing vessels."
				}),
				Description_Order            : Description_Order_Early,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Pine,
					Element_Part             : Part_Bulk,
					Element_Flags            : Element_Flag_Suppress_Part_Description,
				])
			}),
		]));
	}
