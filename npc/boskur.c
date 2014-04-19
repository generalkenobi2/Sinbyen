#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Mess Hall - map_-4_-5_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("orc");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Boskur");
    set_title("the cafeteria attendant");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v', ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Boskur, the cafeteria attendant at the crimson barracks",
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
        "say These men are nearly always hungry. to %p",
        "say On the menu today: slop, gruel, or sloppy gruel. to %p",
        "say This food is for the trainees, you'll need to find your own. to %p",
        "say Good %t. to %p",
        ({ 0, ({ "wash", 0 }), ({ 'r', 0, "hands" })}),
        
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
    add_skill_points(Skill_First_Aid, 180);
    add_skill_points(Skill_Steadiness, 100);
    add_skill_points(Skill_Anatomy, 180);
    add_skill_points(Skill_Concentration, 100);
    add_skill_points(Skill_Poison_Lore, 100);
    add_skill_points(Skill_Teaching, 100);
}
