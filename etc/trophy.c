#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
       alter_identity(([
        Identity_Name           : "a statue of a dragon",
        Identity_Nouns          : ({ "statue of a dragon", "statue", "dragon" }),
    ]));
    set_identify_skills(([
        Skill_Dentistry         : 30,
    ]));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), "a {{gold}small gold statue} of a dragon.",
        "  There is a small plaque at the base of the statue",
 
    }));
    set_readable(({ 0, "plaque" }), Skill_Norska, 
    "//  This statue is a symbol of hope //\n"
    "// for all of the beautiful dragons //\n"
    "// in the world that don't get the  //\n"
    "//      love that they deserve.     //");
    set_craft(Craft_Excellent);
        set_shape(([
        Shape_Type              : Geometry_Anthropoid,
        Shape_Length            : 1.0,
        Shape_Width             : 1.0,
        Shape_Height            : 3.0,
    ]));

    add_proportion(([
        Element_Type            : Material_Gold,
        Element_Proportion      : 1.0,
    ]));
}
