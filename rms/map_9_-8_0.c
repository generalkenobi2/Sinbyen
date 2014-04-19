#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Nature's Wrath");
	add_exit(Direction_North);
	add_exit(Direction_West);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a plant-inhabited shop",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : "The air here is fresh, very fresh in fact",
			])),
		}),
		Description_Order                               : Description_Order_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "planters" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "with varieties of {{dark green}flora} are placed in key places around the room, providing an almost jungle-like atmosphere"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Clay,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "contain anywhere from the most common of plants, to plants",
                    "that look akin to the venascera plant",
                }),
            ]),
        }),
	]));
	set_contents(({
		Sinbyen_NPC("sint"),
	}));
}
