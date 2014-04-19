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
    set_short("Candor's Book Store");
    add_exit(Direction_East);
    add_exit(Direction_North);
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is a small bookstore",
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "books" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "various",    ({ 'n', 0 }), "cover the {{brown}counter} and {{brown}shelves}"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Plastic,
                Element_Flags                            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "range from large, bound novels, to small scrolls",
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
            ({ 'n', 0 }), "run along the walls"
            }),
            Description_Order                           : Description_Order_Very_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Oak,
                Element_Flags                            : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "keep the books just out of reach of destructive children",
                }),
            ]),
        }),
    ]));
    set_list_header_left("Item Description");
    set_list_header_right("Cost");
    set_haggle_optimum(75);
    set_buying_power(2000);
    set_inventory_attrition(25);
    set_stock(([
                LS_Magic("lens_of_insight")                 : 3,
                (: Random_Item_Normal_Scroll :)             : 2,
                (: Random_Item_Safe_Magical_Scroll :)       : 2,
                (: Random_Item_Magical :)                   : 1,
                (: Random_Item_Book :)                      : 3,
                (: Random_Item_Book :)                      : 3,
        ]));

    set_operators(({
        Sinbyen_NPC("candor"),
    }));
    set_operations(Trader_Buy | Trader_View | Trader_List | Trader_Identify | Trader_Return);
    set_contents(({
        Sinbyen_NPC("candor"),
    }));
}
