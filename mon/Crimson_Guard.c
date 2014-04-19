#include <Sinbyen.h>
#include <autonomon.h>
#include <speech.h>


inherit Sinbyen_Monster("Citizen");

void configure() {
    ::configure();
    set_race(random_element(({ "thond", "human", "orc" })));
    alter_identity(Identity_Special_Names, ({ "SINBYEN_GUARD" }), Identity_Alter_Add);
    alter_identity(Identity_Special_Names, ({ "Crimson" }), Identity_Alter_Add);
    set_culture("Losthavener");
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            ({ 'v', 0 }), ({ "are", 0 }), "a hefty", ({ 'x', 0 }), ({ 'c', 0 }),
            "with", random_element(({    
                        "shoulder-length",
                        "long",
                        "short",
                    })),
                            Description(([
                                Description_Type    : Description_Type_Element_Name,
                                Description_Index   : Material_Hair,
                                Description_Flags   : Description_Flag_Noun,
                            ])),
            ",",
                            Description(([
                                Description_Type    : Description_Type_Element_Name,
                                Description_Index   : Material_Skin,
                                Description_Flags   : Description_Flag_Noun,
                            ])),
            "and",
                            Description(([
                                Description_Type    : Description_Type_Element_Color,
                                Description_Index   : Material_Eye,
                                Description_Content : "eyes",
                            ])),
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "blonde",
                    "black",
                    "dark brown",
                    "white",
                    "light gray",
    })));
    alter_element(Material_Eye, Element_Color, random_element(({
                    "blue",
                    "green",
                    "brown",
                    "sky blue"
    })));
    alter_element(Material_Skin, Element_Color, random_element(({
                    "black",
                    "white",
                    "tan",
                    "brown"
    })));
    set_level(32 + random(10));
    set_alignment(({ 0, 0 }));
    add_friend("SINBYEN_GUARD");
    add_friend("SINBYEN_CITIZEN");
    add_friend("LOSTHAVEN_DWELLER");
    add_enemy("SINBYEN_DEMON");
    add_enemy("SINBYEN_UNDEAD");
    set_strike_location("head");
    set_can_kill(True);
    set_area_guarding(True);
    set_realms(({ "SINBYEN_CITY" }));
    set_ambulate_flag(Ambulate_Flag_Extended_Fleeing, True);
    set_combat_mode_selected(Combat_Mode_Patient);
    set_ambulate_flag(Ambulate_Flag_Chase, True);
    add_permanent_attribute_adjustment(Attribute_Strength, 40);
    add_permanent_attribute_adjustment(Attribute_Constitution, 40);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 10);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 100);
    add_permanent_attribute_adjustment(Attribute_Perception, 100);
    add_permanent_attribute_adjustment(Attribute_Size, 20);
    add_skill_points(Skill_Massive_Blow, 600);
    add_skill_points(Skill_Linguistics, 80);
    add_skill_points(Skill_Anglic, 40);
    add_skill_points(Skill_Precision_Strike, 400);
    add_skill_points(Skill_Sword, 900);
    add_skill_points(Skill_Chromatostasis, 900);
    add_skill_points(Skill_Tactics, 150);
    add_skill_points(Skill_Flail, 900);
    add_skill_points(Skill_Hammer, 900);
    add_skill_points(Skill_Axe, 900);
    add_skill_points(Skill_Quickness, 100);
    add_skill_points(Skill_Massive_Exertion, 600);
    add_skill_points(Skill_Hardiness, 400);
    add_skill_points(Skill_Dodge, 200);
    add_skill_points(Skill_Strategy, 200);
    add_skill_points(Skill_Subordination, 200);
    add_skill_points(Skill_Spelunking, 200);
    add_skill_points(Skill_Killer_Instinct, 400);
    add_skill_points(Skill_Martial_Arts, 150);
    add_skill_points(Skill_Spear, 900);
    add_skill_points(Skill_Steadiness, 200);
    add_skill_points(Skill_Resilience, 300);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Blindfighting, 80);
    set_combat_chat(20, ({
        
        "shout You'll never make it out of here alive! to %e",        
        "shout You're done! to %e",
        "shout Feel my wrath! to %e",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
        "shout My kinsmen! Aid me!",
    }));
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon(random_element(({
                                            "crimson_great_axe",
                                            "crimson_great_sword",
        }))),
        Belonging_Flags    : Belonging_Flag_Hold_Two_Handed,            
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("steel_suit_guard"),    
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("crimson_cloak2"),    
        ]),
    }));
    add_special_attack(([
        Special_Attack_Name         : ({ "Queen's Strike" }),
        Special_Attack_Vector       : Vector_Blade,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward at an angle, spinning around and thrusting", "%c", "violently forward", }),
        Special_Attack_Type         : ({ "cutting", "piercing" }),
        Special_Attack_Skill        : ({ Skill_Sword, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Somewhat_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greatsword),
        Special_Attack_Activity     : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Large,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Massive Cleave" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward straight at", "%e", "with all", ({ 'r', 0, "might" }), }),
        Special_Attack_Type         : ({ "cutting", "piercing", "crushing", }),
        Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Somewhat_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greataxe),
        Special_Attack_Activity     : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Very_Large,
    ]));
}



