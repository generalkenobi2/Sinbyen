#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
    ::configure();
    set_race(random_element(({"skeleton", "thond", "human", "orc" })));
    alter_identity(([    
        Identity_Special_Names      : ({ "SINBYEN_UNDEAD" }),
        Identity_Code               : "reanimated",
        Identity_Known_Adjectives   : ({({ "reanimated", 0, Seeable_Order_Early })}),
        Identity_Known_Nouns        : ({({ "corpse", 0, Seeable_Order_Late })}),
        Identity_Flags              : Identity_Flag_Suppress_Elements,
    ]));
    set_identify_skills(([
                Skill_Arcane_Lore           : 100,
                Skill_Qlippotic_Lore        : 120,
                Skill_Legend_Lore           : 100,
    ]));
    if(query_race() != "skeleton")
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "with large", random_element(({
                                        "lifeless",
                                        "emotionless",
                                        "empty",
                                    })),
                                Description(([
                                    Description_Type    : Description_Type_Element_Color,
                                    Description_Index   : Material_Eye,
                                    Description_Content : "eyes",
                                ])),
                ",", random_element(({
                                        "rotting",
                                        "decomposing",
                                        "deteriorating",
                                    })),
                                Description(([
                                    Description_Type    : Description_Type_Element_Name,
                                    Description_Index   : Material_Skin,
                                    Description_Flags   : Description_Flag_Noun,
                                ])),
                ", and", random_element(({
                                        "dirty,",
                                        "grungy,",
                                        "clumps of",
                                    })),
                     random_element(({
                                        "shoulder-length",
                                        "short",
                                        "long",
                                    })),
                    Description(([
                        Description_Type    : Description_Type_Element_Name,
                        Description_Index   : Material_Hair,
                        Description_Flags   : Description_Flag_Noun,
                    ])),
        }),
        Description_Order                   : Description_Order_Extremely_Early,
    ]));                            
    add_description(([
        Description_Type                    : Description_Type_Simple,
        Description_Content                 : ({
            random_element(({
                            "ripped",
                            "torn",
                            })),
            "clothing clings to", ({ 'r', 0, "limbs" }),
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    set_level(36 + random(10));
    set_aggressive(True);
    set_alignment(({ -400, -400 }));
    add_friend("SINBYEN_UNDEAD");
    set_strike_location("head");
    set_can_kill(True);
    set_walk_verb("wander");
    set_combat_mode_selected(Combat_Mode_Patient);
    add_permanent_attribute_adjustment(Attribute_Strength, 200);
    add_permanent_attribute_adjustment(Attribute_Constitution, 300);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 100);
    add_permanent_attribute_adjustment(Attribute_Perception, 30);
    add_permanent_attribute_adjustment(Attribute_Size, random_range(30, 60));
    add_skill_points(Skill_Massive_Blow, 300);
    add_skill_points(Skill_Precision_Strike, 300);
    add_skill_points(Skill_Sword, 900);
    add_skill_points(Skill_Tactics, 150);
    add_skill_points(Skill_Flail, 900);
    add_skill_points(Skill_Hammer, 900);
    add_skill_points(Skill_Axe, 900);
    add_skill_points(Skill_Quickness, 100);
    add_skill_points(Skill_Massive_Exertion, 600);
    add_skill_points(Skill_Hardiness, 600);
    add_skill_points(Skill_Dodge, 200);
    add_skill_points(Skill_Strategy, 200);
    add_skill_points(Skill_Subordination, 200);
    add_skill_points(Skill_Spelunking, 200);
    add_skill_points(Skill_Killer_Instinct, 300);
    add_skill_points(Skill_Qlippotic_Affinity, 200);
    add_skill_points(Skill_Spear, 900);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Combat_Reflexes, 200);
    add_skill_points(Skill_Blindfighting, 300);

    
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon("undead_weapon"),
        Belonging_Flags : Belonging_Flag_Hold_Two_Handed,            
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
