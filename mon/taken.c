#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
    ::configure();
    set_race(random_element(({ "thond", "human", "orc", })));
    alter_identity(([    
        Identity_Special_Names      : ({ "SINBYEN_DEMON" }),
        Identity_Code               : "taken",
        Identity_Nouns              : ({"creature", "huge creature", "anthropic creature"}),
        Identity_Known_Nouns        : ({({ "taken", 0, Seeable_Order_Early })}),
        Identity_Adjectives         : ({ "huge", "anthropic" }),
        Identity_Known_Adjectives   : ({}),
        Identity_Flags              : Identity_Flag_Suppress_Elements | Identity_Flag_Suppress_Race | Identity_Flag_Suppress_Sex,
    ]));
    set_identify_skills(([
                Skill_Arcane_Lore           : 100,
                Skill_Qlippotic_Lore        : 120,
                Skill_Legend_Lore           : 100,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            ({ 'v', 0 }), ({ "are", 0 }), "an enormous, demonic creature.",
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    add_known_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as one of the Taken, a possessed creature that no longer has the willpower to resist, and allows the possessor to take full control",
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            " Upon closer inspection it appears that", ({ 'p', 0 }), "may have once been", 'a', ({ 'x', 0 }), ({ 'c', 0 }),
        }),
        Description_Order                               : Description_Order_Very_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "slabs of muscle shift and move with each motion", ({ 'p', 0 }), "makes",
        }),
        Description_Order                               : Description_Order_Significantly_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            'a', "set of",
                random_element(({
                                "massive",
                                "twisted",
                                "long",
                })),
            "{{black}black horns} sprout from the top of", ({ 'r', 0, "head" }), 
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({    
            ({ 'r', 0, "body" }), ({ "are", 0 }), "covered by",
                    
                            Description(([
                                Description_Type    : Description_Type_Element_Name,
                                Description_Index   : Material_Skin,
                                Description_Flags   : Description_Flag_Noun,
                            ])),
            "and has glowing",
                            Description(([
                                Description_Type    : Description_Type_Element_Color,
                                Description_Index   : Material_Eye,
                                Description_Content : "eyes",
                            ])),
            "that stand out in the {{shadowfire}unnatural darkness} that surrounds", ({ 'o', 0 }),
        }),
        Description_Order                               : Description_Order_Slightly_Early,
    ]));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "dark black",
                    "gray",
                    "dark gray",
                    "white",
                    "light gray",
    })));    
    alter_element(Material_Eye, Element_Color, random_element(({
                    "pearly light blue",
                    "pearly light green",
    })));
    alter_element(Material_Skin, Element_Color, random_element(({
                    "bright green-spotted black",
                    "light blue-spotted black",
                    "light blue-spotted gray",
                    "bright green-spotted gray"
                    "bright green-streaked black",
                    "light blue-streaked black",
                    "light blue-streaked gray",
                    "bright green-streaked gray",
    })));
    set_trait(Trait_Berserkergang, 5);
    set_level(60 + random(10));
    set_aggressive(True);
    set_alignment(({ -750, -750 }));
    set_primary_language(Skill_Archaen);
    add_friend("SINBYEN_DEMON");
    set_strike_location("head");
    set_can_kill(True);
    set_walk_verb("lumber");
    add_affiliation("demonic blood");
    set_combat_mode_selected(Combat_Mode_Patient);
    add_permanent_attribute_adjustment(Attribute_Strength, 500);
    add_permanent_attribute_adjustment(Attribute_Constitution, 500);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 300);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_permanent_attribute_adjustment(Attribute_Size, random_range(70, 110));
    add_skill_points(Skill_Massive_Blow, 700);
    add_skill_points(Skill_Precision_Strike, 400);
    add_skill_points(Skill_Sword, 1500);
    add_skill_points(Skill_Chromatostasis, 1200);
    add_skill_points(Skill_Tactics, 150);
    add_skill_points(Skill_Flail, 1500);
    add_skill_points(Skill_Hammer, 1500);
    add_skill_points(Skill_Axe, 1500);
    add_skill_points(Skill_Quickness, 200);
    add_skill_points(Skill_Massive_Exertion, 700);
    add_skill_points(Skill_Hardiness, 500);
    add_skill_points(Skill_Dodge, 500);
    add_skill_points(Skill_Supernal_Durability, 200);
    add_skill_points(Skill_Strategy, 200);
    add_skill_points(Skill_Subordination, 200);
    add_skill_points(Skill_Spelunking, 200);
    add_skill_points(Skill_Killer_Instinct, 400);
    add_skill_points(Skill_Qlippotic_Affinity, 300);
    add_skill_points(Skill_Martial_Arts, 400);
    add_skill_points(Skill_Spear, 1200);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Fire_Resistance, 100);
    add_skill_points(Skill_Water_Resistance, 100);
    add_skill_points(Skill_Force_Resistance, 100);
    add_skill_points(Skill_Qlippotic_Resistance, 450);
    add_skill_points(Skill_Heat_Resistance, 100);
    add_skill_points(Skill_Chaos_Resistance, 100);
    add_skill_points(Skill_Piercing_Resistance, 100);
    add_skill_points(Skill_Cutting_Resistance, 100);
    add_skill_points(Skill_Crushing_Resistance, 100);
    add_skill_points(Skill_Blindfighting, 300);
    add_skill_points(Skill_Archaen, 300);
    set_trait(Trait_Paraneurism, True);
    set_trait(Trait_Paravision, True);
    set_chat(3, ({
        ";sniff the air",
        ";growl",
        ";look around",
        "say I sense something",
        "say A challenger? to %p",
    }));
    set_combat_chat(20, ({        
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        "say blood... to %e",
    }));
    set_attack_message(({
        0, ({ "rush", 0 }), "toward", "%e",
    }));
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon("demon_weapon"),
        Belonging_Flags    : Belonging_Flag_Hold_Two_Handed,
        ]),
        ([
        Belonging_File  : Random_Item_Armour,    
        ]),
        ([
        Belonging_File  : Random_Item_Armour,    
        ]),
        ([
        Belonging_File  : Random_Item_Any,    
        ]),
        
    }));
    add_special_attack(([
        Special_Attack_Name         : ({ "Shoulder Slam" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "slam", 0 }), ({ 'r', 0, "shoulder" }), "violently toward", "%e", }),
        Special_Attack_Type         : ({ "crushing", "force" }),
        Special_Attack_Skill        : ({ Skill_Sword, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Powerful,
        Special_Attack_Chance       : Special_Attack_Chance_Somewhat_Frequent,
        Special_Attack_Size         : Special_Attack_Size_Large,
    ]));
    
}

void taken_weapon_class() {
    set_weapon_class(16, Limb_Type_Hand, ({"claw!cutting", "shadow", "spirit" }));
    set_weapon_class(10, Limb_Type_Head, ({"horn!stabbing" }), "horns");
    init_command("stop attacking with uppercut");
    init_command("stop attacking with elbow smash");
    init_command("stop attacking with punch");
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
}

void create() {
    ::create();
    call_out("taken_weapon_class", 2);
}
