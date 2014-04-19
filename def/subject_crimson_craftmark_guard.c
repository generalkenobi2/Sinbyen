#include <Sinbyen.h>
#include <skills.h>
#include <subjects.h>

inherit "/std/def/subject";

void configure() {
	::configure();
	set_subject_name("the craftmark of the Crimson Guard");
	set_subject_type(Subject_Type_Symbol);
	set_subject_description_known(
		"the craftmark of the Crimson Guard, an "
		"emblazoned image of a {{dark red}shield}"
	);
	set_subject_description_unknown(
		"an emblazoned image of a {{dark red}shield}"
	);
	set_subject_identify_skills(([
		Skill_Armour_Lore : 70,
		Skill_Symbology   : 100,
		Skill_Weapon_Lore : 70,
	]));
}
