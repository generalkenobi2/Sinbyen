#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Nizari.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Venomous Tendencies");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_East);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is an untidy shop",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "span the back wall"
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
                    ({ 't', 0 }), "are covered in {{red}vials} and {{greenish}beakers}",
                    "of various shapes and sizes",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "ingredients" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			"various",	({ 'n', 0 }), "cover the counter."
			}),
			Description_Order                           : Description_Order_Middle,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Vegetation,
				Element_Flags            				: Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "consist of a variety of different grass, mosses, ferns, mushrooms",
                    " and other miscellaneous plant matter."
                }),
            ]),
        }),
	]));
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(75);
	set_buying_power(500);
	set_inventory_attrition(25);
	set_stock(([
		(: Random_Item_Weapon					:)  : 1,
		(: Nizari_Misc("poison_vial") 			:)	: 10,
		(: Nizari_Comestible("hemlock_herb") 	:) 	: 10,
		(: Nizari_Comestible("foxglove_herb") 	:) 	: 10,
		(: Nizari_Comestible("nightshade_herb") :) 	: 10,
		

	]));
	set_operators(({
		Sinbyen_NPC("vanadius"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("vanadius"),
	}));
}
