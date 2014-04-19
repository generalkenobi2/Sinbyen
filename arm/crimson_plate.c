#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Code             : "plate armour",
        Identity_Known_Adjectives : ({({ "crimson", 0, Seeable_Order_Significantly_Late })}),
    ]));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), 'a',
        Description(Description_Type_Craftsmanship_Adjective),
        Description(Description_Type_Armour_Type_Name),
        "made of",
        Description(Description_Type_Element_Base_Name),
        "and inset with a large",
        
                        Description(([
                            Description_Type                        : Description_Type_Element_Name,
                            Description_Index                       : Element(([
                                Element_Type                        : Material_Bloodstone,
                                Element_Color                       : "shimmering crimson",
                            ])),
                        ])),
    }));

    add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a suit of crimson plate armour.  This armour works to empower",
        "those experiencing feelings of extreme anger and hatred.",
    }));
    set_craft(Craft_Exquisite);
    armour()->set_ablative(0.05);
    armour()->set_armour_type(Armour_Type_Tailsuit);
    armour()->set_armour_style(Armour_Style_Articulated);
    armour()->set_race("iyiyik");


    add_proportion(([
        Element_Type              : Material_Adamantium,
        Element_Proportion        : 2.00,
        Element_Color             : "black and red",
    ]));
    add_proportion(([
        Element_Type              : Material_Bloodstone,
        Element_Proportion        : 0.05,
        Element_Part              : Part_Inset,
        Element_Flags             : Element_Flag_Secondary,
        Element_Color              : "shimmering crimson",
    ]));
    add_proportion(([
        Element_Type              : Material_Uru,
        Element_Proportion        : 2.00,
        Element_Part              : Part_Infusion,
        Element_Flags             : Element_Flag_Secondary | Element_Flag_Untransmutable,
    ]));    
    add_proportion(([
        Element_Type              : Material_Leather,
        Element_Proportion        : 0.1,
        Element_Part              : Part_Underlayer,
        Element_Flags             : Element_Flag_Secondary
    ]));
}
