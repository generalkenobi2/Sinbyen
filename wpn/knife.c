#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        weapon()->set_weapon_type(Weapon_Type_Knife);
        set_craft(Craft_Good);
        add_material(Material_Steel);
        set_global_rarity(Rarity_Common);
}
