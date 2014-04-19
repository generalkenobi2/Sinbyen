#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Lady Dibella's Dark Fantasies - map_7_2_0//
//House - map_-7_-10_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("kielleth");
    set_sex(Sex_Female);
    set_level(80);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_culture_name("Dibella", False, "Lady");
    alter_identity(Identity_Name_Title, ([
                Seeable_Word  : "the seductress",
                Seeable_Flags : Seeable_Flag_Verbose_Only,
        ]));
    set_alignment(({ -800, -400 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Lady Dibella's Darkest Fantasies" }));
    add_description(({
        ({'v', 0 }), ({ "are", 0 }), "a tall, slender, young woman with pixie-cut",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Hair,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", fair",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Skin,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", and deep",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
    }));
    
    add_description(({
        ({ 'p', 0 }), ({ "are", 0 }), "stunningly attrictive",
    }));
    add_description(({
        ({ 'o', 0 }), "ample bosom and curvacious figure seem even more evident dressed as", ({ 'p', 0 }), ({ "are", 0 }),
    }));
    add_description(({
        ({ 'r', 0, "posture" }), "and attitude express an aura of confidence and power",
    }));
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }), "as Lady Dibella, the seductress",
    }));
    alter_element(Material_Hair, Element_Color, "blonde");
    alter_element(Material_Eye, Element_Color, "blue");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_attack_scatter(50);
    set_strike_location("head");
    set_trait(Trait_Handedness, Limb_Lateral_None);
    set_trait(Trait_Sadism, 3);
    set_trait(Trait_Masochism, 6);
    set_chat(3, ({
        "say Welcome to my domain. to %p",
        "say I have everything we need to fulfill your deepest desires, %p. to %p",
        "say I have many things i can teach you, if you so wish it. to %p",
        "say Tell me your darkest fantasies, %p. to %p",
        ";brush up against %p suggestively",
        "say I've shown you what i have to offer, now what can you offer me? to %p",
        "say Do you wish to know my deepest secrets? to %p",
        "say Pain and pleasure go hand in hand. to %p",
        "say Can i help you find something? to %p",
        ";adjust a strap on my {{black}harness}",
        "say Welcome %p, feel free to let your eyes wander. to %p",
        ";examine my tessen",
        ";bend over to tighten a strap on my {{black}left thigh-high boot}",
        ";bend over to tighten a strap on my {{black}right thigh-high boot}",
        ";smile at %p",
        ";ajust myself in a nearby mirror",
        ";grin at %p knowingly",
        "wield nyerie with left hand",
        "wield nytelse with right hand",
        ";bend over seductively",
        ";wrap my arms around %p",
        
    }));
    set_combat_chat(20, ({
        "say Oh please make this hurt!",
        "say Can you feel that?!",
        "shout Don't stop!",
        ";twist around behind %e",
        "start attacking with all",
        "shout Scream for me!",
        "shout Hit me again! Oh god hit me again!",
        "visualize a chi shield around myself",
        "visualize a chi shield around myself",
        "visualize a chi shield around myself",

    }));
    add_permanent_attribute_adjustment(Attribute_Strength, 50);
    add_permanent_attribute_adjustment(Attribute_Constitution, 200);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 500);
    add_permanent_attribute_adjustment(Attribute_Willpower, 400);
    add_permanent_attribute_adjustment(Attribute_Charisma, 500);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_affiliation("Synousia Algesis");
    add_affiliation("Aisenshi");
    add_affiliation("the Sodality of the Nine-Spoked Wheel");
    add_explicit_maneuver_access("chi strike");
    add_explicit_maneuver_access("chi kick");
    add_explicit_maneuver_access("shadow strike");
    add_skill_points(Skill_Qlippotic_Affinity, 666);
    add_skill_points(Skill_Chromatostasis, 666);
    add_skill_points(Skill_Legend_Lore, 600);
    add_skill_points(Skill_Stamina, 6000);
    add_skill_points(Skill_Elder_Lore, 600);
    add_skill_points(Skill_Quickness, 600);
    add_skill_points(Skill_Dodge, 600);
    add_skill_points(Skill_Hardiness, 500);
    add_skill_points(Skill_Combat_Meditation, 300);
    add_skill_points(Skill_Martial_Arts, 200);
    add_skill_points(Skill_Dancing, 500);
    add_skill_points(Skill_Precision_Strike, 600);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Philosophy, 500);
    add_skill_points(Skill_Telesma, 600);
    add_skill_points(Skill_Tactics, 400);
    add_skill_points(Skill_Strategy, 400);
    add_skill_points(Skill_Meditation, 300);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Unarmed_Combat, 400);
    add_skill_points(Skill_Blindfighting, 300);
    add_skill_points(Skill_Erotic_Arts, 5000);
    add_skill_points(Skill_Erotic_Lore, 5000);
    add_skill_points(Skill_Awareness, 400);
    add_skill_points(Skill_Dagger, 500);
    add_skill_points(Skill_Find_Weakness, 800);
    add_skill_points(Skill_Killer_Instinct, 400);
    add_skill_points(Skill_Lack_of_Weakness, 400);
    add_skill_points(Skill_Massive_Blow, 400);
    add_skill_points(Skill_Massive_Exertion, 400);
    add_skill_points(Skill_Recuperation, 800);
    add_skill_points(Skill_Breath_Control, 400);
    add_skill_points(Skill_Impact_Absorption, 400);
    add_skill_points(Skill_Fire_Resistance, 400);
    add_skill_points(Skill_Cold_Resistance, 400);
    add_skill_points(Skill_Regeneration, 200);
    set_skill_points(Skill_Shield, 0);

    set_belongings(({
        Sinbyen_Weapon("nyeri"),
        Sinbyen_Armour("boots"),
        Sinbyen_Armour("gloves"),
        Sinbyen_Armour("harness"),
        Sinbyen_Armour("skirt"),
    }));
    
    add_known("chi strike");
    add_known("chi kick");
    add_known("shadow strike");
    add_known("rising torrent");
    
    add_special_attack(([
        Special_Attack_Name            : ({ "Spinning Torrent" }),
        Special_Attack_Vector       : Vector_Torrent,
        Special_Attack_Message        : ({ 0, ({ "crouch", 0 }), "and", ({ "leap", 0 }), "forward, spinning in rapid succesion" }),
        Special_Attack_Type         : ({ "cutting", "ice", "spirit", }),
        Special_Attack_Skill        : ({ Skill_Dagger, Skill_Dancing }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Tessen),
        Special_Attack_Chance       : Special_Attack_Chance_Occasional,
        Special_Attack_Size            : Special_Attack_Size_Very_Large
    ]));
    
    add_special_attack(([
        Special_Attack_Name            : ({ "Vault" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message        : ({ 0, ({ "vault", 0 }), "over", "%e", "and", ({ "thrust", 0 }), "%c", "at", ({ 'r', "%e", "back" })}),
        Special_Attack_Type         : ({ "cutting", "fire", "spirit", }),
        Special_Attack_Skill        : ({ Skill_Dagger, Skill_Dancing }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Dagger),
        Special_Attack_Chance       : Special_Attack_Chance_Occasional,
        Special_Attack_Size            : Special_Attack_Size_Very_Large
    ]));
    
    
}