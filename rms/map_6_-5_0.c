#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

status magickal_only(object obj) {
        return obj->query_property(Prop_Magical) || obj->query_property(Prop_Primal);
}

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Dalemaar's Magic Shoppe");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_East);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is an ornate shop",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"magickal items fill the room",
				Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Astral_Perception,
					Condition_Value     			    : (1),
                ]),
                Description_Content                     : ", so many that the air itself seems to be charged with magickal energy",
			])),	".",
		}),
		Description_Order                               : Description_Order_Very_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "beautiful" }),
			Identity_Nouns                              : ({ "rug" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "covers the floor.",
			}),
			Description_Order                           : Description_Order_Slightly_Early,
			Description_Flags							: Description_Flag_Identity_Pluralize,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Cotton,
				Element_Color							: "red",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is covered in an ornate geometric spiral pattern.",              
					}),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "eye-catching" }),
			Identity_Nouns                              : ({ "tapestries" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "adorn the walls",
			}),
			Description_Order                           : Description_Order_Significantly_Early,
			Description_Flags							: Description_Flag_Identity_Pluralize,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Silk,
				Element_Color							: "white",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "all depict a {{white}female danaan figure} performing some kind of deed or",
					"daring act.  The largest of the tapestries portrays her with hands raised high,",
					"{{sparkling}light} pouring from her fingertips, and spiraling into the sky.",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "line the walls, stopping before each tapestry, then continuing on the other side",
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Oak,
			]),
			([
				Element_Type                            : Material_Dweomer,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "appear brand new.  None of the shelves sag under the weight",
                    "of items placed on them and they gleam as though just polished.",
                }),
            ]),
        }),
	]));
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(75);
	set_buying_power(10000);
	set_inventory_attrition(25);
	set_operators(({
		Sinbyen_NPC("dalemaar"),
	}));
	set_contents(({
		Sinbyen_NPC("dalemaar"),
	}));
	set_stock(([
                LS_Anklet("magic_mapping")              : 1,
                LS_Magic("lens_of_insight")             : 4,
                (:
                        random_element(({
                                LS_Misc("quartz_ball"),
                                LS_Misc("quartz_ball"),
                                LS_Misc("quartz_ball"),
                                LS_Misc("quartz_ball"),
                                LS_Misc("beryl_ball"),
                        }))
            :)                                      : 2,
                LS_Magic("panoramicon")                 : 1,
                LS_Magic("adrift_cube")                 : 1,
                (: Random_Item_Safe_Magical_Gem :)      : 2,
                (: Random_Item_Safe_Discharger_Wand :)  : 3,
                (: Random_Item_Safe_Magical_Ring :)     : 5,
                (: Random_Item_Safe_Magical_Scroll :)   : 2,
                (: Random_Item_Magical :)               : 6,
        ]));
        set_specialty_rule(#'magickal_only);
        set_evaluate_modifier(50);
        set_identify_modifier(100);
        set_operations(Trader_Shop | Trader_Identify | Trader_Evaluate);
}
