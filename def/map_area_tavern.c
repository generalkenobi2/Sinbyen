#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("tavern");
    set_map_feature_summary("The Raging Gnoll Tavern");
    add_map_feature_terrain(Terrain_Building);
    set_map_feature_exposure(Exposure_Enclosed);
    add_map_feature_realm("SINBYEN_CITY");
    add_map_feature_realm("SINBYEN_TAVERN");
    add_map_feature_adjacency_exclusion("up");
    set_map_feature_exploration_significant(True);
    set_map_feature_visualize("{{red}B}");
    set_map_feature_specify("B");
    set_map_feature_access(Move_Access_Tunnel);
    add_map_feature_exit_boundary(Direction_Up, "ceiling");
    set_map_feature_light(2);
    
    add_map_feature_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "This is the {{blood red}Raging Iyiyik Tavern}. The floor is wet with spilled spirits",
                Description(([
                Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : ", and the air wreaks of alcohol",
            ])), ".",
            
        }),
        Description_Order            : Description_Order_Very_Early,
    ]));
    
    add_map_feature_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            Description(([
                Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Hearing,
                ]),
                Description_Content                     : ({ "It is difficult to hear over the "
                "drunken patrons noisily conversing", }),
            ])),
        }),
        Description_Order            : Description_Order_Early,
    ]));

}
