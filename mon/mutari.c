#include <Sinbyen.h>
#include <autonomon.h>
#include <mental_disorders.h>
#include <Devonshire.h>

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
        Identity_Code                       : "mutari",
        Identity_Nouns                      : ({({"deformed tailed anthropic creature", 0, Seeable_Order_Early }),({ "creature", 0, Seeable_Order_Early }), ({"anthrope", 0, Seeable_Order_Early })}),
        Identity_Known_Nouns                : ({({ "mutari", 0, Seeable_Order_Early })}),
        Identity_Flags                      : Identity_Flag_Suppress_Elements | Identity_Flag_Suppress_Race | Identity_Flag_Suppress_Sex,
    ]));
    set_identify_skills(([
                Skill_Arcane_Lore           : 200,
                Skill_Qlippotic_Lore        : 120,
                Skill_Legend_Lore           : 160,
    ]));
    add_description(([
        Description_Type                    : Description_Type_Simple,
        Description_Content                 : ({
            ({ 'v', 0 }), ({ "are", 0 }), "a large, deformed creature, that appears to have chosen to walk on hands and feet rather than stand",
        }),
        Description_Order                   : Description_Order_Extremely_Early,
    ]));    
    add_known_description(([
        Description_Type                    : Description_Type_Simple,
        Description_Content                 : ({
            'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as one of the Mutari, the result of a powerful demon gone mad",
        }),
        Description_Order                   : Description_Order_Extremely_Early,
    ]));
    add_description(([
                Description_Type            : Description_Type_Viewer_Condition,
                Description_Index           : ([
                    Condition_Type_Code     : Condition_Type_Attribute,
                    Condition_Info          : Attribute_Perception,
                    Condition_Value         : (200),
                ]),
                Description_Content         : ({
                    "Upon closer inspection it appears that", ({ 'p', 0 }), "may have once been", 'a', ({ 'x', 0 }), ({ 'c', 0 }),
                }),
                Description_Order                       : Description_Order_Very_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            Description(([
                Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Hearing,
                ]),
                Description_Content                     :({ "each quick, disjointed motion is accompanied by the sound of bones snapping and tearing flesh" }),            ])),
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "each movement", ({ 'p', 0 }), ({ "make", 0 }), "is strange,", ({ 'r', 0, "limbs" }), "bend in places where no joints would be", }),
        Description_Order                               : Description_Order_Significantly_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            'a', "set of",
                random_element(({
                                "broken",
                                "twisted",
                })),
            "{{black}black horns} rest on the top of", ({ 'r', 0, "head" }), 
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({    
            ({ 'r', 0, "body" }), ({ "are", 0 }), "covered by scarred",
                    
                            Description(([
                                Description_Type        : Description_Type_Element_Name,
                                Description_Index       : Material_Skin,
                                Description_Flags       : Description_Flag_Noun,
                            ])),
            ", and empty scarred sockets sit where one would expect to see eyes",
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
    set_trait(Trait_Handedness, Limb_Lateral_None, ({ Limb_Lateral_None, Limb_Lateral_Left, Limb_Lateral_Right }), True);
    set_trait(Trait_Berserkergang, 5);
    set_trait(Trait_Regrowth, 5);
    set_level(80 + random(15));
    set_anatomy("clawed tailed anthropoid");
    set_corpse_remains("/w/krash/Sinbyen/mod/disfigured_remains");
    set_limb_remains("/w/krash/Sinbyen/mod/disfigured_limbs");
    set_armour_class(30);
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_aggressive(True);
    set_agg_delay(10);
    set_alignment(({ -750, -750 }));
    set_primary_language(Skill_Archaen);
    set_can_kill(True);
    set_walk_verb("crawl");
    add_affiliation("demonic blood");
    add_permanent_attribute_adjustment(Attribute_Strength, 500);
    add_permanent_attribute_adjustment(Attribute_Constitution, 500);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 300);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_permanent_attribute_adjustment(Attribute_Size, random_range(40, 100));
    add_skill_points(Skill_Massive_Blow, 800);
    add_skill_points(Skill_Precision_Strike, 550 + random(100));
    add_skill_points(Skill_Chromatostasis, 1200);
    add_skill_points(Skill_Tactics, 350 + random(100));
    add_skill_points(Skill_Quickness, 950 + random(100));
    add_skill_points(Skill_Massive_Exertion, 650 + random(100));
    add_skill_points(Skill_Hardiness, 550 + random(100));
    add_skill_points(Skill_Dodge, 700 + random(100));
    add_skill_points(Skill_Supernal_Durability, 450 + random(100));
    add_skill_points(Skill_Spelunking, 300);
    add_skill_points(Skill_Killer_Instinct, 600);
    add_skill_points(Skill_Qlippotic_Affinity, 300);
    add_skill_points(Skill_Martial_Arts, 800 + random(200));
    add_skill_points(Skill_Unarmed_Combat, 1000 + random(300));
    add_skill_points(Skill_Stamina, 3000);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Combat_Reflexes, 1200);
    add_skill_points(Skill_Fire_Resistance, 300);
    add_skill_points(Skill_Water_Resistance, 300);
    add_skill_points(Skill_Force_Resistance, 300);
    add_skill_points(Skill_Qlippotic_Resistance, 900);
    add_skill_points(Skill_Heat_Resistance, 300);
    add_skill_points(Skill_Chaos_Resistance, 300);
    add_skill_points(Skill_Piercing_Resistance, 100);
    add_skill_points(Skill_Cutting_Resistance, 100);
    add_skill_points(Skill_Courage, 1000);
    add_skill_points(Skill_Crushing_Resistance, 100);
    add_skill_points(Skill_Blindfighting, 1800);
    add_skill_points(Skill_Regeneration, 300);
    add_skill_points(Skill_Archaen, 300);
    set_trait(Trait_Paraneurism, True);
    set_trait(Trait_Blindness, existing_limbs(Limb_Type_Head));
    

    set_chat(10, ({
        ";cough violently",
        ";run my tongue along the ground",
        ";scream incoherently",
        ";scratch madly at the ground",
        ";chitter madly",
        ";growl",
        "throw item",
        "throw item",
        "throw item",
        "get all",
        "shout will this pain never end?",
        "shout end it, end me, oh the pain",
        "shout no this isn't how it ends",
        "shout can't see it anymore",
        "shout can't make me.. stop",
        "shout if i can't see it, it won't hurt anymore!",
        "shout why oh why...",
        "shout need to find food!",
        ({ ({ 't', 0 }), ({ "drag", 0 }), ({ 'r', 0, "face" }), "along the ground in a zig zag pattern", }),
        ({ ({ 't', 0 }), ({ "rip", 0 }), "a small section of", ({ 'r', 0, "skin" }), "from", ({ 'r', 0, "body" }), "and", ({ "eat", 0 }), "it", }),
        

        
    }));
    set_combat_chat(20, ({        
        "concentrate on inducing bloodlust in myself",
        "concentrate on inducing bloodlust in myself",
        ";scream incoherently",
        "unwield all",
        "unwield all",
        "throw item!",
        "shout just a taste! to %e",
        "shout so hungry! to %e",
    }));
    set_attack_message(({
        "sensing", "%e", 0, ({ "leap", 0 }), ", flailing through the air, at", "%e",
    }));
    set_belongings(({
        ([
        Belonging_File  : Random_Item_Armour,
        ]),
        ([
        Belonging_File  : Random_Item_Armour,
        ]),
        ([
        Belonging_File  : Random_Item_Any,
        ]),
        ([
        Belonging_File  : Random_Item_Any,
        ]),
        ([
        Belonging_File  : Random_Item_Any,
        ]),
        
    }));
        LS_Mental_Disorder("productive_aphasia")->inflict_mental_disorder(this_object(), 100, True);
        LS_Mental_Disorder("neuralgia")->inflict_mental_disorder(this_object(), semirandom(80, 4), True);
        LS_Mental_Disorder("tourette's_syndrome")->inflict_mental_disorder(this_object(), semirandom(80, 4), True);
        
    add_special_attack(([
        Special_Attack_Name         : ({ "Ancient Agony" }),
        Special_Attack_Vector       : Vector_Needle,
        Special_Attack_Message      : ({ 0, ({ "wail", 0 }), "in agony as a piece of {{white}bone} rips free from", ({ 'r', 0, "body" }), ".  The {{white}bone} starts spinning and hurdles toward", "%e", }),
        Special_Attack_Type         : ({ "piercing", "spirit", "disease" }),
        Special_Attack_Skill        : ({ Skill_Qlippotic_Affinity, Skill_Pain_Tolerance }),
        Special_Attack_Power        : Special_Attack_Power_Overwhelming,
        Special_Attack_Chance       : Special_Attack_Chance_Very_Infrequent,
        Special_Attack_Activity     : 40,
        Special_Attack_Size         : Special_Attack_Size_Small,
        Special_Attack_Strike       : Special_Attack_Strike_Accurate,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Ancient Rain" }),
        Special_Attack_Vector       : Vector_Storm,
        Special_Attack_Message      : ({ 0, ({ "scream", 0 }), "in pain as a cloud of {{pearly light green}glowing blood} is torn from", ({ 'r', 0, "body" }), ".  The storm of {{pearly light green}glowing blood} spreads and flies toward", "%e", }),
        Special_Attack_Type         : ({ "primal", "water", "acid", "shadow", "spirit"}),
        Special_Attack_Skill        : ({ Skill_Qlippotic_Affinity, Skill_Pain_Tolerance }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Chance       : Special_Attack_Chance_Very_Infrequent,
        Special_Attack_Activity     : 50,
        Special_Attack_Size         : Special_Attack_Size_Colossal,
        Special_Attack_Strike       : Special_Attack_Strike_Very_Accurate,
    ]));
}

void mutari_weapon_class() {
    set_weapon_class(20, Limb_Type_Hand, ({"claw!cutting", "shadow", "disease" }));
    set_weapon_class(20, Limb_Type_Head, ({"bite!piercing", "shadow", "poison" }), "teeth");
    set_weapon_class(14, Limb_Type_Head, ({"horn!stabbing" }), "horns");
    init_command("stop attacking with uppercut");
    init_command("stop attacking with elbow smash");
    init_command("stop attacking with punch");
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
    init_command("unwield all");
}

void create() {
    ::create();
    call_out("mutari_weapon_class", 2);
}

