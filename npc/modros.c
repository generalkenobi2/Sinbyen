#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Medical Office - map_-3_-5_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Male);
    set_level(15);
    set_culture_name("Modros");
    set_title("the medic");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Modros, the medic that tends to the frequently wounded Crimson Guard",
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
        "say Are you in need of medical attention? to %p",
        "say I was recently assigned the medical post, I guess someone's got to do it. to %p",
        "say Don't get too beat up, I'm a medic, not a bloody miracle worker. to %p",
        "say These boys don't know the meaning of careful, every day someone's breaking something. to %p",
        "say Good %t. to %p",
        ({ 0, ({ "raise", 0 }), ({ 'r', 0, "eyebrow" })}),
        "say I often question how the men are trained here, always so many injuries",
        
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
    add_extension(LS_Extension("instructor"), (:
        $1->add_instructor_teaching(([
            Teaching_Index             : ({
                Skill_First_Aid,
                Skill_Poison_Lore,
                Skill_Anatomy,
            }),
            Teaching_Cost_Adjust       : 2.5,
            Teaching_Limit             : Null,
            Teaching_Reserve           : 30,
        ]));
        $1->set_instructor_available_pattern("what skills do you teach");
        $1->set_instructor_instruct_pattern("teach me");
        return;
    :));
    
}
