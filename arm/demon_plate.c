#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Code             : "plate armour",
        Identity_Known_Adjectives : ({({ "blood", 0, Seeable_Order_Significantly_Late })}),
    ]));
    add_description(({
        "This is", 'a',
        Description(Description_Type_Craftsmanship_Adjective),
        Description(Description_Type_Armour_Type_Name),
        "made of",
        Description(Description_Type_Element_Base_Name),
        "and inset with a large",
        
                        Description(([
                            Description_Type                        : Description_Type_Element_Name,
                            Description_Index                       : Element(([
                                Element_Type                        : Material_Moonstone,
                                Element_Color                       : "shimmering red",
                            ])),
                        ])),
    }));

    add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a suit of blood plate armour",
    }));
    set_craft(Craft_Exquisite);
    armour()->set_armour_type(Armour_Type_Suit);
    armour()->set_armour_style(Armour_Style_Articulated);
    armour()->set_race("human");
    armour()->set_autonomon_adapt(True);


    add_proportion(([
        Element_Type              : Material_Adamantium,
        Element_Proportion        : 3.0,
        Element_Color             : "red",
    ]));
    add_proportion(([
        Element_Type              : Material_Uru,
        Element_Proportion        : 1.0,
        Element_Color             : "red",
        Element_Flags             : Element_Flag_Secondary,
    ]));
    add_proportion(([
        Element_Type              : Material_Moonstone,
        Element_Proportion        : 0.05,
        Element_Part              : Part_Inset,
        Element_Flags             : Element_Flag_Secondary,
        Element_Color              : "shimmering red",
    ]));
    
    add_proportion(([
        Element_Type              : Material_Leather,
        Element_Proportion        : 0.1,
        Element_Part              : Part_Underlayer,
        Element_Flags             : Element_Flag_Secondary
    ]));
}
