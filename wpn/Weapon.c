#include <Sinbyen.h>
#include <item.h>

inherit "std/item";

void configure() {
        ::configure();

set_global_rarity(Rarity_Rare);
        set_craft(Craft_Excellent);
        add_proportion(([
            Element_Type             : Material_Carbonite,
            Element_Proportion       : 0.50,
            Element_Flags             : Element_Flag_Suppress_Material_Name,
        ]));
        add_proportion(([
            Element_Type             : Material_Steel,
            Element_Proportion       : 3.0,
            Element_Color             : "black",
        ]));
        add_proportion(([
            Element_Type             : Material_Onyx,
            Element_Proportion       : 0.01,
            Element_Part             : Part_Inset,
        ]));
        add_proportion(([
            Element_Type             : Material_Qlippotam,
            Element_Proportion       : 0.25,
            Element_Flags             : Element_Flag_Suppress_Material_Name | Element_Flag_Suppress_Override_Color,
        ]));
        
}
