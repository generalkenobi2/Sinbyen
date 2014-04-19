#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Kim's Candy Exchange");
	add_exit(Direction_West);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a candy store",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "jars", "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "line the shelves and counters here"
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
                    ({ 't', 0 }), "have been placed just out of reach of smaller children on the upper shelves and",
                    "towards the rear of the counters.  The jars are filled with all manner of candies and other sweets",
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
		(: Sinbyen_Comestible("fizzy_apple") :)          : 10,
		(: Sinbyen_Comestible("fizzy_cherry") :)          : 10,
		(: Sinbyen_Comestible("fizzy_grape") :)          : 10,
		(: Sinbyen_Comestible("fizzy_lime") :)          : 10,
		(: Sinbyen_Comestible("fizzy_melon") :)          : 10,
		(: Sinbyen_Comestible("fizzy_orange") :)          : 10,
		(: Sinbyen_Comestible("honey_sucker") :)          : 10,
		(: Sinbyen_Comestible("honey_chew") :)          : 10,
	]));
	set_operators(({
		Sinbyen_NPC("kim"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("kim"),
	}));
}

