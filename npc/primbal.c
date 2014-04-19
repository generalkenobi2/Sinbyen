#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>
#include <Banir_Lok.h>

inherit Sinbyen_Monster("Citizen");

//Primbal's Armour - map_6_-1_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("thond");
    set_sex(Sex_Male);
    set_level(40);
    set_culture_name("Primbal" );
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);
    add_description(({
        "massive for a",({'c',0}),",",({'r',0,"muscled figure"}),({"are",0}),"drenched in sweat and soot",
    })),
    add_known_description(({
      'v',({ "recognize", 'v' }), ({ 'o', 0 }),  "as Primbal, the owner of Primbal's Armoury, sole supplier to the Crimson Fist",
    }));
    add_permanent_attribute_adjustment(Attribute_Size, 40);
    alter_element(Material_Hair, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "brown");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    add_skill_points(Skill_Metallurgy, 400);
    add_skill_points(Skill_Smithing, 400);
    add_skill_points(Skill_Armour_Lore, 250);
    add_skill_points(Skill_Weapon_Lore, 250);
    add_skill_points(Skill_Stamina, 300);
    add_skill_points(Skill_Hammer, 300);
    add_skill_points(Skill_Massive_Blow, 300);
    add_skill_points(Skill_Heat_Tolerance, 200);
    add_skill_points(Skill_Breath_Control, 180);
    add_skill_points(Skill_Hardiness, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say What do you want? to %p",
        "say I don't have time for idle chatter! to %p",
        "say Buy something or get out. to %p",
        "say I can teach you but it's not cheap. to %p",
        "say Can you work the bellows? to %p",
        ({0,({"wipe",0}),({'r',0,"brow"})}),
        ({0,({"hammer",0}),"a {{holy fire}red hot piece of metal} on the {{dark gray}anvil}."}),
        ({0,({"compress",0}),"the {{brown}bellows} three times and the forge {{bright fire}burns brightly}."}),
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
        ([
        Belonging_File      : Banir_Lok_Weapon("hammer"),
        Belonging_Initialize: (:
            $1->transmute_element(Material_Mithril, Material_Adamantite);
        :),
        ]),
    }));
    add_extension(LS_Extension("instructor"), (:
        $1->add_instructor_teaching(([
            Teaching_Index             : ({
                Skill_Metallurgy,
                Skill_Hammer,
                Skill_Smithing,
                Skill_Armour_Lore,
                Skill_Weapon_Lore,
                Skill_Stamina,
                Skill_Heat_Tolerance,
                Skill_Massive_Blow,
                Skill_Breath_Control,
                Skill_Hardiness,
            }),
            Teaching_Cost_Adjust       : 2.5,
            Teaching_Limit             : Null,
            Teaching_Reserve           : 100,
        ]));
        $1->set_instructor_available_pattern("what skills do you train");
        $1->set_instructor_instruct_pattern("train me in");
        return;
    :));
    
}