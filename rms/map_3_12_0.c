#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Hanoma.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
    Map_Base::configure();
    set_short("Durod's Tackle Shop");
    add_exit(Direction_North);
    add_exit(Direction_East);
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is a small tackle and bait shop",
            Description(([
                Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : ", that smells lightly of fish",
            ])),
            ".",
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "hooks", "bobbers", "tackle" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "a large variety of", ({ 'n', 0 }), ", {{white}platic bobbers} and other {{black}tackle} sits on shelves and wall hangers",
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Copper,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    "all the tackle is of high quality materials and appears that it was made to last",
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
       (:Hanoma_Weapon("fishing_rod"):)                 : 10,
    ]));
    set_operators(({
        Sinbyen_NPC("durod"),
    }));
    set_operations(Trader_Tavern | Trader_List);
    set_contents(({
        Sinbyen_NPC("durod"),
    }));
    
}
