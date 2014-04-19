#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        set_craft(Craft_Good);
        armour()->set_armour_type(Armour_Type_Apron);
        armour()->set_race("human");
        armour()->set_autonomon_adapt(True);
        add_proportion(([
                Element_Type       : Material_Cotton,
                Element_Proportion : 1.0,
                Element_Color      : "white",
        ]));
        set_global_rarity(Rarity_Very_Common);
}
