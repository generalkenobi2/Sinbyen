#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("a spacious dining hall");
	set_exit_flags(Direction_West, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	add_exit(Direction_North);
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is", 'a', "luxurious dining hall inside the Rageborn family manor",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "dining table", "table" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "fills a large portion of the room"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Oak,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "has been painstakingly carved out of a single piece of wood.  ",
                    "The legs of the table all of some sort of intricate carving embedded in them.",
                }),
            ]),
        }),
	]));
	add_contents(({
			Sinbyen_Misc("fireplace"),
		}));
}
