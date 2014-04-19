#include <Sinbyen.h>
#include <item.h>

inherit "std/item";

void configure() {
        ::configure();

set_global_rarity(Rarity_Rare);
        set_craft(Craft_Exquisite);
        add_proportion(([
            Element_Type             : Material_Titanium,
            Element_Proportion       : 0.50,
            Element_Flags             : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
        ]));
        add_proportion(([
            Element_Type             : Material_Adamantite,
            Element_Proportion       : 3.0,
            Element_Color             : "black",
        ]));
        add_proportion(([
            Element_Type             : Material_Uru,
            Element_Proportion       : 0.50,
            Element_Flags             : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
        ]));
        add_description(([
            Description_Type    : Description_Type_Subject_Description,
            Description_Index   : Sinbyen_Definition("subject_crimson_craftmark"),
            Description_Order   : Description_Order_Early,
        ]));
        add_description(([
            Description_Type    : Description_Type_Subject_Description,
            Description_Index   : Sinbyen_Definition("subject_crimson_weapon"),
            Description_Order   : Description_Order_Slightly_Early,
        ]));
}
