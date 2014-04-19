#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        alter_identity(([
            Identity_Adjectives      : ({ "fine" }),
        ]));
        set_craft(Craft_Exquisite);
        armour()->set_armour_type(Armour_Type_Pair_of_Boots);
        armour()->set_race("human");
        armour()->set_autonomon_adapt(True);
        add_proportion(([
                Element_Type        : Material_Leather,
                Element_Proportion  : 1.0,
                Element_Color       :    random_element(({
                                                        "black",
                                                        "brown",
                                        })),
        ]));
        add_proportion(([
                Element_Type        : Material_Brass,
                Element_Proportion  : 1.0,
                Element_Part        : Part_Setting,
                Element_Flags       : Element_Flag_Secondary,
        ]));
        set_global_rarity(Rarity_Rare);
}
