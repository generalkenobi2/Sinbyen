#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

internal int suppression_messages_time;

mixed sinbyen_church_can_attack_in(mapping args) {
        if(suppression_messages_time <= time())
                return ({
                        0, ({ "feel", 0 }), 'a',
                        ([
                                Message_Content     : ({
                                        "majestic",
                                }),
                                Message_Senses      : Message_Sense_Spiritual,
                        ]),
                        "force acting to suppress", ({ 'r', 0, "aggression" }),
                });
        return False;
}

void sinbyen_church_fail_attack_in(mapping args) {
        if(suppression_messages_time <= time()) {
                object def = args["defender"];
                if(def)
                        def->display(([
                                Message_Content : ({
                                        0, ({ "feel", 0 }), "as if some force is watching over", ({ 'o', 0 }),
                                }),
                                Message_Senses  : Message_Sense_Spiritual,
                        ]));
                suppression_messages_time = time() + 5;
        }
        return False;
}

void configure() {
	Map_Base::configure();
	set_short("a church sanctuary");
	add_exit(Direction_South);
	add_exit(Direction_East);
    add_hook(Can_Attack_In, #'sinbyen_church_can_attack_in);
    add_hook(Fail_Attack_In, #'sinbyen_church_fail_attack_in);
    add_abstract_item(([
        Abstract_Item_Identity                      : ([
            Identity_Nouns                              : ({ "stained glass windows", "glass windows", "windows" }),
            Identity_Flags                              : Identity_Flag_Plural,
        ]),
        Abstract_Item_Attach_Description                : ([
            Description_Type                            : Description_Type_Simple,
            Description_Content                         : ({
               "beautiful", ({ 'n', 0 }), "adorn the wall"
            }),
            Description_Order                           : Description_Order_Early,
        ]),
        Abstract_Item_Elements                          : ({
            ([
                Element_Type                            : Material_Glass,
                Element_Color                           : "blue-and-red-white",
                Element_Flags                           : Element_Flag_Suppress_Color_Name | Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
            ]),
        }),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "depict many scenes of a robed woman and a small child",
                }),
            ]),
        }),
    ]));
    set_contents(([
        Sinbyen_Misc("pew") : 3,
    ]));
}
