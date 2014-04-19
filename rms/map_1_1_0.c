#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Temple.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
    Map_Base::configure();
    trader::configure();
    set_short("The Raging Gnoll Tavern");
    add_exit(Direction_West);
    add_exit(Direction_South);
    add_exit(Direction_Southwest);

    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "corner bar", "bar" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
                ({ 'a', 0 }), "completly covers this corner of the room",
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Mahogany,
                Element_Color                           : "red",
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({'t',0 }), "is very well crafted and has several taps available for one's drink of choice",
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
        (: Sinbyen_Comestible("raging_gnoll")            :)    : 6,
        (: Temple_Comestible("bloody_mad_martigan")      :)    : 10,
        (: Sinbyen_Comestible("water_pack")              :)    : 40,
        (: Sinbyen_Comestible("firebreather")            :)    : 40,
        (: Sinbyen_Comestible("beer")                    :)    : 40,
        (: Sinbyen_Comestible("sinbyen_lager")           :)    : 6,
    ]));
    set_operators(({
        Sinbyen_NPC("darlena"),
    }));
    set_operations(Trader_Shop);
    set_contents(({
        Sinbyen_NPC("darlena"),
    }));

}
