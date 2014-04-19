#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Bank - map_-2_-7_0//
//House - map_-4_-7_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("thond");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Sneva" );
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Sneva, the multifunction banker in Sinbyen",
    }));
    alter_element(Material_Hair, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "brown");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say I'm the banker, the security guard, the plumber, the handyman, and the notary, so you've probably come to the right guy! to %p",
        "say Would you like to make a deposit? to %p",
        "say We'll keep your cash safe for when you need it most. to %p",

        
    }));
    set_combat_chat(20, ({
        ";say Don't do this! to %e",


    }));
    set_belongings(({
        Sinbyen_Misc("vault_key"),
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