#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Fashion_Shoppe.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Jangrid's Rainments");
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_North, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_South);
	add_exit(Direction_East);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is an upscale clothing store",
			
		}),
		Description_Order                               : Description_Order_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "racks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			"sets of",	({ 'n', 0 }), "have been placed about the store and into the walls"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
                Element_Color                           : "white",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "themselves have been painted white and have not a fleck",
                    " missing or blemish on the paint",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "clothing" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "hangs on the {{white}racks}"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Silk,
				Element_Flags							: Element_Flag_Suppress_Color_Name,
				Element_Color							: "white",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are beautifully made",
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
                (: Fashion_Shoppe_Armour("shoes") 		:) : 2,
                (: Fashion_Shoppe_Armour("top_hat") 	:) : 2,
                (: Fashion_Shoppe_Armour("tuxedo") 		:) : 2,
                (: Fashion_Shoppe_Armour("pants") 		:) : 2,
                (: Fashion_Shoppe_Armour("shirt") 		:) : 2,
                (: Fashion_Shoppe_Armour("vest") 		:) : 2,
                (: Fashion_Shoppe_Armour("shirt") 		:) : 2,
                (: Fashion_Shoppe_Armour("skirt") 		:) : 2,
                (: Fashion_Shoppe_Armour("dress") 		:) : 2,

        ]));
	set_operators(({
		Sinbyen_NPC("jangrid"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("jangrid"),
	}));
	
}
