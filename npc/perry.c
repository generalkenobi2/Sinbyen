#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Grinning Cat - map_-3_-1_0//
//House - map_-8_-4_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("thond");
    set_sex(Sex_Female);
    set_level(15);
    set_culture_name("Perry" );
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Waitress at the Grinning Cat" }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Perry, a waitress at the Grinning Cat",
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
        "say Take a seat, I'll be with you shortly. to %p",
        "say I hope you're hungry! to %p",
        "say Welcome to the Grinning Cat! to %p",

        
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