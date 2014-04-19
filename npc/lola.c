#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Sinbyen Strip Club - map_7_-9_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Female);
    set_level(1);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_culture_name("Lola");
    alter_identity(Identity_Name_Title, ([
                Seeable_Word  : "the stripper",
                Seeable_Flags : Seeable_Flag_Verbose_Only,
        ]));
    set_alignment(({ -800, -400 }));
    add_description(({
        "This is a young woman with short",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Hair,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", fair",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Index   : Material_Skin,
            Description_Flags   : Description_Flag_Noun,
        ])),
        ", and deep",
        Description(([
            Description_Type    : Description_Type_Element_Color,
            Description_Index   : Material_Eye,
            Description_Content : "eyes",
        ])),
    }));
    
    add_description(({
        ({ 'p', 0 }), ({ "are", 0 }), "extremely attractive,", ({ "have", 0 }), "large round breasts, and wide curvaceous hips",
    }));
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }), "as Lola, one of the strippers at the strip club",
    }));
    alter_element(Material_Hair, Element_Color, "brown");
    alter_element(Material_Eye, Element_Color, "green");
    alter_element(Material_Skin, Element_Color, "white");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    set_attack_scatter(50);
    set_strike_location("head");
    set_trait(Trait_Handedness, Limb_Lateral_None);
    set_trait(Trait_Sadism, 3);
    set_trait(Trait_Masochism, 6);
    set_chat(15, ({
        ";dance slowly",
        ";spin around the pole",
        ({ 0, ({ "shake", 0 }), ({ 'r', 0, "breasts" }), "in front of", "%p", }),
        ";lean toward %p",
        ";crawl across the stage",
        ";walk to the edge of the stage",
        ";hang from the pole upside down",
        ({ 0, ({ "climb", 0 }), "up the pole and", ({ "hang", 0 }), "upside down", }),
        ({ 0, ({"turn",0}),({'r',0,"back"}),"to","%p",",",({"bend",0}),"over, and",({"wink",0}),"at","%p","from between",({'r',0,"long slender legs"})}),
        ";bend over in front of %p",
        ";smile at %p",
        ";slide my back down the pole",
        ";bend over seductively",
        "remove thong",
        "wear thong",
        ({ 0, ({"arch",0}),({'r',0,"back"}),"and",({"fall",0}),"to",({'r',0,"knees"})}),
        ({ 0, ({"gaze",0}),"at","%p","and",({"lick",0}),({'r',0,"lips"}),"seductively"}),
        
    }));
    set_combat_chat(20, ({
        "say Help me!",
    }));
    add_affiliation("Synousia Algesis");
    add_skill_points(Skill_Erotic_Arts, 5000);
    add_skill_points(Skill_Erotic_Lore, 5000);
    add_skill_points(Skill_Dancing, 5000);
    add_skill_points(Skill_Chromatostasis, 5000);
    

    set_belongings(({
        Sinbyen_Armour("thong"),
    }));

    
    
}