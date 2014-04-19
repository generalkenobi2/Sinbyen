#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        set_identity(([
            Identity_Nouns                  : ({ "arrow", "silver tipped arrow", "silver arrow" }),
            Identity_Known_Nouns            : ({ "silverthorn arrow", "arrow" }),
            Identity_Adjectives             : ({ "silver", "tipped" }),
            Identity_Known_Adjectives       : ({}),
    ]));
    
        add_description(({
                "This is", 'a',
                Description(([
                        Description_Type    : Description_Type_Element_Name,
                        Description_Content : Description(Description_Type_Weapon_Type_Name),
                ])),
                ".  It has a broad",
                Description(([
                        Description_Type    : Description_Type_Element_Name,
                        Description_Index   : ([
                                Element_Part    : Part_Tip,
                        ]),
                        Description_Content : "head",
                ])),
                "for extreme penetration.",
        }));
        
        add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a silverthorn arrow, a rare type of",
        "arrow that has been enchanted with spirit energy that releases rapidly on impact.",
    }));
    
        set_craft(Craft_Unearthly);
        set_properties(({
            Prop_Explosive,
            Prop_Magical,
        }));
        weapon()->set_weapon_type(Weapon_Type_Barbed_Arrow);
        weapon()->add_weapon_feature_modifier(([
                Modifier_Index      : Weapon_Feature_Penetrate,
                Modifier_Amount     : 8.0,
                Modifier_Bound      : 8.0,
                Modifier_Flags      : Modifier_Flag_Persistent,
        ])); 
        add_proportion(([
                Element_Type       : Material_Ironwood,
                Element_Proportion : 0.8,
                Element_Flags      : Element_Flag_Secondary,
        ]));
        add_proportion(([
                Element_Type       : Material_Silver,
                Element_Proportion : 0.2,
                Element_Flags      : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
        ]));
}
