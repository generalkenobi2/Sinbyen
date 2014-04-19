#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//House - map_-10_-3_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("orc");
    set_sex(Sex_Male);
    set_level(60);
    add_friend("SINBYEN_GUARD");
    add_friend("SINBYEN_CITIZEN");
    add_enemy("SINBYEN_UNDEAD");
    add_enemy("SINBYEN_DEMON");
    set_culture_name("Shanks", False, "Headmaster");
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Special_Names, ({ "SINBYEN_LEADER" }), Identity_Alter_Add);
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Shanks, the headmaster of the crimson guard",
    }));
    alter_element(Material_Hair, Element_Color, "black");
    alter_element(Material_Eye, Element_Color, "brown");
    alter_element(Material_Skin, Element_Color, "black");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    add_permanent_attribute_adjustment(Attribute_Strength, 500);
    add_permanent_attribute_adjustment(Attribute_Constitution, 200);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 200);
    add_permanent_attribute_adjustment(Attribute_Willpower, 200);
    add_permanent_attribute_adjustment(Attribute_Charisma, 100);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_permanent_attribute_adjustment(Attribute_Size, 40);
    add_skill_points(Skill_Chromatostasis, 600);
    set_omniscience(True);
    add_skill_points(Skill_Stamina, 6000);
    add_skill_points(Skill_Quickness, 400);
    add_skill_points(Skill_Dodge, 600);
    add_skill_points(Skill_Hardiness, 1000);
    add_skill_points(Skill_Martial_Arts, 200);
    add_skill_points(Skill_Dancing, 60);
    add_skill_points(Skill_Precision_Strike, 600);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Leadership, 400);
    add_skill_points(Skill_Tactics, 300);
    add_skill_points(Skill_Strategy, 400);
    add_skill_points(Skill_Meditation, 300);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Unarmed_Combat, 100);
    add_skill_points(Skill_Blindfighting, 300);
    add_skill_points(Skill_Awareness, 400);
    add_skill_points(Skill_Axe, 1000);
    add_skill_points(Skill_Find_Weakness, 800);
    add_skill_points(Skill_Killer_Instinct, 400);
    add_skill_points(Skill_Lack_of_Weakness, 400);
    add_skill_points(Skill_Massive_Blow, 400);
    add_skill_points(Skill_Massive_Exertion, 400);
    add_skill_points(Skill_Recuperation, 800);
    add_skill_points(Skill_Breath_Control, 400);
    add_skill_points(Skill_Impact_Absorption, 100);
    add_skill_points(Skill_Fire_Resistance, 100);
    add_skill_points(Skill_Cold_Resistance, 100);
    add_skill_points(Skill_Regeneration, 200);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Welcome to our barracks. to %p",
        "say If you wish to join you must petition Thurgg Bloodfist, our primarch. to %p",
        "say Good %t. to %p",
        "say If you've come to train you're more than welcome here. to %p",
        "say Good %t, %p, my name is Shanks, I run this barracks and training facility. to %p",
        "nod at %p",
        "say Thurgg used to wander the land seeking his fortune until he happened across our village and rescued us from invaders. to %p",
        "say Thurgg helped us rebuild after the village was destroyed. to %p",
        "rest",

        
    }));
    set_attack_message(({
        0, ({ "charge", 0 }), "toward", "%e",
    }));
    set_combat_chat(20, ({
        "say You will be executed for this! to %e",
        "say Pay for your crimes!",
        "say Crimson! To me!",
        "say Your petty attempt to best me is laughable! to %e",
    }));
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon(random_element(({
                                                            "crimson_giant_axe",
                                                            }))),
        Belonging_Flags    : Belonging_Flag_Hold_Two_Handed,            
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("steel_suit_guard"),    
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("crimson_cloak"),    
        ]),
    }));
    
    
}
