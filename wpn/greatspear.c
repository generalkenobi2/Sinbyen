#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        weapon()->set_weapon_type(Weapon_Type_Greatspear);
        set_craft(Craft_Excellent);
        add_proportion(([
			Element_Type             : Material_Uru,
			Element_Proportion       : 0.50,
			Element_Flags			 : Element_Flag_Suppress_Element_Name,
		]));
		add_proportion(([
			Element_Type             : Material_Steel,
			Element_Proportion       : 3.0,
		]));
		add_proportion(([
			Element_Type             : Material_Qlippotam,
			Element_Proportion       : 0.25,
		]));
        set_global_rarity(Rarity_Common);
}
