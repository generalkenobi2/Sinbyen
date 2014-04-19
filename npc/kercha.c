#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit Sinbyen_Monster("Citizen");

//Sinbyen Visitor Center - map_4_-8_0//

void configure() {
    ::configure();
    set_culture("Losthavener");
    set_race("human");
    set_sex(Sex_Female);
    set_level(15);
    set_culture_name("Kercha");
    set_alignment(({ 1000, 1000 }));
    add_description(Description_Type_Generic);    
    add_known_description(({
      'v',    ({ "recognize", 'v' }), ({ 'o', 0 }),  "as Kercha, the volunteer that helps run Sinbyen's visitor's center",
    }));
    alter_element(Material_Hair, Element_Color, "blonde");
    alter_element(Material_Eye, Element_Color, "green");
    alter_element(Material_Skin, Element_Color, "tan");
    set_combat_mode_selected(Combat_Mode_Balanced);
    set_can_kill(True);
    add_skill_points(Skill_Norska, 400);
    set_primary_language(Skill_Norska);
    set_attack_scatter(50);
    set_strike_location("head");
    set_chat(3, ({
        "say Welcome to my Sinbyen! to %p",
        "say You should visit the backyard BBQ in the lower quarter of the city. to %p",
        "say Thurgg hates horses, once he left for several months, and in his absence, an unfortunate man set up a stables, when Thurgg returned, the results weren't pretty. to %p",
        "say Wickett runs a quaint general store just south of the Sinbyen Square to %p",
        "say Just outside north of the yard we have the finest clothing and jewelry in Sinbyen. to %p",
        "say If you would like to speak with the mayor you'll find Marco west of here, just across the yard. to %p",
        "say Northwest of here is the Crimson Barracks, the home of the Crimson Guard and the Crimson Fist! to %p",
        "say Just northeast of here you'll find Joe's Mammoth Barbecue, one of the best establishments in Sinbyen if I say so myself! to %p",
        "say Sint Skogen runs a shop east of here offers weapons that do all sorts of magickal things. to %p",
        "say A small furniture store is situated in the lower quarter south of here. to %p",
        "say Auriel has the finest archery range in Sinbyen.  She's on the east side of the city square. to %p",
        "say Dataro owns a fine shop that sells cloaks and capes in the city square. to %p",
        "say Agin runs a shop in the city square completely devoted to dragons. to %p",
        "say The skooma den is a cheap little bar southwest of here in our lower quarter. to %p",
        "say If you're in need of a bank you'll find one west of here. to %p",
        "say There's so much to do in Sinbyen! to %p",
        "say The tombs to the southeast of us used to be a resting place for the honored dead, but now seem to have come back to haunt us! to %p",
        "say If you're in need of armour, primbal runs a shop just east of the Raging Gnoll. to %p",
        "say Starling has a cute little fruit market right outside the Raging Gnoll. to %p",
        "say Candor has the finest book store that I've seen. to %p",
        "say If you're feeling weary, you can ease your mind with our counselor driskul, he's just north of the city park. to %p",
        "say If you're into bondage and such you might try visiting Dibella in the city square northeast of here. to %p",
        "say Frank runs a fantastic fish market on the north side of Sinbyen. to %p",
        "say The prison in northwest Sinbyen is empty for the most part, but we keep it in case the need arises. to %p",
        "say Have you visited Thurgg?  He's scary but if you're wanting to join the Crimson Fist you'll have to talk to him. to %p",
        "say Amstaar runs a fantastic alchemy shop in east Sinbyen! to %p",
        "say We've got a dock north of the city wall if you want to watch the ocean. to %p",
        "say Kim runs a sweet little candy store just north of the park. to %p",
        "say The Raging Gnoll is a great place to go to let off steam and grab a drink. to %p",
        "say Iskaarl runs a shop full of odd items on the east side of Sinbyen. to %p",
        "say Thurgg refuses to live in a regular house like the rest of us, and the city was constructed around his cave. to %p",
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
    }));
    
    
}
