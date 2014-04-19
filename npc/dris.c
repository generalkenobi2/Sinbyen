#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Dris Archery - map_-1_-4_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("thond");
    set_sex(Sex_Male);
    set_level(40);
    set_culture_name("Dris", False, "Sergeant");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);
    add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'o', 0 }), "as Dris, a sergeant of the Crimson Fist, and skilled bowmaster",
    }));
    alter_element(Material_Hair, Element_Color, "dark brown");
    alter_element(Material_Eye, Element_Color, "dark brown");
    alter_element(Material_Skin, Element_Color, "light tan");
    add_permanent_attribute_adjustment(Attr_Str, 20);
    add_permanent_attribute_adjustment(Attr_Int, 120);
    add_permanent_attribute_adjustment(Attr_Con, 20);
    add_permanent_attribute_adjustment(Attr_Dex, 400);
    add_permanent_attribute_adjustment(Attr_Wil, 100);
    add_permanent_attribute_adjustment(Attr_Cha, 110);
    add_permanent_attribute_adjustment(Attr_Per, 200);
    add_permanent_attribute_adjustment(Attr_Siz, 40);
    set_combat_mode_selected(Combat_Mode_Patient);
    set_chat(3, ({
        "say I'm one of the few in the Crimson Fist willing to use a bow. to %p",
        "say If you can kill them before they can engage in combat you can move on that much more quickly. to %p",
        "say Aim for the heart, or strike for the head, either way, it ends it quickly. to %p",
        "say A truly good weapon is priceless. to %p",
        ";clean the counter",
    }));
    set_combat_chat(20, ({
        "say I don't want to hurt you! to %e",
    }));
    
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon("crimson_great_bow"),
        Belonging_Flags    : Belonging_Flag_Hold_Two_Handed,            
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("leather_suit_guard"),    
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("crimson_cloak"),    
        ]),
    }));
    set_strike_location("head");
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    add_skill_points(Skill_Dodge, 200);
    add_skill_points(Skill_Quickness, 180);
    add_skill_points(Skill_Precision_Strike, 200);
    add_skill_points(Skill_Archery, 300);
    add_skill_points(Skill_Tactics, 100);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Training, 150);
    add_skill_points(Skill_Teaching, 150);
    add_skill_points(Skill_Stamina, 300);
    add_skill_points(Skill_Hardiness, 300);
    add_skill_points(Skill_Breath_Control, 300);
    add_skill_points(Skill_Steadiness, 300);
    add_extension(LS_Extension("instructor"), (:
        $1->add_instructor_teaching(([
            Teaching_Index             : ({
                Skill_Archery,
                Skill_Dodge,
                Skill_Quickness,
                Skill_Steadiness,
                Skill_Combat_Reflexes,
            }),
            Teaching_Cost_Adjust       : 2.5,
            Teaching_Limit             : Null,
            Teaching_Reserve           : 20,
        ]));
        $1->set_instructor_available_pattern("what skills do you train");
        $1->set_instructor_available_pattern("what skills do you train");
        $1->set_instructor_instruct_pattern("train me in");
        return;
    :));
    
}
