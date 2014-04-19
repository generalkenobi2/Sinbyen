#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("church");
    set_map_feature_summary("a church");
    add_map_feature_terrain(Terrain_Building);
    add_map_feature_terrain(Terrain_Holy);
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_access(Move_Access_Tunnel);
    add_map_feature_realm("SINBYEN_CHURCH");
    add_map_feature_adjacency_exclusion("up");
    set_map_feature_exploration_significant(True);
    add_map_feature_exit_boundary(Direction_Up, "ceiling");
    set_map_feature_visualize("{{white}I}");
    set_map_feature_specify("I");
    set_map_feature_light(2);


    add_map_feature_description(({
        "this is a small church",
    }));
    add_map_feature_description(({
        Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Hearing,
                ]),
                Description_Content                     : "a pure and resolute tone is barely audible",
			])),
    }));
    add_map_feature_description(({
        Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Tactile_Sensation,
                ]),
                Description_Content                     : "despite the open door, the air here seems to be completely at peace",
			])),
    }));
}