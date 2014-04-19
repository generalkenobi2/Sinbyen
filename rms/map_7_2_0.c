#include <Sinbyen.h>
#include <room.h>
#include <trader.h>
#include <items.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)


void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Lady Dibella's Dark Fantasies");
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"This is Lady Dibella's Dark Fantasies, a shop where you can find objects of",
			"questionable nature, that may or may not be frowned upon elsewhere.",
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : " The air here is sweet with fragrance.",
			])),
		}),
		Description_Order                               : Description_Order_Early,
	]));	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "racks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				"Rows of",({ 'n', 0 }), "stretch across the walls from one side of the",
				"room to the other",
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
                    ({ 't', 0 }), "are filled with countless variants of lingerie,",
                    "bonds, ties, whips, chains and various other oddities.",
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
		Sinbyen_NPC("dibella"),
	}));
	set_operations(Trader_Shop);
	
	set_contents(({
		Sinbyen_NPC("dibella"),
		Sinbyen_Misc("sinbyen_trashcan"),
	}));
}
