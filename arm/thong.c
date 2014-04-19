#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
    ::configure();
    add_description(Description_Type_Generic);
    set_craft(Craft_Exquisite);
    alter_identity(([
        Identity_Name           : "silk thong",
        Identity_Nouns          : ({ "thong" }),
        Identity_Flags          : Identity_Flag_Suppress_Armour_Type,
    ]));
    armour()->set_armour_type(Armour_Type_Panties);
    armour()->set_race("human");
    add_proportion(([
        Element_Type            : Material_Silk,
        Element_Proportion      : 1.0,
        Element_Color           : "black",
    ]));    
    set_global_rarity(Rarity_Unusual);
}
