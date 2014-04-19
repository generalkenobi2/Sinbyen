#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Sinbyen Altar - map_-8_-7_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Male);
    set_level(15);
    alter_identity(Identity_Special_Names, ({ "SINBYEN_PRIEST" }), Identity_Alter_Add);
    set_culture_name("Cartwin", False, "Patris");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);
    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Patris Cartwin, the priest of Sinbyen's church",
    }));
    alter_element(Material_Hair, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "brown");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_affiliation("the Pantarchic Church");
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Can I help you my child? to %p",
        "say May the light of Yehovah light your path. to %p",
        "say Bless you child. to %p",

        
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