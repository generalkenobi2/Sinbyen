#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Dataro's Cloaks n' Capes - map_9_2_0//
//House - map_-8_-3_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("garou");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Dataro", "Trelska");
    set_alignment(({ 0, 0 }));
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    add_description(Description_Type_Generic);
    add_description(({
        "His",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Fur,
            Description_Flags   : Description_Flag_Noun,
        ])),
        "is extremely mangy and covered with {{brown}dirt}, his",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Skin,
            Description_Flags   : Description_Flag_Noun,
        ])),
        "is wrinkled with age. His",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
        "however, seem to be full of life.",
    }));
    
    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), "him as Dataro, an old tailor that specializes in the making",
      "of custom cloaks and capes.",
    }));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Welcome to my shop. to %p",
        "say Is there something i can help you find? to %p",
        "say Everything here i make by hand, and it sells fast, so get it while you can. to %p",

        
    }));
    set_combat_chat(20, ({
        ";say Guards! Help!",


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