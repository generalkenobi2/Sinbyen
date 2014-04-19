#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Losthaven.h>
#include <Yathryn.h>
#include <Avalon.h>
#include <Darkhold.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Agin's Dragon Emporium");
	set_code("Agin's Dragon Emporium");
	add_exit(Direction_East);
	add_exit(Direction_West);	
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the Dragon Emporium, a shop where one can find anything and everything relating to dragons.",
		}),
		Description_Order                               : Description_Order_Very_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "shelves", "displays", }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				"There are", ({ 'n', 0 }), "and {{clear}displays} all across the shop that display",
				"all manner of dragon accessories",
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
                    ({ 't', 0 }), "and {{clear}displays} are loaded with small {{gold}statues} of dragons, {{green}dragon puppets},",
                    "{{white-white-blue sequence}dragon embroided clothing} and a multitude of other unique items.",
                }),
            ]),
        }),
	]));
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(75);
	set_buying_power(10000);
	set_inventory_attrition(25);
	set_stock(([
		(: Random_Item_Shop :)          			: 1,
		(: Losthaven_Misc("doll_dragon") 		:)	: 2,
		(: LS_Comestible("dragon_haunch") 		:)	: 2,
		(:	Yathryn_Comestible("dragon_blood") 	:)	: 4,
		(:	Avalon_Comestible("dragon_egg")		:)	: 2,
		(:	Darkhold_Weapon("dragon_puppet") 	:)	: 4,
		(:	Sinbyen_Misc("trophy")				:)	: 3,
	]));
	set_operators(({
		Sinbyen_NPC("agin_dragonclaw"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("agin_dragonclaw"),
		Sinbyen_Misc("sinbyen_trashcan"),
		Sinbyen_NPC("gramp"),
	}));
}
