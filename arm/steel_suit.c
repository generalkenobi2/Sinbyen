#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit Sinbyen_Armour("Crimson_Armour");

void configure() {
    ::configure();
    armour()->set_autonomon_adapt(True);
    armour()->set_armour_type(random_element(({
                                                Armour_Type_Full_Suit,
                                                Armour_Type_Pteratectum,
                                                Armour_Type_Tailsuit,
                                                Armour_Type_Shivarix,
                                                Armour_Type_Sithalissar,
                                                })));
    armour()->set_armour_style(Armour_Style_Articulated);
    armour()->set_race(random_element(({
                            "amberite",
                            "human",
                            "garou",
                            "aviar",
                            "faerie",
                            "ogre",
                            "minotaur",
                            "dragon",
                            "zuth",
                        })));
    add_proportion(([
        Element_Type              : Material_Steel,
        Element_Proportion        : 3.0,
        Element_Color             : random_element(({
                                    "black",
                                    "dark red",
                                    "white",
                                    })),
    ]));
}
