#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Mammoth Joe's - map_6_-3_0//
//House - map_7_-3_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("orc");
    set_sex(Sex_Male);
    set_level(15);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_culture_name("Joe", False, "Mammoth");
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Mammoth Joe's" }));
    add_description(({
        "This is a rather large orc with a round stomach,",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Hair,
            Description_Flags   : Description_Flag_Noun,
        ])),
        "that has begun to recede,",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Skin,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", and",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
        "that are full of joy.",
    }));
    
    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }), "as Mammoth Joe, the friendly owner of Mammoth Joes Mammoth Steaks.",
    }));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_attack_scatter(50);
    set_strike_location("head");
    alter_element(Material_Hair, Element_Color, "black");
    alter_element(Material_Eye, Element_Color, "dark blue");
    alter_element(Material_Skin, Element_Color, "black");
    set_chat(3, ({
        "say Welcome to Mammoth Joe's! to %p",
        "say We have mammoth flanks, ribs, chops, shoulder roast, even bacon! We have mammoth bacon! to %p",
        "say Everything here is fantastic, try it all! to %p",
        "say What can i do you for %p?",
        "say Try the rib roast, it's incredible. to %p",        
    }));
    set_combat_chat(20, ({
        ";say Guards! Help!",


    }));
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Weapon("knife"),                    
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("chef_hat"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("leather_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("white_cotton_apron"),
        ]),
    }));
    
    
}