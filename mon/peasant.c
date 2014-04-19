#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race(random_element(([
                "human"     : 10,
                "thond"     : 10,
                "dana"      : 8, 
                "goblin"    : 6,
                "orc"       : 10,
                "garou"     : 4,
                "gnome"     : 6,
                "sekh"      : 7,
                "sleestak"  : 3,
                "aviar"     : 4,
                "domandan"  : 10,
                "llelimin"  : 2,
    ])));
    set_sex(random_element(({
                Sex_Male,
                Sex_Female,
    })));
    set_level(5 + random(20));
    set_title("the peasant");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as one of the common class in Sinbyen",
    }));
    if(query_race() == "garou" || query_race() == "sekh"){
        alter_element(Material_Fur, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blonde",
                    "red",
                    "reddish",
                    "brownish",
        })));
    }
    if(query_race() != "garou" || query_race() != "sekh"){
        alter_element(Material_Hair, Element_Color, random_element(({
                        "brown",
                        "black",
                        "blonde",
                        "red",
                        "reddish",
                        "brownish",
        })));
    }
    alter_element(Material_Eye, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blue",
                    "blueish",
                    "green",
                    "brownish",
    })));
    alter_element(Material_Skin, Element_Color, random_element(({
                    "white",
                    "black",
                    "brown",
                    "tan",
    })));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say How are you? to %p",
        "say Work, work, work... thats all we seem to do around here. to %p",
        "whisper \"Sweep the walk\", he said. \"It will be quick\", he said! to myself",
        "whisper When will they appreciate the hard work I do? to myself",
        "whisper What a beautiful %t. to myself",
        "whisper I can't stand it when he does that. to myself",
        "whisper Can't wait to get home. to myself",
        "whisper Every day it's the same thing. to myself",
        "whisper I need to get a new pair of boots. to myself",
        ({ 0,({ "examine", 0 }), ({ 'r', 0, "clothing" }) }),
        "sigh",
        "roll",
        ({ 0,({ "brush", 0 }), ({ 'l', 0 }), "off." }),
        ({ 0,({ "swat", 0 }), "at a fly." }),
        ({ 0,({ "look", 0 }), "around." }),
        "whisper I can't stand it when he does that. to myself",
        "say Good %t. to %p",
        "say And just who do you think you are? to %p",
    }));
    set_combat_chat(20, ({
        ";say What have i done?! to %e",


    }));
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Armour("leather_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("brown_cotton_pants"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("white_cotton_shirt"),
        ]),        
    }));
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
