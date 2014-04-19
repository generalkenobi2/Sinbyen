#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Sinbyen Strip Club Entrance - 7/-8/0//
//Drak's House - 2/-12/0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("lothar");
    set_sex(Sex_Male);
    set_level(50);
    set_culture_name("Drak");
    set_title("the bouncer");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Drak, the bouncer at the gentleman's club.",
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
    add_permanent_attribute_adjustment(Attribute_Strength, 600);
    add_permanent_attribute_adjustment(Attribute_Constitution, 500);
    add_permanent_attribute_adjustment(Attribute_Dexterity, 200);
    add_permanent_attribute_adjustment(Attribute_Perception, 200);
    add_permanent_attribute_adjustment(Attribute_Size, 100);
    set_chat(3, ({
        "say Rule #1. Don't touch the dancers. to %p",
        "say Rule #2. Don't touch the dancers. to %p",
        "say Rule #3. If you break rule 1 or 2 you answer to me. to %p",
        "say Rule #4. Don't start fights. to %p",
        "say Rule #5. Don't drink too much. to %p",
        "say Rule #6. Don't dance, that's the dancer's job. to %p",
        "say Rule #7. Don't sing along, if you were any good we'd hire you. to %p",
        "say Rule #8. I'm never wrong, so don't argue. to %p",
        "say Rule #9. Walk home, Thurgg kills horses. to %p",
        "say Rule #10. Do NOT make it hail. to %p",
        "say Rule #11. Tips are welcome. to %p",
        "say Most importantly, rule #12. Don't talk to me. to %p",
        ({ 0, ({ "raise", 0 }), ({ 'r', 0, "eyebrow" })}),        
    }));
    set_combat_chat(20, ({
        ";say It's go time! to %e",
        "dis",
        "dis",
        "dis",


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
    add_affiliation("the Brute Squad");
    add_skill_points(Skill_First_Aid, 180);
    add_skill_points(Skill_Steadiness, 200);
    add_skill_points(Skill_Anatomy, 180);
    add_skill_points(Skill_Concentration, 100);
    add_skill_points(Skill_Poison_Lore, 100);
    add_skill_points(Skill_Brawling, 600);
    add_skill_points(Skill_Unarmed_Combat, 600);
    add_skill_points(Skill_Combat_Reflexes, 600);
    add_skill_points(Skill_Massive_Blow, 300);
    add_skill_points(Skill_Quickness, 400);
    add_skill_points(Skill_Hardiness, 2000);
    add_skill_points(Skill_Dodge, 300);
    add_skill_points(Skill_Cutting_Resistance, 400);
    add_skill_points(Skill_Piercing_Resistance, 400);
    add_skill_points(Skill_Fire_Resistance, 400);
    add_skill_points(Skill_Earth_Resistance, 400);
    add_skill_points(Skill_Stamina, 800);
    add_skill_points(Skill_Carousing, 600);
}
