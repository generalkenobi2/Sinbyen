#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
    Map_Base::configure();
    set_short("The Raging Iyiyik Tavern");
    add_exit(Direction_East);
    add_exit(Direction_West);
    add_exit(Direction_North);
    add_exit(Direction_South);
    add_exit(Direction_Northwest);
    add_exit(Direction_Northeast);
    
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "tables" }),
            Identity_Flags                              : Identity_Flag_Plural,
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
            "Several",({ 'n', 0 }),"dot the area, each capable of seating four patrons",
            }),
            Description_Order                           : Description_Order_Early,
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
                    ({ 't', 0 }), "are nicked and dented with age and hard use",
                }),
            ]),
        }),
    ]));
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({ "sign" }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
                ({ 'a', 0 }), "stands near the entrance",
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
                    ({ 't', 0 }), "has a message written on it",
                }),
            ]),
        }),
    ]));
    set_readable(({ 0, "sign" }), Skill_Norska,
    "//     The Raging Iyiyik Tavern    //\n"
    "//                                 //\n"
    "//     Serving the angry since:    //\n"
    "//          Arienle, 341           //\n"
    "//                                 //\n"
    "//           -NO HORSES-           //");
}
