#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        alter_identity(([
            Identity_Nouns           : ({ "shirt" }),
            Identity_Adjectives      : ({ "fine" }),
        ]));
        set_craft(Craft_Exquisite);
        armour()->set_armour_type(Armour_Type_Shirt);
        armour()->set_race("human");
        armour()->set_autonomon_adapt(True);
        add_proportion(([
                Element_Type       : random_element(({
                                                        Material_Cotton,
                                                        Material_Silk,
                                                    })),
                Element_Proportion : 1.0,
                Element_Color      : random_element(({
                                                        "black",
                                                        "silver",
                                                        "white",
                                                        "red",
                                     })),
        ]));
        set_global_rarity(Rarity_Very_Common);
}
