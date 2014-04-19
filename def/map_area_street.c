#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("street");
    set_map_feature_summary("a paved stone street");
    add_map_feature_terrain(Terrain_Street);
    set_map_feature_exposure(Exposure_Exposed);
    set_map_feature_visualize("{{gray}=}");
    add_map_feature_realm("SINBYEN_CITY");
    add_map_feature_realm("SINBYEN_STREET");
    add_map_feature_adjacency_exclusion("up");
    set_map_feature_exploration_significant(True);
    set_map_feature_specify("=");
    set_map_feature_light(1);
    
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "braziers", "fires" }),
                Identity_Flags               : Identity_Flag_Plural,
            ]),
            Abstract_Item_Descriptions       : ({({
                "The {{fiery}flaming} braziers are are placed securely atop pedestals near the curb."
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    "On either side of the street {{fiery}flaming}", ({ 'n', 0 }), "can be found."
                }),
                Description_Order            : Description_Order_Middle,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Iron,
                    Element_Part             : Part_Bulk,
                    Element_Flags            : Element_Flag_Suppress_Part_Description,
                ])
            }),
        ]));
        
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "street", "stones", "blocks" }),
            ]),
            Abstract_Item_Descriptions       : ({({
                "This smooth street has been skillfully paved with setts.  Each block meeting "
                "the next in a concentric circles.  This pattern continues down the street"
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    "This is a main city", ({ 'n', 0 }), ". The area is clean and free of "
                    "debris and other trash.  The air is sweet with the smell of pine wood "
                    "and roasted meats.  The area is filled with the sounds of children "
                    "playing, dogs barking, and the idle chatter of the inhabitants."
                    
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