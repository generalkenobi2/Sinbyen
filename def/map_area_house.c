#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
    ::configure();
    set_map_feature_name("house");
    set_map_feature_summary("a house");
    set_map_feature_access(Move_Access_Tunnel);
    add_map_feature_terrain(Terrain_Building);
    set_map_feature_cross_obscure(1.0);
    set_map_feature_exposure(Exposure_Enclosed);
    set_map_feature_visualize("{{brown}h}");
    set_map_feature_exploration_significant(True);
    set_map_feature_specify("h");
    set_map_feature_light(1);
    add_map_feature_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is", 'a', "simple log home."
        }),
        Description_Order            : Description_Order_Very_Early,
    ]));
    
    add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "windows" }),
                Identity_Adjectives			 : ({ "thick" }),
            ]),
            Abstract_Item_Descriptions       : ({({
                ({ 't', 0 }), "are double-paned, and built to withstand harsh weather.",
            })}),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                ({ 'n', 0 }), "look out over the street.",
                }),
                Description_Order            : Description_Order_Early,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Glass,
                    Element_Part             : Part_Bulk,
                    Element_Color			 : "clear",
                ])
            }),
        ]));
        
        add_map_feature_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "spit", "pot", "utensils" }),
            ]),
            Abstract_Item_Descriptions       : ({
                ({ "The", 		
                Description(([
                    Description_Type    : Description_Type_Element_Name,
                    Description_Index   : Material_Steel,
                    Description_Flags   : Description_Flag_Noun,
                    Description_Content : "spit",
                ])), ", {{gray}pot}, and {{gray}utensils} seem to be well used, but in good condition.",})
            }),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                ({ 'a', 0 }), ", {{gray}pot}, and {{gray}utensils} are neatly arranged near the fire",
                }),
                Description_Order            : Description_Order_Significantly_Early,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Steel,
                    Element_Part             : Part_Bulk,
                ])
            }),
        ]));
        add_map_feature_contents(({
            Sinbyen_Misc("fireplace"),
        }));
        add_map_feature_contents(({
            Sinbyen_Misc("sinbyen_bed"),
        }));
        add_map_feature_contents(({
            Sinbyen_Misc("sinbyen_chair"),
        }));
        add_map_feature_contents(({
            Sinbyen_Misc("sinbyen_table"),
        }));
                    
}