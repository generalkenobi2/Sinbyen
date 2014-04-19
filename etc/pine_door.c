#include <item.h>
#include <Sinbyen.h>

inherit "/std/door";
  
void configure() {
        ::configure();
        alter_identity(Identity_Nouns, ({ "door" }), True);
		add_description(({
                "this is a door made of",
                Description(Description_Type_Element_Subdescription),
                "mounted on",
                Description(([
                        Description_Type    : Description_Type_Element_Name,
                        Description_Index   : ([
                                Element_Part    : Part_Setting,
                        ]),
                        Description_Content : "hinges",
                ])),
                ".",
        }));
        add_description(Description_Type_Craftsmanship_Description);
        set_craft(Craft_Excellent);
        add_proportion(([
                Element_Type            : Material_Oak,
                Element_Proportion      : 1.00,
        ]));
        add_proportion(([
                Element_Type            : Material_Iron,
                Element_Proportion      : 0.02,
                Element_Part            : Part_Setting,
                Element_Flags           : Element_Flag_Secondary,
        ]));


        set_closed(True);
        set_breakable(True);
        set_lockable(True);
        set_locked(False);
        set_lock_quality(3);
}
