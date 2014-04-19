#include <Valathyr.h>
#include <item.h>

inherit "/std/item";

internal descriptor skill_mod;

void cloak_do_equip(mapping args) {
	object who = args["who"];
	skill_mod = who->add_skill_modifier(([
		Modifier_Index  : ({ Skill_Fire_Affinity, Skill_Courage }),
		Modifier_Amount : 500,
	]));
}

void cloak_do_unequip(mapping args) {
	object who = args["who"];
	who->remove_skill_modifier(&skill_mod);
}

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Cloak);
	armour()->set_race("dana");
	add_hook(Do_Equip_Item, #'cloak_do_equip);
	add_hook(Do_Unequip_Item, #'cloak_do_unequip);
	add_proportion(([
		Element_Type           : Material_Silk,
		Element_Proportion     : 1.0,
	]));
}
