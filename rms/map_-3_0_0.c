#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Fontaine's Fishery storage room");
	add_exit(Direction_East);
	add_exit(Direction_North);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the storage room for Fontaine's Fishery.",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "barrels", "boxes", "crates" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), ", {{brown}crates}, and {{brown}boxes} cover nearly every dimin of",
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
                  "Nearly everything in this room seems to have collected a fine layer of dust",
                }),
            ]),
        }),
	]));
}
