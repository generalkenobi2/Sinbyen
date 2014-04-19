#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns : ({ "mug" }),
    ]));
    add_description(({
                        'a', "large",     Description(([
                                            Description_Type    : Description_Type_Element_Name,
                                            Description_Index   : Material_Tin,
                                            Description_Flags   : Description_Flag_Noun,
                                        ])),                        
                        "mug with a sizable handle",
        
        
    }));
    add_description(({"\"RG\" has been engraved into", ({ 'r', 0, "side" }), }));
    set_craft(Craft_Excellent);
    set_shape(Common_Shape_Empty_Mug);
    add_proportion(([
        Element_Type       : Material_Tin,
        Element_Proportion : 1.5,
        Element_Color      : "gray",
    ]));
}
