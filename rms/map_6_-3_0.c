#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <Grinning_Cat.h>
#include <trader.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	add_extension(Grinning_Cat_Support);
	set_short("Mammoth Joe's Barbecue");
	add_exit(Direction_North);
	add_exit(Direction_West);
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is", 'a', "spacious diner.",
			
		}),
		Description_Order                               : Description_Order_Very_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : "The aroma of barbecue and roasted meats is fantastic.",
			])),
			
		}),
		Description_Order                               : Description_Order_Middle,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "tables" }),
			Identity_Adjectives							: ({ "long" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
			({ 'n', 0 }), "are here to seat the patrons as they enjoy their food."
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
                    ({ 't', 0 }), "look worn but have been polished to shine.",
                    " The owner of the establishment seems to take pride in having a clean shop."
                }),
            ]),
        }),
	]));
	set_operators(({
		Sinbyen_NPC("joe"),
	}));
	set_stock(([
		Grinning_Cat_Comestible("acqua_frizzante")         :30,
		Sinbyen_Comestible("mammoth_bacon")	: 30,
		Sinbyen_Comestible("mammoth_steak") : 6,
		Sinbyen_Comestible("mammoth_salad")	: 6,
		Sinbyen_Comestible("mammoth_wings") : 30,
		Sinbyen_Comestible("mammoth_burger"): 10,
	]));
	set_list_header_left("Food");
	set_list_header_right("Price");
	set_haggle_optimum(75);
	set_buying_power(1000);
	set_inventory_display(({ "menu" }), Skill_Norska);
	set_inventory_static(True);
	set_operations(Trader_Tavern);
}
