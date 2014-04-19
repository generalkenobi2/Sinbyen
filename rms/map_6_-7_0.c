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
	set_short("Amstaar's Alchemy");
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_North, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	add_exit(Direction_West);
	add_exit(Direction_East);
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "full of {{red}potions} and {{greenish}vials} span the back wall"
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
                    ({ 't', 0 }), "are covered in {{red}vials} and {{greenish}beakers}",
                    "of various shapes and sizes",
                }),
            ]),
        }),
	]));
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(1);
	set_buying_power(10000);
	set_inventory_attrition(25);
	set_stock(([
		(: LS_Potion("great_growth") 				:)          : 2,
		(: LS_Potion("great_shrinking") 			:)          : 2,
		(: LS_Potion("great_healing") 				:)          : 5,
		(: LS_Potion("great_spirit_restoration") 	:)          : 5,
	]));
	set_operators(({
		Sinbyen_NPC("amstaar"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("amstaar"),
	}));
}
