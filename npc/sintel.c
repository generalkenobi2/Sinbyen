#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Sintel's Weapons - map_8_2_0//
//House - map_-7_-3_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Sintel");
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Sintel's Weapons" }));
    add_description(Description_Type_Generic);    
    add_description(({
        "He has more scar tissue running down his left arm than unmarred skin.",
        "It appears to be some sort of burn damage",
    }));
    add_known_description(({
      'v',    ({ "recognize", 'v' }), "him as Sintel, a long time resident of Sinbyen since he",
      "was burnt by an unwelcome run in with a fire drake.",
    }));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_attack_scatter(50);
    set_strike_location("head");
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_trait(Trait_Handedness, Limb_Lateral_None);
    set_trait(Trait_Sadism, 3);
    set_trait(Trait_Masochism, 6);
    set_chat(3, ({
        "say Welcome to my shop. to %p",
        "say Is there something i can help you find? to %p",
        "say My weapons are reasonably priced and aplenty. to %p",

        
    }));
    set_combat_chat(20, ({
        ";say I'm too damned old to be doing this. to %e",


    }));
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Armour("leather_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("brown_cotton_pants"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("white_cotton_shirt"),
        ]),        
    }));
    
    
}