#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("catacomb headstone");
    set_map_feature_summary("near a large headstone");
    add_map_feature_terrain(Terrain_Unholy);
    add_map_feature_terrain(Terrain_Ground);
    add_map_feature_realm("Sinbyen_Catacombs");
    add_map_feature_realm("Sinbyen_Catacombs_Deep");
    add_map_feature_realm("Sinbyen_Catacombs_Ancient");
    remove_map_feature_terrain(Terrain_Urban);
    add_map_feature_adjacency_exclusion("up");
    add_map_feature_adjacency_exclusion("down");
    set_map_feature_exposure(Exposure_None);
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{gray}+}");
    set_map_feature_specify("+");
    set_map_feature_light(0);
    add_map_feature_description(([
        Description_Type                    : Description_Type_Simple,
        Description_Content                 : ({
            "This is deep in the catacombs beneath Sinbyen",
        }),
        Description_Order                   : Description_Order_Early,
    ]));
    add_map_feature_abstract_item(([
        Abstract_Item_Identity              : ([
            Identity_Adjectives             : ({ "destroyed" }),
            Identity_Nouns                  : ({ "gravestone" }),
        ]),
        Abstract_Item_Attach_Description    : ([
            Description_Type                : Description_Type_Simple,
            Description_Content             : ({
                ({ 'a', 0 }), "is lying on the ground",
            }),
            Description_Order               : Description_Order_Early,
        ]),
        Abstract_Item_Elements              : ({
            ([
                Element_Type                : Material_Granite,
            ]),
        }),
        Abstract_Item_Descriptions          : ({
            ([
                Description_Type            : Description_Type_Simple,
                Description_Content         : ({
                    ({ 't', 0 }), "appears to have shattered when whoever, or whatever, was buried inside",
                    " emerged"
                }),
            ]),
        }),
    ]));
    add_map_feature_description(([
        Description_Type            : Description_Type_Viewer_Condition,
        Description_Index           : ([
            Condition_Type_Code     : Condition_Type_Astral_Perception,
            Condition_Value         : (3),
        ]),
        Description_Content         : ({
            "The area seems almost alive with an {{unholy fire}ancient, evil, power}.",
        }),
    ]));
}
