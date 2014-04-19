#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void shield_deflect(mapping args) {
	if(!random(50) && find_call_out("shield_stun") == -1)
		call_out("shield_stun", 1);
}

void shield_stun() {
	object who = query_user();
	if(!who)
		return;
	if(!who->check_spell_points(15))
		return;
	who->message(({ "a {{shimmering}holy wave of energy} floods forth from", ({ 's', 0, this_object() })}));
	foreach(object att : who->query_attackers())
		att->stun_living(10, 0, "holy");
}

void configure() {
	::configure();
	set_creator(({ "kenobi" }));
	add_description(Description_Type_Generic);
	add_description(({
		"A large {{dark red}red cross} adorns the {{pure white}pure white surface} of the shield",
	}));
	set_craft(Craft_Exquisite);
	weapon()->set_weapon_type(Weapon_Type_Kite_Shield);
	add_proportion(([
		Element_Type       	: Material_Adamantium,
		Element_Proportion 	: 3.0,
		Element_Color      	: "white",
	]));
	add_proportion(([
		Element_Type       	: Material_Kedusham,
		Element_Proportion 	: 0.1,
		Element_Part		: Part_Aura,
	]));
	add_property(Prop_Holy);
	add_hook(Mod_Deflect_Attack, #'shield_deflect);
}
