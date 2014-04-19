#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Candor's Book Store - map_2_1_0//
//House - map_3_1_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("gnome");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Candor");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Candor, the owner of the Sinbyen's resident toy store",
    }));
    alter_element(Material_Hair, Element_Color, "white");
    alter_element(Material_Eye, Element_Color, "green");
    alter_element(Material_Skin, Element_Color, "tan");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Welcome to my shop. to %p",
        "say Something for a quiet evening? to %p",
        "say We have the largest selection of books in Sinbyen! to %p",

        
    }));
    set_combat_chat(20, ({
        ";say Don't do this! to %e",


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