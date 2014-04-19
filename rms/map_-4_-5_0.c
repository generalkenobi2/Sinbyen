#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
    Map_Base::configure();
    set_short("a mess hall");
    add_exit(Direction_North);

add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is simple mess hall",
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "tables" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "a few",    ({ 'n', 0 }), "sit folded into the wall",
            }),
            Description_Order                           : Description_Order_Slightly_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Pine,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "fold up into spaces in the wall to allow for easy storage",
                }),
            ]),
        }),
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "pots", "kitchen" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "There is a kitchen equipped with two large",    ({ 'n', 0 }), "and other simple cooking supplies"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Iron,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "appear as though they've seen numerous uses",
                }),
            ]),
        }),
    ]));
}
