#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Training Room - map_-5_-5_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("sleestak");
    set_sex(Sex_Female);
    set_level(40);
    set_culture_name("Ziltar", False, "Sergeant");
    set_alignment(({ 0, 0 }));
    add_description(({
        'v', ({ "are", 0 }), "a grizzled looking", ({ 'c', 0 }), "with",
        
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
        ".",
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }), ({ 'o', 0 }), "as Ziltar, the lead instructor for new recruits of the Crimson Fist",
    }));
    alter_element(Material_Scales, Element_Color, "dark green");
    alter_element(Material_Eye, Element_Color, "dark brown");
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
        "say Strike fast, and strike hard. to %p",
        "say Mercy is for the weak, the weak have no place here. to %p",
        "say If you hesitate, you die. to %p",
        "say Remember, if it bleeds, you can kill it. to %p",
        "say Anger makes you strong. to %p",
        "say An angry soldier makes quick decisions, no time is wasted overthinking the situation. to %p",
        "say Channel your fury. to %p",
    }));
    set_combat_chat(20, ({
        "say This is the last mistake you'll make! to %e",
    }));
    
    set_belongings(({
        ([
        Belonging_File  : Sinbyen_Weapon("crimson_giant_sword"),
        Belonging_Flags : Belonging_Flag_Hold_Two_Handed,            
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("steel_suit_guard"),    
        ]),
        ([
        Belonging_File  : Sinbyen_Armour("crimson_cloak"),    
        ]),
    }));
    set_strike_location("head");
    set_can_kill(True);
    set_trait(Trait_Aphobia, True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    add_skill_points(Skill_Dodge, 800);
    add_skill_points(Skill_Quickness, 400);
    add_skill_points(Skill_Precision_Strike, 600);
    add_skill_points(Skill_Sword, 1000);
    add_skill_points(Skill_Axe, 400);
    add_skill_points(Skill_Pole_Arm, 400);
    add_skill_points(Skill_Spear, 400);
    add_skill_points(Skill_Flail, 400);
    add_skill_points(Skill_Hammer, 400);
    add_skill_points(Skill_Tactics, 100);
    add_skill_points(Skill_Combat_Reflexes, 700);
    add_skill_points(Skill_Training, 150);
    add_skill_points(Skill_Teaching, 150);
    add_skill_points(Skill_Stamina, 500);
    add_skill_points(Skill_Hardiness, 500);
    add_skill_points(Skill_Breath_Control, 300);
    add_skill_points(Skill_Steadiness, 300);
    add_extension(LS_Extension("instructor"), (:
        $1->add_instructor_teaching(([
            Teaching_Index             : ({
                Skill_Sword,
                Skill_Flail,
                Skill_Pole_Arm,
                Skill_Steadiness,
                Skill_Combat_Reflexes,
                Skill_Hammer,
                Skill_Spear,
                Skill_Axe,
                Skill_Breath_Control,
                Skill_Hardiness,
            }),
            Teaching_Cost_Adjust       : 2.5,
            Teaching_Limit             : Null,
            Teaching_Reserve           : 80,
        ]));
        $1->set_instructor_available_pattern("what skills do you train");
        $1->set_instructor_instruct_pattern("train me in");
        return;
    :));
}
