#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//True Ice - map_2_-7_0//
//House - map_1_-7_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Female);
    set_level(15);
    set_culture_name("Meridith");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Meridith, the owner of True Ice",
    }));
    alter_element(Material_Hair, Element_Color, "white");
    alter_element(Material_Eye, Element_Color, "brown");
    alter_element(Material_Skin, Element_Color, "black");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say We have the finest jewelry money can buy, if you can afford it. to %p",
        "say Your loved ones will remember this always. to %p",
        "say Take a look around, we have nothing but the finest here. to %p",

        
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