#include <Losthaven_Sewers.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
	::configure();
	set_race("rat");
	add_description(Description_Type_Generic);
	add_friend("SINBYEN_CREATURE");
	set_enemies(({ "!sekh" }));
	set_level(1);
	set_move_time(semirandom(240));
	set_wimpy(semirandom(30));
	set_ambulate_flag(Ambulate_Flag_Chase, True);
	set_preferred_realms(({ "Sewers" }));
	set_wander_realms(({ "Losthaven" }));
	set_walk_verb("scrabble");
	set_attack_message(({
		0, ({ "squeak", 0 }), "and", ({ "leap", 0 }), "at", ({ 'e', "%e" }),
	}));
	set_assist_message(query_attack_message());
	set_chat(5, ({
		";squeak noisily",
		";make a chittering noise",
		";sniff the air",
	}));
	set_keepable(True);
	set_keep_cost(Keep_Cost_Character_Low - Keep_Cost_Character_Adjust_Medium);
}
