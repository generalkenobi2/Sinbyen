#include <Sinbyen.h>
#include <skills.h>
#include <subjects.h>

inherit "/std/def/subject";

void configure() {
	::configure();
	set_subject_name("crimson weapons");
	set_subject_type(Subject_Type_Item);
	set_subject_description_known(
		"weapon from the crimson armoury"
	);
	set_subject_identify_skills(([
		Skill_Armour_Lore : 70,
		Skill_Symbology   : 100,
		Skill_Weapon_Lore : 70,
	]));
}
