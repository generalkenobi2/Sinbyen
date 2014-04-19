inherit "/std/item";

#include <item.h>



void configure() {
        ::configure();
        set_craft(Craft_Excellent);
        add_proportion(([
			Element_Type             : Material_Uru,
			Element_Proportion       : 0.50,
			Element_Flags			 : Element_Flag_Suppress_Material_Name,
		]));
		add_proportion(([
			Element_Type             : Material_Steel,
			Element_Proportion       : 3.0,
		]));
		add_proportion(([
			Element_Type             : Material_Qlippotam,
			Element_Proportion       : 0.25,
		]));
}
