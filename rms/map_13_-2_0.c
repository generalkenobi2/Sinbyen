#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("An storage room");
	add_exit(Direction_West);
	
	add_description(({
		"This is a plain storage room.",
	}));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				"There are", ({ 'n', 0 }), "that run along the bare walls here.",
			}),
			Description_Order                           : Description_Order_Middle,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are completely empty, and are covered in a light layer of dust.",
                }),
            ]),
        }),
	]));
}
