#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
    Map_Base::configure();
    set_readable(({ 0, "sign" }), Skill_Norska,
    "//        Iyiyik Grove Park        //\n"
    "//                                 //\n"
    "//        Wildlife Preserve        //\n"
    "//                                 //\n"
    "//                                 //\n"
    "//           -NO HORSES-           //");
    add_abstract_item(([
        Abstract_Item_Identity                          : ([
            Identity_Nouns                              : ({
                "sign"
            }),
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
                "a",({ 'n', 0 }),"hangs on a nearby tree.",
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Iron,
                Element_Color                           : "rusty",
            ]),
        }),
    ]));
}
