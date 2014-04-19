#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Raging Gnoll - map_1_1_0//
//House - map_-6_-10_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("sekh");
    set_sex(Sex_Female);
    set_level(15);
    set_culture_name("Darlena");
    alter_identity(Identity_Name_Title, ([
                Seeable_Word  : "the bartender",
                Seeable_Flags : Seeable_Flag_Verbose_Only,
        ]));
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);
    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Darlena, the bartender of the Raging Gnoll",
    }));
    alter_element(Material_Fur, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "blue");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say What can i get you? to %p",
        "say We have the strongest drinks in all of Sinbyen. to %p",
        "say Do you know what you'll be having today? to %p",

        
    }));
    set_combat_chat(20, ({
        ";say I'll have no rough play in here! to %e",


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