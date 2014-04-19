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
    set_short("Darron's Back Alley BBQ");
    add_exit(Direction_North);
    
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is", 'a', "barbecue house",
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "grill" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "An exceedingly large",({ 'n', 0 }),"stretches across the back wall here"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Steel,
                Element_Color                           : "black",
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is an excellently crafted grill, it appears to do its job well",
                }),
            ]),
        }),
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "tables" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "several",    ({ 'n', 0 }), "are here for one to take a seat at",
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Pine,
                Element_Color                           : "black",
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are set with utensils",
                }),
            ]),
        }),
    ]));
    set_operators(({
        Sinbyen_NPC("darron"),
    }));
    set_stock(([
        Grinning_Cat_Comestible("acqua_frizzante")    :30,
        Sinbyen_Comestible("barbecue_chicken")        :30,
        Sinbyen_Comestible("barbecue_steak")          :10,
        Sinbyen_Comestible("barbecue_ribs")           :10,
    ]));
    set_list_header_left("Cuisine");
    set_list_header_right("Price");
    set_haggle_optimum(75);
    set_buying_power(1000);
    set_inventory_display(({ "menu" }), Skill_Norska);
    set_inventory_static(True);
    set_operations(Trader_Tavern);
}


