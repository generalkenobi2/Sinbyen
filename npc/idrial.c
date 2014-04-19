#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>
#include <craft.h>

inherit "/std/autonomon";

//House - map_-10_-3_0//

descriptor setting() {
    return random_element(({
            Material_Ruby,
            Material_Emerald,
            Material_Sapphire,
            Material_Onyx,
            Material_Opal,
            Material_Diamond,
            Material_Topaz,
            Material_Aquamarine,
            Material_Garnet,
            Material_Alexandrite,
            Material_Eog,
    }));
}

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("amberite");
    set_sex(Sex_Female);
    set_level(100);
    add_friend("SINBYEN_GUARD");
    add_friend("SINBYEN_CITIZEN");
    add_enemy("SINBYEN_UNDEAD");
    add_enemy("SINBYEN_DEMON");
    set_culture_name("Idrial", False, "Captain");
    alter_identity(Identity_Name_Title, ([
                Seeable_Word  : "of the crimson guard",
                Seeable_Flags : Seeable_Flag_Verbose_Only,
        ]));
    set_alignment(({ 1000, 1000 }));
    alter_identity(Identity_Special_Names, ({ "SINBYEN_GUARD" }), Identity_Alter_Add);
    alter_identity(Identity_Special_Names, ({ "SINBYEN_LEADER" }), Identity_Alter_Add);
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Idrial Minara, captain of the Crimson Guard, and long time friend of Thurgg Bloodfist",
    }));
    alter_element(Material_Hair, Element_Color, "blonde");
    alter_element(Material_Eye, Element_Color, "blue");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    add_permanent_attribute_adjustment(Attribute_Strength, 50);
    add_permanent_attribute_adjustment(Attribute_Constitution, 200);
    add_permanent_attribute_adjustment(Attribute_Intelligence, 200);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 300);
    add_permanent_attribute_adjustment(Attribute_Willpower, 300);
    add_permanent_attribute_adjustment(Attribute_Charisma, 300);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_permanent_attribute_adjustment(Attribute_Size, 10);
    add_affiliation("the Knights of the Round Table");
    add_skill_points(Skill_Chromatostasis, 600);
    set_omniscience(True);
    set_area_control(True);
    set_area_guarding(True);
    add_skill_points(Skill_Stamina, 6000);
    add_skill_points(Skill_Quickness, 400);
    add_skill_points(Skill_Dodge, 400);
    add_skill_points(Skill_Hardiness, 1000);
    add_skill_points(Skill_Martial_Arts, 200);
    add_skill_points(Skill_Dancing, 60);
    add_skill_points(Skill_Precision_Strike, 600);
    add_skill_points(Skill_Sephirotic_Affinity, 400);
    add_skill_points(Skill_Qlippotic_Resistance, 400);
    add_skill_points(Skill_Steadiness, 400);
    add_skill_points(Skill_Resilience, 600);
    add_skill_points(Skill_Philosophy, 500);
    add_skill_points(Skill_Leadership, 600);
    add_skill_points(Skill_Tactics, 300);
    add_skill_points(Skill_Strategy, 400);
    add_skill_points(Skill_Meditation, 300);
    add_skill_points(Skill_Combat_Reflexes, 400);
    add_skill_points(Skill_Unarmed_Combat, 100);
    add_skill_points(Skill_Blindfighting, 300);
    add_skill_points(Skill_Awareness, 400);
    add_skill_points(Skill_Sword, 1000);
    add_skill_points(Skill_Find_Weakness, 800);
    add_skill_points(Skill_Killer_Instinct, 400);
    add_skill_points(Skill_Lack_of_Weakness, 400);
    add_skill_points(Skill_Massive_Blow, 400);
    add_skill_points(Skill_Massive_Exertion, 400);
    add_skill_points(Skill_Recuperation, 800);
    add_skill_points(Skill_Breath_Control, 400);
    add_skill_points(Skill_Impact_Absorption, 100);
    add_skill_points(Skill_Fire_Resistance, 100);
    add_skill_points(Skill_Cold_Resistance, 100);
    add_skill_points(Skill_Regeneration, 200);
    set_skill_points(Skill_Shield, 1000);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say My men and I keep this city safe. to %p",
        "say May the light of Yehovah never leave you wanting. to %p",
        "say Having a good %t? to %p",
        "say It's good to see you %p. to %p",
        "say Captain Idrial, at your service. to %p",
        "nod at %p",
        "say Thurgg may not agree with everything I say or believe but we respect one another. to %p",
        "say If you spot trouble, please bring it to my attention. to %p",
        ";whisper a prayer to myself",

        
    }));
    set_attack_message(({
        0, ({ "whisper", 0 }), "a prayer to", ({ 'l', 0 }), "and", ({ "stride", 0 }), "toward", "%e",
    }));
    set_combat_chat(20, ({
        "say Crimson! Take this ruffian!",
        "say Pay for your crimes!",
        "say You will not escape!",
        "say Crimson, succor me!",
        "say Crimson, succor me!",
        "shout Crimson! Don't let this %e get away!",
        "shout Crimson! Kill %e!  They have broken the law and must pay the price!",
        "say Justice shall prevail!",
        "say I shall pray for your soul to find peace",
        "say Crimson! Rally together!",
        "say Crimson! Rally together!",
        "say Crimson! Rally together!",
        "say Crimson! To me!",
        "say Crimson! To me!",
        "say Crimson! To me!",
        "say Crimson! To me!",
        "say Crimson! To me!",


    }));
    set_belongings(({
        ([
        Belonging_File          : Sinbyen_Armour("captain_suit"),
        Belonging_Alternate     : Sinbyen_Armour("steel_suit"),
        ]),
        ([
        Belonging_File          : Sinbyen_Weapon("ren"),
        Belonging_Alternate     : ([
        Belonging_File          : LS_Weapon("longsword"),
        Belonging_Initialize    : (:
            $1->transmute_element(Material_Iron, Material_Mithril);
            $1->set_craft(Craft_Exquisite);
            $1->set_weapon_skills(([
                Skill_Precision_Strike      : 1.0,
                Skill_Sephirotic_Affinity   : 2.0,
            ]));
            $1->add_proportion(([
                    Element_Type                : Material_Ruby,
                    Element_Proportion          : 0.1,
                    Element_Part                : Part_Inset,
            ]));
            $1->set_properties(({
                Prop_Holy,
            }));
            $1->set_damage_types(({ "cutting", "cutting", ({"cutting", "piercing"}), ({"cutting","holy"})}));
        :)
        ]),
        ]),
        ([
        Belonging_File          : Sinbyen_Weapon("captain_shield"),
        ]),
        ([
        Belonging_File          : Sinbyen_Armour("crimson_cloak"),
        ]),    
    }));
    
    
}
