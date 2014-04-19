#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Starling Sprite's Sweets - map_-2_-1_0//
//House - map_-12_-3_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("faerie");
    set_sex(Sex_Female);
    set_level(15);
    set_culture_name("Starling" );
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Starling Sprite Sweets" }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Starling, the energetic faerie that runs Starling Sprite Sweets",
    }));
    alter_element(Material_Hair, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "gray");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Needing a sweet treat? to %p",
        "say I hope you're hungry! to %p",
        "say We have the sweetest foods around. to %p",

        
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