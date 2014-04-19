#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("catacomb tunnel");
    set_map_feature_summary("a tunnel through some catacombs");
    add_map_feature_terrain(Terrain_Ground);
    add_map_feature_terrain(Terrain_Underground);
    remove_map_feature_terrain(Terrain_Urban);
    add_map_feature_realm("Sinbyen_Catacombs");
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{chiaroscuro},}");
    set_map_feature_specify("x");
    set_map_feature_light(0);
    add_map_feature_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "These are the catacombs beneath Sinbyen, a resting place for the honored dead."
        }),
        Description_Order                               : Description_Order_Very_Early,
    ]));
    add_map_feature_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            Description(([
                        Description_Type                : Description_Type_Viewer_Condition,
                        Description_Index               : ([
                        Condition_Type_Code             : Condition_Type_Tactile_Sensation,
                        ]),
                        Description_Content             : "The air here carries a slight chill.",
                    ])),
        }),
        Description_Order            : Description_Order_Early,
    ]));
}
