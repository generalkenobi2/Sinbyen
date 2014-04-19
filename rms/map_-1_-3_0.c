#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("A Crimson Fist Barracks");
	set_exit_flags(Direction_North, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_East, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a military barracks",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity 							: ([
			Identity_Nouns                              : ({ "window" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "looks out over the street"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Glass,
				Element_Color                           : "clear",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is very clean and is free of fingerprints and dirt",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity 							: ([
			Identity_Adjectives                         : ({ "double-stacked" }),
			Identity_Nouns                              : ({ "bunk beds", "beds", "bunks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			"four rows of",	({ 'n', 0 }), "line the walls and the center of this large room",
			}),
			Description_Order                           : Description_Order_Very_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
				Element_Color                           : "red"
			]),
			([
				Element_Type                            : Material_Cotton,
				Element_Color                           : "red",
				Element_Flags           			    : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are neatly made, the sheet on top of them is stretched tight enough to bounce a gold coin on",
                }),
            ]),
        }),
	]));
	
}
