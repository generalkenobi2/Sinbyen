#include <item.h>


inherit "/std/item";

private descriptor skill_mod;

void bow_do_equip(mapping args) {
    skill_mod = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Archery,
        Modifier_Amount : 40,        
    ]));
    skill_mod = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Combat_Reflexes,
        Modifier_Amount : 40,        
    ]));
}
void bow_do_unequip(mapping args) {
    args["who"]->remove_skill_modifier(&skill_mod);
}

void configure() {
    ::configure();
    add_description(Description_Type_Generic);
    set_craft(Craft_Exquisite);
    weapon()->set_weapon_type(Weapon_Type_Recurved_Longbow);
    weapon()->set_damage_types( "piercing", "spirit" );
    set_known_value_added(500);
    add_proportion(([
        Element_Type             : Material_Iron_Oak,
        Element_Proportion       : 0.75,
        Element_Part             : Part_Bulk
    ]));
    add_proportion(([
        Element_Type             : Material_Steel,
        Element_Proportion       : 0.10,
        Element_Color            : "black",
        Element_Part             : Part_Backing,
    ]));
    add_proportion(([
        Element_Type             : Material_Pneumax,
        Element_Proportion       : 0.15,
    ]));
    
add_hook(Do_Equip_Item, #'bow_do_equip);
add_hook(Do_Unequip_Item, #'bow_do_unequip);
}
