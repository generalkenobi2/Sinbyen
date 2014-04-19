#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
    ::configure();
    set_race("skeleton");
	alter_identity(Identity_Adjectives, ({"reanimated"}));    
    add_description(Description_Type_Generic);
    set_level(38 + random(10));
    set_aggressive(True);
    set_alignment(({ -750, -750 }));
    add_friend("SINBYEN_UNDEAD");
	set_strike_location("head");
	set_can_kill(True);
	set_walk_verb("wander");
	set_combat_mode_selected(Combat_Mode_Patient);
	add_permanent_attribute_adjustment(Attribute_Strength, 200);
	add_permanent_attribute_adjustment(Attribute_Constitution, 300);
	add_permanent_attribute_adjustment(Attribute_Dexterity, 100);
	add_permanent_attribute_adjustment(Attribute_Perception, 30);
	add_permanent_attribute_adjustment(Attribute_Size, 30);
	add_skill_points(Skill_Massive_Blow, 300);
	add_skill_points(Skill_Precision_Strike, 300);
	add_skill_points(Skill_Sword, 900);
	add_skill_points(Skill_Tactics, 150);
	add_skill_points(Skill_Flail, 900);
	add_skill_points(Skill_Hammer, 900);
	add_skill_points(Skill_Axe, 900);
	add_skill_points(Skill_Quickness, 200);
	add_skill_points(Skill_Shield, 600);
	add_skill_points(Skill_Massive_Exertion, 600);
	add_skill_points(Skill_Hardiness, 400);
	add_skill_points(Skill_Dodge, 400);
	add_skill_points(Skill_Supernal_Durability, 200);
	add_skill_points(Skill_Strategy, 200);
	add_skill_points(Skill_Subordination, 200);
	add_skill_points(Skill_Spelunking, 200);
	add_skill_points(Skill_Killer_Instinct, 300);
	add_skill_points(Skill_Qlippotic_Affinity, 200);
	add_skill_points(Skill_Spear, 900);
	add_skill_points(Skill_Steadiness, 400);
	add_skill_points(Skill_Resilience, 600);
	add_skill_points(Skill_Combat_Reflexes, 200);
	add_skill_points(Skill_Fire_Resistance, 600);
	add_skill_points(Skill_Water_Resistance, 600);
	add_skill_points(Skill_Force_Resistance, 600);
	add_skill_points(Skill_Sephirotic_Resistance, 600);
	add_skill_points(Skill_Qlippotic_Resistance, 600);
	add_skill_points(Skill_Heat_Resistance, 600);
	add_skill_points(Skill_Order_Resistance, 600);
	add_skill_points(Skill_Chaos_Resistance, 600);
	add_skill_points(Skill_Cutting_Resistance, 600);
	add_skill_points(Skill_Crushing_Resistance, 600);
	set_trait(Trait_Paravision, True);

	
	set_belongings(({
		([
		Belonging_File  : Sinbyen_Weapon("undead_weapon"),
		Belonging_Flags	: Belonging_Flag_Hold_Two_Handed,			
		]),
		([
		Belonging_File  : Sinbyen_Armour("splint_greathelm"),	
		]),
		([
		Belonging_File  : Sinbyen_Armour("splint_halfsuit"),	
		]),
		([
		Belonging_File  : Sinbyen_Armour("leather_boots"),	
		]),
		
	}));
	
}
