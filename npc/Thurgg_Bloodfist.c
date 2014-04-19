#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Thurgg's Cave map_2_-4_0//

void horse_combat() {
    object victim = query_attacker();
    if(victim == 0) {
        return;
    }
    if (victim->race()->query_race_category("equine")){
        init_command("shout Fuck that horse up!");
    }
    else{
        init_command("frown");
    }
}

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("iyiyik");
    set_sex(Sex_Male);
    set_level(80);
    set_omniscience(True);
    add_friend("SINBYEN_GUARD");
    add_friend("SINBYEN_CITIZEN");
    add_enemy("horse");
    add_enemy("SINBYEN_DEMON");
    add_enemy("SINBYEN_UNDEAD");
    set_culture_name(({ "Thurgg", "Bloodfist" }));
    set_alignment(({ 0, -750 }));
    add_description(({
        ({'v', 0 }), ({ "are", 0 }), "a massive, muscular", ({ 'c', 0 }), "with",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Fur,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ",",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Skin,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", and",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
    }));
    add_description(({
          "scars cover", ({ 'q', 0 }), "muscled figured",
    }));
    add_description(({
          ({ 'v', 0 }), ({ "are", 0 }),  "undoubtedly a killing machine",
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'o', 0 }), "as the fierce primarch of the Crimson Fist",
    }));
    add_known_description(({
        ({ 'p', 0 }), ({ "are", 0 }), "well known for irrational violence and an unhealthy hatred of horses",
    }));
    alter_element(Material_Hair, Element_Color, "black");
    alter_element(Material_Eye, Element_Color, "black");
    alter_element(Material_Fur, Element_Color, "mottled brown");
    add_permanent_attribute_adjustment(Attr_Str, 1200);
    add_permanent_attribute_adjustment(Attr_Int, 120);
    add_permanent_attribute_adjustment(Attr_Con, 600);
    add_permanent_attribute_adjustment(Attr_Dex, 400);
    add_permanent_attribute_adjustment(Attr_Wil, 200);
    add_permanent_attribute_adjustment(Attr_Cha, 110);
    add_permanent_attribute_adjustment(Attr_Per, 200);
    add_permanent_attribute_adjustment(Attr_Siz, 70);
    set_combat_mode_selected(Combat_Mode_Patient);
    set_trait(Trait_Berserkergang, 3);
    set_trait(Trait_Paraneurism, True);
    set_trait(Trait_Paravision, True);
    
    set_chat(3, ({
        "say Did you come here looking for me? to %p",
        "say I don't much care for horses, so keep them out of my city. to %p",
        "say I once punched a villager's head so hard, it flew over Sinbyen. to %p",
        "say A heavilly armoured knight works as a fine anchor. to %p",
        "say If you're angry enough you no longer feel pain. to %p",
        "say Even death cannot seat my anger. to %p",
        "say I don't think i've met someone that i didn't like better dead. to %p",
        "say The Crimson Fist is accepting of great warriors that are willing to apply their strength and harness their anger. to %p",
        "whisper Dashing through the snow... get the fuck out of my way... to myself",
        "say Anger can fix anything, and if it didnt work the first time, you obviously weren't angry enough. to %p",
        "say Kill first, ask questions later. to %p",
        "say Shen. to %p",
        "snarl",
        "say You're still breathing? to %p",
        ";crack my knuckles",
        ";glare at %p",
        ";growl angrily",
        "cut head from corpse",
    }));
    set_responses(([  
                ({ "join", "petition" }) : 
                        (: "say I'm in no mood to talk about this right now." :),
    ]));      

    set_combat_chat(20, ({
        "shout Once you're dead I'm going to hollow your head and use it as a hat! to %e",
        "shout You never had a chance! %e",
        ";scream in anger",
        "shout Bow before me! I may let you live!",
    }));
    
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Weapon("hestjeger"),
        Belonging_Flags        : Belonging_Flag_Hold_Two_Handed,
            Belonging_Alternate : ([
                                    Belonging_File  : LS_Weapon("greataxe"),
                                    Belonging_Flags : Belonging_Flag_Hold_Two_Handed,
            ]),            
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("crimson_plate"),
        Belonging_Initialize       : (:
                                $1->armour()->perform_adapt(this_object())
                        :),
        ]),
    }));
    set_strike_location("head");
    set_primary_language(Skill_Norska);
    set_can_kill(True);
    set_weapon_class(24, Limb_Type_Hand, ({"cutting", "spirit" }));

        add_skill_points(Skill_Dodge, 600);
        add_skill_points(Skill_Streetwise, 400);
        add_skill_points(Skill_Norska, 100);
        add_skill_points(Skill_Supernal_Durability, 400);
        add_skill_points(Skill_Axe, 1400);
        add_skill_points(Skill_Quickness, 400);
        add_skill_points(Skill_Tenacity, 400);
        add_skill_points(Skill_Logistics, 200);
        add_skill_points(Skill_Subordination, 100);
        add_skill_points(Skill_Unarmed_Combat, 600);
        add_skill_points(Skill_Brawling, 600);
        add_skill_points(Skill_Hardiness, 1000);
        add_skill_points(Skill_Killer_Instinct, 600);
        add_skill_points(Skill_Literacy, 40);
        add_skill_points(Skill_Steadiness, 9001);
        add_skill_points(Skill_Pain_Tolerance, 400);
        add_skill_points(Skill_Stamina, 10000);
        add_skill_points(Skill_Combat_Reflexes, 1000);
        add_skill_points(Skill_Courage, 500);
        add_skill_points(Skill_Intimidation, 400);
        add_skill_points(Skill_Anatomy, 800);
        add_skill_points(Skill_Leadership, 400);
        add_skill_points(Skill_Massive_Blow, 1000);
        add_skill_points(Skill_Robustness, 800);
        add_skill_points(Skill_Blindfighting, 500);
        add_skill_points(Skill_Resilience, 400);
        add_skill_points(Skill_Breath_Control, 300);
        
    add_special_attack(([
        Special_Attack_Name            : ({ "Enraged Arc" }),
        Special_Attack_Vector       : Vector_Arc,
        Special_Attack_Message        : ({ 0, ({ "sidestep", 0 }), "and", ({ "swing", 0 }), "%c", "with incredible speed and might", }),
        Special_Attack_Type         : ({ "cutting", "piercing", "spirit", }),
        Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Overwhelming,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greataxe),
        Special_Attack_Activity        : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Profuse,
        Special_Attack_Size            : Special_Attack_Size_Huge,
    ]));
    add_special_attack(([
        Special_Attack_Name            : ({ "Clean Split" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message        : ({ 0, ({ "swing", 0 }), "%c", "downward at an angle", "%e", "with all", ({ 'r', 0, "might" }), }),
        Special_Attack_Type         : ({ "cutting", "piercing", "spirit", }),
        Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greataxe),
        Special_Attack_Activity        : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size            : Special_Attack_Size_Very_Large,
    ]));
add_explicit_maneuver_access("straight knee");
    
}

