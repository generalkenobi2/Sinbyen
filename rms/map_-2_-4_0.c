#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("The Crimson Fist Guildhall");
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_East);
	add_exit(Direction_West);
	add_exit(Direction_North);
	add_exit(Direction_South);
	add_exit(Direction_Northwest);	
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is an open area inside the hall",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity 							: ([
			Identity_Adjectives                         : ({ "rolled" }),
			Identity_Nouns                              : ({ "mats", "mat" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "have been rolled around a nearby support for easy storage",
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Rubber,
				Element_Color                           : "red",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are rather thin and serve just to slightly cushion the hard floor",
                }),
            ]),
        }),
	]));
	
}
