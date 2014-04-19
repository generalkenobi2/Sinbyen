#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("catacomb tunnel deep");
    set_map_feature_summary("a tunnel through ancient catacombs");
    add_map_feature_terrain(Terrain_Ground);
    add_map_feature_terrain(Terrain_Underground);
    add_map_feature_terrain(Terrain_Ground);
    remove_map_feature_terrain(Terrain_Urban);
    add_map_feature_realm("Sinbyen_Catacombs");
    add_map_feature_realm("Sinbyen_Catacombs_Deep");
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{chiaroscuro},}");
    set_map_feature_specify("X");
    set_map_feature_light(0);
    
    add_map_feature_description(([
        Description_Type                        : Description_Type_Simple,
        Description_Content                     : ({
            "This tunnel is deep in the catacombs beneath Sinbyen, few are buried this far below"
        }),
        Description_Order                       : Description_Order_Very_Early,
    ]));
    add_map_feature_description(([
        Description_Type                        : Description_Type_Simple,
        Description_Content                     : ({
            Description(([
                        Description_Type        : Description_Type_Viewer_Condition,
                        Description_Index       : ([
                        Condition_Type_Code     : Condition_Type_Tactile_Sensation,
                        ]),
                        Description_Content     : "The air here is cold.",
                    ])),
        }),
        Description_Order                       : Description_Order_Early,
    ]));
}
