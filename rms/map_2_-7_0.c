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
	set_short("True Ice");
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_North, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	add_exit(Direction_West);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this appears to be a high class jewelry store",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "display case", "case", "display" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "stretches across one side of the room"
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
                    ({ 't', 0 }), "is filled with diamonds of all shapes and sizes;",
                    "  diamond rings, diamond necklaces, diamond bracelets, diamond earrings etc.",
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
		(: Random_Item_Shop :)          : 10,
	]));
	set_operators(({
		Sinbyen_NPC("meridith"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("meridith"),
	}));

	
}
