#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("catacomb stairs");
    set_map_feature_summary("near a staircase");
    add_map_feature_terrain(Terrain_Ground);
    add_map_feature_terrain(Terrain_Underground);
    remove_map_feature_terrain(Terrain_Urban);
    add_map_feature_realm("Sinbyen_Catacombs");
    add_map_feature_realm("Sinbyen_Catacombs_Deep");
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{red}V}");
    set_map_feature_specify("V");
    set_map_feature_light(0);
    
    add_map_feature_description(([
        Description_Type                     : Description_Type_Simple,
        Description_Content                  : ({
            "These are the catacombs beneath Sinbyen"
        }),
        Description_Order                    : Description_Order_Very_Early,
    ]));
    add_map_feature_description(([
        Description_Type                     : Description_Type_Simple,
        Description_Content                  : ({
            Description(([
                        Description_Type     : Description_Type_Viewer_Condition,
                        Description_Index    : ([
                        Condition_Type_Code  : Condition_Type_Tactile_Sensation,
                        ]),
                        Description_Content  : "the air here is cold",
                    ])),
        }),
        Description_Order                    : Description_Order_Early,
    ]));
    add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "staircase" }),
            ]),
            Abstract_Item_Descriptions       : ({({
                "An ancient", ({ 'n', 0 }), "to be sure, it is chipped and cracked with age"
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    'a', ({ 'n', 0 }), "is here",
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
}
