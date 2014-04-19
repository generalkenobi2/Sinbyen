#include <Sinbyen.h>
#include <autonomon.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

void guard_create() {
    set_weapon_class(10, Limb_Type_Hand, ({"crushing", "force" }));
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
    init_command("wear all");
}

void spar() {
    object who = this_object();
    object array nearby = who->query_nearby_character_objects();
    int i = 0;
    if(nearby[i] == 0) {
        return;
    }
    if(nearby[i]->query_names() == "SINBYEN_TRAINEE"){
        if(random(2) == 1){
            object target = nearby[i];
            who->init_command("emit approach" + target);
            int control = random(3);
            if(control == 1){
                target->init_command("nod at" + who);
                who->init_command("emit begin sparring with" + target);
            }
            else{
                target->init_command("shake");
            }
        }
    }
    return;
}

void spar_callout() {
    if(random(3) == 1) {
        call_out("spar", 2);
    }
    
}

void configure() {
    ::configure();
    set_race(random_element(({ "thond", "human", "orc" })));
    alter_identity(Identity_Special_Names, ({ "SINBYEN_GUARD" }), Identity_Alter_Add);
    alter_identity(Identity_Special_Names, ({ "SINBYEN_TRAINEE" }), Identity_Alter_Add);
    set_culture("Losthavener");
    set_title("the crimson trainee");
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
                                                            }))
    );
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
                                                            }))
    );
    set_level(24 + random(10));
    set_alignment(({ 0, 0 }));
    add_friend("SINBYEN_GUARD");
    add_friend("SINBYEN_CITIZEN");
    add_friend("LOSTHAVEN_DWELLER");
    add_enemy("SINBYEN_DEMON");
    add_enemy("SINBYEN_UNDEAD");
    set_strike_location("head");
    set_can_kill(True);
    set_realms(({ "CRIMSON_BARRACKS" }));
    set_ambulate_flag(Ambulate_Flag_Extended_Fleeing, True);
    set_combat_mode_selected(Combat_Mode_Patient);
    set_ambulate_flag(Ambulate_Flag_Chase, True);
    add_permanent_attribute_adjustment(Attribute_Strength, 40);
    add_permanent_attribute_adjustment(Attribute_Constitution, 40);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 10);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 100);
    add_permanent_attribute_adjustment(Attribute_Perception, 100);
    add_permanent_attribute_adjustment(Attribute_Size, 10);
    add_skill_points(Skill_Massive_Blow, 200);
    add_skill_points(Skill_Linguistics, 80);
    add_skill_points(Skill_Anglic, 40);
    add_skill_points(Skill_Precision_Strike, 400);
    add_skill_points(Skill_Sword, 300);
    add_skill_points(Skill_Tactics, 150);
    add_skill_points(Skill_Axe, 300);
    add_skill_points(Skill_Quickness, 100);
    add_skill_points(Skill_Massive_Exertion, 300);
    add_skill_points(Skill_Hardiness, 100);
    add_skill_points(Skill_Dodge, 200);
    add_skill_points(Skill_Strategy, 100);
    add_skill_points(Skill_Subordination, 100);
    add_skill_points(Skill_Spelunking, 200);
    add_skill_points(Skill_Killer_Instinct, 200);
    add_skill_points(Skill_Martial_Arts, 150);
    add_skill_points(Skill_Spear, 300);
    add_skill_points(Skill_Steadiness, 200);
    add_skill_points(Skill_Resilience, 300);
    add_skill_points(Skill_Combat_Reflexes, 200);
    add_skill_points(Skill_Blindfighting, 80);
    set_combat_chat(20, ({
        
        "shout You'll never make it out of here alive! to %e",        
        "shout My masters have taught me well! to %e",

    }));
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon(random_element(({
                                            "crimson_great_axe",
                                            "crimson_great_sword",
        }))),
        Belonging_Flags : Belonging_Flag_Hold_Two_Handed,            
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("steel_suit_guard"),    
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("crimson_cloak2"),    
        ]),
    }));
    add_hook(At_Heart_Beat, #'spar_callout);

}



void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
                call_out("guard_create", 2);
}
