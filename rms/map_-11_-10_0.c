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
	set_short("The Skooma Den");
	add_exit(Direction_West);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is", 'a', "shady looking bar",
			}),
		Description_Order                               : Description_Order_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"smoke lingers in the air here",
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : ", that smells of questionable legality",
			])),
			".",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "bar" }),
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
				Element_Type                            : Material_Ironwood,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is well polished but has its share of dents and nicks",                }),
            ]),
        }),
	]));
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(75);
	set_buying_power(2000);
	set_inventory_attrition(25);
	set_stock(([
		(:	Sinbyen_Comestible("sinbyen_lager")	:)	: 3,
		(:	Sinbyen_Comestible("water_pack")	:)	: 3,
		(:	Sinbyen_Comestible("beer")			:)	: 3,
		(:	LS_Comestible("melange_beer")		:)	: 5,
		(:	LS_Comestible("melange_coffee")		:)	: 5,
		(:	LS_Comestible("melange_extract")	:)	: 5,
		(:	LS_Comestible("melange_stick")		:)	: 5,
		(:	LS_Comestible("melange_tea")		:)	: 5,
	]));
	set_operators(({
		Sinbyen_NPC("toker"),
	}));
	set_operations(Trader_Shop);
}
