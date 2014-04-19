#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	::configure();
	set_map_feature_name("trail");
    set_map_feature_summary("a wooded trail");
	add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
			Identity_Nouns               : ({ "trail", "path" }),
		]),
			Abstract_Item_Descriptions       : ({({
				"A {{light brown}trail} carves its way through the {{forest}trees} here",
                        Description(([
                                Description_Type                    : Description_Type_Element_Name,
                                Description_Index                   : Element(Material_Earth),
                                Description_Flags                   : Description_Flag_Noun,
                        ])),
            })}),
		Abstract_Item_Attach_Description : ([
			Description_Type             : Description_Type_Simple,
			Description_Content          : ({
				"The {{light brown}trail} is narrow and cuts through the trees",
                                Description(([
                                        Description_Type                    : Description_Type_Element_Name,
                                        Description_Index                   : Element(Material_Earth),
                                        Description_Flags                   : Description_Flag_Noun,
                                ])),
			}),
		]),
		Abstract_Item_Elements           : ({
                        Material_Earth,
		}),
	]));
	add_map_feature_abstract_item(([
		Abstract_Item_Identity           : ([
			Identity_Nouns               : ({ "trees" }),
		]),
			Abstract_Item_Descriptions       : ({({
				"The {{forest}trees} green and lush, and their branches healhty and sticky with resin",
                        Description(([
                                Description_Type                    : Description_Type_Element_Name,
                                Description_Index                   : Element(Material_Leaf),
                                Description_Flags                   : Description_Flag_Noun,
                        ])),
            })}),
		Abstract_Item_Attach_Description : ([
			Description_Type             : Description_Type_Simple,
			Description_Content          : ({
				"Coniferous trees line both sides of the path, leaving the air smelling fresh",
                                Description(([
                                        Description_Type                    : Description_Type_Element_Name,
                                        Description_Index                   : Element(Material_Fir),
                                        Description_Flags                   : Description_Flag_Noun,
                                ])),
			}),
		]),
		Abstract_Item_Elements           : ({
                        Material_Fir,
						Material_Leaf,
		}),
	]));
	
	add_map_feature_terrain(Terrain_Forest);
	set_map_feature_cross_obscure(0.1);
	set_map_feature_exposure(Exposure_Cover);
	set_map_feature_visualize("{{light brown}.}");
	set_map_feature_exploration_significant(True);
	set_map_feature_specify(".");
		set_map_feature_access(([
        Direction_Up                            : Move_Access_Tunnel,
    ]));
}
