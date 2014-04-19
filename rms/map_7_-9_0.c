#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
    Map_Base::configure();
    set_short("a dimly lit room");
    add_exit(Direction_North);
    
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "pole", "stage" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
                ({ 'a', 0 }), "rises up from the center of a {{black}stage} here"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Steel,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is securely fastened to the base of the stage and to the",
                    "ceiling.  Dancers use this to enhance their appeal on stage."
                }),
            ]),
        }),
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Adjectives                         : ({ "plush" }),
            Identity_Nouns                              : ({ "chairs" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
                ({ 'n', 0 }), "surround the stage"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Velvet,
                Element_Color                           : "red",
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are soft and well suited for spectator comfort",
                }),
            ]),
        }),
    ]));
    set_contents(({
        Sinbyen_NPC("lola"),
    }));
    set_contents(([
        Sinbyen_Monster("gentleman") : 4,
    ]));
}
