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
    set_race(random_element(({
                "human",
                "thond",
    })));
    set_sex(random_element(({
                Sex_Male,
                Sex_Female,
    })));
    set_level(5 + random(20));
    set_title("the noble");
    set_alignment(({ 0, 0 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as one of the nobles of Sinbyen",
    }));
    alter_element(Material_Hair, Element_Color, random_element(({
                    "brown",
                    "black",
                    "blonde",
                    "red",
                    "reddish",
                    "brownish",
    })));
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
    set_chat(3, ({
        "say There's a marvelous play showing in Liathyr, you simply must see it! to %p",
        "say These commoners think they can do whatever they like these days! to myself",
        "say Please keep your distance %p! to %p",
        ({ 0, ({ "adjust", 0 }), ({ 'r', 0, "attire" }) }),
        ({ 0, ({ "glance", 0 }), "at", "%p" }),
        "frown",
        "say You should visit Jangrid's... immediately. to %p",
        "say Oh my, what is that wretched smell!",
        "say Another tourist? to %p",
        "say The weather here is usually abysmal. to %p",
        "say I can't believe these gorillas call themselves the city guard! to myself",
        "whisper Tonight I think I shall have my servants make clam soup. to myself",
        "say I can only hope that one day the common rabble will learn their place! to myself",
        "say Despite his wretched appearance, Joe makes a very delicious meal. to %p",
        "say I went to Dataro's once to buy a fine cloak and was set upon by a ghastly creature, it was all I could do but to shout for the guard and run! to %p",
    }));
    set_combat_chat(20, ({
        ";say You dare assault your superior!? Guards! Arrest this %c. to %p",


    }));
    set_belongings(({
        ([
        Belonging_File      : Sinbyen_Armour("fine_boots"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("fine_pants"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("fine_shirt"),
        ]),
        ([
        Belonging_File      : Sinbyen_Armour("silk_cloak"),
        ]),        
    }));
}


void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
}
