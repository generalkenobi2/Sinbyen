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
    set_race(random_element(({
                "human",
                "thond",
    })));
    set_sex(random_element(({
                Sex_Male,
                Sex_Female,
    })));
    set_level(5 + random(20));
    set_title("the servant");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as one of the serving class in Sinbyen",
    }));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blonde",
                    "red",
                    "reddish",
                    "brownish",
    })));
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
        "say Bid thee well. to %p",
        "say 'Tis an honor to serve. to %p",
        "say Don't mind me. to %p",
        "say Good %t. to %p",
        
    }));
    set_combat_chat(20, ({
        ";say My lord, help me!",


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
    add_skill_points(Skill_First_Aid, 180);
    add_skill_points(Skill_Steadiness, 100);
    add_skill_points(Skill_Anatomy, 180);
    add_skill_points(Skill_Concentration, 100);
    add_skill_points(Skill_Poison_Lore, 100);
    add_skill_points(Skill_Teaching, 100);
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
