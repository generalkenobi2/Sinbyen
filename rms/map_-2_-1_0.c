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
	set_short("Starling Sprite Fruits");
	add_exit(Direction_East);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"This is a fruit filled shop",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "netted" }),
			Identity_Nouns                              : ({ "baskets" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "loaded with various fruits hang from the ceiling"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Brass,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "appear to have been recently polished.",
                    "  They contain a variety of fruits",
						Description(([
							Description_Type                        : Description_Type_Viewer_Condition,
							Description_Index                       : ([
								Condition_Type_Code                 : Condition_Type_Hearing,
							]),
							Description_Content                     : " that smell delicious",
						])),
					".",
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
		(: LS_Comestible("banana") 			:)          : 10,
		(: LS_Comestible("apple") 			:)          : 10,
		(: LS_Comestible("berries") 		:)          : 10,
		(: LS_Comestible("blackberry") 		:)          : 10,
		(: LS_Comestible("blueberry") 		:)          : 10,
		(: LS_Comestible("cherry") 			:)          : 10,
		(: LS_Comestible("cranberry") 		:)          : 10,
		(: LS_Comestible("grape") 			:)          : 10,
		(: LS_Comestible("kiwi") 			:)          : 10,
		(: LS_Comestible("nectarine") 		:)          : 10,
		(: LS_Comestible("orange") 			:)          : 10,
		(: LS_Comestible("papaya") 			:)          : 10,
		(: LS_Comestible("peach") 			:)          : 10,
		(: LS_Comestible("pear") 			:)          : 10,
		(: LS_Comestible("plum") 			:)          : 10,
		(: LS_Comestible("pineapple") 		:)          : 10,
		(: LS_Comestible("pomegranate") 	:)          : 10,
		(: LS_Comestible("raspberry") 		:)          : 10,
		(: LS_Comestible("strawberry") 		:)          : 10,
		(: LS_Comestible("tangerine") 		:)          : 10,
		(: Sinbyen_Comestible("watermelon") :)          : 10,
		
	]));
	set_operators(({
		Sinbyen_NPC("starling"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("starling"),
	}));
	
	
}
