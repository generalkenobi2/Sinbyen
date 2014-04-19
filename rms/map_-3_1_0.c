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
    set_short("Fontaine's Fishery");
    add_exit(Direction_East);
    add_exit(Direction_South);
    
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is a spacious shop",
            
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            Description(([
                Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : "The air smells heavily of freshly caught fish",
            ])),
        }),
        Description_Order                               : Description_Order_Very_Early,
    ]));
    
    add_abstract_item(([
            Abstract_Item_Identity           : ([
                Identity_Nouns               : ({ "counter" }),
            ]),
            Abstract_Item_Descriptions       : ({
                ({({ 't', 0 }), "is set with various items and is clearly where most of the",
                "business here is done.  It has a few fish scales scattered about its surface", }),
            }),
            Abstract_Item_Attach_Description : ([
                Description_Type             : Description_Type_Simple,
                Description_Content          : ({
                    "There is a large", ({ 'n', 0 }), "here",
                }),
                Description_Order            : Description_Order_Middle,
            ]),
            Abstract_Item_Elements           : ({
                ([
                    Element_Type             : Material_Aluminum,
                    Element_Part             : Part_Bulk,
                ])
            }),
        ]));
    set_list_header_left("Item Description");
    set_list_header_right("Cost");
    set_haggle_optimum(75);
    set_buying_power(10000);
    set_inventory_attrition(25);
    set_stock(([
        (: Sinbyen_Comestible("fillet_marlin")         :)          : 6,
        (: Sinbyen_Comestible("fillet_salmon")         :)          : 12,
        (: Sinbyen_Comestible("fillet_seabass")        :)          : 8,
        (: Sinbyen_Comestible("fillet_snapper")        :)          : 16,
        (: Sinbyen_Comestible("fillet_tuna")           :)          : 4,
        (: Sinbyen_Comestible("fillet_yellowtail")     :)          : 10,
    ]));
    set_operators(({
        Sinbyen_NPC("fontaine"),
    }));
    set_operations(Trader_Shop);
    set_contents(({
        Sinbyen_NPC("fontaine"),
    }));
    
}
