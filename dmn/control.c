#include <Sinbyen.h>
#include <daemon.h>
#include <Yathryn.h>
#include <senses.h>

inherit "/std/daemon";
inherit "/mod/daemon/control";
inherit "/mod/daemon/broker";
inherit "/mod/daemon/persistence";

status can_sinbyen_be_hostile(mapping args) {
    return args["agent"]->id("SINBYEN_GUARD", Knowledge_Known);
}

void do_sinbyen_be_hostile(mapping args) {
    if(!random(3))
        args["agent"]->message(({ 0, ({ "glare", 0 }), "at", args["who"] }));
    if(!random(3))
        args["agent"]->init_command("say Crimson! We found them!");
}

void fail_sinbyen_be_hostile(mapping args) {
    if(!random(2))
        args["agent"]->message(({ 0, ({ "look", 0 }), "frightened" }));
    args["agent"]->init_command("say Run!");
}

status can_sinbyen_assignment_check(mapping args) {
    int a = args["agent"]->query_level();
    int b = args["who"]->query_level();
    return True;
}

#define Room_Chats_Smith   ({\
	Message(([\
        Message_Content     : ({\
            ([\
                Message_Content : ({\
                    "Popping loudly,",\
                }),\
                Message_Senses  : Message_Sense_Auditory,\
            ]),\
            "the {{dark gray}forge} shoots a {{holy fire}small shower of sparks} upwards",\
        }),\
    ])),\
	"The heat of the forge causes the air to {{shadowfire}ripple} slightly.",\
	Message(([\
        Message_Content     : ({\
            "The {{dark gray}forge} pops and crackles.",\
        }),\
        Message_Senses      : Message_Sense_Auditory,\
    ])),\
	Message(([\
        Message_Content     : ({\
            "The {{dark gray}forge} pops.",\
        }),\
        Message_Senses      : Message_Sense_Auditory,\
    ])),\
})


