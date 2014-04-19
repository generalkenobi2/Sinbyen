#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Nature's Wrath - map_9_-8_0//
//House - map_8_-8_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("sleestak");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Sint", "Skogen");
    set_alignment(({ 1000, 1000 }));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), 'a', ({ 'x', 0 }), ({ 'c', 0 }), "with",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Scales,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", and",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
    }));
    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Sint Skogen, owner of Nature's Wrath",
    }));
    alter_element(Material_Scales, Element_Color, "red");
    alter_element(Material_Eye, Element_Color, "brown");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        //"say Nature is a fickle mistress, best always to keep her as an ally. to %p",
        //"say Strike like the wind my friend. to %p",
        //"say To be one with nature is to be one with yourself. to %p",
        "say we are currently doing renovations, we will be open soon my friend. to %p",
        
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