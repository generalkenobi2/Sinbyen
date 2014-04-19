#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
    Map_Base::configure();
    set_short("the west hallway in Sinbyen's Jailhouse");
    add_exit(Direction_East);
    add_exit(Direction_West);
    
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is a corridor in the Sinbyen jail house",
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "the walls and floor are plain and without adornment",
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({
                "wall","floor",
            }),
        ]),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    "it looks as plain and lifeless",
                }),
            ]),
        }),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Concrete,
                Element_Color                           : "white",
            ]),
        }),
    ]));
}
