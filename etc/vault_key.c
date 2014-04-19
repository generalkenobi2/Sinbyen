#include <Shadow_Tower.h>
#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns          : ({ "key" }),
        Identity_Special_Names  : ({ "SINBYEN_BANK_KEY" }),
    ]));
    set_key_ids(({ "SINBYEN_BANK_KEY" }));
    add_description(Description_Type_Generic);
    set_value_added(1);
    set_shape(Common_Shape_Medium_Key);
    add_proportion(([
        Element_Type            : Material_Silver,
        Element_Proportion      : 1.0,
    ]));
    set_global_rarity(Rarity_Very_Unusual);
}
