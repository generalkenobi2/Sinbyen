#include <Sinbyen.h>
#include <room.h>
#include <items.h>
#include <trader.h>
#include <Vasbarghad.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Auriel's Archery Supply");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_East);
	add_exit(Direction_North);
	set_contents(({
		Sinbyen_NPC("auriel"),
	}));
	
	add_description(({
		"This is an archery supply shop.",
	}));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "bins" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				"There are", ({ 'n', 0 }), "full of arrows of all types laid out across the tables here",
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
                    ({ 't', 0 }), "are the perfect length to house the arrows properly.",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "racks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				"Several", ({ 'n', 0 }), "span across the floor, housing unstrung bows, and an",
				"assortment of gloves, hats, vests, and shoes well suited for archery",
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
                    ({ 't', 0 }), "different sizes and shape depending on what they're designed to hold.",
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
		(: Vasbarghad_Weapon("carbonite_crossbow") :)	: 1,
		(: Vasbarghad_Weapon("corundum_tipped_bolt") :) : 20,
		(: LS_Armour("leather_quiver")	:)	:5,
		(: LS_Weapon("bolt") :)	:20,
		(: LS_Weapon("compound_greatbow") :)	:20,
		(: LS_Weapon("compound_longbow") :)	:20,
		(: LS_Weapon("compound_shortbow") :)	:20,
		(: LS_Weapon("flight_arrow") :)	:20,
		(: LS_Weapon("greatbow") :)	:20,
		(: LS_Weapon("heavy_crossbow") :)	:20,
		(: LS_Weapon("light_crossbow") :)	:20,
		(: LS_Weapon("longbow") :)	:20,
		(: LS_Weapon("recurved_greatbow") :)	:20,
		(: LS_Weapon("recurved_longbow") :)	:20,
		(: LS_Weapon("recurved_shortbow") :)	:20,
		(: LS_Weapon("sheaf_arrow") :)	:20,
		(: LS_Weapon("short_bolt") :)	:20,
		(: LS_Weapon("shortbow") :)	:20,		
	]));
	set_operators(({
		Sinbyen_NPC("auriel"),
	}));
	set_operations(Trader_Shop);
}
