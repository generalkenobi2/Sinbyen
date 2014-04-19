#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>
#include <Imptropolis.h>
#include <craft.h>

inherit Sinbyen_Monster("Citizen");

//Agin's Dragon Emporium - map_6_0_0//
//House - map_-9_-10_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("phaethon");
    set_sex(Sex_Male);
    set_level(20);
    set_culture_name(({ "Agin", "Dragonclaw" }));
    set_alignment(({ 0, 0 }));
    alter_identity(Identity_Known_Nouns, ({ "Owner of the Dragon Emporium" }));
    add_description(Description_Type_Generic);
    add_known_description(({
        'v', ({ "recognize", 'v' }), "him as Agin Dragonclaw, the owner and operator of the Dragon Emporium. His love for the dragon race is known throughout Sinbyen.",
    }));
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_chat(3, ({
        "say Welcome to the Dragon Emporium! to %p",
        "say Gramps here saved my life when i was young, and i've had an undying appreciation for dragons since. to %p",
        "say Dragons are often misunderstood, once you get to know one, you can't help but love em'!. to %p",
        "say Don't mess with Gramp, or i might have to bloodboil you. to %p",
        "say Did you know that dragons can breath all kinds of fire? How amazing is that? to %p",
        "say Talent chances are few and far between, if you mess one up you may as well start over. to %p",
        "say Sometimes i'll take a challenge from one of the followers of Ganesha. to %p",
        "say Hmm... wonder if this will report wild talents... no that didn't work either. to %p",
        "say Thurgg sure has a temper. to %p",
        "say Welcome to the Dragon Emporium. to %p",
        "say Welcome to the Dragon Emporium. to %p",
        "say Sadly, just like humans, some dragons can't be reasoned with",
        "say We put what's left of slain dragons to good use to honor their loss",
        "pet gramp",
        ";polish one of my many dragon statues",
        "say Sometimes when i complete a challenge Ganesha will reward me with a fantastic ring! to %p",
        "say The challenges Ganesha gives are always different and unique, but my favorite is when he asks me to give charity! to %p",
        
    }));
    set_combat_chat(20, ({
        ";cry",
        "say my dragon will save me!",
        "shout Help me Gramp!",
        ";cry for mercy",
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