#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("forest");
    set_map_feature_summary("a coniferous forest");    
    set_map_feature_exposure(Exposure_None);
    add_map_feature_terrain(Terrain_Building);
    add_map_feature_terrain(Terrain_Tunnel);
    add_map_feature_realm("SINBYEN_FOREST");
    set_map_feature_visualize("{{forest green}f}");
    set_map_feature_specify("f");
    set_map_feature_light(1);
    
    add_map_feature_description(([
        Description_Type                                : Description_Type_Viewer_Condition,
        Description_Index                               : ([
            Condition_Type_Code                         : Condition_Type_Daytime,
        ]),
        Description_Content                             : ({
            Description(([
                    Description_Type                    : Description_Type_Viewer_Condition,
                    Description_Index                   : ([
                    Condition_Type_Code                 : Condition_Type_Hearing,
                    ]),
                    Description_Content                 : ({"The area is alive with the sounds",
                    "of nature; birds chirping, bees buzzing, and bushes rustling in the wind.",}),
            ])),    "Insects are darting from place to place.",
        }),
        Description_Order                               : Description_Order_Slightly_Early,
    ]));
    add_map_feature_description(([
        Description_Type                                : Description_Type_Viewer_Condition,
        Description_Index                               : ([
            Condition_Type_Code                         : Condition_Type_Daytime,
            Condition_Flags                             : Condition_Flag_Inverse,
        ]),
        Description_Content                             : ({
            "The night air rushes through the nearby trees",
                                
                Description(([
                        Description_Type                : Description_Type_Viewer_Condition,
                        Description_Index               : ([
                        Condition_Type_Code             : Condition_Type_Hearing,
                        ]),
                        Description_Content             : ", rustles the leaves",
                ])),
            ", and causes the branches to sway lazily.",
        }),
        Description_Order                               : Description_Order_Slightly_Early,
    ]));                                             
    add_map_feature_abstract_item(([
        Abstract_Item_Identity           : ([
            Identity_Nouns               : ({ "trees", "forest" }),
            Identity_Adjectives          : ({ "tall" }),
            Identity_Flags               : Identity_Flag_Plural,
        ]),
        Abstract_Item_Descriptions       : ({({
            "The", ({ 'n', 0 }), "are tall and healthy."
        })}),
        Abstract_Item_Attach_Description : ([
            Description_Type             : Description_Type_Simple,
            Description_Content          : ({
                "The area is covered with", ({ 'n', 0 }), ".",             
                
            }),
            Description_Order            : Description_Order_Early,
        ]),
        Abstract_Item_Elements           : ({
            ([
                Element_Type             : Material_Pine,
                Element_Part             : Part_Bulk,
                Element_Flags            : Element_Flag_Suppress_Part_Description,
            ]),
            
            ([
                Element_Type             : Material_Leaf,
                Element_Part             : Part_Coat,
                Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
            ]),
        }),
    ]));
    add_map_feature_description(([
        Description_Type                 : Description_Type_Viewer_Condition,
        Description_Index                : Condition_Type_Smell,
        Description_Content              : ({
            "In the air hangs the scent of fresh {{brown}resin} and {{forest green}evergreens}.",
        }),
    ]));
}