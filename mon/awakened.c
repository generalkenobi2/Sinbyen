#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
    ::configure();
    set_race(random_element(([ 
                "human"     : 50,
                "orc"       : 50,
                "tuatha"    : 10,
                "amberite"  : 10,
                "fomor"     : 5,
            ])));
    alter_identity(([    
        Identity_Special_Names      : ({ "SINBYEN_DEMON" }),
        Identity_Code               : "awakened",
        Identity_Nouns              : ({({"creature", 0, Seeable_Order_Early }), ({"anthrope", 0, Seeable_Order_Early }), "enormous creature", "anthropic creature"}),
        Identity_Adjectives         : ({ "enormous", "anthropic" }),
        Identity_Known_Adjectives   : ({}),
        Identity_Known_Nouns        : ({({ "awakened", 0, Seeable_Order_Early })}),
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
            'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as one of the Awakened, one of the few demons that have possessed their host long enough to fully consume them and awaken their power",
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "Upon closer inspection it appears that", ({ 'p', 0 }), "may have once been", 'a', ({ 'x', 0 }), ({ 'c', 0 }),
        }),
        Description_Order                               : Description_Order_Very_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "mountains of muscle shift and ripple with each movement", ({ 'p', 0 }), "makes",
        }),
        Description_Order                               : Description_Order_Significantly_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            'a', "set of",
                random_element(({
                    "massive",
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
    
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            ({ 'r', 0, "{{pearly light green}veins}" }), "{{pearly light green}pulse} with",
            "{{pearly light green}flowing light}, as though something magickal was running through them",
        }),
        Description_Order                               : Description_Order_Significantly_Early,
        Description_Flags                                : Description_Flag_Suppress_Element_Alias,
    ]));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "dark black",
                    "gray",
                    "dark gray",
                    "white",
                    "light gray",
    }))
    );    
    alter_element(Material_Eye, Element_Color, random_element(({
                    "pearly light blue",
                    "pearly light green",
    })));
    alter_element(Material_Skin, Element_Color, random_element(({
                    "bright red-spotted black",
                    "light red-spotted black",
                    "light red-spotted gray",
                    "bright red-spotted gray"
                    "bright red-streaked black",
                    "light red-streaked black",
                    "light red-streaked gray",
                    "bright red-streaked gray",
    })));
    set_level(70 + random(20));
    set_trait(Trait_Aphobia, True);
    set_aggressive(True);
    set_alignment(({ -750, -750 }));
    set_primary_language(Skill_Archaen);
    add_friend("SINBYEN_DEMON");
    set_strike_location("head");
    set_can_kill(True);
    add_affiliation("demonic blood");
    set_combat_mode_selected(Combat_Mode_Patient);
    add_permanent_attribute_adjustment(Attribute_Strength, 600);
    add_permanent_attribute_adjustment(Attribute_Constitution, 600);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 500);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 500);
    add_permanent_attribute_adjustment(Attribute_Perception, 300);
    add_permanent_attribute_adjustment(Attribute_Size, random_range(90, 140));
    add_skill_points(Skill_Massive_Blow, 900);
    add_skill_points(Skill_Precision_Strike, 700);
    add_skill_points(Skill_Sword, 1800);
    add_skill_points(Skill_Chromatostasis, 1200);
    add_skill_points(Skill_Tactics, 400);
    add_skill_points(Skill_Flail, 1800);
    add_skill_points(Skill_Hammer, 1800);
    add_skill_points(Skill_Axe, 1800);
    add_skill_points(Skill_Pole_Arm, 1800);
    add_skill_points(Skill_Quickness, 400);
    add_skill_points(Skill_Massive_Exertion, 700);
    add_skill_points(Skill_Hardiness, 600);
    add_skill_points(Skill_Dodge, 700);
    add_skill_points(Skill_Supernal_Durability, 400);
    add_skill_points(Skill_Strategy, 400);
    add_skill_points(Skill_Subordination, 200);
    add_skill_points(Skill_Spelunking, 300);
    add_skill_points(Skill_Killer_Instinct, 600);
    add_skill_points(Skill_Qlippotic_Affinity, 500);
    add_skill_points(Skill_Martial_Arts, 600);
    add_skill_points(Skill_Spear, 1800);
    add_skill_points(Skill_Courage, 5000);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Combat_Reflexes, 700);
    add_skill_points(Skill_Water_Resistance, 100);
    add_skill_points(Skill_Force_Resistance, 100);
    add_skill_points(Skill_Qlippotic_Resistance, 600);
    add_skill_points(Skill_Heat_Resistance, 100);
    add_skill_points(Skill_Chaos_Resistance, 100);
    add_skill_points(Skill_Piercing_Resistance, 100);
    add_skill_points(Skill_Cutting_Resistance, 100);
    add_skill_points(Skill_Crushing_Resistance, 100);
    add_skill_points(Skill_Archaen, 300);
    set_trait(Trait_Paraneurism, True);
    set_trait(Trait_Paravision, True);
    set_chat(3, ({
        ";scan the area",
        ";snort",
        ";breath deeply",
        "say Soon I will be strong enough to leave this place",
        "say I can feel my power growing",
        "say Blast these tunnels!  They go on forever.",
        "say Leave me be, %p, or I will end you",
        
    }));
    set_combat_chat(20, ({        
        "say Did you expect this to go well? to %e",
        "say I will destroy you. to %e",
        "say Soon my i will drink your blood. to %e",
        "start following %e",
    }));
    set_attack_message(({
        ({ "draw", 0 }), ({ 'r', 0, "weapon" }), "and", ({ "approach", 0 }), "%e",
    }));
    set_belongings(({
        ([
            Belonging_File      : Sinbyen_Weapon("demon_weapon"),
            Belonging_Flags     : Belonging_Flag_Hold_Two_Handed,
        ]),
        ([
            Belonging_File      : Sinbyen_Armour("demon_plate"),
        ]),
        ([
            Belonging_File      : Random_Item_Armour,
        ]),
        ([
            Belonging_File      : Random_Item_Any,
        ]),
    }));
    
    add_special_attack(([
        Special_Attack_Name         : ({ "Enraged Arc" }),
        Special_Attack_Vector       : Vector_Arc,
        Special_Attack_Message      : ({ 0, ({ "sidestep", 0 }), "and", ({ "swing", 0 }), "%c", "with incredible speed and might", }),
        Special_Attack_Type         : ({ "cutting", "spirit", "force", }),
        Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Axe),
        Special_Attack_Activity     : 40,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Huge,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Queen's Cross" }),
        Special_Attack_Vector       : Vector_Blade,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward at an angle, spinning around and bringing", "%c", "up and across again", }),
        Special_Attack_Type         : ({ "cutting", "spirit", "force", }),
        Special_Attack_Skill        : ({ Skill_Sword, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Sword),
        Special_Attack_Activity     : 40,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Huge,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Massive Hammer Swing" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward straight at", "%e", "with all", ({ 'r', 0, "might" }), }),
        Special_Attack_Type         : ({ "force", "spirit", "crushing", }),
        Special_Attack_Skill        : ({ Skill_Hammer, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Hammer),
        Special_Attack_Activity     : 40,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Huge,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Massive Flail Swing" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward straight at", "%e", "with all", ({ 'r', 0, "might" }), }),
        Special_Attack_Type         : ({ "force", "spirit", "crushing", }),
        Special_Attack_Skill        : ({ Skill_Flail, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Flail),
        Special_Attack_Activity     : 40,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Huge,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Reaper's Gambit" }),
        Special_Attack_Vector       : Vector_Blade,
        Special_Attack_Message      : ({ 0, ({ "jump", 0 }), "back and", ({ "raise", 0 }), "%c", "back momentarily and {{shadowfire}dark energy} rushes into", "%c", ". ", 'c', 0, "then", ({ "leap", 0 }), "forward, swinging", ({ 'r', 0, "%c" }), "with demonic fury", }),
        Special_Attack_Type         : ({ "shadow", "spirit", "cutting", }),
        Special_Attack_Skill        : ({ Skill_Pole_Arm, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Scythe),
        Special_Attack_Activity     : 40,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Large,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Keen's Lance" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "gather", 0 }), "{{shadowfire}dark energy} around the", "%c", "and", ({ "thrust", 0 }), "it toward", "%e", }),
        Special_Attack_Type         : ({ "piercing", "spirit", "shadow", }),
        Special_Attack_Skill        : ({ Skill_Spear, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Activity     : 40,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Spear),
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Small,
    ]));
    
}

void awakened_weapon_class() {
    set_weapon_class(18, Limb_Type_Hand, ({"claw!cutting", "shadow", "spirit" }));
    set_weapon_class(12, Limb_Type_Head, ({"horn!stabbing" }), "horns");
    init_command("stop attacking with uppercut");
    init_command("stop attacking with elbow smash");
    init_command("stop attacking with punch");
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
    init_command("set resolve to 100");
}

void create() {
    ::create();
    call_out("awakened_weapon_class", 2);
}