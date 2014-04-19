#include <Iaocia.h>
#include <autonomon.h>
#include <directions.h>
#include <interval.h>

inherit Iaocia_Monster("Hive_Hunter");

void acid_spray_barrier (object barrier) {
        int vital_humour = query_vital_humour();
        message(([
                Message_Content   : ({
                        0, ({ "rear", 0 }), "back and", ({ "spray", 0 }),
                        "a large quantity of",
                        Description(([          
                                Description_Type: Description_Type_Material_Name,
                                Description_Index: vital_humour,
                        ])),
                        "at",
                        barrier
                }),
                Message_Senses    : Message_Sense_Visual | Message_Sense_Tactile_For_Source,
                Message_Alternate : (([
                                Message_Content : ({ 0, ({ "hear", 0 }), "a spraying sound" }),
                                Message_Flags   : Message_Flag_Resubjectify_To_Viewer,
                                Message_Senses  : Message_Sense_Auditory,
                ])),
        ]));
        
        if (barrier->query_indestructible() || !barrier->query_breakable()) {
                barrier->message(([
                        Message_Content : ({
                                "The",
                                Description(([          
                                        Description_Type: Description_Type_Material_Name,
                                        Description_Index: vital_humour,
                                ])),
                                "dissolves completely",
                        }),
                        Message_Senses    : Message_Sense_Visual | Message_Sense_Tactile_For_Source,
                        Message_Alternate : (([
                                        Message_Content : ({ 0, ({ "hear", 0 }), "hissing and fizzing sounds" }),
                                        Message_Flags   : Message_Flag_Resubjectify_To_Viewer,
                                        Message_Senses  : Message_Sense_Auditory,
                        ])),
                ]));
                return;
        }
        
        barrier->message(([
                Message_Content : ({
                        "The",
                        Description(([          
                                Description_Type: Description_Type_Material_Name,
                                Description_Index: vital_humour,
                        ])),
                        "eats through", 0, "very rapidly",
                }),
                Message_Senses    : Message_Sense_Visual | Message_Sense_Tactile_For_Source,
                Message_Alternate : (([
                                Message_Content : ({ 0, ({ "hear", 0 }), "hissing and fizzing sounds" }),
                                Message_Flags   : Message_Flag_Resubjectify_To_Viewer,
                                Message_Senses  : Message_Sense_Auditory,
                ])),
        ]));

        barrier->message(([
                Message_Content : ({
                        0, ({ "fall", 0 }), "apart from excessive corrosion",
                }),
                Message_Senses    : Message_Sense_Visual | Message_Sense_Tactile_For_Source,
                Message_Alternate : (([
                                Message_Content : ({ 0, ({ "hear", 0 }), "a clatter like something falling apart" }),
                                Message_Flags   : Message_Flag_Resubjectify_To_Viewer,
                                Message_Senses  : Message_Sense_Auditory,
                ])),
        ]));
        
        barrier->set_broken(True);
}

string shortest_name(object barrier) {
        mixed array barrier_names = barrier->query_names();
                
        if (!sizeof(barrier_names))
                return 0;
                
        int strlen_of_shortest_name = strlen(barrier_names[0]);
        int shortest_name_index = 0;
        
        for (int i=1; i<sizeof(barrier_names); i++) {
                if (strlen(barrier_names[i]) < strlen_of_shortest_name) {
                        shortest_name_index = i;
                        strlen_of_shortest_name = strlen(barrier_names[i]);
                }
        }
        
        return barrier_names[shortest_name_index];
}

void break_barrier (object barrier) {
        string barrier_name = shortest_name(barrier);
        
        if (!barrier_name || !strlen(barrier_name))
                return;
        
        init_command("break " + barrier_name);
}

void attack_barrier (object barrier) {
        if (!random(2))
                acid_spray_barrier(barrier);
        else
                break_barrier(barrier);

        init_command(Direction(barrier->query_direction())->query_direction_name());
}

status find_barriers() {
        object array env_inv = all_inventory(environment(this_object()));
        object array barriers = filter(env_inv, (: $1->is_door() && !$1->query_broken() :));
        
        if (sizeof(barriers)) {
                attack_barrier(random_element(barriers));
                return True;
        }
        
        return False;
}

void configure() {
        ::configure();
        set_race("iaoxi");
        add_description(Description_Type_Generic);
        alter_identity(([
                Identity_Known_Nouns : ({({ "drone", 0, Seeable_Order_Extremely_Late })}),
        ]));
        alter_identity(Identity_Flags, Identity_Flag_Suppress_Sex, Identity_Alter_Add);
        alter_identity(Identity_Special_Names, ({ "IAOCIA_IAOXI_HIVE" }), Identity_Alter_Add);
        add_friend("IAOCIA_IAOXI_HIVE");
        add_enemy("SUNDOWN_VENTURES_COMPANY_DWELLER");
        set_walk_verb("crawl");
        set_aggressive(True);
        set_can_kill(True);
        set_ambulate_flag(Ambulate_Flag_Chase, True);
        set_level(30 + random(16));
        set_alignment(({ 0, 0 }));
        set_sex(Sex_Neuter);
        set_chat(8, ({
                ";hiss gradually",
                "eat remains",
                "eat remains",
                "eat remains",
                ";bare my teeth threateningly",
                "clear strike location",
                "look at %p",
        }));
        set_combat_chat(30, ({
                "set strike location to head",
                "clear strike location",
                "kill %h",
                "kill %h",
                ";hiss ferociously",
                ";squeal loudly",
                ";squeal loudly",
                ";thrash about",
        }));
}

void create() {
        ::create();
        attempt_combat_meditation();
}
