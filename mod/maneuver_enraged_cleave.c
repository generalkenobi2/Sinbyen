#include <Aligned.h>
#include <attack_form.h>
#include <autonomon.h>
#include <colors.h>
#include <combat.h>
#include <damage_types.h>
#include <energy.h>
#include <interactions.h>
#include <modifier.h>
#include <rating_factor.h>
#include <security.h>
#include <traits.h>

inherit "/std/def/armed_maneuver.c");

void configure() {
	::configure();
	set_interaction_name("enraged cleave");
	set_interaction_separators(({ "at" }));
	set_interaction_labels(({ "target" }));
	set_interaction_first_optional(0);
	aligned_set_maneuver_access(([
		Maneuver_Access_Maneuver        : query_interaction_name(),
		Maneuver_Access_Energy_Costs    : ({
			({ Energy_Metabolic, 3.5 }),
		}),
		Maneuver_Access_Preference      : Preference_Very_High,
		Maneuver_Access_Flags           : Maneuver_Access_Flag_Standard_Combat,
	]));
	set_interaction_help(
		"Perform a single verticle attack meant to cleave through armor and bone."
	);
	set_activity_factor(1.05);
	set_weapon_type(Weapon_Type_Greataxe));
	set_damage_shifts(([
	    Damage_Mode_Penetrate           : 0.15,
	    Damage_Mode_Stun                : 0.15,
	]));
	set_aim(15);
	set_damage_type(({ "cutting", "crushing" }));
	set_message(({
		0, ({ "swing", 0 }), ({ 'r', 0, "%w" }), "in a furious downward strike at", "%t",
	}));
    set_attack_rating_factor_modifications(({
        Rating_Factor(([
            Rating_Factor_Type          : Rating_Factor_Type_Entire_Skill,
            Rating_Factor_Skill         : Skill_Axe,
            Rating_Factor_Weight        : 1.00,
        ])),
		Rating_Factor(([
            Rating_Factor_Type          : Rating_Factor_Type_Entire_Skill,
            Rating_Factor_Skill         : Skill_Massive_Blow,
            Rating_Factor_Weight        : 1.00,
        ])),
		
    }));
}
