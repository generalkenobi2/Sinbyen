#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("a jail cell in Sinbyen's Jailhouse");
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a cramped jail cell",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "low" }),
			Identity_Nouns                              : ({ "bunk bed", "bed" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "sits against the wall here",
			}),
			Description_Order                           : Description_Order_Very_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
                Element_Color                           : "white",
			]),
			([
				Element_Type                            : Material_Cotton,
                Element_Color                           : "white",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is poorly made and has very little padding between the hard",
                    "wood and the person sleeping on it",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "bars" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			"There are",	({ 'n', 0 }), "that cover the entrance",
			}),
			Description_Order                           : Description_Order_Significantly_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Iron,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "serve to keep the inmates in",
                }),
            ]),
        }),
	]));
	
}
