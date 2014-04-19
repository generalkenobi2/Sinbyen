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
                "aviar"     : 4,
                "domandan"  : 10,
                "llelimin"  : 2,
    ])));
    set_sex(random_element(([
                Sex_Male    : 9,
                Sex_Female  : 1,
    ])));
    set_level(5 + random(20));
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
    set_chat(8, ({
        "say Lola, you've got it all! to lola",
        "whistle at lola",
        "stare at lola",
        "gasp",
        "smile",
        "grin",
        "say Baby you're amazing! to lola",
        "say I'm gonna marry you one day! to lola",
        "say I don't ever want to go home.",
        "say Make it rain!",
        "whistle at lola",
        ";lean on the edge of the stage",
        ";gawk",
        ";shake my head in disbelief",
        "laugh",
        "sigh",
        "sigh",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
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
        ([
        Belonging_File      : Sinbyen_Comestible("beer"),
        Belonging_Count     : 5,
        ]),
    }));
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
