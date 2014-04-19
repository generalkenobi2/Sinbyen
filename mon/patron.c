#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race(random_element(([
                "human"     : 10,
                "thond"     : 10,
                "dana"      : 8, 
                "goblin"    : 6,
                "orc"       : 10,
                "garou"     : 4,
                "gnome"     : 6,
                "sekh"      : 7,
                "aviar"     : 4,
                "domandan"  : 10,
                "llelimin"  : 2,
    ])));
    set_sex(random_element(({
                Sex_Male,
                Sex_Female,
    })));
    set_level(5 + random(20));
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as one of the common class in Sinbyen",
    }));
    if(query_race() == "garou" || query_race() == "sekh"){
        alter_element(Material_Fur, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blonde",
                    "red",
                    "reddish",
                    "brownish",
        })));
    }
    if(query_race() != "garou" || query_race() != "sekh"){
        alter_element(Material_Hair, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blonde",
                    "red",
                    "reddish",
                    "brownish",
        })));
    }
    alter_element(Material_Eye, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blue",
                    "blueish",
                    "green",
                    "brownish",
    })));
    alter_element(Material_Skin, Element_Color, random_element(({
                    "white",
                    "black",
                    "brown",
                    "tan",
    })));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(8, ({
        "say Have you seen the Crimson Fist training facility lately?",
        "say My spouse and I plan on visiting Almeria soon.",
        "shout Darlena, I'll have another!",
        "shout What do you mean you're married?",
        "whisper I think I'll have another. to myself",
        "shout Darlena, you make the best drinks",
        "shout Can you believe it!?",
        "shout Why do you always say that!?",
        "shout If you've never been to Sanctuary, stop telling us about it!",
        "shout Darlena!",
        "shout Another, we'll have another!",
        "shout Damn runtlings, fulps is not the best!",
        "shout Baby, you're coming home with me tonight.",
        "say I'm completely sober.",
        "shout ... and that's why I'm never sleeping with those two again.",
        "shout I'm going home!",
        "shout Marco is going to bankrupt this city!",
        "say Have you heard of the blind prophet?",
        "say Why would you do that!?",
        "say So you burnt the beavers lodge down!?",
        "say I hate it when you tell jokes, they're genuinely awful.",
        "say It's not funny when I have to explain the joke to you!",
        "say You're probably broke because you're always here!",
        "say If I were you, I'd go home and apologize.",
        "say Tomorrow will be a better day.",
        "say I wonder if they'll ever allow horses here again.",
        "shout That sentence had too many syllables! Apologize!",
        "say Did you see the ass on her?",
        "shout That guy is like a god.",
        "say I wish I had a shield like that.",
        "say That's not music, that's garbage, absolute rubbish.",
        "say That's not funny, ducks don't put out fires.",
        "say You're preaching to the choir.",
        "say Dude, you're retarded, shut up.",
        "say If it's making you mad why do you keep playing it!?",
        "shout Why do must you, get in way!",
        "say Yeah, that about sums it up.",
        "say Nothing about that is ok. It's not ok, you're not ok, I'm not ok. So no... It's not ok.",
        "say It doesn't matter that he did it first! If it was a bad idea you shouldn't have followed him!",
        "say Kids these days...",
        "say I don't know, it like exploded or something.",
        "laugh",
        "sigh",
        "sigh",
        "roll",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
        "drink alcohol",
    }));
    set_combat_chat(20, ({
        ";say What have i done?! to %e",


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
        Belonging_File      : Sinbyen_Comestible("sinbyen_lager"),
        Belonging_Count     : 5,
        ]),
        ([
        Belonging_File      : Sinbyen_Comestible("beer"),
        Belonging_Count     : 5,
        ]),
    }));
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
