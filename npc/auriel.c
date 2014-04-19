#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Auriel's Archery - map_12_0_0//
//House - map_13_0_0//


void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("dana");
    set_sex(Sex_Female);
    set_level(40);
    set_culture_name(({ "Auriel", "Tianamen" }));
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of Auriel's Archery Supply" }));
    add_description(({
        "This is a tall, beautiful", ({ 'c', 0 }), "with",
        
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Hair,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ",",
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
        ".",
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }), "her as the owner of Auriel's Archery Supply, Auriel Tianamen.  True to her heritage, she is a master of ranged combat.",
    }));
    alter_element(Material_Hair, Element_Color, "dark brown");
    alter_element(Material_Eye, Element_Color, "shifting green");
    alter_element(Material_Skin, Element_Color, "light tan");
    add_permanent_attribute_adjustment(Attr_Str, 20);
    add_permanent_attribute_adjustment(Attr_Int, 120);
    add_permanent_attribute_adjustment(Attr_Con, 20);
    add_permanent_attribute_adjustment(Attr_Dex, 400);
    add_permanent_attribute_adjustment(Attr_Wil, 100);
    add_permanent_attribute_adjustment(Attr_Cha, 110);
    add_permanent_attribute_adjustment(Attr_Per, 200);
    set_combat_mode_selected(Combat_Mode_Patient);
    set_chat(3, ({
        "say Every life is precious, none are without value.",
        "say %p, you should never kill for sport, but only out of necessity. to %p",
        "say Welcome to Auriel's Archery Supply. to %p",
        "say Can i help you find something? to %p",
        "say We have a fantastic selection of archery equipment to choose from. to %p",
        "say Our archery range is currently under construction, but should be finished soon!. to %p",
        "say We have longbows, crossbows, recurve bows, and shortbows! to %p",
        "say We have the best bows east of Valathyr. to %p",
        "say Our arrows are made from the straightest northern pine wood around! to %p",
        ";clean a storage rack",
        ";string a bow skillfully, tests the draw weight, then unstrings the bow and places the bow on a rack",
        ";examine an arrow in a storage bin",
        ";stretch",
        ";check stock compared to a small ledger",
        ";hum softly to myself",
        "put arrow in quiver",
    }));
    set_combat_chat(20, ({
        "say please don't do this! to %e",
        "shout Guards, please help me!",
        "say I don't want to hurt you! to %e",
        "say Please, i beg of you! Leave me in peace! to %e",
    }));
    
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Weapon("aurielbow"),
        Belonging_Flags        : Belonging_Flag_Hold_Two_Handed,
                    
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("leather_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("archery_gloves"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("mithril_chain"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("silk_cloak"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("mithril_circlet"),
        ]),
        ([
        Belonging_File      : Sinbyen_Weapon("silverthorn_arrow"),
        Belonging_Count       : 10,
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("everfull_quiver"),
        ]),        
    }));
    set_strike_location("head");
    set_can_kill(True);
    add_skill_points(Skill_Dodge, 600);
    add_skill_points(Skill_Quickness, 600);
    add_skill_points(Skill_Precision_Strike, 600);
    add_skill_points(Skill_Archery, 600);
    add_skill_points(Skill_Tactics, 100);
    add_skill_points(Skill_Combat_Reflexes, 600);
    
}
