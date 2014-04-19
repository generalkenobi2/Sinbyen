#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("bay floor");
    set_map_feature_summary("the ocean floor of a bay");
    add_map_feature_terrain(Terrain_Bottom);
    set_map_feature_cross_obscure(0.1);
    set_map_feature_exposure(Exposure_None);
    set_map_feature_visualize("{{dark green}%}");
    add_map_feature_realm("SINBYEN_OCEAN");
    set_map_feature_exploration_significant(False);
    set_map_feature_specify("%");
    set_map_feature_light(1);
    
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "waters", "bay"}),
            ]),
            Abstract_Item_Descriptions       : ({({
                "The {{watery}water} is crystal clear",
                    Description(([
                        Description_Type                        : Description_Type_Viewer_Condition,
                        Description_Index                       : ([
                        Condition_Type_Code                       : Condition_Type_Tactile_Sensation,
                        ]),
                        Description_Content                     : ", but is brutally cold",
                    ])),
            
                ".",
                 
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                "The",

                Description(([
                        Description_Type                        : Description_Type_Viewer_Condition,
                        Description_Index                       : ([
                        Condition_Type_Code                       : Condition_Type_Tactile_Sensation,
                        ]),
                        Description_Content                     : "{{gray}icy}",
                ])),
                    
                ({ 'n', 0 }), "of the bay are clear, allowing {{lightfire}light} to "
                "filter in from above.  Fish swim freely about the area, occasionally "
                "stirring up a {{swampy}cloud of murk} from the floor of the bay."
                }),
                Description_Order            : Description_Order_Early,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Water,
                    Element_Part             : Part_Bulk,
                    Element_Flags            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
                ])
            }),
        ]));
}