#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("cliff");
    set_map_feature_summary("a rocky cliff");
    add_map_feature_terrain(Terrain_Mountains);
    set_map_feature_exposure(Exposure_Exposed);
    add_map_feature_realm("Sinbyen_Mountains");
    add_map_feature_adjacency_exclusion("up");
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{gray}c}");
    set_map_feature_specify("c");
    
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "weeds", "shrubs" }),
                Identity_Flags               : Identity_Flag_Plural,
            ]),
            Abstract_Item_Descriptions       : ({({
                "The {{green}weeds} and {{green}shrubs} provide cling to the {{mottled gray}face} of the rock."
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    "{{green}Shrubs} and", ({ 'n', 0 }), "dot the side of the cliff. The {{green}weeds} sway "
                    "back and forth in the sea breeze."
                }),
                Description_Order            : Description_Order_Middle,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Vegetation,
                    Element_Part             : Part_Bulk,
                    Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
                ])
            }),
        ]));
        
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "face", "cliff" }),
            ]),
            Abstract_Item_Descriptions       : ({({
                "The {{mottled gray}cliff face} is nearly straight up and down, and offers little to climb on."
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    "This is the sheer", ({ 'n', 0 }), "of a cliff. {{green}Tufts} of grass can be"
                    " seen peeking over the ledge several yares above."
                }),
                Description_Order            : Description_Order_Early,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Granite,
                    Element_Part             : Part_Bulk,
                ])
            }),
        ]));
    
}
