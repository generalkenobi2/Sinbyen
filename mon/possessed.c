#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
    ::configure();
    set_race(random_element(([ 
                "thond"     : 50,
                "human"     : 50,
                "orc"       : 50,
                "tuatha"    : 10,
                "amberite"  : 10,
                "fomor"     : 5,
            ])));
    alter_identity(([    
        Identity_Special_Names      : ({ "SINBYEN_UNDEAD", "SINBYEN_DEMON" }),
        Identity_Code               : "posessed",
        Identity_Known_Adjectives   : ({({ "possessed", 0, Seeable_Order_Late })}),
        Identity_Flags                : Identity_Flag_Suppress_Elements,
    ]));
    set_identify_skills(([
                Skill_Arcane_Lore           : 100,
                Skill_Qlippotic_Lore        : 120,
                Skill_Legend_Lore           : 100,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
        ({ 'v', 0 }), ({ "are", 0 }), "an astoundingly large", ({ 'c', 0 }),
        "with", random_element(({    
                        "shoulder-length",
                        "long",
                        "short",
                        "patchy",
                    })),
                            Description(([
                                Description_Type    : Description_Type_Element_Name,
                                Description_Index   : Material_Hair,
                                Description_Flags   : Description_Flag_Noun,
                            ])),
        ",", random_element(({
                        "tightly stretched",
                        "decaying",
                    })),
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
        "that glow sickeningly in the {{shadowfire}unnatural darkness} that surrounds", ({ 'o', 0 }),
        }),
        Description_Order                               : Description_Order_Extremely_Early,
    ]));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "dark black",
                    "gray",
                    "dark gray",
                    "white",
                    "light gray",
                                                            }))
    );
    alter_element(Material_Eye, Element_Color, "pearly light blue");
    alter_element(Material_Skin, Element_Color, random_element(({
                    "bright red-spotted black",
                    "light blue-spotted black",
                    "light blue-spotted gray",
                    "bright red-spotted gray"
                    "bright red-streaked black",
                    "light blue-streaked black",
                    "light blue-streaked gray",
                    "bright red-streaked gray",
    })));
    set_level(48 + random(10));
    set_aggressive(True);
    set_alignment(({ -750, -750 }));
    add_friend("SINBYEN_UNDEAD");
    add_friend("SINBYEN_DEMON");
    set_strike_location("head");
    set_can_kill(True);
    set_walk_verb("stride");
    add_affiliation("demonic blood");
    set_combat_mode_selected(Combat_Mode_Patient);
    add_permanent_attribute_adjustment(Attribute_Strength, 300);
    add_permanent_attribute_adjustment(Attribute_Constitution, 400);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 200);
    add_permanent_attribute_adjustment(Attribute_Perception, 100);
    add_permanent_attribute_adjustment(Attribute_Size, random_range(50, 80));
    add_skill_points(Skill_Massive_Blow, 600);
    add_skill_points(Skill_Precision_Strike, 400);
    add_skill_points(Skill_Sword, 1200);
    add_skill_points(Skill_Chromatostasis, 1200);
    add_skill_points(Skill_Tactics, 150);
    add_skill_points(Skill_Flail, 1200);
    add_skill_points(Skill_Hammer, 1200);
    add_skill_points(Skill_Axe, 1200);
    add_skill_points(Skill_Quickness, 100);
    add_skill_points(Skill_Massive_Exertion, 600);
    add_skill_points(Skill_Hardiness, 400);
    add_skill_points(Skill_Dodge, 400);
    add_skill_points(Skill_Supernal_Durability, 100);
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
    add_skill_points(Skill_Fire_Resistance, 50);
    add_skill_points(Skill_Water_Resistance, 50);
    add_skill_points(Skill_Force_Resistance, 50);
    add_skill_points(Skill_Qlippotic_Resistance, 300);
    add_skill_points(Skill_Heat_Resistance, 50);
    add_skill_points(Skill_Chaos_Resistance, 50);
    add_skill_points(Skill_Crushing_Resistance, 50);
    add_skill_points(Skill_Blindfighting, 300);
    set_trait(Trait_Paraneurism, True);    
    set_combat_chat(20, ({
        
        "concentrate on inducing bloodlust in myself",
    }));
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
        ([
        Belonging_File  : Random_Item_Any,
        ]),
    }));
}
