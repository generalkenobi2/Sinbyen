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
    set_title("of the Rageborn family");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as one of the nobles of Sinbyen",
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
        "say Our family has stood by Thurgg since we rebuilt this city! to %p",
        "say The Rageborn lineage goes back hundreds of years, back before Sinbyen was just a fishing village. to %p",
        "say Do you have business with my family? to %p",
        "say Those of the Crimson Fist are always welcome here. to %p",
        "say Do you like our home? to %p",
        "say Have you been to the Raging Iyiyik lately? to %p",
        "say Sinbyen is grand, is it not? to %p",
        "say If you've no further business, kindly see yourself out. to %p",
        
    }));
    set_combat_chat(20, ({
        ";say You dare assault your superior!? Guards! Arrest this %c. to %p",
    }));
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Armour("fine_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("fine_pants"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("fine_shirt"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("silk_cloak"),
        ]),
    }));
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
