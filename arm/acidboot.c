#include <interval.h>
#include <item.h>
#include <Sinbyen.h>
#include <special_attack.h>
#include <race.h>

inherit "/std/item";
inherit "/def/descriptor/special_attack";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Pair_of_Boots);
	armour()->set_armour_style(Armour_Style_Simple);


	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 0.85,
	]));
	add_proportion(([
		Element_Type              : Material_Fur,
		Element_Proportion        : 0.15,
		Element_Part			  : Part_Underlayer,
	]));
	
add_special_attack(([
		Special_Attack_Name             : "acidic stream",
		Special_Attack_Actuation        : Actuation_Spit,
		Special_Attack_Skill            : Skill_Eructation,
		Special_Attack_Type             : ({ "acid", "poison" }),
		Special_Attack_Vector           : Vector_Stream,
		Special_Attack_Power            : Special_Attack_Power_Very_Overwhelming,
		Special_Attack_Energy_Costs     : ({
			({ Energy_Spiritual, 6.0 }),
			({ Energy_Metabolic, 4.0 }),
		}),
		Special_Attack_Activity         : 16,
		Special_Attack_Condition        : Magick_Required,
		Special_Attack_Preference       : Preference_Moderate,
	]));
}
