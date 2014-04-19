#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Fierro's Elemental Armoury - map_6_1_0//
//House - map_6_2_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("thond");
    set_sex(Sex_Male);
    set_level(20);
    set_culture_name(({ "Fierro", "Vandego" }));
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of the Elemental Armoury" }));
    add_description(Description_Type_Generic);
    add_known_description(({
        'v', ({ "recognize", 'v' }), "him as Fierro Vandego, the somewhat eccentric owner of the Elemental Armoury. He sells prized armours that have elemental properties ranging from simple elemental resistances to full body contact damage.",
    }));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_chat(3, ({
        "say Welcome to the The Elemental Armoury! Unfortunately we are not yet open for business, but you're welcome to look around. to %p",
        //"say One good strike is all it takes to end it, that's why it's important to wear the right armour! to %p",
        //"say Have you ever fought a dragon?  One taste of their flames will leave you wishing you'd bought something that'd resist that inferno. to %p",
        //"say If you're going to fight something that's made of fire you should wear some of my aquarax gear, every time it hits you it'l wish it hadn't. to %p",
        //"say Take a look at my fine armours! to %p",
        //"say My armour does more than just protect, it bites back when you're attacked. to %p",
        //"say This is the only place you'll find armour like this, i can guarantee that! to %p",
        //"say I alone know the technique to making this type of armour. to %p",
        //"say Can i help you find something? to %p",
        //"say Welcome to the The Elemental Armoury! to %p",
        //"say Welcome to the The Elemental Armoury! to %p",
        //";adjust one of the armour displays",
        //";spray some substance on a rag and wipes down one of the suits of armour. ",
        
    }));
    set_combat_chat(20, ({
        "flee",
        "shout Guards! Guards!",
        "shout Help me, Guards!",
        ";duck",
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
}