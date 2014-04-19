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
	set_short("Sintel's Weapons");
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	
	add_description(({
	
	"This is Sintel's Weaponry, two aisles run the length of the store.",
	
	}));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "racks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			({ 'n', 0 }), "run the length of both aisles.",
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Iron,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are laden with an assortment of various weapon types,",
                    "and sizes.",
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
		(: Random_Item_Weapon :)          : 10,
	]));
	set_operators(({
		Sinbyen_NPC("sintel"),
	}));
	set_operations(Trader_Shop);
	
	set_contents(({
		Sinbyen_NPC("sintel"),
	}));
	
}
