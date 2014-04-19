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
	set_short("Wickett's General Goods");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_North, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_North);
	add_exit(Direction_West);
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"This is a small store that appears to sell a large variety of goods",
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
			"There are", ({ 'a', 0 }), "and {{brown}bins} of an assortment of goods here."
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
                    ({ 't', 0 }), "carry all manner of goods, some that look new, and some",
                    "that appear as though they've been to the exoma and back",
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
		(: Random_Item_Shop 			:)		: 5,
		(: LS_Container("backpack")		:)  	: 4,
		(: LS_Equipment("torch")        :) 		: 50,
		(: LS_Equipment("oil_flask")    :)  	: 20,
		(: LS_Equipment("compass")      :)		: 8,
		(: LS_Comestible("canteen")     :)		: 6,
	]));
	set_operators(({
		Sinbyen_NPC("wickett"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("wickett"),
	}));
}
