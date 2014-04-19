#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Kim's Candy Exchange Storeroom");
	add_exit(Direction_North);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the storage room for Kim's Candy Exchange.",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "barrels", "boxes", "crates", "jars" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), ", {{brown}crates}, {{clear}jars} and {{brown}boxes} cover nearly every dimin of",
				"this room.",
			}),
			Description_Order                           : Description_Order_Early,
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
                  "The {{brown}containers} are free of dust and have been sanded smooth",
				  " and the {{clear}glass jars} are crystal clear",
                }),
            ]),
        }),
	]));
	
}
