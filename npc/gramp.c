#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Agin's Dragon Emporium - map_6_0_0//
//House - map_-9_-10_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("dragon");
    set_sex(Sex_Female);
    set_level(49);
    set_culture_name("Gramp");
    alter_identity(Identity_Name_Title, ([
                Seeable_Word  : "the Dragon",
                Seeable_Flags : Seeable_Flag_Verbose_Only,
        ]));
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Lady Dibella's Darkest Fantasies" }));
    add_description(Description_Type_Generic);
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_aggressive(False);
    set_strike_location("head");
    set_trait(Trait_Handedness, Limb_Lateral_None);
    set_chat(3, ({
        ";sigh contentedly",
        ";stare at %p",
        ";lick %p",
        ";nuzzle @Agin@",
    }));
    set_combat_chat(20, ({
        ";breath in deeply",
    }));
    add_permanent_attribute_adjustment(Attribute_Strength, 50);
    add_permanent_attribute_adjustment(Attribute_Constitution, 50);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 50);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 50);
    add_permanent_attribute_adjustment(Attribute_Willpower, 50);
    add_permanent_attribute_adjustment(Attribute_Charisma, 50);
    add_permanent_attribute_adjustment(Attribute_Perception, 50);
    add_permanent_attribute_adjustment(Attribute_Size, 100);

    add_skill_points(Skill_Light_Affinity, 500);
    add_skill_points(Skill_Eskara_Affinity, 500);
    add_skill_points(Skill_Magick_Affinity, 500);
    add_skill_points(Skill_Goetic_Investiture, 500);
    add_skill_points(Skill_Quickness, 600);
    add_skill_points(Skill_Dodge, 400);
    add_skill_points(Skill_Hardiness, 1000);
    add_skill_points(Skill_Eructation, 2000);
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