void configure() {
    ::configure();
    set_creator("kenobi");
    set_area("Sinbyen");
    set_base_exploration_experience(300);    
    set_definition_registration(([
        Sinbyen_Definition("map_*") : 0,
    ]));    
    set_definition_unregistration(([
        Sinbyen_Definition("map_*") : 0,
    ]));
    add_extension(LS_Extension("guardian"), (:
        $1->set_realms(({ "SINBYEN_CITY" }));
        $1->set_omniscient(True);
        $1->set_coordinator(Sinbyen_NPC("idrial"));
        $1->add_hook("can_guardian_be_hostile", #'can_sinbyen_be_hostile);
        $1->add_hook("do_guardian_be_hostile", #'do_sinbyen_be_hostile);
        $1->add_hook("fail_guardian_be_hostile", #'fail_sinbyen_be_hostile);
        $1->add_hook("can_guardian_assign_guard", #'can_sinbyen_assignment_check);
        $1->set_max_assignment_base(30);
        $1->set_max_assignment_scale(10);
        $1->set_death_pacify(True);
        return;
    :));
    add_extension(LS_Extension("map"), (:
        $1->set_base_room(Sinbyen_Room("Map_Base"));
        $1->set_room_prefix(Sinbyen_Room("map_"));
        $1->set_coordinate_format("%d_%d_%d");
        $1->set_map_conf(Sinbyen_Data("map.conf"));
        $1->set_map_directionality(Map_Directionality_Extended);
    :));
    //Wanders Tavern//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("SINBYEN_TAVERN");
        $1->set_wander_time(60);
        $1->set_preferred_realms(({ "SINBYEN_TAVERN" }));
        $1->add_population(Sinbyen_Monster("patron"), 12);
        return;
    :));
    //Wanders Forests//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("SINBYEN_FOREST");
        $1->set_wander_time(60);
        $1->set_preferred_realms(({ "SINBYEN_FOREST" }));
        $1->add_population(LS_Monster("songbird"), 12);
        $1->add_population(LS_Monster("falcon"), 2);
        $1->add_population(LS_Monster("deer"), 2);
        $1->add_population(LS_Monster("rabbit"), 12);
        $1->add_population(LS_Monster("badger"), 2);
        $1->add_population(LS_Monster("hedgehog"), 2);
        $1->add_population(LS_Monster("tree_frog"), 3);
        return;
    :));
    //Wanders Oceans//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("SINBYEN_OCEAN");
        $1->set_wander_time(60);
        $1->set_preferred_realms(({ "SINBYEN_OCEAN" }));
        $1->add_population(LS_Monster("fish"), 30);
        $1->add_population(LS_Monster("octopus"), 6);
        $1->add_population(LS_Monster("eel"), 2);
        $1->add_population(LS_Monster("manta_ray"), 2);
        $1->add_population(LS_Monster("sea_turtle"), 2);
        $1->add_population(LS_Monster("shark"), 2);
        return;
    :));
    //Wanders City Manor//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("SINBYEN_MANOR");
        $1->set_wander_time(60);
        $1->set_preferred_realms(({ "SINBYEN_MANOR" }));
        $1->add_population(Sinbyen_Monster("servant"), 3);
        $1->add_population(Sinbyen_Monster("rageborn"), 4);
        return;
    :));
    //Wanders City Streets//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("SINBYEN_STREET");
        $1->set_wander_time(60);
        $1->set_preferred_realms(({ "SINBYEN_STREET" }));
        $1->add_population(Sinbyen_Monster("noble"), 12);
        $1->add_population(Sinbyen_Monster("peasant"), 60);
        $1->add_population(Sinbyen_Monster("servant"), 8);
        $1->add_population(Sinbyen_Monster("guard"), 50);
        $1->add_population(Sinbyen_Monster("lieutenant"), 4);
        $1->add_person(Sinbyen_NPC("idrial"), Sinbyen_Room("map_9_0_0"));
        return;
    :));
    //Do not Wander//
    add_extension(LS_Extension("populace"), (:
        $1->add_person(Sinbyen_NPC("agin_dragonclaw"), Sinbyen_Room("map_6_0_0"));
        $1->add_person(Sinbyen_NPC("amstaar"), Sinbyen_Room("map_6_-7_0"));
        $1->add_person(Sinbyen_NPC("auriel"), Sinbyen_Room("map_12_0_0"));
        $1->add_person(Sinbyen_NPC("boskur"), Sinbyen_Room("map_-4_-5_0"));
        $1->add_person(Sinbyen_NPC("candor"), Sinbyen_Room("map_2_1_0"));
        $1->add_person(Sinbyen_NPC("cartwin"), Sinbyen_Room("map_-8_-7_0"));
        $1->add_person(Sinbyen_NPC("dalemaar"), Sinbyen_Room("map_6_-5_0"));
        $1->add_person(Sinbyen_NPC("darlena"), Sinbyen_Room("map_1_1_0"));
        $1->add_person(Sinbyen_NPC("darron"), Sinbyen_Room("map_-10_-11_0"));
        $1->add_person(Sinbyen_NPC("dataro"), Sinbyen_Room("map_9_2_0"));
        $1->add_person(Sinbyen_NPC("dibella"), Sinbyen_Room("map_7_2_0"));
        $1->add_person(Sinbyen_NPC("drak"), Sinbyen_Room("map_7_-8_0"));
        $1->add_person(Sinbyen_NPC("dris"), Sinbyen_Room("map_-1_-4_0"));
        $1->add_person(Sinbyen_NPC("driskul"), Sinbyen_Room("map_2_-1_0"));
        $1->add_person(Sinbyen_NPC("durod"), Sinbyen_Room("map_3_12_0"));
        $1->add_person(Sinbyen_NPC("farid"), Sinbyen_Room("map_-3_12_0"));
        $1->add_person(Sinbyen_NPC("fierro_vandego"), Sinbyen_Room("map_6_1_0"));
        $1->add_person(Sinbyen_NPC("fontaine"), Sinbyen_Room("map_-3_1_0"));
        $1->add_person(Sinbyen_NPC("gramp"), Sinbyen_Room("map_6_0_0"));
        $1->add_person(Sinbyen_NPC("iskaarl"), Sinbyen_Room("map_6_-9_0"));
        $1->add_person(Sinbyen_NPC("jangrid"), Sinbyen_Room("map_3_-7_0"));
        $1->add_person(Sinbyen_NPC("jermal"), Sinbyen_Room("map_-9_-1_0"));
        $1->add_person(Sinbyen_NPC("joe"), Sinbyen_Room("map_6_-3_0"));
        $1->add_person(Sinbyen_NPC("kercha"), Sinbyen_Room("map_4_-8_0"));
        $1->add_person(Sinbyen_NPC("kim"), Sinbyen_Room("map_3_0_0"));
        $1->add_person(Sinbyen_NPC("lola"), Sinbyen_Room("map_7_-9_0"));
        $1->add_person(Sinbyen_NPC("marco"), Sinbyen_Room("map_1_-8_0"));
        $1->add_person(Sinbyen_NPC("meridith"), Sinbyen_Room("map_2_-7_0"));
        $1->add_person(Sinbyen_NPC("modros"), Sinbyen_Room("map_-3_-5_0"));
        $1->add_person(Sinbyen_NPC("perry"), Sinbyen_Room("map_-3_-1_0"));
        $1->add_person(Sinbyen_NPC("primbal"), Sinbyen_Room("map_6_-1_0"));
        $1->add_person(Sinbyen_NPC("ralphgar"), Sinbyen_Room("map_3_-10_0"));
        $1->add_person(Sinbyen_NPC("shanks"), Sinbyen_Room("map_-3_-3_0"));
        $1->add_person(Sinbyen_NPC("shanks"), Sinbyen_Room("map_3_-10_0"));
        $1->add_person(Sinbyen_NPC("sint"), Sinbyen_Room("map_9_-8_0"));
        $1->add_person(Sinbyen_NPC("sintel"), Sinbyen_Room("map_8_2_0"));
        $1->add_person(Sinbyen_NPC("sneva"), Sinbyen_Room("map_-2_-7_0"));
        $1->add_person(Sinbyen_NPC("starling"), Sinbyen_Room("map_-2_-1_0"));
        $1->add_person(Sinbyen_NPC("thurgg_bloodfist"), Sinbyen_Room("map_2_-4_0"));
        $1->add_person(Sinbyen_NPC("toker"), Sinbyen_Room("map_-11_-10_0"));
        $1->add_person(Sinbyen_NPC("vanadius"), Sinbyen_Room("map_6_-4_0"));
        $1->add_person(Sinbyen_NPC("wickett"), Sinbyen_Room("map_10_-3_0"));
        $1->add_person(Sinbyen_NPC("ziltar"), Sinbyen_Room("map_-5_-5_0"));
        return;
    :));
    //Wandering trainees inside the crimson barracks//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("CRIMSON_BARRACKS");
        $1->set_wander_time(40);
        $1->set_preferred_realms(({"CRIMSON_BARRACKS"}));
        $1->add_population(Sinbyen_Monster("trainee"), 12);
        return;
    :));
    //Multilevel catacomb monsters//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("Sinbyen_Catacombs");
        $1->set_wander_time(180);
        $1->set_preferred_realms(({ "Sinbyen_Catacombs" }));
        $1->add_population(Sinbyen_Monster("reanimated"), 100);
        $1->add_population(Sinbyen_Monster("rat"), 40);
        $1->add_population(Sinbyen_Monster("possessed"), 50);
        $1->add_population(Sinbyen_Monster("mutari"), 5);
        $1->add_population(Sinbyen_Monster("giant_rat"), 40);
        return;
    :));
    //Mid - deep level catacomb monsters//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("Sinbyen_Catacombs_Deep");
        $1->set_wander_time(180);
        $1->set_preferred_realms(({ "Sinbyen_Catacombs" }));
        $1->add_population(Sinbyen_Monster("taken"), 40);
        return;
    :));
    //Deep catacomb monsters//
    add_extension(LS_Extension("populace"), (:
        $1->add_map_realm_target("Sinbyen_Catacombs_Ancient");
        $1->set_wander_time(180);
        $1->set_preferred_realms(({ "Sinbyen_Catacombs" }));
        $1->add_population(Sinbyen_Monster("awakened"), 20);
        return;
    :));
    add_extension(LS_Extension("chatter"), (:
		$1->add_chatter("SINBYEN_SMITH", Room_Chats_Smith,
			45, In_Realm("SINBYEN_SMITH"), False);
		return;
	:));
    add_published_location(([
        Sinbyen_Room("map_-9_-7_0")     : 5,
        Sinbyen_Room("map_-8_-7_0")     : 10,
        Sinbyen_Room("map_-7_-7_0")     : 5,
        Sinbyen_Room("map_-9_-8_0")     : 5,
        Sinbyen_Room("map_-8_-8_0")     : 1,
        Sinbyen_Room("map_-7_-8_0")     : 5,
    ]), Rarity_Unusual, Location_Danger_Sanctuary);
}
